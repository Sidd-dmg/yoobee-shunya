# MQTT Manual for End Users

```markdown
<!-- File: c:\Users\Sidd\placement_portal\placement_portal\MQTT_MANUAL.md -->
# 📡 Shunya IoT Gateway — MQTT User Manual

## Table of Contents
- [Connection Details](#connection-details)
- [Topic Structure](#topic-structure)
- [1. Operation Modes](#1-operation-modes)
- [2. Manual Mode](#2-manual-mode)
- [3. Automation Mode](#3-automation-mode)
- [4. Queue Mode](#4-queue-mode)
- [5. Hybrid Mode](#5-hybrid-mode)
- [6. OTA Firmware Updates](#6-ota-firmware-updates)
- [7. Event Logs](#7-event-logs)
- [8. Status & Monitoring](#8-status--monitoring)
- [9. Quick Reference](#9-quick-reference)

---

## Connection Details

| Parameter | Value |
|-----------|-------|
| **Broker IP** | `82.112.230.108` |
| **Port** | `1883` |
| **Username** | `shunya` |
| **Password** | `shunyaIOT` |

> 💡 **Your Device MAC** is printed on the device label and also shown in the Serial monitor on boot.  
> All topics use your MAC address **without colons** (e.g., `A1B2C3D4E5F6`).

---

## Topic Structure

```
PUBLISH (send commands to device):
  {MAC}/command          ← Send all commands here

SUBSCRIBE (receive data from device):
  {MAC}/status           ← Device status updates
  {MAC}/node1            ← Node 1 sensor data
  {MAC}/node2            ← Node 2 sensor data
  {MAC}/node3            ← Node 3 sensor data
  {MAC}/node4            ← Node 4 sensor data
  {MAC}/event_log        ← Event log data
  {MAC}/ota/status       ← OTA update status
```

**Example** — if your MAC is `A1B2C3D4E5F6`:
- Command topic: `A1B2C3D4E5F6/command`
- Status topic:  `A1B2C3D4E5F6/status`

---

## 1. Operation Modes

The gateway supports **4 modes**. Switch between them using the `mode` command.

| Mode | Value | Description |
|------|-------|-------------|
| Manual | `0` | You control relays directly via MQTT |
| Automation | `1` | Relays controlled by temperature/humidity rules |
| Queue | `2` | Relays follow a timed sequence |
| Hybrid | `3` | Automation + Queue combined |

### Switch Mode — Immediate
```json
{"mode": 0}
```
```json
{"mode": 1}
```
```json
{"mode": 2}
```
```json
{"mode": 3}
```

### Switch Mode — Graceful (waits for current queue cycle to finish)
```json
{"mode": 0, "transition": "graceful"}
```

### Switch Mode and Save to Memory
```json
{"mode": 1, "auto_save": true}
```

---

## 2. Manual Mode

> ⚠️ Must be in **Mode 0** for relay commands to work.

### Turn Individual Relays ON/OFF

**Relay 1 ON:**
```json
{"relay1": 1}
```

**Relay 1 OFF:**
```json
{"relay1": 0}
```

**Relay 2 ON:**
```json
{"relay2": 1}
```

**Relay 3 OFF:**
```json
{"relay3": 0}
```

**Relay 4 ON:**
```json
{"relay4": 1}
```

### Control Multiple Relays at Once
```json
{"relay1": 1, "relay2": 0, "relay3": 1, "relay4": 0}
```

### Turn ALL Relays ON
```json
{"all": 1}
```

### Turn ALL Relays OFF
```json
{"all": 0}
```

> 💾 Manual relay states are **automatically saved** to memory and restored after a reboot.

---

## 3. Automation Mode

> ⚠️ Must be in **Mode 1** for automation to run.

Automation rules monitor sensor nodes and control relays based on **temperature** and/or **humidity** thresholds.

### How Thresholds Work

| Condition | Action |
|-----------|--------|
| `temp > tempMax` | Relay turns **ON** |
| `temp < tempMin` | Relay turns **OFF** |
| Between min and max | Relay **holds current state** (hysteresis) |

Same logic applies to humidity.

---

### Example 1 — Temperature Only (Single Rule)
> Node 1 controls Relay 1. Turn ON if temp > 30°C, turn OFF if temp < 25°C.

```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 25,
          "max": 30
        }
      }
    ]
  }
}
```

---

### Example 2 — Humidity Only
> Node 2 controls Relay 2. Turn ON if humidity > 70%, turn OFF if humidity < 50%.

```json
{
  "automation": {
    "rules": [
      {
        "node": 2,
        "relay": 2,
        "humidity": {
          "min": 50,
          "max": 70
        }
      }
    ]
  }
}
```

---

### Example 3 — Temperature AND Humidity (OR Logic)
> Relay turns ON if **either** temp > 35°C **OR** humidity > 80%.

```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 25,
          "max": 35
        },
        "humidity": {
          "min": 40,
          "max": 80
        },
        "logic": "OR"
      }
    ]
  }
}
```

---

### Example 4 — Temperature AND Humidity (AND Logic)
> Relay turns ON only if **both** temp > 35°C **AND** humidity > 80%.

```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 25,
          "max": 35
        },
        "humidity": {
          "min": 40,
          "max": 80
        },
        "logic": "AND"
      }
    ]
  }
}
```

---

### Example 5 — Multiple Rules (4 Nodes, 4 Relays)
> Each node independently controls its own relay.

```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": {"min": 20, "max": 30}
      },
      {
        "node": 2,
        "relay": 2,
        "temp": {"min": 22, "max": 32}
      },
      {
        "node": 3,
        "relay": 3,
        "humidity": {"min": 40, "max": 75}
      },
      {
        "node": 4,
        "relay": 4,
        "temp": {"min": 18, "max": 28},
        "humidity": {"min": 30, "max": 65},
        "logic": "OR"
      }
    ]
  }
}
```

---

### Example 6 — One Node Controls Multiple Relays
> Node 1 controls both Relay 1 and Relay 2 with different thresholds.

```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": {"min": 25, "max": 30}
      },
      {
        "node": 1,
        "relay": 2,
        "temp": {"min": 30, "max": 35}
      }
    ]
  }
}
```

---

### Clear All Automation Rules
```json
{
  "automation": {
    "clear": true
  }
}
```

---

## 4. Queue Mode

> ⚠️ Must be in **Mode 2** for queue to run.

Queue mode runs relays in a **timed sequence**, one step at a time.  
Each step either turns a relay ON for a duration, or adds a delay (all relays OFF).

### Step Types

| Type | Description |
|------|-------------|
| `"relay"` | Turn a specific relay ON for `duration` seconds |
| `"delay"` | All relays OFF for `duration` seconds |

---

### Example 1 — Simple 2-Relay Sequence (Looping)
> Relay 1 ON for 10s → Relay 2 ON for 10s → repeat forever.

```json
{
  "queue": {
    "loop": true,
    "auto_start": true,
    "steps": [
      {"relay": 1, "duration": 10},
      {"relay": 2, "duration": 10}
    ]
  }
}
```

---

### Example 2 — Sequence with Delays Between Steps
> Relay 1 ON 30s → All OFF 10s → Relay 2 ON 30s → All OFF 10s → repeat.

```json
{
  "queue": {
    "loop": true,
    "auto_start": true,
    "steps": [
      {"relay": 1, "duration": 30},
      {"delay": 10},
      {"relay": 2, "duration": 30},
      {"delay": 10}
    ]
  }
}
```

---

### Example 3 — 4-Relay Round Robin (Irrigation Style)
> Each relay runs for 5 minutes in sequence, loops forever.

```json
{
  "queue": {
    "loop": true,
    "auto_start": true,
    "steps": [
      {"relay": 1, "duration": 300},
      {"relay": 2, "duration": 300},
      {"relay": 3, "duration": 300},
      {"relay": 4, "duration": 300}
    ]
  }
}
```

---

### Example 4 — Run Once (No Loop)
> Relay 1 ON for 60 seconds, then stop.

```json
{
  "queue": {
    "loop": false,
    "auto_start": true,
    "steps": [
      {"relay": 1, "duration": 60}
    ]
  }
}
```

---

### Example 5 — Complex Multi-Step Sequence
> Full irrigation cycle with delays.

```json
{
  "queue": {
    "loop": true,
    "auto_start": true,
    "steps": [
      {"relay": 1, "duration": 120},
      {"delay": 30},
      {"relay": 2, "duration": 90},
      {"delay": 30},
      {"relay": 3, "duration": 60},
      {"delay": 30},
      {"relay": 4, "duration": 45},
      {"delay": 300}
    ]
  }
}
```

---

### Queue Control Commands

**Pause the queue:**
```json
{"queue_control": "pause"}
```

**Resume a paused queue:**
```json
{"queue_control": "resume"}
```

**Stop the queue (disables auto-start):**
```json
{"queue_control": "stop"}
```

**Restart the queue from Step 1:**
```json
{"queue_control": "restart"}
```

**Enable auto-start on reboot:**
```json
{"queue_control": "enable_autostart"}
```

**Disable auto-start on reboot:**
```json
{"queue_control": "disable_autostart"}
```

---

## 5. Hybrid Mode

> ⚠️ Must be in **Mode 3** for hybrid to run.

Hybrid mode combines **Automation** and **Queue** simultaneously.  
The final relay state is determined by a **logic rule** applied to both systems.

### Logic Types

| Logic | Behavior |
|-------|----------|
| `"AND"` | Relay ON only if **both** automation AND queue want it ON |
| `"OR"` | Relay ON if **either** automation OR queue wants it ON |

---

### Example 1 — OR Logic (Either system can activate relay)
> Queue runs a timed cycle. Automation can also turn on relays independently.  
> Relay turns ON if EITHER condition is met.

```json
{
  "hybrid": {
    "logic": "OR",
    "automation": {
      "rules": [
        {
          "node": 1,
          "relay": 1,
          "temp": {"min": 25, "max": 35}
        }
      ]
    },
    "queue": {
      "loop": true,
      "steps": [
        {"relay": 2, "duration": 60},
        {"delay": 30},
        {"relay": 3, "duration": 60},
        {"delay": 30}
      ]
    }
  }
}
```

---

### Example 2 — AND Logic (Both systems must agree)
> Relay only turns ON if the queue schedules it AND automation conditions are met.  
> Useful for safety interlocks (e.g., only irrigate if it's hot enough).

```json
{
  "hybrid": {
    "logic": "AND",
    "automation": {
      "rules": [
        {
          "node": 1,
          "relay": 1,
          "temp": {"min": 28, "max": 40}
        }
      ]
    },
    "queue": {
      "loop": true,
      "steps": [
        {"relay": 1, "duration": 120},
        {"delay": 600}
      ]
    }
  }
}
```

---

### Change Hybrid Logic Only (without reconfiguring rules)
```json
{"hybrid": {"logic": "OR"}}
```
```json
{"hybrid": {"logic": "AND"}}
```

---

## 6. OTA Firmware Updates

### Check if a New Version is Available
```json
{"ota_check": true}
```

**Response on `{MAC}/ota/status`:**
```json
{
  "ota_available": true,
  "current_version": "3.0.1",
  "new_version": "3.0.2"
}
```

---

### Trigger OTA Update
> ⚠️ Device will reboot after update. All relays turn OFF during update.

```json
{"ota_update": true}
```

**Response on `{MAC}/ota/status` during update:**
```json
{"ota_status": "starting", "message": "OTA update initiated..."}
```

**On success:**
```json
{"ota_status": "success", "message": "Rebooting. Will rollback if new firmware is invalid."}
```

**On failure (auto-rollback to previous firmware):**
```json
{"ota_status": "failed", "error": "...", "message": "Image validation failed. Rollback safe."}
```

**After successful reboot (new firmware verified):**
```json
{"ota_status": "verified", "message": "New firmware marked as valid. Rollback cancelled.", "version": "3.0.2"}
```

---

## 7. Event Logs

The device logs every relay change to internal storage (SPIFFS) **when MQTT is disconnected**.  
Logs are sent to MQTT when connection is restored or on demand.

> 📦 Maximum **5000 log entries** stored. Oldest entries are dropped when full.

---

### Get Log Count
```json
{"event_log": "count"}
```

**Response on `{MAC}/event_log`:**
```json
{
  "status": "count",
  "count": 142,
  "max": 5000,
  "spiffs_used": 204800,
  "spiffs_total": 10420224
}
```

---

### Send All Logs to MQTT
```json
{"event_log": "send"}
```

**Response — Start notification:**
```json
{"status": "sending", "total_count": 142, "batch_size": 20}
```

**Response — Each batch (20 logs per batch):**
```json
{
  "batch_index": 0,
  "batch_count": 20,
  "total": 142,
  "logs": [
    {
      "relay_id": 1,
      "state": "ON",
      "mode": "manual",
      "trigger": "manual",
      "timestamp": "2025-01-15 14:32:10",
      "uptime_ms": 123456,
      "nodes": [
        {"id": 1, "temp": 28.5, "hum": 65.2}
      ]
    }
  ]
}
```

**Response — Completion:**
```json
{"status": "complete", "sent_count": 142, "message": "All event logs sent"}
```

---

### Clear All Logs
```json
{"event_log": "clear"}
```

**Response:**
```json
{"status": "cleared", "message": "Event log cleared"}
```

---

### Send Logs Then Clear (One Command)
```json
{"event_log": "send_and_clear"}
```

---

## 8. Status & Monitoring

### Request Current Status
The device publishes status automatically every **10 seconds** to `{MAC}/status`.

**Example status payload:**
```json
{
  "mode": 0,
  "mode_name": "manual",
  "timestamp": "2025-01-15 14:32:10",
  "uptime_ms": 3600000,
  "wifi_connected": true,
  "wifi_rssi": -65,
  "wifi_channel": 11,
  "wifi_ssid": "MyNetwork",
  "ip_address": "192.168.1.105",
  "mqtt_connected": true,
  "pairing_mode": false,
  "paired_nodes": 2,
  "relays": [true, false, false, true],
  "nodes": [
    {
      "id": 1,
      "active": true,
      "temperature": 28.5,
      "humidity": 65.2,
      "last_seen_ms": 4500,
      "mac": "AA:BB:CC:DD:EE:FF"
    },
    {
      "id": 2,
      "active": true,
      "temperature": 31.2,
      "humidity": 70.1,
      "last_seen_ms": 3200,
      "mac": "11:22:33:44:55:66"
    }
  ]
}
```

---

### Sensor Node Data
Published automatically when sensor data is received.  
Topic: `{MAC}/node1`, `{MAC}/node2`, etc.

```json
{
  "node_id": 1,
  "temperature": 28.5,
  "humidity": 65.2,
  "node_uptime_ms": 86400000,
  "timestamp": "2025-01-15 14:32:10"
}
```

---

## 9. Quick Reference

### All Command Payloads at a Glance

```
MODES
─────────────────────────────────────────────────────
Switch to Manual:       {"mode": 0}
Switch to Automation:   {"mode": 1}
Switch to Queue:        {"mode": 2}
Switch to Hybrid:       {"mode": 3}
Graceful transition:    {"mode": 0, "transition": "graceful"}
Save mode to memory:    {"mode": 1, "auto_save": true}

MANUAL MODE
─────────────────────────────────────────────────────
Relay 1 ON:             {"relay1": 1}
Relay 1 OFF:            {"relay1": 0}
Relay 2 ON:             {"relay2": 1}
Relay 3 ON:             {"relay3": 1}
Relay 4 OFF:            {"relay4": 0}
Multiple relays:        {"relay1": 1, "relay2": 0, "relay3": 1, "relay4": 0}
All ON:                 {"all": 1}
All OFF:                {"all": 0}

AUTOMATION MODE
─────────────────────────────────────────────────────
Set rules:              {"automation": {"rules": [...]}}
Clear rules:            {"automation": {"clear": true}}

QUEUE MODE
─────────────────────────────────────────────────────
Set queue:              {"queue": {"loop": true, "steps": [...]}}
Pause:                  {"queue_control": "pause"}
Resume:                 {"queue_control": "resume"}
Stop:                   {"queue_control": "stop"}
Restart:                {"queue_control": "restart"}
Enable auto-start:      {"queue_control": "enable_autostart"}
Disable auto-start:     {"queue_control": "disable_autostart"}

HYBRID MODE
─────────────────────────────────────────────────────
Set hybrid:             {"hybrid": {"logic": "OR", "automation": {...}, "queue": {...}}}
Change logic only:      {"hybrid": {"logic": "AND"}}

OTA UPDATES
─────────────────────────────────────────────────────
Check version:          {"ota_check": true}
Start update:           {"ota_update": true}

EVENT LOGS
─────────────────────────────────────────────────────
Get count:              {"event_log": "count"}
Send logs:              {"event_log": "send"}
Clear logs:             {"event_log": "clear"}
Send and clear:         {"event_log": "send_and_clear"}
```

---

## ⚠️ Important Notes

1. **Mode must match command** — Manual relay commands only work in Mode 0. Automation config only applies in Mode 1, etc.
2. **Relay numbering** — Relays are numbered **1 to 4** in all commands.
3. **Node numbering** — Nodes are numbered **1 to 4** in automation rules.
4. **Queue durations** — All durations are in **seconds**.
5. **Auto-save** — Manual relay states and queue configs are saved automatically. Mode changes require `"auto_save": true` to persist.
6. **OTA safety** — If new firmware crashes on boot, the device **automatically rolls back** to the previous working firmware.
7. **Offline logging** — Event logs are only written when **MQTT is disconnected**. When MQTT is connected, events go directly to MQTT.
8. **Pairing mode** — Hold the boot button for **1 second** to enable pairing. It auto-disables after **2 minutes**.
```

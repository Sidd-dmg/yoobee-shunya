# Shunya IoT Gateway — MQTT User Manual

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
- [9. Important Behaviors](#9-important-behaviors)
- [10. Quick Reference](#10-quick-reference)

---

## Connection Details

| Parameter | Value |
|-----------|-------|
| **Broker IP** | `82.112.230.108` |
| **Port** | `1883` |
| **Username** | `shunya` |
| **Password** | `shunyaIOT` |

> **Your Device Topic Prefix** is your device MAC address **without colons**.  
> Example: MAC `A1:B2:C3:D4:E5:F6` → prefix is `A1B2C3D4E5F6`  
> The MAC is shown in the Serial monitor on boot and also visible in the BLE provisioning  
> app as **"Shunya A1:B2:C3:D4:E5:F6"**.

---

## Topic Structure

```
PUBLISH commands TO device:
  {MAC}/command            ← Send ALL commands here

SUBSCRIBE to receive FROM device:
  {MAC}/status             ← Full device status (auto every 10 seconds, retained)
  {MAC}/node1              ← Node 1 sensor data (on each sensor reading)
  {MAC}/node2              ← Node 2 sensor data
  {MAC}/node3              ← Node 3 sensor data
  {MAC}/node4              ← Node 4 sensor data
  {MAC}/event_log          ← Offline event log data (on request)
  {MAC}/ota/status         ← OTA update progress and result (retained)
```

**Example** — if your MAC prefix is `A1B2C3D4E5F6`:
- Send commands to: `A1B2C3D4E5F6/command`
- Read status from: `A1B2C3D4E5F6/status`

---

## 1. Operation Modes

The gateway supports **4 modes**.

| Mode | Value | Description |
|------|-------|-------------|
| Manual | `0` | You control relays directly via MQTT commands |
| Automation | `1` | Relays controlled automatically by temperature/humidity sensor rules |
| Queue | `2` | Relays follow a user-defined timed sequence |
| Hybrid | `3` | Automation and Queue run simultaneously, combined by AND/OR logic |

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

### Switch Mode — Graceful Transition
> Only applies when currently in Queue mode.  
> The device waits for the current queue cycle to finish before switching.

```json
{"mode": 0, "transition": "graceful"}
```

### Switch Mode and Persist to EEPROM
> Without `auto_save`, the mode resets to the last saved mode after reboot.

```json
{"mode": 1, "auto_save": true}
```

> **When switching away from Manual mode**, all relays are turned OFF immediately  
> before the new mode starts.

---

## 2. Manual Mode

> The device must be in **Mode 0 (Manual)** for relay commands to take effect.  
> In any other mode, relay commands sent via MQTT are ignored.

### Turn Individual Relays ON or OFF

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

**Relay 3 ON:**
```json
{"relay3": 1}
```

**Relay 4 OFF:**
```json
{"relay4": 0}
```

### Control Multiple Relays in One Command
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

> 💾 Manual relay states are **automatically saved to EEPROM** after every change  
> and are **restored on reboot** when the device is in Manual mode.

---

## 3. Automation Mode

> The device must be in **Mode 1 (Automation)**.  
> When entering Automation mode, **all relays are turned OFF** first for a clean start.

Automation rules monitor paired sensor nodes and control relays based on  
**temperature** and/or **humidity** thresholds.

### How Thresholds Work

| Sensor Reading | Action |
|----------------|--------|
| `value > max` | Relay turns **ON** |
| `value < min` | Relay turns **OFF** |
| `min ≤ value ≤ max` | Relay **holds its current state** (hysteresis band) |

> This hysteresis prevents rapid ON/OFF toggling near the threshold.  
> Additionally, the relay state cannot change faster than once every **3 seconds**.

### Rule Parameters

| Field | Required | Description |
|-------|----------|-------------|
| `node` | ✅ | Node ID to monitor (1–4) |
| `relay` | ✅ | Relay to control (1–4) |
| `temp` | Optional | Temperature thresholds `{"min": X, "max": Y}` |
| `humidity` | Optional | Humidity thresholds `{"min": X, "max": Y}` |
| `logic` | Optional | `"OR"` (default) or `"AND"` — applies when both temp and humidity are set |

> Maximum **16 rules** (`MAX_AUTO_RULES`) can be configured at once.  
> A single node can control multiple relays, and multiple nodes can control the same relay.

---

### Example 1 — Temperature Only
> Node 1 controls Relay 1.  
> Relay ON when temp > 30°C, OFF when temp < 25°C.

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
> Node 2 controls Relay 2.  
> Relay ON when humidity > 70%, OFF when humidity < 50%.

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

### Example 3 — Temperature AND Humidity with OR Logic
> Relay turns ON if **either** temp > 35°C **OR** humidity > 80%.

```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": {"min": 25, "max": 35},
        "humidity": {"min": 40, "max": 80},
        "logic": "OR"
      }
    ]
  }
}
```

---

### Example 4 — Temperature AND Humidity with AND Logic
> Relay turns ON only if **both** temp > 35°C **AND** humidity > 80%.

```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": {"min": 25, "max": 35},
        "humidity": {"min": 40, "max": 80},
        "logic": "AND"
      }
    ]
  }
}
```

---

### Example 5 — All 4 Nodes, Each Controlling Its Own Relay
```json
{
  "automation": {
    "rules": [
      {"node": 1, "relay": 1, "temp": {"min": 20, "max": 30}},
      {"node": 2, "relay": 2, "temp": {"min": 22, "max": 32}},
      {"node": 3, "relay": 3, "humidity": {"min": 40, "max": 75}},
      {"node": 4, "relay": 4, "temp": {"min": 18, "max": 28}, "humidity": {"min": 30, "max": 65}, "logic": "OR"}
    ]
  }
}
```

---

### Example 6 — One Node Controlling Multiple Relays at Different Thresholds
```json
{
  "automation": {
    "rules": [
      {"node": 1, "relay": 1, "temp": {"min": 25, "max": 30}},
      {"node": 1, "relay": 2, "temp": {"min": 30, "max": 35}}
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

> Clearing rules does **not** turn off relays. Relays hold their last state.

---

## 4. Queue Mode

> The device must be in **Mode 2 (Queue)**.  
> When entering Queue mode, **all relays are turned OFF** first.

Queue mode runs relays in a **timed sequence**, executing one step at a time.

### Step Types

| JSON Key | Description |
|----------|-------------|
| `"relay"` + `"duration"` | Turn the specified relay ON for `duration` seconds |
| `"delay"` | All relays OFF for the specified number of seconds |

> - Relay numbers: **1 to 4**
> - Duration/delay unit: **seconds**
> - Maximum steps per queue: **20** (`MAX_QUEUE_STEPS`)

---

### Example 1 — Simple 2-Relay Alternating Loop
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

### Example 2 — Sequence with Gaps Between Steps
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

### Example 3 — 4-Zone Irrigation Round Robin
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

### Example 4 — Run Once, No Loop
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

### Example 5 — Configure Queue but Do NOT Auto-Start
```json
{
  "queue": {
    "loop": true,
    "auto_start": false,
    "steps": [
      {"relay": 1, "duration": 60},
      {"relay": 2, "duration": 60}
    ]
  }
}
```
Then start it manually:
```json
{"queue_control": "restart"}
```

---

### Queue Control Commands

**Pause the running queue (relays hold their current state):**
```json
{"queue_control": "pause"}
```

**Resume a paused queue:**
```json
{"queue_control": "resume"}
```

**Stop the queue and turn OFF all relays (also disables auto-start):**
```json
{"queue_control": "stop"}
```

**Restart the queue from Step 1 (turns OFF all relays first, then starts):**
```json
{"queue_control": "restart"}
```

**Enable auto-start on next reboot:**
```json
{"queue_control": "enable_autostart"}
```

**Disable auto-start on next reboot:**
```json
{"queue_control": "disable_autostart"}
```

---

## 5. Hybrid Mode

> The device must be in **Mode 3 (Hybrid)**.  
> When entering Hybrid mode, **all relays are turned OFF** first.

Hybrid mode runs **Automation** and **Queue** at the same time.  
The final relay state is determined by combining both systems using a **logic rule**.

### Logic Types

| Logic | Relay turns ON when... |
|-------|------------------------|
| `"OR"` | **Either** automation OR queue wants the relay ON |
| `"AND"` | **Both** automation AND queue want the relay ON |

---

### Example 1 — OR Logic
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

### Example 2 — AND Logic (Safety Interlock)
```json
{
  "hybrid": {
    "logic": "AND",
    "automation": {
      "rules": [
        {
          "node": 1,
          "relay": 1,
          "temp": {"min": 20, "max": 28}
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

### Change Only the Logic Type
```json
{"hybrid": {"logic": "OR"}}
```
```json
{"hybrid": {"logic": "AND"}}
```

---

## 6. OTA Firmware Updates

> During an OTA update, **all relays are turned OFF** and the queue is stopped.  
> The device is **unresponsive to MQTT commands** until the update completes and it reboots.

### Check if a New Firmware Version is Available
```json
{"ota_check": true}
```

**Response on `{MAC}/ota/status` — update available:**
```json
{
  "ota_available": true,
  "current_version": "3.0.1",
  "new_version": "3.0.2"
}
```

> If already up to date, **no MQTT message is published**. "Firmware is up to date." is printed to Serial only.

---

### Trigger OTA Update
```json
{"ota_update": true}
```

**Response — starting:**
```json
{
  "ota_status": "starting",
  "message": "OTA update initiated..."
}
```

**Response — image corrupt (safe rollback, device stays on current firmware):**
```json
{
  "ota_status": "failed",
  "error": "ESP_ERR_OTA_VALIDATE_FAILED",
  "message": "Image validation failed. Rollback safe."
}
```

**Response — update successful (device reboots immediately after):**
```json
{
  "ota_status": "success",
  "message": "Rebooting. Will rollback if new firmware is invalid."
}
```

**Response — new firmware verified on first boot after update:**
```json
{
  "ota_status": "verified",
  "message": "New firmware marked as valid. Rollback cancelled.",
  "version": "3.0.2"
}
```

> **Automatic Rollback:** If the new firmware crashes before completing boot,  
> the ESP32 automatically boots back into the previous working firmware.

---

## 7. Event Logs

The device logs every relay state change to internal flash storage (SPIFFS).

> **Important:** Relay events are logged to SPIFFS **only when MQTT is disconnected**.  
> When MQTT is connected, relay events are published directly to MQTT in real time  
> and are **not** written to the local log file.

> Maximum **5000 entries** (`EVENT_LOG_MAX_ENTRIES`) are stored. When full,  
> the **oldest entry is dropped** to make room (streaming rotation — no full RAM load).

### Log Entry Fields

| Field | Description |
|-------|-------------|
| `relay_id` | Relay number (1–4) |
| `state` | `"ON"` or `"OFF"` |
| `mode` | `"manual"`, `"automation"`, `"queue"`, or `"hybrid"` |
| `trigger` | `"manual"`, `"automation"`, `"queue"`, or `"hybrid"` |
| `timestamp` | Date and time (IST) or `"N/A"` if NTP not synced |
| `uptime_ms` | Device uptime in milliseconds at time of event |
| `nodes` | Snapshot of all active node temperatures and humidities |

---

### Get Log Entry Count
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
> Logs are sent in batches of **20 entries** (`EVENT_LOG_BATCH_SIZE`) per MQTT message.

```json
{"event_log": "send"}
```

**Response — start notification:**
```json
{
  "status": "sending",
  "total_count": 142,
  "batch_size": 20
}
```

**Response — each batch:**
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
        {"id": 1, "temp": 28.5, "hum": 65.2},
        {"id": 2, "temp": 31.0, "hum": 70.1}
      ]
    }
  ]
}
```

**Response — completion:**
```json
{
  "status": "complete",
  "sent_count": 142,
  "message": "All event logs sent"
}
```

**Response — no logs found:**
```json
{
  "status": "no_logs",
  "message": "No offline event logs found"
}
```

**Response — log file empty:**
```json
{
  "status": "empty",
  "message": "Event log is empty"
}
```

> Sending large logs is a **blocking operation**.  
> The device may be slow to respond to other MQTT commands during this time.

---

### Clear All Logs
```json
{"event_log": "clear"}
```

**Response on `{MAC}/event_log`:**
```json
{
  "status": "cleared",
  "message": "Event log cleared"
}
```

---

### Send All Logs Then Clear in One Command
```json
{"event_log": "send_and_clear"}
```

> Sends all logs first, waits 500ms, then clears the log file.

---

## 8. Status & Monitoring

### Automatic Status Publishing
The device publishes its full status to `{MAC}/status` every **10 seconds** automatically  
(retained message). It also publishes immediately after any mode change, relay change,  
or queue step change.

---

### Full Status Payload — Manual Mode (Mode 0)

```json
{
  "mode": 0,
  "mode_name": "manual",
  "timestamp": "2025-01-15 14:32:10",
  "uptime_ms": 3600000,

  "wifi_connected": true,
  "wifi_rssi": -65,
  "wifi_channel": 6,
  "wifi_ssid": "MyNetwork",
  "ip_address": "192.168.1.105",

  "mqtt_connected": true,

  "pairing_mode": false,
  "paired_nodes": 2,

  "relays": [true, false, true, false],

  "nodes": [
    {
      "id": 1,
      "active": true,
      "temperature": 28.5,
      "humidity": 65.2,
      "last_seen_ms": 4200,
      "mac": "AA:BB:CC:DD:EE:FF"
    },
    {
      "id": 2,
      "active": true,
      "temperature": 31.0,
      "humidity": 70.1,
      "last_seen_ms": 1800,
      "mac": "11:22:33:44:55:66"
    }
  ],

  "event_log": {
    "pending_count": 47,
    "max_entries": 5000,
    "spiffs_used": 204800,
    "spiffs_total": 10420224,
    "log_exists": true,
    "topic": "A1B2C3D4E5F6/event_log"
  },

  "ota_available": 0,
  "firmware_version": "3.0.1"
}
```

> **`relays` array** — index 0 = Relay 1, index 1 = Relay 2, index 2 = Relay 3, index 3 = Relay 4.  
> `true` = ON, `false` = OFF.

> **`wifi_ssid`** and **`ip_address`** are only present when WiFi is connected.

> **`event_log.pending_count`** — number of relay events logged to SPIFFS while MQTT  
> was offline. Use `{"event_log": "send"}` to retrieve them.

---

### Full Status Payload — Automation Mode (Mode 1)

> Includes all fields from Manual Mode, plus `automation_rules` and `automation_rule_count`.

```json
{
  "mode": 1,
  "mode_name": "automation",
  "timestamp": "2025-01-15 14:32:10",
  "uptime_ms": 3600000,

  "wifi_connected": true,
  "wifi_rssi": -65,
  "wifi_channel": 6,
  "wifi_ssid": "MyNetwork",
  "ip_address": "192.168.1.105",

  "mqtt_connected": true,
  "pairing_mode": false,
  "paired_nodes": 2,

  "relays": [true, false, false, false],

  "nodes": [
    {
      "id": 1,
      "active": true,
      "temperature": 28.5,
      "humidity": 65.2,
      "last_seen_ms": 4200,
      "mac": "AA:BB:CC:DD:EE:FF"
    }
  ],

  "automation_rule_count": 2,
  "automation_rules": [
    {
      "rule_index": 1,
      "node_id": 1,
      "relay_id": 1,
      "use_temp": true,
      "use_hum": false,
      "logic": "OR",
      "last_state": "ON",
      "temp": {
        "min": 25.0,
        "max": 30.0
      }
    },
    {
      "rule_index": 2,
      "node_id": 1,
      "relay_id": 2,
      "use_temp": true,
      "use_hum": true,
      "logic": "AND",
      "last_state": "OFF",
      "temp": {
        "min": 20.0,
        "max": 28.0
      },
      "humidity": {
        "min": 40.0,
        "max": 70.0
      }
    }
  ],

  "event_log": {
    "pending_count": 0,
    "max_entries": 5000,
    "spiffs_used": 0,
    "spiffs_total": 10420224,
    "log_exists": false,
    "topic": "A1B2C3D4E5F6/event_log"
  },

  "ota_available": 0,
  "firmware_version": "3.0.1"
}
```

---

### Full Status Payload — Queue Mode (Mode 2)

> Includes all fields from Manual Mode, plus `queue` object.

```json
{
  "mode": 2,
  "mode_name": "queue",
  "timestamp": "2025-01-15 14:32:10",
  "uptime_ms": 3600000,

  "wifi_connected": true,
  "wifi_rssi": -65,
  "wifi_channel": 6,
  "wifi_ssid": "MyNetwork",
  "ip_address": "192.168.1.105",

  "mqtt_connected": true,
  "pairing_mode": false,
  "paired_nodes": 1,

  "relays": [true, false, false, false],

  "nodes": [
    {
      "id": 1,
      "active": true,
      "temperature": 28.5,
      "humidity": 65.2,
      "last_seen_ms": 4200,
      "mac": "AA:BB:CC:DD:EE:FF"
    }
  ],

  "queue": {
    "running": true,
    "paused": false,
    "loop_enabled": true,
    "auto_start": true,
    "total_steps": 4,
    "current_step": 1,
    "step_elapsed_sec": 45,
    "step_remaining_sec": 255,
    "current_relay": 1,
    "current_duration": 300,
    "steps": [
      {"step": 1, "relay_id": 1, "duration": 300, "type": "relay", "active": true},
      {"step": 2, "relay_id": 2, "duration": 300, "type": "relay", "active": false},
      {"step": 3, "relay_id": 3, "duration": 300, "type": "relay", "active": false},
      {"step": 4, "relay_id": 0, "duration": 60,  "type": "delay", "active": false}
    ]
  },

  "event_log": {
    "pending_count": 12,
    "max_entries": 5000,
    "spiffs_used": 8192,
    "spiffs_total": 10420224,
    "log_exists": true,
    "topic": "A1B2C3D4E5F6/event_log"
  },

  "ota_available": 1,
  "firmware_version": "3.0.1"
}
```

> **`queue.current_step`** — 1-based step number currently executing.  
> **`queue.step_elapsed_sec`** — seconds elapsed in the current step.  
> **`queue.step_remaining_sec`** — seconds remaining in the current step.  
> **`queue.current_relay`** — relay currently active (`0` = delay step, no relay ON).  
> **`steps[].type`** — `"relay"` for relay steps, `"delay"` for all-OFF delay steps.  
> **`steps[].active`** — `true` only for the currently executing step.  
> These runtime fields (`step_elapsed_sec`, `step_remaining_sec`, `current_relay`, `current_duration`)  
> are **only present** when the queue is running and not paused.

---

### Full Status Payload — Hybrid Mode (Mode 3)

> Includes all fields from Manual Mode, plus `queue`, `automation_rules`, and `hybrid` objects.

```json
{
  "mode": 3,
  "mode_name": "hybrid",
  "timestamp": "2025-01-15 14:32:10",
  "uptime_ms": 3600000,

  "wifi_connected": true,
  "wifi_rssi": -65,
  "wifi_channel": 6,
  "wifi_ssid": "MyNetwork",
  "ip_address": "192.168.1.105",

  "mqtt_connected": true,
  "pairing_mode": false,
  "paired_nodes": 2,

  "relays": [true, false, false, false],

  "nodes": [
    {
      "id": 1,
      "active": true,
      "temperature": 28.5,
      "humidity": 65.2,
      "last_seen_ms": 4200,
      "mac": "AA:BB:CC:DD:EE:FF"
    }
  ],

  "queue": {
    "running": true,
    "paused": false,
    "loop_enabled": true,
    "auto_start": true,
    "total_steps": 2,
    "current_step": 1,
    "step_elapsed_sec": 10,
    "step_remaining_sec": 110,
    "current_relay": 1,
    "current_duration": 120,
    "steps": [
      {"step": 1, "relay_id": 1, "duration": 120, "type": "relay", "active": true},
      {"step": 2, "relay_id": 0, "duration": 600, "type": "delay", "active": false}
    ]
  },

  "automation_rule_count": 1,
  "automation_rules": [
    {
      "rule_index": 1,
      "node_id": 1,
      "relay_id": 1,
      "use_temp": true,
      "use_hum": false,
      "logic": "OR",
      "last_state": "ON",
      "temp": {
        "min": 20.0,
        "max": 28.0
      }
    }
  ],

  "hybrid": {
    "logic": "AND",
    "automation_active": true,
    "queue_active": true
  },

  "event_log": {
    "pending_count": 0,
    "max_entries": 5000,
    "spiffs_used": 0,
    "spiffs_total": 10420224,
    "log_exists": false,
    "topic": "A1B2C3D4E5F6/event_log"
  },

  "ota_available": 0,
  "firmware_version": "3.0.1"
}
```

> **`hybrid.logic`** — `"OR"` or `"AND"` — how automation and queue results are combined.  
> **`hybrid.automation_active`** — `true` if automation evaluated any relay change this cycle.  
> **`hybrid.queue_active`** — `true` if the queue is currently requesting a relay ON.

---

### Sensor Node Data
Published automatically to `{MAC}/node{id}` each time a sensor reading is received.  
Only **Node 1 and Node 2** data is also forwarded to the connected display (Pico) via Serial2.  
Nodes 3 and 4 are available via MQTT only.

**Example — `{MAC}/node1`:**
```json
{
  "node_id": 1,
  "temperature": 28.5,
  "humidity": 65.2,
  "node_uptime_ms": 86400000,
  "timestamp": "2025-01-15 14:32:10"
}
```

> **`node_uptime_ms`** — uptime of the sensor node itself (not the gateway).  
> **`timestamp`** — gateway time when the data was received (IST, from NTP).

---

## 9. Important Behaviors

### WiFi & Provisioning

| Situation | Behavior |
|-----------|----------|
| No saved WiFi credentials | BLE provisioning starts automatically |
| Saved credentials but connection fails | BLE provisioning starts automatically |
| WiFi disconnects during operation | Auto-reconnect every 10 seconds (no BLE) |
| Button held 1 second | Enable node pairing mode |
| Button held 5 seconds | Reset WiFi credentials and restart |
| Button held 10 seconds | Reset all paired nodes and restart |
| Button held 20 seconds | **Factory reset** — clears all EEPROM and WiFi |

### MQTT Reconnection
- Reconnect is attempted every **5 seconds** when disconnected.
- On reconnect, the device **subscribes** to `{MAC}/command` and **publishes** a full status immediately.

### Node Timeout
- If a node has not sent data for **60 seconds**, it is considered offline.
- Automation rules for that node are **skipped** until data is received again.

### OTA Auto-Check
- The device checks for a new firmware version automatically at a fixed interval (`OTA_CHECK_INTERVAL`).
- It also checks once on every boot (if WiFi is connected).

### `markFirmwareValid()` Timing
> `markFirmwareValid()` is called in `setup()` **before** WiFi and MQTT connect.  
> Therefore, the MQTT publish inside it (`ota_status: verified`) will **never fire** on first boot.  
> The Serial log will still show the verification message correctly.

---

## 10. Quick Reference

### All Command Keys

| Key | Value | Description |
|-----|-------|-------------|
| `mode` | `0`–`3` | Switch operation mode |
| `transition` | `"graceful"` | Graceful mode switch (queue only) |
| `auto_save` | `true` | Persist mode to EEPROM |
| `relay1`–`relay4` | `0` or `1` | Control individual relay (Manual mode only) |
| `all` | `0` or `1` | Control all relays (Manual mode only) |
| `automation` | Object | Configure automation rules |
| `queue` | Object | Configure queue steps |
| `queue_control` | String | Control queue execution |
| `hybrid` | Object | Configure hybrid mode |
| `event_log` | String | Manage offline event logs |
| `ota_check` | `true` | Check for firmware update |
| `ota_update` | `true` | Trigger firmware update |

### Queue Control Values

| Value | Action |
|-------|--------|
| `"pause"` | Pause queue |
| `"resume"` | Resume queue |
| `"stop"` | Stop queue, all relays OFF, disable auto-start |
| `"restart"` | Restart queue from step 1, all relays OFF first |
| `"enable_autostart"` | Enable auto-start on reboot |
| `"disable_autostart"` | Disable auto-start on reboot |

### Event Log Command Values

| Value | Action |
|-------|--------|
| `"count"` | Get number of stored log entries |
| `"send"` | Send all logs to MQTT in batches |
| `"clear"` | Delete all stored logs |
| `"send_and_clear"` | Send all logs then delete |

### Status Topic Fields Summary

| Field | Present In Modes | Description |
|-------|-----------------|-------------|
| `mode`, `mode_name` | All | Current operation mode |
| `timestamp`, `uptime_ms` | All | Gateway time and uptime |
| `wifi_*`, `ip_address` | All | WiFi connection info |
| `mqtt_connected` | All | MQTT connection state |
| `pairing_mode`, `paired_nodes` | All | Node pairing info |
| `relays[]` | All | Array of 4 relay states (true/false) |
| `nodes[]` | All | All paired node data |
| `queue{}` | Mode 2, 3 | Queue runtime status and all steps |
| `automation_rules[]` | Mode 1, 3 | All active automation rules |
| `automation_rule_count` | Mode 1, 3 | Number of active rules |
| `hybrid{}` | Mode 3 | Hybrid logic and active flags |
| `event_log{}` | All | SPIFFS log info and pending count |
| `ota_available` | All | `1` if update available, `0` if not |
| `firmware_version` | All | Current firmware version string |

# ESP-B Gateway – MQTT Command & Control Documentation

This document contains **all MQTT topics, commands, payloads, scenarios, and examples** supported by the ESP-B Gateway.
---

## Table of Contents
- [MQTT Topics](#mqtt-topics)
- [Mode Control](#mode-control)
- [Manual Mode Commands](#manual-mode-commands)
- [Automation Mode Commands](#automation-mode-commands)
- [Queue Mode Commands](#queue-mode-commands)
- [Queue Control Commands](#queue-control-commands)
- [OTA Update Commands](#ota-update-commands)
- [Status Messages](#status-messages)
- [Button Functions](#button-functions)
- [Important Notes](#important-notes)
- [Troubleshooting](#troubleshooting)
- [Version Information](#version-information)

---

## MQTT Topics

The ESP-B Gateway uses your device MAC address as the topic prefix.

### Command Topic (Subscribe)
```
{MAC_ADDRESS}/command
```

Example:
```
A1B2C3D4E5F6/command
```

### Status Topic (Publish)
```
{MAC_ADDRESS}/status
```

Example:
```
A1B2C3D4E5F6/status
```

### Sensor Data Topics (Publish)
```
{MAC_ADDRESS}/node{X}/temp
{MAC_ADDRESS}/node{X}/hum
```

Example:
```
A1B2C3D4E5F6/node1/temp → 25.3
A1B2C3D4E5F6/node1/hum  → 55.2
```

### OTA Status Topic (Publish)
```
{MAC_ADDRESS}/ota/status
```

---

## Mode Control

The ESP-B Gateway operates in three distinct modes.  
Switching modes automatically saves the configuration to EEPROM.

### Mode Values
- `0` = Manual Mode
- `1` = Automation Mode
- `2` = Queue Mode

### Switch to Manual Mode
```json
{
  "mode": 0
}
```

Description:
- Switches to manual control mode
- Maintains relay states from EEPROM
- Allows individual relay control
- Stops any running automation or queue

Use Case: Manual relay testing

---

### Switch to Automation Mode
```json
{
  "mode": 1
}
```

Description:
- Turns OFF all relays initially
- Waits for sensor data
- Controls relays using automation rules

---

### Switch to Queue Mode
```json
{
  "mode": 2
}
```

Description:
- Turns OFF all relays initially
- Executes queue steps sequentially
- Supports looping and delays

---

### Switch Mode And Make It Default
```json
{
  "mode": 1,
  "auto_save": true
}
```

Description:
- Switches mode
- Saves the changed mode as default

---

## Manual Mode Commands

### Control Individual Relays
```json
{
  "relay1": 1,
  "relay2": 0,
  "relay3": 1,
  "relay4": 0
}
```

Description:
- `1` = ON, `0` = OFF
- States saved to EEPROM

### Example – Turn ON Relay 1
```json
{
  "relay1": 1
}
```

### Turn All Relays ON
```json
{
  "all": 1
}
```

### Turn All Relays OFF
```json
{
  "all": 0
}
```

### Mixed Control
```json
{
  "relay1": 1,
  "relay3": 1,
  "all": 0
}
```

---

## Automation Mode Commands

### Rule Structure
- `node` (1–4)
- `relay` (1–4)
- `temp` thresholds (optional)
- `humidity` thresholds (optional)
- `logic` (`OR` / `AND`)

---

### Single Node Temperature Control
```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": { "min": 25.0, "max": 30.0 }
      }
    ]
  }
}
```

---

### Single Node Humidity Control
```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 2,
        "humidity": { "min": 40.0, "max": 70.0 }
      }
    ]
  }
}
```

---

### Multiple Relays – Same Node Temperature
```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": { "min": 20.0, "max": 28.0 }
      },
      {
        "node": 1,
        "relay": 2,
        "temp": { "min": 22.0, "max": 30.0 }
      }
    ]
  }
}
```

---

### Temperature OR Humidity Control
```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": { "min": 25.0, "max": 30.0 },
        "humidity": { "min": 40.0, "max": 70.0 }
      }
    ]
  }
}
```

---

### Temperature AND Humidity Control
```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": { "min": 25.0, "max": 30.0 },
        "humidity": { "min": 40.0, "max": 70.0 },
        "logic": "AND"
      }
    ]
  }
}
```

---

### Multi-Node, Multi-Relay Automation
```json
{
  "automation": {
    "rules": [
      { "node": 1, "relay": 1, "temp": { "min": 20.0, "max": 28.0 } },
      { "node": 2, "relay": 2, "humidity": { "min": 35.0, "max": 65.0 } },
      {
        "node": 3,
        "relay": 3,
        "temp": { "min": 22.0, "max": 30.0 },
        "humidity": { "min": 40.0, "max": 70.0 },
        "logic": "OR"
      },
      { "node": 4, "relay": 4, "temp": { "min": 18.0, "max": 26.0 } }
    ]
  }
}
```

---

### Clear All Automation Rules
```json
{
  "automation": { "clear": true }
}
```

---


## Queue Mode Commands

### Queue Structure
```json
{
  "queue": {
    "loop": true,
    "loop_delay": 3600,
    "auto_start": true,
    "steps": []
  }
}
```

---

### Simple Sequential Queue
```json
{
  "queue": {
    "loop": false,
    "steps": [
      { "relay": 1, "duration": 10 },
      { "relay": 2, "duration": 15 },
      { "relay": 3, "duration": 20 },
      { "relay": 4, "duration": 5 }
    ]
  }
}
```

---

### Looping Queue
```json
{
  "queue": {
    "loop": true,
    "steps": [
      { "relay": 1, "duration": 30 },
      { "relay": 2, "duration": 30 },
      { "relay": 3, "duration": 30 },
      { "relay": 4, "duration": 30 }
    ]
  }
}
```

---

### Queue With Loop Delay
```json
{
  "queue": {
    "loop": true,
    "loop_delay": 3600,
    "steps": [
      { "relay": 1, "duration": 300 },
      { "relay": 2, "duration": 450 },
      { "relay": 3, "duration": 600 }
    ]
  }
}
```

---

### Queue With Delays Between Steps
```json
{
  "queue": {
    "loop": true,
    "steps": [
      { "relay": 1, "duration": 10 },
      { "delay": 5 },
      { "relay": 2, "duration": 15 },
      { "delay": 5 },
      { "relay": 3, "duration": 10 }
    ]
  }
}
```

---

### Queue Without Auto-Start
```json
{
  "queue": {
    "loop": true,
    "auto_start": false,
    "steps": [
      { "relay": 1, "duration": 30 },
      { "relay": 2, "duration": 30 }
    ]
  }
}
```

---

### Complex Irrigation Queue
```json
{
  "queue": {
    "loop": true,
    "loop_delay": 7200,
    "steps": [
      { "relay": 1, "duration": 600 },
      { "delay": 120 },
      { "relay": 2, "duration": 900 },
      { "delay": 120 },
      { "relay": 3, "duration": 450 },
      { "delay": 120 },
      { "relay": 4, "duration": 750 }
    ]
  }
}
```

---


## Queue Control Commands

```json
{ "queue_control": "pause" }
```

```json
{ "queue_control": "resume" }
```

```json
{ "queue_control": "stop" }
```

```json
{ "queue_control": "restart" }
```

```json
{ "queue_control": "enable_autostart" }
```

```json
{ "queue_control": "disable_autostart" }
```

---

## OTA Update Commands

### Check for Updates
```json
{ "ota_check": true }
```

### Perform OTA Update
```json
{ "ota_update": true }
```

---

## Status Messages

### Manual Mode Status
```json
{
  "mode": 0,
  "mode_name": "manual",
  "firmware_version": "1.0.0",
  "relays": [true, false, true, false],
  "nodes": [
    { "id": 1, "temp": 25.3, "hum": 55.2, "active": true },
    { "id": 2, "temp": 26.1, "hum": 58.7, "active": true }
  ]
}
```

---

### Automation Mode Status
```json
{
  "mode": 1,
  "mode_name": "automation",
  "firmware_version": "1.0.0",
  "relays": [true, false, false, false],
  "nodes": [
    { "id": 1, "temp": 31.2, "hum": 52.3, "active": true }
  ]
}
```

---

### Queue Mode Status
```json
{
  "mode": 2,
  "mode_name": "queue",
  "firmware_version": "1.0.0",
  "relays": [true, false, false, false],
  "queue_running": true,
  "queue_paused": false,
  "queue_auto_start": true,
  "current_step": 1,
  "total_steps": 4,
  "nodes": [
    { "id": 1, "temp": 24.8, "hum": 52.3, "active": true }
  ]
}
```

---

## Button Functions

| Press Duration | Function | Description |
|---------------|----------|-------------|
| 1 second | Enable Pairing Mode | Allows new ESP-A nodes to pair for 30 seconds |
| 5 seconds | Reset WiFi | Clears WiFi credentials and restarts |
| 10 seconds | Reset Paired Nodes | Removes all paired ESP-A nodes |
| 20 seconds | Factory Reset | Flushes EEPROM and removes all configuration |

---

## Important Notes

- All configurations are saved to EEPROM
- Automation has 3-second rate limiting
- Nodes inactive after 60 seconds
- Queue auto-start honored on boot

---

## Troubleshooting

### Relay Not Responding
1. Check manual mode
2. Verify relay number
3. Check MQTT connection
4. Review serial monitor

### Automation Not Working
1. Node active
2. Automation rules configured
3. Mode set to automation
4. Sensor data received

### Queue Not Starting
1. Auto-start enabled
2. Steps configured
3. Mode set to queue

---

## Version Information

- Firmware Version: via status topic
- GitHub Repository: [Your Repository URL]
- OTA Update URL: [Your firmware.bin URL]

---

End of documentation.

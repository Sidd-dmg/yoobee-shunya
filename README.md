# MQTT Gateway Control & Telemetry Specification

This repository documents the **MQTT topics, payload formats, command structures, and telemetry schema**
for Shunya Irrigation System supporting **Manual**, **Automation**, and **Queue** modes.

---

## Table of Contents

- Connection Information
- Mode Control
- Manual Mode Commands
- Automation Mode Commands
- Queue Mode Commands
- Queue Control Commands
- OTA Update Commands
- Status Messages
- Practical Examples
- Button Functions
- Important Notes
- Troubleshooting
- Version Information

---

## Connection Information

### MQTT Topics

The ESP-B Gateway uses its **MAC address** as the topic prefix.

#### Command Topic (Subscribe)
```
{MAC_ADDRESS}/command
```

Example:
```
A1B2C3D4E5F6/command
```

#### Status Topic (Publish)
```
{MAC_ADDRESS}/status
```

#### Sensor Data Topics (Publish)
```
{MAC_ADDRESS}/node{X}/temp
{MAC_ADDRESS}/node{X}/hum
```

Example:
```
A1B2C3D4E5F6/node1/temp → 25.3
A1B2C3D4E5F6/node1/hum  → 55.2
```

#### OTA Status Topic
```
{MAC_ADDRESS}/ota/status
```

---

## Mode Control

The ESP-B Gateway operates in three modes.  
All mode changes are automatically saved to EEPROM.

| Mode | Value |
|----|----|
| Manual | 0 |
| Automation | 1 |
| Queue | 2 |

### Switch to Manual Mode
```json
{
  "mode": 0
}
```

- Stops automation and queue
- Preserves relay states from EEPROM
- Allows direct relay control

---

### Switch to Automation Mode
```json
{
  "mode": 1
}
```

- Turns OFF all relays initially
- Uses automation rules
- Requires sensor data from paired nodes

---

### Switch to Queue Mode
```json
{
  "mode": 2
}
```

- Turns OFF all relays initially
- Executes timed relay sequences
- Supports looping and delays

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
  "all": 0,
  "relay1": 1,
  "relay3": 1
}
```

> Individual relay commands override the `all` command.

---

## Automation Mode Commands

### Rule Structure
```json
{
  "node": 1,
  "relay": 1,
  "temp": {
    "min": 25.0,
    "max": 30.0
  },
  "humidity": {
    "min": 40.0,
    "max": 70.0
  },
  "logic": "AND | OR"
}
```

### Single Temperature Rule
```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 25.0,
          "max": 30.0
        }
      }
    ]
  }
}
```

### Temperature + Humidity (AND)
```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 25.0,
          "max": 30.0
        },
        "humidity": {
          "min": 40.0,
          "max": 70.0
        },
        "logic": "AND"
      }
    ]
  }
}
```

### Clear All Automation Rules
```json
{
  "automation": {
    "clear": true
  }
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
    "steps": [
      { "relay": 1, "duration": 300 },
      { "delay": 120 },
      { "relay": 2, "duration": 450 }
    ]
  }
}
```

### Simple Sequential Queue
```json
{
  "queue": {
    "loop": false,
    "steps": [
      { "relay": 1, "duration": 10 },
      { "relay": 2, "duration": 15 }
    ]
  }
}
```

### Switch to Queue Mode and Configure
```json
{
  "mode": 2,
  "queue": {
    "loop": true,
    "steps": [
      { "relay": 1, "duration": 30 },
      { "relay": 2, "duration": 30 }
    ]
  }
}
```

---

## Queue Control Commands

| Action | Payload |
|------|---------|
| Pause | `{ "queue_control": "pause" }` |
| Resume | `{ "queue_control": "resume" }` |
| Stop | `{ "queue_control": "stop" }` |
| Restart | `{ "queue_control": "restart" }` |
| Enable Auto-Start | `{ "queue_control": "enable_autostart" }` |
| Disable Auto-Start | `{ "queue_control": "disable_autostart" }` |

---

## OTA Update Commands

### Check for Updates
```json
{
  "ota_check": true
}
```

### Perform OTA Update
```json
{
  "ota_update": true
}
```

⚠ Device will reboot and remain offline for 30–60 seconds.

---

## Status Messages

### Manual Mode Status
```json
{
  "mode": 0,
  "mode_name": "manual",
  "firmware_version": "1.0.0",
  "relays": [true, false, true, false]
}
```

### Automation Mode Status
```json
{
  "mode": 1,
  "mode_name": "automation",
  "relays": [true, false, false, false]
}
```

### Queue Mode Status
```json
{
  "mode": 2,
  "mode_name": "queue",
  "queue_running": true,
  "current_step": 1,
  "total_steps": 4
}
```

---

## Button Functions

| Press Duration | Function |
|---------------|---------|
| 1 second | Enable pairing mode |
| 5 seconds | Reset WiFi |
| 10 seconds | Clear paired nodes |
| 20 seconds | Factory reset |

---

## Important Notes

- All configurations stored in EEPROM
- Automation has 3-second rate limiting
- Nodes inactive after 60 seconds
- Queue auto-starts if enabled
- Mode changes saved immediately

---

## Troubleshooting

### Relay Not Responding
1. Ensure mode is Manual (`mode: 0`)
2. Verify relay number (1–4)
3. Check MQTT connection
4. Review serial logs

### Automation Not Working
1. Node paired and active
2. Mode set to Automation (`mode: 1`)
3. Rules configured
4. Sensor data arriving

### Queue Not Starting
1. Check `auto_start`
2. Ensure steps are defined
3. Mode must be Queue (`mode: 2`)

---

## Version Information

- Firmware Version: via status message
- GitHub Repository: [ADD URL]
- OTA Firmware URL: [ADD firmware.bin URL]

---

End of documentation.

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
{MAC_ADDRESS}/node{X}
```

Example:
```
A1B2C3D4E5F6/node1
```



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


---

## Status Messages

### Manual Mode Status
```json
{
  "mode": 0,
  "mode_name": "manual",
  "timestamp": "2024-12-19 14:30:45",
  "uptime_ms": 3456789,
  "wifi_connected": true,
  "wifi_rssi": -45,
  "wifi_channel": 11,
  "wifi_ssid": "MyWiFi",
  "ip_address": "192.168.1.100",
  "mqtt_connected": true,
  "pairing_mode": false,
  "paired_nodes": 2,
  "relays": [true, false, true, false],
  "nodes": [
    {
      "id": 1,
      "active": true,
      "temperature": 25.3,
      "humidity": 65.2,
      "last_seen_ms": 3450000,
      "mac": "AA:BB:CC:DD:EE:01"
    },
    {
      "id": 2,
      "active": true,
      "temperature": 26.1,
      "humidity": 62.8,
      "last_seen_ms": 3451000,
      "mac": "AA:BB:CC:DD:EE:02"
    }
  ],
  "ota_available": false,
  "firmware_version": "1.0.0"
}
```

---

### Automation Mode Status
```json
{
  "mode": 1,
  "mode_name": "automation",
  "timestamp": "2024-12-19 14:35:20",
  "uptime_ms": 3756789,
  "wifi_connected": true,
  "wifi_rssi": -47,
  "wifi_channel": 11,
  "wifi_ssid": "MyWiFi",
  "ip_address": "192.168.1.100",
  "mqtt_connected": true,
  "pairing_mode": false,
  "paired_nodes": 2,
  "relays": [true, false, true, false],
  "nodes": [
    {
      "id": 1,
      "active": true,
      "temperature": 28.5,
      "humidity": 70.3,
      "last_seen_ms": 3750000,
      "mac": "AA:BB:CC:DD:EE:01"
    },
    {
      "id": 2,
      "active": true,
      "temperature": 24.2,
      "humidity": 58.1,
      "last_seen_ms": 3751000,
      "mac": "AA:BB:CC:DD:EE:02"
    }
  ],
  "automation_rules": [
    {
      "node_id": 1,
      "relay_id": 1,
      "temp_min": 20.0,
      "temp_max": 30.0,
      "hum_min": 40.0,
      "hum_max": 80.0,
      "use_temp": true,
      "use_hum": true,
      "logic": "OR",
      "last_state": true
    },
    {
      "node_id": 2,
      "relay_id": 4,
      "temp_min": 18.0,
      "temp_max": 25.0,
      "hum_min": 30.0,
      "hum_max": 70.0,
      "use_temp": true,
      "use_hum": false,
      "logic": "AND",
      "last_state": true
    }
  ],
  "ota_available": false,
  "firmware_version": "1.0.0"
}
```

---

### Queue Mode Status
```json
{
  "mode": 2,
  "mode_name": "queue",
  "timestamp": "2024-12-19 14:40:15",
  "uptime_ms": 4056789,
  "wifi_connected": true,
  "wifi_rssi": -46,
  "wifi_channel": 11,
  "wifi_ssid": "MyWiFi",
  "ip_address": "192.168.1.100",
  "mqtt_connected": true,
  "pairing_mode": false,
  "paired_nodes": 1,
  "relays": [true, false, true, false],
  "nodes": [
    {
      "id": 1,
      "active": true,
      "temperature": 25.8,
      "humidity": 64.5,
      "last_seen_ms": 4050000,
      "mac": "AA:BB:CC:DD:EE:01"
    }
  ],
  "queue": {
    "running": true,
    "paused": false,
    "current_step": 2,
    "total_steps": 5,
    "loop_enabled": true,
    "auto_start": true
  },
  "ota_available": false,
  "firmware_version": "1.0.0"
}
```
### Sensor Data
```json
{
  "node_id": 1,
  "temperature": 25.3,
  "humidity": 65.2,
  "node_uptime_ms": 123456,
  "timestamp": "2024-12-19 14:30:45"
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

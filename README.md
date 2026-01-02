# MQTT Gateway Control & Telemetry Specification

This repository documents the **MQTT topics, payload formats, command structures, and telemetry schema**
for Shunya Irrigation System supporting **Manual**, **Automation**, and **Queue** modes.

---

## 1. Command Topic (Subscribe)

### 🔹 Topic Pattern
```
{MAC_ADDRESS}/command
```

**Example**
```
A0B1C2D3E4F5/command
```

### 🔹 Purpose
Receives JSON commands to control:
- Gateway operation mode
- Relay states
- Automation rules
- Queue configuration

### 🔹 QoS
- `0` or `1`
- **Recommended:** `1`

### 🔹 Retained
-  No

---

## 1.1 Mode Change Commands

Switch between **Manual**, **Automation**, and **Queue** modes.

### Basic Mode Change
```json
{ "mode": 0 }
```

| Mode | Description |
|------|-------------|
| 0 | Manual Mode |
| 1 | Automation Mode |
| 2 | Queue Mode |

---

### Advanced Mode Change
```json
{
  "mode": 1,
  "transition": "graceful",
  "auto_save": true
}
```

#### Parameters
| Field | Type | Required | Description |
|------|------|----------|-------------|
| mode | Integer (0–2) | Yes | Operation mode |
| transition | String | No | immediate / graceful (default: immediate) |
| auto_save | Boolean | No | Save mode to EEPROM (default: false) |

---

## 1.2 Manual Mode Commands (Mode = 0)

### Individual Relay Control
```json
{
  "relay1": 1,
  "relay2": 0,
  "relay3": 1,
  "relay4": 0
}
```

### All Relays ON
```json
{ "all": 1 }
```

### All Relays OFF
```json
{ "all": 0 }
```

#### Parameters
| Field | Description |
|------|-------------|
| relay1–relay4 | `0` = OFF, `1` = ON |
| all | `0` = All OFF, `1` = All ON |

---

## 1.3 Automation Mode Configuration (Mode = 1)

Configure **temperature and humidity-based automation** rules.

### Single Node Configuration
```json
{
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "control_type": "temperature",
        "temp": {
          "min": 26.0,
          "max": 30.0
        },
        "hysteresis": 1.0
      },
    ]
  }
}
```

---

### Multi-Node Configuration
```json
{
  "mode": 1,
  "automation": {
    "rules": [
      {
        "node": 1,
        "relay": 1,
        "control_type": "temperature",
        "temp": {
          "min": 26.0,
          "max": 30.0
        },
        "hysteresis": 1.0
      },
      {
        "node": 1,
        "relay": 2,
        "control_type": "humidity",
        "humidity": {
          "min": 40.0,
          "max": 70.0
        },
        "hysteresis": 2.0
      },
      {
        "node": 2,
        "relay": 3,
        "control_type": "humidity",
        "humidity": {
          "min": 40.0,
          "max": 70.0
        },
        "hysteresis": 2.0
      },
      {
        "node": 2,
        "relay": 4,
        "control_type": "both_and",
        "temp": {
          "min": 26.0,
          "max": 30.0
        },
        "humidity": {
          "min": 60.0,
          "max": 80.0
        },
        "hysteresis": 1.0
      },
      {
        "node": 2,
        "relay": 4,
        "control_type": "both_and",
        "temp": {
          "min": 26.0,
          "max": 30.0
        },
        "humidity": {
          "min": 60.0,
          "max": 80.0
        },
        "hysteresis": 1.0
      },
      {
        "node": 2,
        "relay": 5,
        "control_type": "either_or",
        "temp": {
          "min": 26.0,
          "max": 30.0
        },
        "humidity": {
          "min": 60.0,
          "max": 80.0
        },
        "hysteresis": 1.0
      }
    ]
  }
}
```

---

### Automation Parameters
| Field | Description |
|------|-------------|
| node1–node4 | Sensor node identifier |
| relay | Relay number (1–4) |
| temp.min / temp.max | Temperature thresholds (°C) |
| humidity.min / humidity.max | Humidity thresholds (%) |
| hysteresis | Prevents rapid toggling |


### Automation Logic
| control_type | Behavior |
|----------------|----------|
| `"temperature"` | Only temperature controls relay |
| `"humidity"` | Only humidity controls relay |
| `"both_and"` | **Both** temp AND humidity must exceed thresholds |
| `"either_or"` | **Either** temp OR humidity exceeds threshold 

---

##  1.4 Queue Mode Configuration (Mode = 2)

### Basic Queue
```json
{
  "queue": {
    "loop": false,
    "steps": [
      { "relay": 1, "duration": 30 },
      { "relay": 2, "duration": 20 },
      { "relay": 3, "duration": 15 }
    ]
  }
}
```

---

### Queue with Delays
```json
{
  "queue": {
    "loop": true,
    "loop_delay": 10,
    "steps": [
      { "relay": 1, "duration": 30 },
      { "delay": 5 },
      { "relay": 2, "duration": 20 },
      { "delay": 3 },
      { "relay": 3, "duration": 15 },
      { "relay": 4, "duration": 25 }
    ]
  }
}
```

---

### Queue Parameters
| Field | Description |
|------|-------------|
| loop | Repeat queue indefinitely |
| loop_delay | Delay between loops (seconds) |
| steps | Array (max 20 steps) |
| relay | Relay number (1–4) |
| duration | Relay ON time (seconds) |
| delay | Wait without relay action |

### Step Execution Flow
1. Turn relay **ON**
2. Wait for `duration`
3. Turn relay **OFF**
4. Move to next step
5. Repeat if `loop = true`

---

## 1.5 Queue Control Commands

```json
{ "queue_control": "pause" }
{ "queue_control": "resume" }
{ "queue_control": "stop" }
{ "queue_control": "restart" }
```

| Command | Description |
|--------|-------------|
| pause | Pause queue |
| resume | Resume queue |
| stop | Stop queue & turn off relays |
| restart | Restart from step 1 |

---

## 2. Status Topic (Publish)

### 🔹 Topic Pattern
```
{MAC_ADDRESS}/status
```

**Example**
```
A0B1C2D3E4F5/status
```

### 🔹 Publish Interval
- Every **10 seconds**

### 🔹 QoS
- `0` or `1`

### 🔹 Retained
-  Yes

---

##  Status Payload Examples

###  Manual Mode
```json
{
  "mode": 0,
  "mode_name": "manual",
  "relays": [true, false, true, false],
  "nodes": [
    { "id": 1, "temp": 28.5, "hum": 65.2, "active": true },
    { "id": 2, "temp": 27.3, "hum": 62.8, "active": true }
  ]
}
```

---

### Automation Mode
```json
{
  "mode": 1,
  "mode_name": "automation",
  "relays": [true, false, false, true],
  "nodes": [
    { "id": 1, "temp": 28.5, "hum": 65.2, "active": true },
    { "id": 2, "temp": 27.3, "hum": 62.8, "active": true },
    { "id": 3, "temp": 29.1, "hum": 68.5, "active": true }
  ]
}
```

---

###  Queue Mode
```json
{
  "mode": 2,
  "mode_name": "queue",
  "relays": [true, false, false, false],
  "queue_running": true,
  "queue_paused": false,
  "current_step": 2,
  "total_steps": 5,
  "nodes": [
    { "id": 1, "temp": 28.5, "hum": 65.2, "active": true }
  ]
}
```

---

###  Status Fields
| Field | Description |
|------|-------------|
| mode | Current mode (0–2) |
| mode_name | manual / automation / queue |
| relays | Relay states |
| queue_running | Queue executing |
| queue_paused | Queue paused |
| current_step | Active step |
| total_steps | Total steps |
| nodes | Sensor nodes |
| id | Node ID |
| temp | Temperature (°C) |
| hum | Humidity (%) |
| active | Seen in last 60s |

---

##  3. Sensor Data Topics (Publish)

### 3.1 Temperature
```
{MAC_ADDRESS}/{NODE_ID}/temp
```

**Example**
```
A0B1C2D3E4F5/node1/temp
```

Payload:
```
28.5
```

- QoS: `0`
- Retained: Yes
- Trigger: Data received from ESP-A

---

### 3.2 Humidity
```

{MAC_ADDRESS}/{NODE_ID}/hum
```

**Example**
```
A0B1C2D3E4F5/node1/hum
```

Payload:
```
65.2
```

- QoS: `0`
- Retained: Yes
- Trigger: Data received from ESP-A

---


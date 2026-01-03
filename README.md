# ESP-B Gateway – MQTT Command & Control Documentation


## Table of Contents


## Connection Information


## Mode Control


## Manual Mode Commands


## Automation Mode Commands


## Queue Mode Commands


## Queue Control Commands


## OTA Update Commands


## Status Messages


## Practical Examples


## Button Functions


## Connection Information


## MQTT Topics

The ESP-B Gateway uses your device's MAC address as the topic prefix for unique identification.
Command Topic (Subscribe):
```json
{MAC_ADDRESS}/command
Example: A1B2C3D4E5F6/command
Status Topic (Publish):
```json
{MAC_ADDRESS}/status
Example: A1B2C3D4E5F6/status
Sensor Data Topics (Publish):
```json
{MAC_ADDRESS}/node{X}/temp
```json
{MAC_ADDRESS}/node{X}/hum
Example: 
A1B2C3D4E5F6/node1/temp → 25.3
A1B2C3D4E5F6/node1/hum → 55.2
OTA Status Topic (Publish):
```json
{MAC_ADDRESS}/ota/status

## Mode Control

The ESP-B Gateway operates in three distinct modes. Switching modes automatically saves the configuration to EEPROM.
Mode Values
0 = Manual Mode
1 = Automation Mode
2 = Queue Mode
Switch to Manual Mode
Payload:
```json
{
  "mode": 0
}
```
Description:
Switches to manual control mode
Maintains current relay states from EEPROM
Allows individual relay control via MQTT
Stops any running queue or automation
Use Case: Direct control of relays for testing or manual operation
Switch to Automation Mode
Payload:
```json
{
  "mode": 1
}
```
Description:
Switches to automation mode
Turns OFF all relays initially for clean state
Waits for sensor data from paired nodes
Controls relays based on configured automation rules
Requires automation rules to be configured
Use Case: Temperature/humidity-based automatic relay control
Switch to Queue Mode
Payload:
```json
{
  "mode": 2
}
```
Description:
Switches to queue mode
Turns OFF all relays initially for clean state
Auto-starts queue if auto_start is enabled and queue is configured
Executes relay operations in sequential steps
Supports looping and delays
Use Case: Timed irrigation systems, sequential operations

## Manual Mode Commands

Manual mode provides direct control over individual relays or all relays simultaneously.
Control Individual Relays
Payload:
```json
{
  "relay1": 1,
  "relay2": 0,
  "relay3": 1,
  "relay4": 0
}
```
Description:
1 = Turn relay ON
0 = Turn relay OFF
You can control one or multiple relays in a single command
Relay states are automatically saved to EEPROM
States persist across reboots
Example - Turn on only Relay 1:
```json
{
  "relay1": 1
}
```
Turn All Relays ON
Payload:
```json
{
  "all": 1
}
```
Description:
Turns all 4 relays ON simultaneously
Saves state to EEPROM
Useful for testing or emergency activation
Turn All Relays OFF
Payload:
```json
{
  "all": 0
}
```
Description:
Turns all 4 relays OFF simultaneously
Saves state to EEPROM
Useful for emergency stop or system shutdown
Mixed Control
Payload:
```json
{
  "relay1": 1,
  "relay3": 1,
  "all": 0
}
```
Description:
Individual relay commands override the "all" command
In this example: Relay 1 and 3 will be ON, Relay 2 and 4 will be OFF
Processing order: "all" command first, then individual relays

## Automation Mode Commands

Automation mode allows you to create rules that automatically control relays based on sensor data from paired nodes.
Rule Structure
Each automation rule consists of:
node: Which sensor node to monitor (1-4)
relay: Which relay to control (1-4)
temp: Temperature thresholds (optional)
min: Turn relay OFF if temperature < min
max: Turn relay ON if temperature > max
humidity: Humidity thresholds (optional)
min: Turn relay OFF if humidity < min
max: Turn relay ON if humidity > max
logic: "OR" or "AND" (only when both temp and humidity are used)
Single Node Temperature Control
Payload:
```json
{
  "automation": {
    "rules": [
```json
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 25.0,
          "max": 30.0
        }
```
      }
    ]
  }
}
Description:
Monitors Node 1's temperature
Controls Relay 1
Relay turns ON when temperature > 30.0°C
Relay turns OFF when temperature < 25.0°C
Relay maintains state when 25.0°C ≤ temperature ≤ 30.0°C
Use Case: Cooling fan that activates when temperature exceeds 30°C
Single Node Humidity Control
Payload:
```json
{
  "automation": {
    "rules": [
```json
      {
        "node": 1,
        "relay": 2,
        "humidity": {
          "min": 40.0,
          "max": 70.0
        }
```
      }
    ]
  }
}
Description:
Monitors Node 1's humidity
Controls Relay 2
Relay turns ON when humidity > 70.0%
Relay turns OFF when humidity < 40.0%
Relay maintains state when 40.0% ≤ humidity ≤ 70.0%
Use Case: Dehumidifier that activates when humidity exceeds 70%
Control Multiple Relays with Same Node Temperature
Payload:
```json
{
  "automation": {
    "rules": [
```json
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 20.0,
          "max": 28.0
        }
```
      },
```json
      {
        "node": 1,
        "relay": 2,
        "temp": {
          "min": 22.0,
          "max": 30.0
        }
```
      }
    ]
  }
}
Description:
Both relays monitor the same node (Node 1)
Each relay has different temperature thresholds
Relay 1: Activates at 28°C, deactivates at 20°C
Relay 2: Activates at 30°C, deactivates at 22°C
Use Case: Multi-stage cooling system with different activation points
Control Relay with Node Temperature AND Humidity
Payload:
```json
{
  "automation": {
    "rules": [
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
        }
```
      }
    ]
  }
}
Description:
Monitors both temperature AND humidity from Node 1
Uses OR logic by default
Relay turns ON if temperature > 30°C OR humidity > 70%
Relay turns OFF if temperature < 25°C AND humidity < 40%
Use Case: Climate control that responds to either high temperature or high humidity
Temperature AND Humidity with AND Logic
Payload:
```json
{
  "automation": {
    "rules": [
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
        "logic": "AND"
      }
```
    ]
  }
}
Description:
Monitors both temperature AND humidity from Node 1
Uses AND logic
Relay turns ON only if temperature > 30°C AND humidity > 70%
Relay turns OFF if temperature < 25°C OR humidity < 40%
Use Case: Precise climate control requiring both conditions to be met
Control Different Relays with Temperature and Humidity from Same Node
Payload:
```json
{
  "automation": {
    "rules": [
```json
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 20.0,
          "max": 28.0
        }
```
      },
```json
      {
        "node": 1,
        "relay": 2,
        "humidity": {
          "min": 40.0,
          "max": 70.0
        }
```
      }
    ]
  }
}
Description:
Relay 1 controlled by Node 1's temperature
Relay 2 controlled by Node 1's humidity
Independent control based on different parameters
Use Case: Separate temperature and humidity control from a single sensor
Multi-Node, Multi-Relay Complex Setup
Payload:
```json
{
  "automation": {
    "rules": [
```json
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 20.0,
          "max": 28.0
        }
```
      },
```json
      {
        "node": 2,
        "relay": 2,
        "humidity": {
          "min": 35.0,
          "max": 65.0
        }
```
      },
```json
      {
        "node": 3,
        "relay": 3,
        "temp": {
          "min": 22.0,
          "max": 30.0
        },
        "humidity": {
          "min": 40.0,
          "max": 70.0
        },
        "logic": "OR"
      },
```json
      {
        "node": 4,
        "relay": 4,
        "temp": {
          "min": 18.0,
          "max": 26.0
        }
```
      }
    ]
  }
}
Description:
Supports up to 16 automation rules
Each rule can monitor any node and control any relay
Mix temperature-only, humidity-only, and combined rules
Each rule operates independently
Use Case: Multi-zone climate control system
Clear All Automation Rules
Payload:
```json
{
  "automation": {
    "clear": true
  }
```
}
Description:
Removes all configured automation rules
Turns off all relays
Resets automation to default state
Saves cleared state to EEPROM
Switch to Automation Mode and Configure Rules
Payload:
```json
{
  "mode": 1,
  "automation": {
    "rules": [
```json
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 25.0,
          "max": 30.0
        }
```
      }
    ]
  }
}
Description:
Switches to automation mode
Configures rules in a single command
Saves everything to EEPROM

## Queue Mode Commands

Queue mode executes relay operations in a sequential, timed manner. Perfect for irrigation systems or timed processes.
Queue Structure
A queue consists of:
steps: Array of operations to execute
relay: Which relay to control (1-4)
duration: How long to keep relay ON (in seconds)
delay: Wait time without activating any relay (in seconds)
loop: Whether to repeat the queue (true/false)
loop_delay: Delay between loop cycles (in seconds)
auto_start: Auto-start queue on boot (true/false, default: true)
Simple Sequential Queue (No Loop)
Payload:
```json
{
  "queue": {
    "loop": false,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 10
      },
```json
      {
        "relay": 2,
        "duration": 15
      },
```json
      {
        "relay": 3,
        "duration": 20
      },
```json
      {
        "relay": 4,
        "duration": 5
      }
```
    ]
  }
}
Description:
Executes once and stops
Relay 1 ON for 10 seconds
Relay 2 ON for 15 seconds
Relay 3 ON for 20 seconds
Relay 4 ON for 5 seconds
Total duration: 50 seconds
Auto-starts immediately and on boot
Use Case: One-time sequential operation
Looping Queue
Payload:
```json
{
  "queue": {
    "loop": true,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 30
      },
```json
      {
        "relay": 2,
        "duration": 30
      },
```json
      {
        "relay": 3,
        "duration": 30
      },
```json
      {
        "relay": 4,
        "duration": 30
      }
```
    ]
  }
}
Description:
Repeats indefinitely
Each relay activates for 30 seconds
Immediately starts next cycle after completion
Continues until manually stopped
Use Case: Continuous rotation between zones
Queue with Loop Delay
Payload:
```json
{
  "queue": {
    "loop": true,
    "loop_delay": 3600,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 300
      },
```json
      {
        "relay": 2,
        "duration": 450
      },
```json
      {
        "relay": 3,
        "duration": 600
      }
```
    ]
  }
}
Description:
Repeats indefinitely with delay between cycles
Relay 1: 5 minutes (300s)
Relay 2: 7.5 minutes (450s)
Relay 3: 10 minutes (600s)
Waits 1 hour (3600s) before starting next cycle
Use Case: Irrigation system that runs every hour
Queue with Delays Between Steps
Payload:
```json
{
  "queue": {
    "loop": true,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 10
      },
```json
      {
        "delay": 5
      },
```json
      {
        "relay": 2,
        "duration": 15
      },
```json
      {
        "delay": 5
      },
```json
      {
        "relay": 3,
        "duration": 10
      }
```
    ]
  }
}
Description:
Includes wait periods between relay activations
Relay 1 ON for 10 seconds
Wait 5 seconds (all relays OFF)
Relay 2 ON for 15 seconds
Wait 5 seconds (all relays OFF)
Relay 3 ON for 10 seconds
Repeats continuously
Use Case: Operations requiring settling time between steps
Queue Without Auto-Start
Payload:
```json
{
  "queue": {
    "loop": true,
    "auto_start": false,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 30
      },
```json
      {
        "relay": 2,
        "duration": 30
      }
```
    ]
  }
}
Description:
Configures queue but doesn't start it
Queue will NOT auto-start on boot
Must be manually started with queue_control: restart
Useful for scheduled operations
Complex Irrigation Queue Example
Payload:
```json
{
  "queue": {
    "loop": true,
    "loop_delay": 7200,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 600
      },
```json
      {
        "delay": 120
      },
```json
      {
        "relay": 2,
        "duration": 900
      },
```json
      {
        "delay": 120
      },
```json
      {
        "relay": 3,
        "duration": 450
      },
```json
      {
        "delay": 120
      },
```json
      {
        "relay": 4,
        "duration": 750
      }
```
    ]
  }
}
Description:
Zone 1: 10 minutes irrigation
Wait 2 minutes
Zone 2: 15 minutes irrigation
Wait 2 minutes
Zone 3: 7.5 minutes irrigation
Wait 2 minutes
Zone 4: 12.5 minutes irrigation
Wait 2 hours before next cycle
Use Case: Multi-zone drip irrigation system
Switch to Queue Mode and Configure
Payload:
```json
{
  "mode": 2,
  "queue": {
    "loop": true,
    "loop_delay": 120,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 30
      },
```json
      {
        "relay": 2,
        "duration": 30
      }
```
    ]
  }
}
Description:
Switches to queue mode
Configures and starts queue in one command
Saves to EEPROM

## Queue Control Commands

Control queue execution without reconfiguring it.
Pause Queue
Payload:
```json
{
  "queue_control": "pause"
}
```
Description:
Pauses queue execution at current step
Current relay remains in its state
Timer stops
Can be resumed later
Resume Queue
Payload:
```json
{
  "queue_control": "resume"
}
```
Description:
Resumes paused queue
Continues from where it was paused
Timer resumes
Stop Queue
Payload:
```json
{
  "queue_control": "stop"
}
```
Description:
Stops queue execution
Turns OFF all relays
Disables auto-start
Queue configuration remains saved
Restart Queue
Payload:
```json
{
  "queue_control": "restart"
}
```
Description:
Restarts queue from step 0
Turns OFF all relays first
Enables auto-start
Useful for manual triggering
Enable Auto-Start
Payload:
```json
{
  "queue_control": "enable_autostart"
}
```
Description:
Enables auto-start flag
Queue will start automatically on boot
Doesn't start queue immediately
Disable Auto-Start
Payload:
```json
{
  "queue_control": "disable_autostart"
}
```
Description:
Disables auto-start flag
Queue will NOT start automatically on boot
Doesn't stop currently running queue

## OTA Update Commands

Over-The-Air firmware updates via MQTT.
Check for Updates
Payload:
```json
{
  "ota_check": true
}
```
Description:
Checks GitHub for new firmware version
Compares with current version
Publishes result to {MAC}/ota/status
Doesn't download or install
Response Example:
```json
{
  "ota_available": true,
  "current_version": "1.0.0",
  "new_version": "1.1.0"
}
```
Perform OTA Update
Payload:
```json
{
  "ota_update": true
}
```
Description:
Downloads latest firmware from GitHub
Verifies download
Installs new firmware
Automatically restarts device
Warning: Device will be offline during update (30-60 seconds)

## Status Messages

The ESP-B Gateway publishes status messages to {MAC}/status topic.
Manual Mode Status
Published Message:
```json
{
  "mode": 0,
  "mode_name": "manual",
  "firmware_version": "1.0.0",
  "relays": [true, false, true, false],
  "nodes": [
```json
    {
      "id": 1,
      "temp": 25.3,
      "hum": 55.2,
      "active": true
    },
```json
    {
      "id": 2,
      "temp": 26.1,
      "hum": 58.7,
      "active": true
    }
```
  ]
}
Description:
relays: Array of relay states [relay1, relay2, relay3, relay4]
nodes: Array of paired sensor nodes with latest readings
active: true if node seen in last 60 seconds
Automation Mode Status
Published Message:
```json
{
  "mode": 1,
  "mode_name": "automation",
  "firmware_version": "1.0.0",
  "relays": [true, false, false, false],
  "nodes": [
```json
    {
      "id": 1,
      "temp": 31.2,
      "hum": 52.3,
      "active": true
    }
```
  ]
}
Queue Mode Status
Published Message:
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
```json
    {
      "id": 1,
      "temp": 24.8,
      "hum": 52.3,
      "active": true
    }
```
  ]
}
Description:
queue_running: Whether queue is currently executing
queue_paused: Whether queue is paused
queue_auto_start: Whether queue will auto-start on boot
current_step: Current step number (1-indexed)
total_steps: Total number of steps in queue

## Practical Examples

Example 1: Greenhouse Temperature Control
Scenario: Control exhaust fan based on greenhouse temperature
Payload:
```json
{
  "mode": 1,
  "automation": {
    "rules": [
```json
      {
        "node": 1,
        "relay": 1,
        "temp": {
          "min": 25.0,
          "max": 32.0
        }
```
      }
    ]
  }
}
Behavior:
Fan (Relay 1) turns ON when temperature exceeds 32°C
Fan turns OFF when temperature drops below 25°C
Fan maintains state between 25-32°C
Example 2: Multi-Zone Humidity Control
Scenario: Control humidifiers in different zones
Payload:
```json
{
  "mode": 1,
  "automation": {
    "rules": [
```json
      {
        "node": 1,
        "relay": 1,
        "humidity": {
          "min": 50.0,
          "max": 70.0
        }
```
      },
```json
      {
        "node": 2,
        "relay": 2,
        "humidity": {
          "min": 45.0,
          "max": 65.0
        }
```
      },
```json
      {
        "node": 3,
        "relay": 3,
        "humidity": {
          "min": 55.0,
          "max": 75.0
        }
```
      }
    ]
  }
}
Behavior:
Each zone has independent humidity control
Different thresholds for different zones
Humidifiers activate when humidity exceeds max
Example 3: 4-Zone Drip Irrigation System
Scenario: Water 4 garden zones sequentially, twice per day
Payload:
```json
{
  "mode": 2,
  "queue": {
    "loop": true,
    "loop_delay": 43200,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 900
      },
```json
      {
        "delay": 300
      },
```json
      {
        "relay": 2,
        "duration": 1200
      },
```json
      {
        "delay": 300
      },
```json
      {
        "relay": 3,
        "duration": 600
      },
```json
      {
        "delay": 300
      },
```json
      {
        "relay": 4,
        "duration": 800
      }
```
    ]
  }
}
Behavior:
Zone 1: 15 minutes
Wait 5 minutes
Zone 2: 20 minutes
Wait 5 minutes
Zone 3: 10 minutes
Wait 5 minutes
Zone 4: 13.3 minutes
Wait 12 hours (43200s) before next cycle
Example 4: Timed Grow Light Control
Scenario: 12 hours ON, 12 hours OFF cycle
Payload:
```json
{
  "mode": 2,
  "queue": {
    "loop": true,
    "loop_delay": 0,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 43200
      },
```json
      {
        "delay": 43200
      }
```
    ]
  }
}
Behavior:
Lights ON for 12 hours (43200 seconds)
Lights OFF for 12 hours (43200 seconds)
Repeats continuously
Example 5: Emergency Stop All
Scenario: Immediately turn off all relays
Payload:
```json
{
  "mode": 0,
  "all": 0
}
```
Behavior:
Switches to manual mode
Turns off all relays
Stops any automation or queue
Example 6: Test All Relays Sequentially
Scenario: Test each relay for 5 seconds
Payload:
```json
{
  "mode": 2,
  "queue": {
    "loop": false,
    "auto_start": true,
    "steps": [
```json
      {
        "relay": 1,
        "duration": 5
      },
```json
      {
        "relay": 2,
        "duration": 5
      },
```json
      {
        "relay": 3,
        "duration": 5
      },
```json
      {
        "relay": 4,
        "duration": 5
      }
```
    ]
  }
}
Behavior:
Tests each relay for 5 seconds
Runs once and stops
Total test time: 20 seconds

## Button Functions

The ESP-B Gateway has a boot button for physical control.
| Press Duration | Function | Description |
|---------------|----------|-------------|
| **1 second** | Enable Pairing Mode | Allows new ESP-A nodes to pair for 30 seconds |
| **5 seconds** | Reset WiFi | Clears WiFi credentials and restarts (enters AP mode) |
| **10 seconds** | Reset Paired Nodes | Removes all paired ESP-A nodes |
| **20 seconds** | Factory Reset | Flushes entire EEPROM, removes all configuration, WiFi, and nodes |


## Visual Feedback

The serial monitor provides feedback during button press:
Button pressed...
>>> Release now to ENABLE PAIRING <<<
>>> Release now to RESET WiFi <<<
>>> Release now to RESET PAIRED NODES <<<
>>> Release now to FACTORY RESET (FLUSH ALL EEPROM) <<<

## Important Notes


## Data Persistence

All configurations are automatically saved to EEPROM
Settings persist across power cycles and reboots
Manual mode: Relay states saved
Automation mode: All rules saved
Queue mode: Queue configuration and auto-start flag saved

## Rate Limiting

Automation mode has 3-second rate limiting to prevent relay flickering
Prevents rapid state changes at threshold boundaries

## Node Timeout

Nodes are considered inactive if no data received for 60 seconds
Automation rules won't trigger for inactive nodes
Node status visible in status messages

## Queue Behavior

Queue auto-starts on boot if auto_start is true
Stopping queue disables auto-start
Restarting queue enables auto-start
All relays turned OFF before queue starts

## Mode Switching

Switching to Automation or Queue mode turns OFF all relays first
Manual mode preserves relay states from EEPROM
Mode changes are saved immediately

## Troubleshooting

Relay Not Responding
1.
Check mode is correct (mode: 0 for manual)
2.
Verify relay number (1-4, not 0-3)
3.
Check MQTT connection
4.
Review serial monitor for errors
Automation Not Working
1.
Verify nodes are paired and active
2.
Check automation rules are configured
3.
Ensure mode is set to 1 (automation)
4.
Verify sensor data is being received
5.
Check thresholds are appropriate
Queue Not Starting
1.
Check auto_start is true
2.
Verify queue has steps configured
3.
Ensure mode is set to 2 (queue)
4.
Check for queue_control stop command
OTA Update Failed
1.
Verify internet connection
2.
Check GitHub repository is accessible
3.
Ensure sufficient free memory
4.
Review serial monitor for error messages

## Version Information

Current Firmware Version: Check via status message or serial monitor
GitHub Repository: [Your Repository URL]
OTA Update URL: [Your firmware.bin URL]
This documentation covers all MQTT commands and payloads for the ESP-B Gateway system. For hardware setup and ESP-A node pairing, refer to the main README.

# RFID-DOOR_LOCK_SYSTEM

## Overview

This project demonstrates an RFID-based door lock system using Arduino Uno, RFID sensor, and a solenoid lock. It integrates an LCD display to show user feedback and uses additional components like LEDs, a buzzer, and a relay module to manage the door lock mechanism. When a valid RFID card is scanned, the door unlocks for a short period. If an unauthorized card is scanned, the system alerts the user with a message and a buzzer sound.

## Components Used
- Arduino Uno
- RFID Sensor (MFRC522)
- Solenoid Lock
- LED (Green/Red)
- Buzzer
- Breadboard
- Relay Module
- Push Button
- Breadboard
- LCD Display (16x2)
- Jumper Wires
- Resistors (220 ohms for LEDs)
  
## Wiring

- RFID Sensor: Connect the MFRC522 RFID sensor to the Arduino following these pin connections:
  - `SDA` -> Pin 10
  - `SCK` -> Pin 13
  - `MOSI` -> Pin 11
  - `MISO` -> Pin 12
  - `IRQ` -> Not connected
  - `GND` -> GND
  - `RST` -> Pin 9
  - `3.3V` -> 3.3V

- Solenoid Lock: Connect the solenoid lock through the relay module, using a separate power source if necessary.
- LEDs: Green and red LEDs are connected to signal lock status (Green for granted, Red for denied).
- Buzzer: The buzzer is connected to signal unauthorized access.
- Push Button: Optional button for manual unlock or emergency situations.
- LCD: Connect the LCD display to pins 7, 8, 9, 10, 11, and 12 on the Arduino.

## How It Works
1. The system initializes and displays a welcome message on the LCD.
2. The RFID reader scans for a card and reads the UID.
3. If the UID matches the authorized card, the door unlocks for 5 seconds, and a message is displayed.
4. If an unauthorized card is scanned, the system denies access and triggers the buzzer.
5. The system is reset after each scan, waiting for the next RFID card.

## Code Explanation
- The RFID sensor is initialized using the `MFRC522` library to read card data.
- A solenoid lock is used, which is controlled via a relay module.
- The LCD display shows feedback such as "Access Granted" or "Access Denied."
- The code includes a hardcoded authorized RFID card UID that can be customized.
  
## Customization
- You can add more UIDs to the code by modifying the authorized UID check.
- The delay for unlocking the door can be adjusted according to your preference.

## Installation
1. Upload the provided code to your Arduino Uno using the Arduino IDE.
2. Connect all components following the wiring instructions.
3. Power the Arduino, and the system will be ready to use.

## Libraries Required
MFRC522 for RFID communication
LiquidCrystal for LCD control

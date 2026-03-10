# RFID Access Control System

![Arduino](https://img.shields.io/badge/Platform-Arduino-blue)
![Language](https://img.shields.io/badge/Language-C++-orange)
![Technology](https://img.shields.io/badge/Technology-RFID-green)

---

## Project Overview

This project implements an RFID-based access control system using an Arduino microcontroller and the MFRC522 RFID reader module.

The system reads the UID (Unique Identifier) of an RFID card and compares it with a predefined authorized UID stored in the program. If the scanned card matches the authorized UID, the system grants access and activates visual indicators. Otherwise, access is denied and an alert signal is triggered.

This type of system is commonly used in secure entry systems, smart buildings, and embedded authentication applications.

---

## Hardware Setup

![Hardware Setup](images/hardware.jpg)

The hardware system consists of an Arduino board connected to an RFID reader module, a 16x2 LCD display, LEDs for status indication, and a buzzer for audio feedback.

---
## Hardware Components

| Component           | Description              |
| ------------------- | ------------------------ |
| Arduino Uno R3      | Main microcontroller     |
| MFRC522 RFID Reader | Reads RFID card UID      |
| RFID Card / Tag     | Authentication key       |
| LCD 16x2            | Displays system messages |
| Buzzer              | Audio feedback           |
| Red & Green LEDs    | Access status indicators |
| Breadboard          | Circuit prototyping      |
| Jumper Wires        | Connections              |

---

## Hardware Connections

### RFID RC522 → Arduino

| RC522 Pin | Arduino Pin |
| --------- | ----------- |
| SDA       | D10         |
| RST       | D9          |
| MOSI      | D11         |
| MISO      | D12         |
| SCK       | D13         |
| VCC       | 3.3V        |
| GND       | GND         |

### LCD 16x2 → Arduino

| LCD Pin | Arduino Pin |
| ------- | ----------- |
| RS      | 7           |
| E       | 6           |
| D4      | 5           |
| D5      | 4           |
| D6      | 3           |
| D7      | 2           |

### Other Components

| Component | Arduino Pin |
| --------- | ----------- |
| Buzzer    | D8          |
| Green LED | A1          |
| Red LED   | A0          |

---

## Software & Libraries

The system is programmed using **Arduino C++** and uses the following libraries:

* `SPI.h` – Communication protocol for the RFID module
* `MFRC522.h` – RFID reader library
* `LiquidCrystal.h` – LCD display control

Example of the authorized RFID UID stored in the code:

```cpp id="r8h3km"
byte allowedUID[4] = {0x90, 0x89, 0x36, 0x52};
```

Only this card will be granted access.

---
## Circuit Diagram

The circuit connects the RFID module to the Arduino through the SPI interface, while the LCD display is connected using digital I/O pins.

---

## System Architecture

The architecture of the system follows a simple embedded control model:

RFID Card → RFID Reader (MFRC522) → Arduino Controller → Output Devices

Output devices include:

* LCD Display (system messages)
* LEDs (access status)
* Buzzer (alert signal)

---

## System Workflow

System operation steps:

1. The system initializes the LCD display and RFID reader.
2. The system waits for an RFID card to be presented.
3. When a card is detected, the UID is read.
4. The UID is compared with the stored authorized UID.
5. If the UID matches:

   * Access is granted
   * Green LED turns on
   * Buzzer beeps once
6. If the UID does not match:

   * Access is denied
   * Red LED turns on
   * Buzzer gives multiple warning beeps
7. The system resets and waits for the next card.

---

## Components Used

* Arduino Uno
* MFRC522 RFID Reader Module
* RFID Card / Tag
* 16x2 LCD Display
* LEDs (Status Indicators)
* Buzzer
* Resistors
* Breadboard and Jumper Wires

---

## Source Code

The Arduino source code for this project is available in:

code/rfid_access_control.ino

The program is written in C++ using the Arduino framework and utilizes the following libraries:

* SPI Library
* MFRC522 Library
* LiquidCrystal Library

---

## Demonstration

![Demo](images/demo.png)

The system demonstrates real-time authentication using RFID technology.

---

## Documentation

Detailed project documentation is available in the following reports:

* Hardware Design → docs/hardware_report.pdf
* Software Implementation → docs/software_report.pdf

---

## Academic Information

This project was developed as part of the **Hardware Systems Laboratory** course.

Instructor:
Dr. Fardin Ghavidel


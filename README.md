# RFID-Based Access Control System

## Project Overview

This project implements a **contactless access control system using RFID technology**.
An RFID card is used as a digital authentication key. When a card is scanned, the system reads its **UID (Unique Identifier)** and compares it with a predefined authorized UID stored in the microcontroller.

If the UID matches, the system grants access and provides visual and audio feedback. Otherwise, access is denied.

The system demonstrates how **embedded hardware, microcontroller programming, and communication protocols** can be integrated to build a simple but practical security solution.

---

## Project Demonstration

### Hardware Setup

![Hardware Setup](images/hardware.jpg)

### Circuit Diagram

![Circuit Diagram](images/circuit.png)

### Working Demo

![Project Demo](images/demo.gif)

*(Add your own images in the `images` folder and they will appear here.)*

---

## System Features

* RFID card authentication
* UID-based access verification
* LCD interface for real-time status messages
* Buzzer audio feedback
* LED indicators for access status
* Simple and scalable embedded security logic

---

## How the System Works

The workflow of the system is as follows:

1. The system initializes and displays
   **"RFID Ready – Tap Card"** on the LCD.

2. A user places an RFID card near the reader.

3. The **MFRC522 RFID module** reads the card's UID.

4. The Arduino compares the scanned UID with the stored authorized UID.

5. If the UID matches:

   * Green LED turns on
   * LCD displays **Access Granted**
   * Buzzer beeps once

6. If the UID does not match:

   * Red LED turns on
   * LCD displays **Access Denied**
   * Buzzer beeps twice

7. After a short delay, the system resets and waits for the next card.

This mechanism is a simplified example of the logic used in real-world **electronic access control systems**.

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

## How to Run the Project

1. Install **Arduino IDE**
2. Install required libraries:

   * MFRC522
   * LiquidCrystal
3. Connect the hardware according to the wiring table
4. Upload the code to the Arduino board
5. Scan an RFID card near the reader
6. Observe the system response on the LCD, LEDs, and buzzer

---

## Academic Information

This project was developed as part of the **Digital Systems Laboratory course** in the
Faculty of Electrical and Computer Engineering.

**Instructor:**
Dr. Fardin Ghavidel

---

## 📄 License

This project is intended for **educational and research purposes**.

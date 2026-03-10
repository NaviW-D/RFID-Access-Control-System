# RFID-Access-Control-System
Overview

This project implements a digital access control system using RFID technology.
An RFID card is used as a digital key. When a user scans the card, the system reads the UID (Unique Identifier) and checks whether it is authorized. If the card is valid, access is granted; otherwise, access is denied.

The system provides visual and audio feedback using an LCD display, LEDs, and a buzzer.

This project was developed as part of the Digital Systems Laboratory course in the Electrical and Computer Engineering department.

Features

Contactless authentication using RFID cards

UID-based access control

LCD interface for system messages

LED indicators for system status

Buzzer feedback for accepted or rejected cards

Secure access verification

System responses:

Card Status	LED	LCD Message	Buzzer
Valid card	Green LED	Access Granted	1 beep
Invalid card	Red LED	Access Denied	2 beeps
Hardware Components

The hardware implementation uses the following components:

Arduino Uno R3

RFID Reader RC522

RFID Card / Tag

LCD Display 16x2

Buzzer

LEDs (Red and Green)

Breadboard

Jumper wires

These components create a simple embedded security system for access control. 

گزارشکار_پروژه_آز_سیستم_2_سخت_…

System Architecture

The system works according to the following process:

System powers on.

LCD displays "RFID Ready – Tap Card".

User places RFID card near the reader.

RFID module reads the card UID.

Microcontroller compares the UID with stored authorized UID.

If the UID matches:

Green LED turns ON

LCD shows Access Granted

Buzzer beeps once

If the UID does not match:

Red LED turns ON

LCD shows Access Denied

Buzzer beeps twice

System resets and waits for the next card.

Hardware Connections
RFID RC522 → Arduino
RC522 Pin	Arduino Pin
SDA	D10
RST	D9
MOSI	D11
MISO	D12
SCK	D13
VCC	3.3V
GND	GND
LCD 16x2 → Arduino
LCD Pin	Arduino Pin
RS	7
E	6
D4	5
D5	4
D6	3
D7	2
Other Connections
Component	Pin
Buzzer	D8
Green LED	A1
Red LED	A0
Software Libraries

The project uses the following Arduino libraries:

SPI.h – communication protocol between Arduino and RFID module

MFRC522.h – RFID reader library

LiquidCrystal.h – LCD control library

Example Authorized UID

Example UID stored in the program:

byte allowedUID[4] = {0x90, 0x89, 0x36, 0x52};

Only this RFID card will unlock the system.

How to Run the Project

Install Arduino IDE

Install the required libraries:

MFRC522

LiquidCrystal

Connect the hardware according to the wiring diagram

Upload the Arduino code

Open the Serial Monitor (optional)

Scan an RFID card

Applications

This type of system can be used in many real-world scenarios:

Smart door locks

Building access systems

Smart cabinets

Attendance systems

Warehouse tracking

RFID technology is widely used because it allows secure, contactless identification using radio frequency signals.

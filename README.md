# RFID Door Lock System Using ATmega328P-PU (Breadboard Build)

This project showcases a straightforward and budget-friendly RFID-based door lock system, centered around the **ATmega328P-PU microcontroller** — programmed with **Arduino ISP** — and entirely assembled on a **breadboard**. It incorporates an **RC522 RFID reader**, a **relay module**, and a **12V solenoid lock** to manage access through RFID cards or tags. A handy **16x2 LCD display** provides real-time feedback, letting users know if access is granted or denied.

This was my mini-project back in college, crafted from the ground up — I didn’t use an Arduino board for deployment. Instead, I programmed the ATmega328P using an Arduino Uno as an ISP programmer, and the whole circuit hand-wired on a breadboard.

## Overview

The primary aim of this project was to create a basic access control system utilizing RFID technology, ensuring that access to a door (or any physical barrier) is only granted to recognized RFID tags. The ATmega328P-PU microcontroller checks the UID of the scanned RFID tag against a predefined list of authorized tags and unlocks the solenoid door lock via a relay when there's a match.

## Hardware Used

| Component | Description |
|---------------------|---------------------------------|
| ATmega328P-PU | Standalone MCU, breadboarded |
| RC522 RFID Reader | 13.56 MHz reader for RFID tags |
| RFID Tags (10) | Keychain-style access cards |
| Solenoid Lock (12V) | Controls door access |
| 1-Channel Relay | To switch solenoid from MCU |
| 16x2 LCD Display | Shows access status |
| 5V to 12V Booster | Boosts voltage for lock |
| Jumper Wires | Breadboard wiring |
| DC Socket + Adapter | 5V regulated power supply |


## Software and Programming

- **Arduino IDE** was used to write and upload the code
- **Arduino Uno served as the ISP programmer**
- Coded in Arduino-style C/C

Ensure the following libraries are installed via the **Arduino Library Manager**:

- **MFRC522 by GithubCommunity** – Version `1.4.12`
- **SPI** – Comes inbuilt 
- **LiquidCrystal** – Version `1.0.7`

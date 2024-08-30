# Signal-to-Character-LCD-Display

A simple Arduino project that reads binary signals, matches them with predefined characters (A-Z), and displays the recognized characters on an LCD screen. The project is ideal for learning about basic signal processing, character recognition, and interfacing with an LCD display using an Arduino.

## Table of Contents

- [Introduction](#introduction)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Wiring Diagram](#wiring-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project is designed to read a continuous binary signal via a digital input pin on the Arduino. The signal is then compared against a predefined set of binary patterns corresponding to the letters A-Z. The recognized characters are displayed on an LCD screen, with a buzzer providing auditory feedback for each signal read.

## Hardware Requirements

- Arduino Uno or compatible board
- 16x2 or 20x4 LCD display
- Buzzer
- Jumper wires
- Breadboard
- LED (for the continuous signal simulation, if needed)
- Resistors (if needed for LED)

## Software Requirements

- Arduino IDE (version 1.8.13 or higher)
- LiquidCrystal library (pre-installed with the Arduino IDE)

## Wiring Diagram

Here's a simple wiring setup:

- **LCD Display**:
  - RS -> Pin 12
  - E  -> Pin 11
  - D4 -> Pin 5
  - D5 -> Pin 4
  - D6 -> Pin 6
  - D7 -> Pin 7
- **Buzzer** -> Pin 3
- **Signal Input** (Simulated LED) -> Pin 2

## Installation

1. Clone the repository to your local machine
2. Open the Arduino IDE and load the `Signal-to-Character-LCD-Display.ino` file from the cloned repository.
3. Connect your Arduino to your computer.
4. Select the correct board and port from the Arduino IDE.
5. Upload the code to your Arduino.

## Usage

1. After uploading the code, the Arduino will begin reading the binary signal from Pin 2.
2. The buzzer will sound for each signal read.
3. The recognized character (A-Z) will be displayed on the LCD.
4. The system will display up to 6 characters before halting. The display will reset when it reaches the maximum count.

## Code Overview

### Main Components:

- **Binary Signal Reading**: The input signal is read from a digital pin and stored in an array.
- **Character Matching**: The input binary array is compared with predefined binary patterns corresponding to the letters A-Z.
- **LCD Display**: Recognized characters are displayed on the LCD. The display refreshes when it reaches the 6th character.
- **Buzzer Feedback**: The buzzer provides auditory feedback for each signal read.

### Key Functions:

- `comparison(int a[][8], int b[], int row, int column)`: This function compares the input array with the predefined binary patterns and returns the index of the matched pattern.
- `setup()`: Initializes the LCD, buzzer, and serial communication.
- `loop()`: The main logic loop that reads the signal, processes the data, and updates the display.

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


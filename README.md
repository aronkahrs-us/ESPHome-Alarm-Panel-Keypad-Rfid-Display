<br/>
<p align="center">
  <a href="https://github.com/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display">
    <img src="https://materialdesignicons.com/api/download/B732FAD7-93A7-478E-810F-835069DE6EDB/000000/1/FFFFFF/0/48" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">ESPHome Alarm Panel</h3>

  <p align="center">
    DIY Alarm Panel using NodeMCU v3 ESP8266 for Home Assistant.
    <br/>
    <br/>
    <a href="https://github.com/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display"><strong>Explore the docs »</strong></a>
    <br/>
    <br/>
    <a href="https://github.com/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display">View Demo</a>
    .
    <a href="https://github.com/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display/issues">Report Bug</a>
    .
    <a href="https://github.com/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display/issues">Request Feature</a>
  </p>
</p>

![Downloads](https://img.shields.io/github/downloads/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display/total) ![Contributors](https://img.shields.io/github/contributors/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display?color=dark-green) ![Issues](https://img.shields.io/github/issues/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display) ![License](https://img.shields.io/github/license/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display) 

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Contributing](#contributing)
* [Authors](#authors)
* [Acknowledgements](#acknowledgements)

## About The Project
## ⚠️ WORK IN PROGRESS ⚠️
![Screen Shot](main.jpg)


Here I'll try to explain and show how I made this custom alarm panel for Home Assistant with a NodeMCU ESP8266

## Parts

* NodeMCU v3 ESP8266
* Matrix 4x4 Keypad
* RC522
* Resistors:
  * x1 47Ω
  * x1 47Ω
  * x1 100Ω
  * x1 150Ω
  * x1 220Ω
  * x1 270Ω
  * x1 470Ω
  * x2  680Ω
  * x1 910Ω
* Buzzer
* Protoboard( I used a 80x120mm, but you can use any size, or any other platform you like)
*Jumper Wires
- Patience and Creativity 😆

## Getting Started

We'll start with the Keypad, in this case I will be using a 4x4 one, you can use a 4x3 but you will need to change some things in [_keypad_custom.h_](https://github.com/aronkahrs-us/ESPHome-Alarm-Panel-Keypad-Rfid-Display/blob/main/ESPHome/keypad_custom.h).

We could use 8 Digital pins of our NodeMCU to connect the keypad, _and if you only want the keypad functionality it's recommended_, but we still need to connect the RC522 and the Display, so we'll really need those pins later, what we are going to do to "free" pins is basically turning the keypad into a selectable voltage divider circuit, where each button is selecting a different divider configuration, resulting in a different voltage which we'll be measuring to determine which key was pressed.



### Prerequisites

This is an example of how to list things you need to use the software and how to install them.

* npm

```sh
npm install npm@latest -g
```

### Installation

1. Get a free API Key at [https://example.com](https://example.com)

2. Clone the repo

```sh
git clone https://github.com/your_username_/Project-Name.git
```

3. Install NPM packages

```sh
npm install
```

4. Enter your API in `config.js`

```JS
const API_KEY = 'ENTER YOUR API';
```

## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

## Contributing



### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Authors

* **Aron Kahrs** - *Physics Student* - [Aron Kahrs](https://github.com/aronkahrs-us) - *Create Repo*

## Acknowledgements

* [Connect A 4×4 Keypad To One Arduino Input](https://www.the-diy-life.com/connect-a-4x4-keypad-to-one-arduino-input/)
* [Othneil Drew](https://github.com/othneildrew/Best-README-Template)
* [ImgShields](https://shields.io/)

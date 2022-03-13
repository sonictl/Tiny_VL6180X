# AboutMe & Motivations
  This is an Arduino library for driving the VL6180X range sensor module with the [digispark-tiny board](http://digistump.com/products/1) (attiny85 microChip) via I2C protocal.

# Basic notes for Atmel Attiny85
  Attiny 85 and based on whicn the digispark-tiny board is low-cost, most mini-size board that I like to use.
  digispark-tiny board is also named as "Digispark USB Development Board - Digistump"
  #### Specs:
 - Support for the Arduino IDE 1.0+ (OSX/Win/Linux)
 - Power via USB or External Source - 5v or 7-35v (12v or less recommended, automatic selection)
 - On-board 500ma 5V Regulator
 - Built-in USB
 - 6 I/O Pins (2 are used for USB only if your program actively communicates over USB, otherwise you can use all 6 even if you are programming via USB)
 - 8k Flash Memory (about 6k after bootloader)
 - I2C and SPI (vis USI)
 - PWM on 3 pins (more possible with Software PWM)
 - ADC on 4 pins
 - Power LED and Test/Status LED
  #### However:
 - attiny85 has no hardware Serial, so `#include <SPI.h>` will not work.
 - `#include <Wire.h>` looks work here.
 - directly use `Serial.begin();` is not supported.

# How to use this library
  
## hardware connection:
    connect the VL6108X SDA with attiny85(Pin5_of_chip = Pin0 of board)
    connect the VL6108X SCL with attiny85(Pin7_of_chip = Pin2 of board)
    power on the VL6108X with 5V

## software env I develop this repo
    vsCode + platformIO
    board: digispark-tiny
    refer to the file `platformio.ini` for more info.

## to use this lib
    put the folder "./lib/Tiny_VL6180X" into the /lib/ folder.
    `#include "Tiny_VL6180X.h"` in `main.cpp`
    compile, upload and run it.

## Dependency tree
    The dep tree and developing steps is shown below:
    ```
    Adafruit_VL6180X.h  <-- lib/Tiny_VL6180X/Tiny_VL6180X.h             (finished)
      -- Adafruit_I2CDevice.h  <-- lib/Tiny_I2CDevice/Tiny_I2CDevice.h  (finished)
           >ps: Is the Wire.h compatible with attiny85 here? 
        -- Wire.h <-- tinyWireM.h 
           >ps: Looks like the Wire.h is OK for attiny85. No need to write this.
    ```

## More examples of code
    refer to the "[Adafruit_VL6180X](https://github.com/adafruit/Adafruit_VL6180X)" Arduino library, and modify the Adafruit into Tiny.

# Acknowledgement
    This repository is developed by modifying the "[Adafruit_VL6180X](https://github.com/adafruit/Adafruit_VL6180X)" Arduino library.
    Thanks for their contribution!!


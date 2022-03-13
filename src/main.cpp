/**
 * @file main.cpp
 * @author sonic
 * @brief 
 *      This code read the  VL6180X range value and 
 *      blink the onboard LED with different time interval.
 *      Please refer to the Adafruit_VL6180X lib, for more examples such as Display the range on OLED screen.
 *      Thanks for Adafruit_VL6180X.
 * @version 0.1
 * @date 2022-03-13  2022-03-13 20:17:42
 * 
 * @copyright MIT license.
 * 
 */

#include <Arduino.h>
#include "Tiny_VL6180X.h"

#define BUILTIN_LED 1     // onboard LED is at pin1 of digispark-tiny board

// self defined blink function with status machine.
void my_blink(int pinx, unsigned long time_interval){
    static enum { LED_TOGGLE, WAIT_DELAY } state = LED_TOGGLE;
    static uint32_t timeLastTransition = 0;

    switch (state){
        case LED_TOGGLE:   // toggle the LED
        digitalWrite(pinx, !digitalRead(pinx));
        timeLastTransition = millis();
        state = WAIT_DELAY;
        break;
    
        case WAIT_DELAY:   // wait for the delay period
        if (millis() - timeLastTransition >= time_interval)
            state = LED_TOGGLE;
        break;
    
        default:
        state = LED_TOGGLE;
        break;
    }
}

// declarations:
int time_intv = 0;
Tiny_VL6180X vl = Tiny_VL6180X();

void setup() {
  // put your setup code here, to run once:
  pinMode(BUILTIN_LED, OUTPUT);
  if (! vl.begin()) {
    my_blink(BUILTIN_LED, 50);    // fast blink if error
    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t range = vl.readRange();
  my_blink(BUILTIN_LED, range * 6);

  // // Some error occurred, print it out!
  // // However, attiny85 has no hardware Serial port.
  // uint8_t status = vl.readRangeStatus();
  // if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
  //   Serial.println("System error");
  // }
  // else if (status == VL6180X_ERROR_ECEFAIL) {
  //   Serial.println("ECE failure");
  // }
  // else if (status == VL6180X_ERROR_NOCONVERGE) {
  //   Serial.println("No convergence");
  // }
  // else if (status == VL6180X_ERROR_RANGEIGNORE) {
  //   Serial.println("Ignoring range");
  // }
  // else if (status == VL6180X_ERROR_SNR) {
  //   Serial.println("Signal/Noise error");
  // }
  // else if (status == VL6180X_ERROR_RAWUFLOW) {
  //   Serial.println("Raw reading underflow");
  // }
  // else if (status == VL6180X_ERROR_RAWOFLOW) {
  //   Serial.println("Raw reading overflow");
  // }
  // else if (status == VL6180X_ERROR_RANGEUFLOW) {
  //   Serial.println("Range reading underflow");
  // }
  // else if (status == VL6180X_ERROR_RANGEOFLOW) {
  //   Serial.println("Range reading overflow");
  // }

  delay(50);
}
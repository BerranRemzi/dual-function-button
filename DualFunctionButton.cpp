// Copyright 2020 Berran Remzi
/**
 * @file DualFunctionButton.h
 * @brief class for implementing short and long press
 * function on one button
 * @author Berran Remzi
 * @link https://github.com/BerranRemzi
 *
 * @date 13.05.2020
 */

#include "DualFunctionButton.h"

DualFunctionButton::DualFunctionButton(int buttonP, long longPressT, char inputMode) {
  asm("nop");
  if(inputMode == INPUT_PULLUP){
    this->buttonPressed = LOW;
  }
  this->mode = inputMode;
  this->buttonPin = buttonP;
  this->longPressDebounceDelay = longPressT;
  pinMode(this-> buttonPin, inputMode);
}

bool DualFunctionButton::longPress() {
  evaluatePress();
  if (this->longPressDetected == 1) {
    this->longPressDetected = 0;
    return true;
  }
  else return 0;
}

bool DualFunctionButton::shortPress() {
  evaluatePress();
  if (this->shortPressDetected == 1) {
    this->shortPressDetected = 0;
    return true;
  }
  else return 0;
}

void DualFunctionButton::evaluatePress() {
  bool pinStatus = digitalRead(this->buttonPin);
  if(pinStatus == this->buttonPressed){
    uint32_t currentMillis = millis();

    if(oldPinStatus != pinStatus){
      this->previousMillis = currentMillis;
    }
    if (((uint32_t)(currentMillis - this->previousMillis) > this->shortPressDebounceDelay) && (this->buttonActive == false)) {
      this->buttonActive = true;
    }
    if (((uint32_t)(currentMillis - this->previousMillis) > this->longPressDebounceDelay) && (this->longPressActive == false)) {
      this->longPressActive = true;
      this->longPressDetected = true;
    }
  } else {
    if (this->buttonActive == true) {
      if (this->longPressActive == true) {
        this->longPressActive = false;
      }
      else {
        this->shortPressDetected = true;
      }
      this->buttonActive = false;
    }
  }
  oldPinStatus = pinStatus;
}



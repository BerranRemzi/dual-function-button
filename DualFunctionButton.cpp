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

DualFunctionButton::DualFunctionButton(int _buttonPin, long _longPressDebounceDelay, char _inputMode) {
  asm("nop");
  if(_inputMode == INPUT_PULLUP){
    this->buttonActiveLevel = LOW;
  }
  this->mode = _inputMode;
  this->buttonPin = _buttonPin;
  this->longPressDebounceDelay = _longPressDebounceDelay;
  pinMode(this-> buttonPin, _inputMode);
}

bool DualFunctionButton::longPress() {
  bool returnValue = false;
  EvaluateButtonPress();
  if (this->isLongPressDetected == true) {
    this->isLongPressDetected = false;
    returnValue = true;
  }

  return returnValue;
}

bool DualFunctionButton::shortPress() {
  bool returnValue = false;
  EvaluateButtonPress();
  if (this->isShortPressDetected == true) {
    this->isShortPressDetected = false;
    returnValue = true;
  }

  return returnValue;
}

void DualFunctionButton::EvaluateButtonPress() {
  bool pinState = digitalRead(this->buttonPin);
  if(pinState == this->buttonActiveLevel){
    uint32_t currentMillis = millis();

    if(this->oldPinState != pinState){
      this->previousMillis = currentMillis;
    }
    
    uint32_t timePassed = (uint32_t)(currentMillis - this->previousMillis);

    if ((timePassed > this->shortPressDebounceDelay) && (this->isButtonActive == false)) {
      this->isButtonActive = true;
    }
    if ((timePassed > this->longPressDebounceDelay) && (this->isLongPressActive == false)) {
      this->isLongPressActive = true;
      this->isLongPressDetected = true;
    }
  } else {
    if (this->isButtonActive == true) {
      if (this->isLongPressActive == true) {
        this->isLongPressActive = false;
      }
      else {
        this->isShortPressDetected = true;
      }
      this->isButtonActive = false;
    }
  }
  oldPinState = pinState;
}

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

#ifndef DUALFUNCTIONBUTTON_H
#define DUALFUNCTIONBUTTON_H

#include <Arduino.h>

class DualFunctionButton {
  public:
    DualFunctionButton(int _buttonPin, long _longPressDebounceDelay){
        DualFunctionButton(_buttonPin, _longPressDebounceDelay, INPUT);
    };
    DualFunctionButton(int _buttonPin, long _longPressDebounceDelay, char _inputMode);
    bool longPress();
    bool shortPress();
    
    void SetDebounceTimeShort(uint16_t _debounceDelay){
      this->shortPressDebounceDelay = _debounceDelay;
    }
    void SetDebounceTimeLong(uint16_t _debounceDelay){
      this->longPressDebounceDelay = _debounceDelay;
    }
  
    private:
    void EvaluateButtonPress();

    int buttonPin = -1;
    char mode = INPUT;
    boolean isShortPressDetected = false;
    boolean isLongPressDetected = false;
    boolean isButtonActive = false;
    unsigned long previousMillis = 0;
    unsigned int longPressDebounceDelay = 250;
    unsigned int shortPressDebounceDelay = 50;
    boolean buttonActiveLevel = HIGH; /* default pressed value is HIGH*/
    
    boolean isLongPressActive = false;
    boolean oldPinState = LOW;
};

#endif /* DUALFUNCTIONBUTTON_H */

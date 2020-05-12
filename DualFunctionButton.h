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
    DualFunctionButton(int buttonP, long longPressT){
        DualFunctionButton(buttonP, longPressT, INPUT);
    };
    DualFunctionButton(int buttonP, long longPressT, char inputMode);
    bool longPress();
    bool shortPress();
    void evaluatePress();
    void SetDebounceTimeShort(uint16_t _debounceDelay){
      this->shortPressDebounceDelay = _debounceDelay;
    }
    void SetDebounceTimeLong(uint16_t _debounceDelay){
      this->longPressDebounceDelay = _debounceDelay;
    }
  
    
    private:
    int buttonPin = -1;
    char mode = INPUT;
    boolean outputOneState = false;
    boolean outputTwoState = false;
    boolean shortPressDetected = false;
    boolean longPressDetected = false;
    unsigned long previousMillis = 0;
    unsigned int longPressDebounceDelay = 250;
    unsigned int shortPressDebounceDelay = 50;
    boolean buttonPressed = HIGH; /* default pressed value is HIGH*/

    boolean buttonActive = false;
    boolean longPressActive = false;
    boolean oldPinStatus = LOW;
};

#endif /* DUALFUNCTIONBUTTON_H */

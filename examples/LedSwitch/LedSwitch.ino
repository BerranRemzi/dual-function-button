// Copyright 2020 Berran Remzi
/**
 * @file LedSwitch.ino
 * @brief Example program for two function with one button
 * @author Berran Remzi
 * @link https://github.com/BerranRemzi
 *
 * @date 13.05.2020
 */

#include "DualFunctionButton.h"

#define LED_EXTERNAL  (11)
#define BUTTON_PIN    (7)

DualFunctionButton button(BUTTON_PIN, 500, INPUT);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_EXTERNAL, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (button.shortPress()) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if (button.longPress()) {
    digitalWrite(LED_BUILTIN, LOW);
  }
  digitalWrite(LED_EXTERNAL, digitalRead(BUTTON_PIN));
}
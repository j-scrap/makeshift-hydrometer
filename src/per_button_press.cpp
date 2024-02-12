#include <Arduino.h>
#include "per_button_press.h"

// debounced check for wether the button was pushed
void button_setup() {
  pinMode(BUTTON_PIN, INPUT);
}

int pressed = LOW;
unsigned long debounceDelay = 75;
bool per_button_push(void *data) {
  Button_Last_Pressed lp = *(Button_Last_Pressed*)data;
  int pressedNow = digitalRead(BUTTON_PIN);
  if (pressedNow == lp.state) {
    return false;
  }
  if (pressedNow != lp.state) {
    unsigned long now = millis();
    if ((now - lp.time) > debounceDelay) {
      lp.time = now;
      lp.state = pressedNow;
      return (pressed == LOW);
    }
  }
  return false;
}

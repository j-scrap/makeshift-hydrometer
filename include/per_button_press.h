#ifndef PER_BUTTON_PRESS_H
#define PER_BUTTON_PRESS_H

const int BUTTON_PIN = 8;

typedef struct Button_Last_Pressed {
  unsigned long time;
  int state;
} Button_Last_Pressed;

void button_setup();
bool per_button_push(void *data);

#endif /* PER_BUTTON_PRESS_H */

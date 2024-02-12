#ifndef SCALE_H
#define SCALE_H

#include <Arduino.h>

const int LOADCELL_DOUT_PIN = 7;
const int LOADCELL_SCK_PIN = 6;

void scale_setup();
void scale_read(void *unused);
float scale_get_value();

#endif /* SCALE_H */

#ifndef THERMOMETER_H
#define THERMOMETER_H

const int THERMOMETER_PIN = 9;

void thermometer_setup();
void thermometer_read(void *unused);
float thermometer_get_value();

#endif /* THERMOMETER_H */

#include <Arduino.h>
#include "OneWire.h"
#include "DallasTemperature.h"

#include "thermometer.h"

OneWire ow(THERMOMETER_PIN);
DallasTemperature dt(&ow);
float thermometer_value = 0.0;

void thermometer_setup() {
  dt.begin();
}

void thermometer_read(void *unused) {
  Serial.print("Reading Thermometer...");
  dt.requestTemperatures();
  thermometer_value = dt.getTempCByIndex(0);
  Serial.println(" done");
}

float thermometer_get_value() {
  return thermometer_value;
}

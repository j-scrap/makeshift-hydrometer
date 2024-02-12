#include "HX711.h"
#include "scale.h"

HX711 scale;
float scale_value = 0.0;


void scale_setup() {
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_offset(-12532);
  scale.set_scale(471.197333333);
}

void scale_reset(void *unused) {
  Serial.print("Resetting scale...");
  scale.tare();
  Serial.println(" done");
}

void scale_read(void *unused) {
  Serial.print("Reading scale...");
  if (scale.is_ready()) {
    scale_value = scale.get_units(10);
  }
  Serial.println(" done");
}

float scale_get_value() {
  return scale_value;
}

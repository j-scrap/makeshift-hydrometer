#include "HX711.h"
#include "scale.h"

HX711 scale;
float scale_value = 0.0;


void scale_setup() {
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_offset(-12532);
  scale.set_scale(471.197333333);
  scale.tare();
}

void scale_read(void *unused) {
  if (scale.is_ready()) {
    scale_value = scale.get_units(10);
  }
}

float scale_get_value() {
  return scale_value;
}

#include <Arduino.h>
#include "per_milliseconds.h"

bool per_milliseconds(void *lt) {
  Per_Time_Data *ptd = (Per_Time_Data*)lt;
  unsigned long now = millis();
  
  // clock reset! (we were running for 50 days?!)
  if (now < ptd->last_time) {
    unsigned long max = (unsigned long) -1;
    return (max - ptd->last_time + now) > 1000;
  }
  else if ((ptd->last_time + ptd->interval) < now) {
    ptd->last_time = now;
    return true;
  }
  return false;
}

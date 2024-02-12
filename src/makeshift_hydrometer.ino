// Calibrating the load cell
#include <LiquidCrystal.h>

#include "eventsys.h"
#include "scale.h"
#include "thermometer.h"
#include "per_button_press.h"
#include "per_milliseconds.h"
#include "mh_lcd.h"

Event_Sys events;

// setup the button reset event
Button_Last_Pressed scale_reset_button_tracker = {
  .time = 0,
  .state = LOW
};
Trigger reset_scale_trigger = {
  .check = per_button_push,
  .data = &scale_reset_button_tracker
};
Action reset_scale_action = {
  .do_action = scale_reset,
  .data = NULL
};
Event reset_scale_button = {
  .trigger = reset_scale_trigger,
  .action = reset_scale_action
};

// setup the scale read event
Per_Time_Data scale_per_seconds_tracker = {
  .last_time = 0,
  .interval = 1000
};
Trigger read_scale_trigger = {
  .check = per_milliseconds,
  .data = &scale_per_seconds_tracker
};
Action read_scale_action = {
  .do_action = scale_read,
  .data = NULL
};
Event read_scale_per_milliseconds = {
  .trigger = read_scale_trigger,
  .action = read_scale_action
};

// setup the thermometer read event
Per_Time_Data thermometer_per_seconds_tracker = {
  .last_time = 0,
  .interval = 1000
};
Trigger read_thermometer_trigger = {
  .check = per_milliseconds,
  .data = &thermometer_per_seconds_tracker
};
Action read_thermometer_action = {
  .do_action = thermometer_read,
  .data = NULL
};
Event read_thermometer_per_milliseconds = {
  .trigger = read_thermometer_trigger,
  .action = read_thermometer_action
};

// setup the lcd display event
Per_Time_Data lcd_per_seconds_tracker = {
  .last_time = 0,
  .interval = 1000
};
Trigger update_lcd_trigger = {
  .check = per_milliseconds,
  .data = &lcd_per_seconds_tracker
};
Action update_lcd_action = {
  .do_action = mh_lcd_update,
  .data = NULL
};
Event update_lcd_per_milliseconds = {
  .trigger = update_lcd_trigger,
  .action = update_lcd_action
};

void setup() {
  Serial.begin(57600);
  init_event_sys(&events);
  scale_setup();
  add_event(&events, &read_scale_per_milliseconds);

  thermometer_setup();
  add_event(&events, &read_thermometer_per_milliseconds);
  
  button_setup();
  add_event(&events, &reset_scale_button);

  mh_lcd_setup();
  add_event(&events, &update_lcd_per_milliseconds);
}

long log_flag = 0;
void loop() {
  check_events(&events);
  /*
  if (millis() % 1000 == 0) {
    if (log_flag == 0) {
      log_flag = millis();
      say_hello_per_second.action();
      events.head_event->action();
      check_events(&events);
    }
  }
  else {
    log_flag = 0;
  }
  */
}

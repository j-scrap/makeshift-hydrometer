#include <Arduino.h>
#include <LiquidCrystal.h>
#include <floatToString.h>

#include "mh_lcd.h"
#include "scale.h"
#include "thermometer.h"

LiquidCrystal lcd(LCD_PIN_RS, LCD_PIN_ENABLE, LCD_PIN_D4, LCD_PIN_D5, LCD_PIN_D6, LCD_PIN_D7);

byte degrees[8] = {
  B00110,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000,
};

void mh_lcd_setup() {
  lcd.createChar(0, degrees);
  lcd.begin(16, 2);
}

void mh_lcd_update(void *unused) {
  lcd.clear();

  // display weight
  char weight_msg[16];
  char weight_str[10];
  float weight = scale_get_value();
  floatToString(weight, weight_str, sizeof(weight_str), 2);
  sprintf(weight_msg, "W: %sg", weight_str);
  lcd.setCursor(0, 0);
  lcd.print(weight_msg);

  // display temp
  char temp_msg[16];
  char temp_str[10];
  float temp = thermometer_get_value();
  floatToString(temp, temp_str, sizeof(temp_str), 2);
  sprintf(temp_msg, "T: %s", temp_str);
  lcd.setCursor(0, 1);
  lcd.print(temp_msg);
  lcd.write(byte(0));
  lcd.print("C");
}

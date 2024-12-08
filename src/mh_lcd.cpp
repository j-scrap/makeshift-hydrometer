#include <Arduino.h>
#include <LiquidCrystal.h>
#include <floatToString.h>

#include "mh_lcd.h"
#include "scale.h"
#include "thermometer.h"
#include "brix_calcs.h"

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
  lcd.begin(16, 2);
  lcd.createChar(0, degrees);
}

void mh_lcd_update(void *unused) {
  lcd.clear();

  // display weight & temp on line 1
  char weight_str[10];
  float weight = scale_get_value();
  floatToString(weight, weight_str, sizeof(weight_str), 0);

  char temp_str[10];
  float temp = thermometer_get_value();
  floatToString(temp, temp_str, sizeof(temp_str), 1);
  Serial.print("Temp: ");
  Serial.println(temp);

  char weight_temp_msg[16];
  sprintf(weight_temp_msg, "%sg %s", weight_str, temp_str);
  lcd.setCursor(0, 0);
  lcd.print(weight_temp_msg);
  lcd.write(byte(0));
  lcd.print("C");
  Serial.print("Weight Temp: ");
  Serial.println(weight_temp_msg);

  // display current brix and desired brix on line 2
  char curr_brix_str[10];
  float curr_brix = current_brix(temp, weight);
  floatToString(curr_brix, curr_brix_str, sizeof(curr_brix_str), 1);

  char target_brix_str[10];
  float target_brix = desired_brix(temp);
  floatToString(target_brix, target_brix_str, sizeof(target_brix_str), 1);

  lcd.setCursor(0, 1);
  lcd.print(curr_brix_str);
  lcd.write(byte(0));
  lcd.print("Bx/");
  lcd.print(target_brix_str);
  lcd.write(byte(0));
  lcd.print("Bx");
  Serial.print("Brix: ");
  Serial.print(curr_brix_str);
  Serial.print(" / ");
  Serial.println(target_brix_str);
}

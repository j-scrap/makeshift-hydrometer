#ifndef MH_LCD_H
#define MH_LCD_H


//LiquidCrystal(rs, enable, d4, d5, d6, d7)
const int LCD_PIN_RS = 12;
const int LCD_PIN_ENABLE = 11;
const int LCD_PIN_D4 = 5;
const int LCD_PIN_D5 = 4;
const int LCD_PIN_D6 = 3;
const int LCD_PIN_D7 = 2;

void mh_lcd_setup();
void mh_lcd_update(void *unused);

#endif /* MH_LCD_H */

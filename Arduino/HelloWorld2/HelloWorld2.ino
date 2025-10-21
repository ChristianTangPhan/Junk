#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Try 0x27 first; if your LCD doesn’t show text, change to 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();        // Initialize the LCD
  lcd.backlight();   // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
}

void loop() {
  // Nothing needed — text stays on screen
}

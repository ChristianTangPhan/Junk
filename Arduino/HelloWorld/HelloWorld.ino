#include <LiquidCrystal.h>
// VSS VDD RW A K Left Middle Right
// G   5   G  5 G 5    V0     G
// (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);       // Initialize 16x2 LCD
  lcd.print("Hello, World!"); // Print message on first line
}

void loop() {
  // Do nothing
}

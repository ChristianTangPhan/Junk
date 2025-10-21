#include <Keypad.h>

const int ROWS = 4;
const int COLS = 4;

char pad[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte row_pins[ROWS] = {8, 9, 10, 11};
byte col_pins[COLS] = {4, 5, 6, 7};

Keypad custom_keypad = Keypad(makeKeymap(pad), row_pins, col_pins, ROWS, COLS);

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  // Get key value if pressed
  char custom_key = custom_keypad.getKey();

  if (custom_key)
  {
    Serial.println(custom_key);
  }

  return;
}

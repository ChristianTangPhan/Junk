#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trig_pin = 12;
const int echo_pin = 13;
float distance;

#define i2c_slave_address 0x08

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Wire.begin(i2c_slave_address);
  Wire.onRequest(send_distance);
}

void loop()
{
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  distance = pulseIn(echo_pin, HIGH) * 0.0343 / 2;

  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance, 1);
  lcd.print("cm ");

  delay(500);
}

void send_distance()
{
  int d = distance * 10; // tenths of cm
  Wire.write((byte*)&d, sizeof(d));
}

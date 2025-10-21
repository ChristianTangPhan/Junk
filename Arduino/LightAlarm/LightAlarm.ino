#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
RTC_DS1307 rtc;

Servo my_servo;
const int servo_pin = 13;
const int button_pin = 8; // Manual test button

// Alarm time
const int ALARM_HOUR = 6;
const int ALARM_MINUTE = 40;

bool alarm_triggered = false;

void setup() 
{
  lcd.begin(16, 2);
  Wire.begin();

  my_servo.attach(servo_pin);
  my_servo.write(90); // Start at 90°

  pinMode(button_pin, INPUT_PULLUP); // Button connected to GND

  if (!rtc.begin()) 
  {
    lcd.print("RTC not found!");
    while (1);
  }

  //rtc.adjust(DateTime(2025,10,18,1,38,40)); // set time once
}

void loop() 
{
  DateTime now = rtc.now();

  // Display time
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  printTwoDigits(now.hour());
  lcd.print(":");
  printTwoDigits(now.minute());
  lcd.print(":");
  printTwoDigits(now.second());

  lcd.setCursor(0, 1);
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.day());
  lcd.print("/");
  lcd.print(now.year());

  // Alarm trigger
  if (now.hour() == ALARM_HOUR && now.minute() == ALARM_MINUTE && !alarm_triggered) 
  {
    move_servo_to_120();
    alarm_triggered = true;
  }

  // Reset alarm flag when minute changes
  if (now.minute() != ALARM_MINUTE) 
  {
    alarm_triggered = false;
  }

  // Manual button trigger
  if (digitalRead(button_pin) == LOW) 
  {
    move_servo_to_120();
    delay(500); // Simple debounce
  }

  delay(200); // Smooth LCD
}

// Move servo 90° → 120° → back to 90° (optional)
void move_servo_to_120() 
{
  my_servo.write(120);
  delay(500);      // hold 1 second
  my_servo.write(90); // return to 90°
}

void printTwoDigits(int number) 
{
  if (number < 10) lcd.print("0");
  lcd.print(number);
}

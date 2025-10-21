#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 7, 6, 5, 4);

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trig_pin = 10;
const int echo_pin = 11;
const int button_pin = 2;

// Variables for the duration and the distance
long duration;
int  distance;

bool show_distance    = true;  // Track what to display
bool last_button_state = HIGH;   // For edge detection

void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);    // Column 0, Row 0
  pinMode(trig_pin, OUTPUT); // Sets the trig_pin as an Output
  pinMode(echo_pin, INPUT); // Sets the echo_pin as an Input
  pinMode(button_pin, INPUT_PULLUP); // Use internal pull-up
  Serial.begin(9600);
}

void loop() 
{
  bool button_state = digitalRead(button_pin);
  distance = calculateDistance();

  if (distance < 15)
  {
    if (button_state == LOW) 
    {
      // Button is pressed → show Hello World
      lcd.setCursor(0, 0);
      processing();
      lcd.print("Gay"); // Extra spaces to clear old text
      delay(5000); // Small delay for readability
      lcd.setCursor(0, 1);
      lcd.print("                "); // Clear second row
    } 
    else 
    {
      lcd.setCursor(0, 0);
      processing();
      lcd.print("Normal"); // Extra spaces to clear old text
      delay(5000); // Small delay for readability
      lcd.setCursor(0, 1);
      lcd.print("                "); // Clear second row
    }
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("                "); // overwrite row
    lcd.setCursor(0,1);
    lcd.print("                "); // overwrite row
    lcd.setCursor(0, 0);
    lcd.print("---GAYDAR---"); // Extra spaces to clear old text
    lcd.setCursor(0, 1);
    lcd.print("                "); // Clear second row
  }

  delay(100); // Small delay for readability
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance()
{ 
  digitalWrite(trig_pin, LOW); 
  delayMicroseconds(2);

  // Sets the trig_pin on HIGH state for 10 micro seconds
  digitalWrite(trig_pin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  // Reads the echo_pin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo_pin, HIGH);

  // Calculate distance in cm (speed of sound = 0.034 cm/µs, divide by 2 for round trip)
  distance = duration * 0.034 / 2;

  return distance;
}

void processing()
{
  lcd.setCursor(0,0);
  lcd.print("                "); // overwrite row
  lcd.setCursor(0,1);
  lcd.print("                "); // overwrite row
  lcd.setCursor(0,0);
  lcd.print("Checking Vibes"); // Extra spaces to clear old text
  delay(5000); // Small delay for readability
  lcd.setCursor(0,0);
  lcd.print("                "); // overwrite row
  lcd.setCursor(0,1);
  lcd.print("                "); // overwrite row
  lcd.setCursor(0,0);

  return;
}
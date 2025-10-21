#include <IRremote.h>

int pin_number = 8;

// Motor pins
const int IN1 = 3;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 9;
const int ENA = 2;
const int ENB = 4;

// Direction button codes
const unsigned long FORWARD = 0xF609FD02;
const unsigned long BACK    = 0xFE01FD02;
const unsigned long LEFT    = 0xF50AFD02;
const unsigned long RIGHT   = 0xF708FD02;
const unsigned long LASER   = 0xF40BFD02;

const unsigned long TIMEOUT_MS = 100;  // ms to freeze if no signal

unsigned long last_direction    = 0;  // store last valid button
unsigned long last_signal_time  = 0;

void setup() 
{
  Serial.begin(9600);
  IrReceiver.begin(pin_number, ENABLE_LED_FEEDBACK);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 241);  // full speed
  analogWrite(ENB, 240);  // full speed
}

void loop() 
{
  if (IrReceiver.decode()) 
  {
    unsigned long direction = IrReceiver.decodedIRData.decodedRawData;

    // store last valid direction (ignore repeat 0)
    if (direction != 0) 
    {
      last_direction = direction;
    }

    last_signal_time = millis(); // update time on any signal
    IrReceiver.resume();
  }

  // Check TIMEOUT_MS: freeze if no signal for TIMEOUT_MS
  if (millis() - last_signal_time > TIMEOUT_MS) 
  {
    freeze();
    last_direction = 0;  // reset
  } 
  else
  {
    Serial.print("Direction received: ");
    Serial.println(last_direction, HEX);

    if      (last_direction == FORWARD) forward();
    else if (last_direction == BACK)    back();
    else if (last_direction == LEFT)    left();
    else if (last_direction == RIGHT)   right();
    else                                freeze();
  }
}

void freeze() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() 
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left() 
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

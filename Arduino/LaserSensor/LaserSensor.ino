const int ldr_pin = A5;       // LDR voltage divider
const int buzzer_pin = 2;     // buzzer
const int threshold = 350;    // adjust based on your laser brightness

void setup() 
{
  pinMode(buzzer_pin, OUTPUT);
  Serial.begin(9800);
}

void loop() 
{
  int ldr_value = analogRead(ldr_pin);
  Serial.println(ldr_value);  // see readings

  if (ldr_value < threshold) // laser hitting LDR
    digitalWrite(buzzer_pin, HIGH);  // turn on buzzer
  else 
    digitalWrite(buzzer_pin, LOW);   // turn off buzzer

  delay(50);
}

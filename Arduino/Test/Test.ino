#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/sin2048_int8.h>  // sine wave table

// --------------------
// Pins
// --------------------
const int speaker_pin     = A0;
const int buzzer_pin      = A1;
const int megalovania_pin = 2;
const int rickroll_pin    = 3;
const int bday_pin        = 4;
const int clash_pin       = 5;
const int royal_pin       = 6;

// --------------------
// Notes (C1–C6 + rests)
// --------------------
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62

#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123

#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247

#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494

#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 830
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988

#define NOTE_C6 1047
#define REST 0

// --------------------
// Notes in Hz
// --------------------
#define NOTE_C3 131
#define NOTE_AS3 233
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_F4 349
#define NOTE_E4 330
#define NOTE_G2 98
#define NOTE_G4 392
#define REST 0

// --------------------
// Melody arrays
// --------------------
int   clash_melody[] = {NOTE_C3,  REST,    NOTE_AS3, REST,    NOTE_C4,  REST,     NOTE_D4,  REST, 
                        NOTE_C3,  REST,    NOTE_AS3, REST,    NOTE_C4,  REST,     NOTE_D4,  REST, 
                        NOTE_C3,  REST,    NOTE_G2,  REST,    NOTE_C3,  REST,      
                        NOTE_AS3, REST,    NOTE_C4,  REST,    NOTE_D4,  REST,     NOTE_F4,  REST,     NOTE_E4, REST,    NOTE_G4, REST};
float clash_length[] = {1.5,      0.5,     0.75,     0.25,    0.75,     0.25,     1.5,      0.5,     
                        1.5,      0.5,     0.75,     0.25,    0.75,     0.25,     1.5,      0.5,
                        1.5,      0.5,     1.5,      0.5,     1.5,      0.5,          
                        0.75,     0.25,    0.75,     0.25,    1.5,      0.5,      1.5,      0.5,      3,       1,       3,       1};
 
int   royal_melody[] = {NOTE_D3, NOTE_F3, NOTE_E3, NOTE_C3, NOTE_D3, NOTE_AS2, NOTE_C3, NOTE_G3};
float royal_length[] = {2, 2, 2, 2, 2, 2, 2, 2};

// --------------------
// Oscillators
// --------------------
Oscil<SIN2048_NUM_CELLS, AUDIO_RATE> osc1(SIN2048_DATA); // clash
Oscil<SIN2048_NUM_CELLS, AUDIO_RATE> osc2(SIN2048_DATA); // royal

// --------------------
// Timing
// --------------------
int clash_index = 0;
int royal_index = 0;
unsigned long clash_timer = 0;
unsigned long royal_timer = 0;

void setup()
{
  startMozzi();
}

void updateControl() {
  unsigned long now = mozziMicros();

  // Clash note timing
  int clash_beat = clash_length[clash_index] * 500; // adjust speed
  if (now - clash_timer >= clash_beat * 1000) {
    clash_index = (clash_index + 1) % (sizeof(clash_melody) / sizeof(int));
    if (clash_melody[clash_index] == REST)
      osc1.setFreq(0);
    else
      osc1.setFreq(clash_melody[clash_index]);
    clash_timer = now;
  }

  // Royal note timing
  int royal_beat = royal_length[royal_index] * 500;
  if (now - royal_timer >= royal_beat * 1000) {
    royal_index = (royal_index + 1) % (sizeof(royal_melody) / sizeof(int));
    if (royal_melody[royal_index] == REST)
      osc2.setFreq(0);
    else
      osc2.setFreq(royal_melody[royal_index]);
    royal_timer = now;
  }
}

int updateAudio() {
  int8_t sample = (osc1.next() + osc2.next()) / 2; // mix both oscillators
  return sample;
}

void loop() {
  audioHook();
}

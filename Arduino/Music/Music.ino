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
// Scale constants
// --------------------
int   scale_melody[] = {NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3};
float scale_length[] = {1,       1,       1,       1,       1      };

// --------------------
// Megalovania Scale
// --------------------
int   mscale_melody[] = {NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_CS5};
float mscale_length[] = {1,       1,       1,        1,       1,       1,       1};

// --------------------
// Never Ganna Give You Up Scale
// --------------------
int   rscale_melody[] = {NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3};
float rscale_length[] = {1,       1,       1,       1,       1,       1,       1};

// --------------------
// Megalovania snippet
// --------------------
int   megalovania_melody[] = {NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4};
float megalovania_length[] = {0.5,     0.5,     1,       1.5,     1,       1,       1,       0.5,     0.5,     0.5};

// --------------------
// Never Ganna Give You Up snippet
// --------------------
int   rickroll_melody[] = {NOTE_CS4, NOTE_DS4, NOTE_GS3, NOTE_DS4, NOTE_F4,  NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_DS4,
                           NOTE_CS4, NOTE_DS4, NOTE_GS3, NOTE_GS3, NOTE_GS4, NOTE_FS4, NOTE_F4,  NOTE_DS4/*,
                           NOTE_CS4, NOTE_DS4, NOTE_GS3, NOTE_DS4, NOTE_F4,  NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_DS4,
                           NOTE_CS4, NOTE_DS4, NOTE_GS3*/};
float rickroll_length[] = {2.5,      2.4,      1.6,      2.5,      2.4,        0.4,      0.4,    0.4,     0.4,
                           2.5,      2.3,      5.5,      0.7,      0.4,        0.4,      0.4,    0.4/*,
                           2.5,      2.4,      1.6,      2.5,      2.4,        0.4,      0.4,    0.4,     0.4,
                           2.5,      2.3,      7.5*/};

// --------------------
// Happy Birthday Song
// --------------------
int   bday_melody[] = {NOTE_C3,  NOTE_C3,  NOTE_D3, NOTE_C3, NOTE_F3, NOTE_E3, 
                       NOTE_C3,  NOTE_C3,  NOTE_D3, NOTE_C3, NOTE_G3, NOTE_F3, 
                       NOTE_C3,  NOTE_C3,  NOTE_C4, NOTE_A3, NOTE_F3, NOTE_E3, NOTE_D3,
                       NOTE_AS3, NOTE_AS3, NOTE_A3, NOTE_F3, NOTE_G3, NOTE_F3};
float bday_length[] = {0.5,      0.5,      1,       1,       1,       2,       
                       0.5,      0.5,      1,       1,       1,       2,       
                       0.5,      0.5,      1,       1,       1,       1,       2,       
                       0.5,      0.5,      1,       1,       1,       2};

// --------------------
// Clash Royale
// --------------------
int   clash_melody[] = {NOTE_C3,  REST,    NOTE_AS3, REST,    NOTE_C4,  REST,     NOTE_D4,  REST, 
                        NOTE_C3,  REST,    NOTE_AS3, REST,    NOTE_C4,  REST,     NOTE_D4,  REST, 
                        NOTE_C3,  REST,    NOTE_G2,  REST,    NOTE_C3,  REST,      
                        NOTE_AS3, REST,    NOTE_C4,  REST,    NOTE_D4,  REST,     NOTE_F4,  REST,     NOTE_E4, REST,    NOTE_G4, REST};
float clash_length[] = {1.5,      0.5,     0.75,     0.25,    0.75,     0.25,     1.5,      0.5,     
                        1.5,      0.5,     0.75,     0.25,    0.75,     0.25,     1.5,      0.5,
                        1.5,      0.5,     1.5,      0.5,     1.5,      0.5,          
                        0.75,     0.25,    0.75,     0.25,    1.5,      0.5,      1.5,      0.5,      3,       1,       3,       1};
 
int   royal_melody[] = {NOTE_D3,  NOTE_D3, NOTE_D3,  NOTE_D3, NOTE_D3,  NOTE_D3,  NOTE_F3,  NOTE_F3, 
                        NOTE_F3,  NOTE_F3, NOTE_E3,  NOTE_E3, NOTE_E3,  NOTE_E3,  NOTE_E3,  NOTE_E3, 
                        NOTE_C3,  NOTE_C3, NOTE_C3,  NOTE_C3, NOTE_D3,  NOTE_D3,
                        NOTE_D3,  NOTE_D3, NOTE_D3,  NOTE_D3, NOTE_AS2, NOTE_AS2, NOTE_AS2, NOTE_AS2, NOTE_C3, NOTE_C3, NOTE_G3, NOTE_G3};

// --------------------
// Setup
// --------------------
void setup()
{
  pinMode(megalovania_pin, INPUT_PULLUP);
  pinMode(rickroll_pin, INPUT_PULLUP);
  pinMode(bday_pin, INPUT_PULLUP);
  pinMode(clash_pin, INPUT_PULLUP);
  pinMode(royal_pin, INPUT_PULLUP);
  pinMode(speaker_pin, OUTPUT);
  Serial.begin(9800);
}

// --------------------
// Loop
// --------------------
void loop()
{
    if (digitalRead(megalovania_pin) == LOW)
    {
        play_megalovania();

        // Wait for button release before allowing replay
        while (digitalRead(megalovania_pin) == LOW)
            delay(10);
    }

    if (digitalRead(rickroll_pin) == LOW)
    {
        play_rickroll();

        // Wait for button release before allowing replay
        while (digitalRead(rickroll_pin) == LOW)
            delay(10);
    }

    if (digitalRead(bday_pin) == LOW)
    {
        play_bday();

        // Wait for button release before allowing replay
        while (digitalRead(bday_pin) == LOW)
            delay(10);
    }
    
    if (digitalRead(clash_pin) == LOW)
    {
        play_clash();

        // Wait for button release before allowing replay
        while (digitalRead(clash_pin) == LOW)
            delay(10);
    }
    
    if (digitalRead(royal_pin) == LOW)
    {
        play_clash();

        // Wait for button release before allowing replay
        while (digitalRead(royal_pin) == LOW)
            delay(10);
    }
}

// --------------------
// Functions
// --------------------
void play_cscale()
{
    float bpm = 30000.0 / 60;

    for (int i = 0; i < sizeof(scale_melody) / sizeof(int); i++)
    {
        int beat = bpm * scale_length[i];

        if (scale_melody[i] == REST)
            delay(beat);
        else
        {
            tone(speaker_pin, scale_melody[i], beat);
            delay(beat * 1.05);
        }
    }
}

void play_mscale()
{
    float bpm = 30000.0 / 60;

    for (int i = 0; i < sizeof(mscale_melody) / sizeof(int); i++)
    {
        int beat = bpm * mscale_length[i];

        if (mscale_melody[i] == REST)
            delay(beat);
        else
        {
            tone(speaker_pin, mscale_melody[i], beat);
            delay(beat * 1.05);
        }
    }
}

void play_rscale()
{
    float bpm = 30000.0 / 60;

    for (int i = 0; i < sizeof(mscale_melody) / sizeof(int); i++)
    {
        int beat = bpm * rscale_length[i];

        if (rscale_melody[i] == REST)
            delay(beat);
        else
        {
            tone(speaker_pin, rscale_melody[i], beat);
            delay(beat * 1.05);
        }
    }
}

void play_megalovania()
{
    float bpm = 30000.0 / 150; // change bmp

    play_mscale(); 

    for (int i = 0; i < sizeof(megalovania_melody) / sizeof(int); i++)
    {
        int beat = bpm * megalovania_length[i];

        if (megalovania_melody[i] == REST)
            delay(beat);
        else
        {
            tone(speaker_pin, megalovania_melody[i], beat);
            delay(beat * 1.05);
        }
    }
}

void play_rickroll()
{
    float bpm = 30000.0 / 90; // change bmp

    play_rscale(); 

    for (int i = 0; i < sizeof(rickroll_melody) / sizeof(int); i++)
    {
        int beat = bpm * rickroll_length[i];

        if (rickroll_melody[i] == REST)
            delay(beat);
        else
        {
            tone(speaker_pin, rickroll_melody[i], beat);
            delay(beat * 1.05);
        }
    }
}

void play_bday()
{
    float bpm = 30000.0 / 80; // change bmp

    for (int i = 0; i < sizeof(bday_melody) / sizeof(int); i++)
    {
        int beat = bpm * bday_length[i];

        if (bday_melody[i] == REST)
            delay(beat);
        else
        {
            tone(speaker_pin, bday_melody[i], beat);
            delay(beat * 1.05);
        }
    }
}

void play_clash()
{
    float bpm = 30000.0 / 145; // change bmp

    for (int i = 0; i < sizeof(clash_melody) / sizeof(int); i++)
    {
        int beat = bpm * clash_length[i];

        if (clash_melody[i] == REST)
            delay(beat);
        else
        {
            tone(speaker_pin, clash_melody[i], beat);
            delay(beat * 1.05);
        }
    }
}

void play_royal()
{
    float bpm = 30000.0 / 145; // change bmp

    for (int i = 0; i < sizeof(royal_melody) / sizeof(int); i++)
    {
        int beat = bpm * clash_length[i];

        if (royal_melody[i] == REST)
            delay(beat);
        else
        {
            tone(buzzer_pin,  royal_melody[i], beat);
            delay(beat * 1.05);
        }
    }
}

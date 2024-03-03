#include <Encoder.h>

#define EN_A 2
#define EN_B 7

Encoder Enc(EN_A, EN_B);

long previousMillis = 0;
long currentMillis = 0;

volatile long currentEncoder;
volatile long previousEncoder = 0;
volatile long oldPosition = 0;
volatile long newPosition;
volatile long diff;

long positionMain  = -999;
float old_rot_speed=0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600); //Set the band rate to your Bluetooth module.
  pinMode(EN_A, INPUT_PULLUP);
  pinMode(EN_B,  INPUT_PULLUP); 
  Serial.println("TwoKnobs Encoder Test:");
}

float read_speed(void)
{
    //read velocity of selected motor
    //return velocity in rad/s
    const int Encoder_1_round = 4000; //define number of pulses in one round of encoder
    currentEncoder = Enc.read();
    diff=currentEncoder-previousEncoder;
    
    float rot_speed;           //rotating speed in rad/s
    const int interval = 1000; //choose interval is 1 second (1000 milliseconds)
    currentMillis = millis();

    if (currentMillis - previousMillis > interval)
    {
        previousMillis = currentMillis;
        rot_speed = (float)(diff*60/ (Encoder_1_round));
        previousEncoder = currentEncoder;
        return rot_speed;
    }
}

void loop() {
float new_rot_speed;
new_rot_speed=read_speed();
if (new_rot_speed != old_rot_speed) {
Serial.print("Speed = ");
Serial.print(new_rot_speed);
Serial.println();
old_rot_speed = new_rot_speed;
}
}

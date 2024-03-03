#include <Encoder.h>

// Define the pins for the rotary encoder
#define EN_A 2
#define EN_B 7

// Create an Encoder object
Encoder Enc(EN_A, EN_B);

// Variables for time and encoder position tracking
long previousMillis = 0;
long currentMillis = 0;
volatile long currentEncoder;
volatile long previousEncoder = 0;
volatile long diff;

// Variables for main position and rotational speed tracking
long positionMain  = -999;
float old_rot_speed = 0;

void setup() 
{
  // Initialize serial communication and set up pins
  Serial.begin(9600); // Set the baud rate for communication
  pinMode(EN_A, INPUT_PULLUP);
  pinMode(EN_B, INPUT_PULLUP); 
  Serial.println("TwoKnobs Encoder Test:");
}

float read_speed(void)
{
    // Read the velocity of the selected motor
    // Return velocity in rad/s
    const int Encoder_1_round = 4000; // Define the number of pulses in one round of the encoder
    currentEncoder = Enc.read();
    diff = currentEncoder - previousEncoder;
    
    float rot_speed;           // Rotating speed in rad/s
    const int interval = 1000; // Choose the interval as 1 second (1000 milliseconds)
    currentMillis = millis();

    if (currentMillis - previousMillis > interval)
    {
        previousMillis = currentMillis;
        rot_speed = (float)(diff * 60 / (Encoder_1_round));
        previousEncoder = currentEncoder;
        return rot_speed;
    }
}

void loop() 
{
    float new_rot_speed;
    new_rot_speed = read_speed();
    
    // Print the speed if it has changed
    if (new_rot_speed != old_rot_speed) {
        Serial.print("Speed = ");
        Serial.print(new_rot_speed);
        Serial.println();
        old_rot_speed = new_rot_speed;
    }
}

// Define the trig and echo pins for three ultrasonic sensors
const int trigPin1 = 15;
const int echoPin1 = 14;
const int trigPin2 = 13;
const int echoPin2 = 11;
const int trigPin3 = 18;
const int echoPin3 = 19;

// Define the motor driver input pins
const int in1 = 5;
const int in2 = 6;
const int in3 = 9;
const int in4 = 10;

void setup() 
{
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Set the ultrasonic sensor pins as output and input
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);  
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  // Set the motor driver input pins as output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

// Variables to store ultrasonic sensor readings
long duration1, distance1;
long duration2, distance2;
long duration3, distance3;

void loop()
{     
  // Measure distance using the first ultrasonic sensor
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);  
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 / 58.2;
  Serial.println("Distance 1");
  Serial.println(distance1);

  // Measure distance using the second ultrasonic sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);  
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 / 58.2;
  Serial.println("distance 2");
  Serial.println(distance2);

  // Measure distance using the third ultrasonic sensor
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);  
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 / 58.2;
  Serial.println("Distance 3");
  Serial.println(distance3);

  // Autonomous movement algorithm based on distance readings
  if (distance1 > 45)
  {
    // Move forward with a specific motor configuration
    analogWrite(in1, 0); 
    analogWrite(in2, 130); 
    analogWrite(in3, 0); 
    analogWrite(in4, 130); 
    
    // Obstacle avoidance based on distance readings from other sensors
    if (distance2 < 20 || distance3 < 20)
    {
      if (distance2 < 20 && distance3 < 20)
      {
        // Stop if obstacles are detected on both sides
        analogWrite(in1, 0); 
        analogWrite(in2, 130); 
        analogWrite(in3, 0); 
        analogWrite(in4, 130); 
      } 
      else if (distance2 > distance3)
      {
        // Adjust motor speed if obstacle is closer on the right
        analogWrite(in1, 0); 
        analogWrite(in2, 255 - (distance2 - distance3) * 3); 
        analogWrite(in3, 255 - (distance2 - distance3) * 3); 
        analogWrite(in4, 0);    
      }
      else if (distance3 > distance2)
      {
        // Adjust motor speed if obstacle is closer on the left
        analogWrite(in1, 255 - (distance3 - distance2) * 3); 
        analogWrite(in2, 0); 
        analogWrite(in3, 0); 
        analogWrite(in4, 255 - (distance3 - distance2) * 3);
      }
    }
  }
  else
  {
    // Stop and adjust motor speed based on obstacle distances
    if (distance2 > distance3)
    {
      analogWrite(in1, 0); 
      analogWrite(in2, 150); 
      analogWrite(in3, 150); 
      analogWrite(in4, 0);    
    }
    else if (distance3 > distance2)
    {
      analogWrite(in1, 150); 
      analogWrite(in2, 0); 
      analogWrite(in3, 0); 
      analogWrite(in4, 150);
    }
  }
}

// Function to measure distance using the second ultrasonic sensor
void right_hc()
{
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);  
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 / 58.2;
}

// Function to measure distance using the third ultrasonic sensor
void left_hc()
{
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);  
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 / 58.2;
}

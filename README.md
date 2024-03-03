# Autonomous_Mapping_Vehicle
**Autonomous Mapping Vehicle with Distance Measurement**

This GitHub repository contains the code for an autonomous mapping vehicle designed to navigate its environment intelligently while measuring distances using an encoder. The project utilizes an Arduino Uno board and ultrasonic sensors (HCSR04) for obstacle detection.

### Key Components:

- **Ultrasonic Sensors:**
  - Three ultrasonic sensors are employed for comprehensive environmental mapping.
  - Connected to the Arduino Uno board through trig and echo pins (trigPin1, echoPin1, trigPin2, echoPin2, trigPin3, echoPin3).

- **Motor Control:**
  - Motor control is achieved through the L293D motor driver, with pins defined as in1, in2, in3, and in4.
  - The autonomous movement algorithm adjusts motor speeds based on sensor readings for obstacle avoidance.

- **Encoder SH38F8:**
  - The encoder SH38F8 is utilized to measure the distance traveled by the vehicle.
  - Connected to the vehicle's chassis, it provides accurate distance measurements for mapping.

### Autonomous Movement Algorithm:

The vehicle's autonomous movement is governed by a PID-based algorithm implemented in the Arduino sketch. The algorithm reads sensor data from the ultrasonic sensors, calculates distances, and adjusts the motor speeds to navigate and avoid obstacles effectively.

### Usage:

1. Connect the ultrasonic sensors and motor control pins to the specified ports on the Arduino Uno board.
2. Upload the provided Arduino sketch to the board.
3. Power up the vehicle and observe its autonomous navigation and distance measurement capabilities.

### Functions:

- `loop()`: Implements the core autonomous movement algorithm based on ultrasonic sensor readings.
- `right_hc()`, `left_hc()`: Helper functions for obtaining right and left distance measurements, respectively.

### Notes:

- Ensure proper wiring of the ultrasonic sensors, motor control, and encoder for accurate functionality.
- Adjust PID constants and sensor thresholds in the algorithm to suit specific environmental conditions.

### Contributing:

Feel free to contribute to the project by suggesting improvements, optimizations, or additional features. Create a pull request with a detailed description of the proposed changes.

**#AutonomousVehicles #Robotics #Arduino #PIDControl #OpenSource**

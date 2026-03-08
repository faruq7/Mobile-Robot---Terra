Objective:
To develop a mobile robot that is capable of reliable motion control, obstacle detection, and basic autonomous manoeuvres.

Mechanical & System Design:
•	Designed and modelled full chassis assembly in CAD using Onshape, including the motors, mounts, and incorporating techniques like clearance and interference checks to ensure ease of production and efficient assembly. 
•	Mechanical components were 3D printed and the electronics researched and then sourced.
•	Integrated dual DC motors with encoders for feedback-based motion control.
•	Utilised ultrasonic sensors for obstacle detection.
•	Developed program using the Arduino IDE.

Motion Control & Behaviour:
The robot was programmed using state machine logic to manage driving states which included:
•	Forward
•	Reverse
•	Left / Right turns
•	Three-point turn manoeuvre

Main Problem Encountered:
The robot had a slight drift to the left when doing standard forward motion. This highlighted there was unequal motor revolutions despite the motors possessing the same gear difference and drive commands.
Solution
The Encoder difference was then logged to an SD card during the forward motion. The data highlighted a substantial difference with the motor revolutions, confirming the imbalance of velocity between motors.
Proportional (P) control was then implemented with the aim of reducing the velocity difference between motors based on the encoder feedback.

Outcome
The forward motion drift had reduced slightly, although small cumulative error remains as on P control was implemented. Integral control will be added to compensate for the accumulated drift over longer distances.

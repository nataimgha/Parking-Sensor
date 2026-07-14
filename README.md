# Parking-Sensor
Parking Sensor for toy cars that emits green or red LED based on distance detected, and outputs a hazard beep if too close.



https://github.com/user-attachments/assets/713b8abc-7a61-4797-9ba3-7ee7b0923bc2


Components used: 1 Arduino Uno, 1 breadboard, 1 HC-SR04 Ultrasonic sensor, 1 green LED, 1 Red LED, 1 active buzzer, 2 220 Ohm resistors, jumper wires


The sensors continuously fires a sonic pulse and calculates distance in centimeters based on duration and speed of sound
Store distance in a variable, and use two conditionals one to output a Red LED to stop if distance is close and safe, and another
to output both the RED LED and the beeping buzzer, if distance is hazardous. IF distance is too far, else green LED

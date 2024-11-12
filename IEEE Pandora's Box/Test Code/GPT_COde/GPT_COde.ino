#include <Servo.h> 

// Sensor and Servo Pins
const int FSen = A4;
int servoPin = 11; 
Servo Servo1; 

// Motor A connections
int enA = 5;
int in1 = 7;
int in2 = 8;

// Motor B connections
int enB = 6;
int in3 = 9;
int in4 = A3;

void setup() {
  Serial.begin(115200);
  pinMode(FSen, INPUT);
  Serial.println("Hey!");
  Servo1.attach(servoPin);
  
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Initialize motor state as off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  int analogReading = analogRead(FSen);
  delay(500);
  Serial.print("Force sensor reading = ");
  Serial.println(analogReading);
  
  // Condition to activate the motor
  if(analogReading >= 20) {
    Serial.println("Activating servo and motor...");
    Servo1.write(130); 
    delay(1000); 

    // Set motors to maximum speed
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    
    // Set motor direction (example: forward)
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    // Keep the motor running for a while (1 second here)
    delay(1000); // Adjust duration as needed
    
    // Stop the motor after running
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    // Reset servo
    Servo1.write(0);
  }
}

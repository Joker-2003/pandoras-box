//1. 5V and GND for relay A1 and A2 connect 
const int FSen = A4;
#include <Servo.h> 
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
pinMode(12,OUTPUT);
digitalWrite(12, LOW);
pinMode(A2, OUTPUT);
digitalWrite(A2, LOW);
pinMode(A1, OUTPUT);
digitalWrite(A1, LOW);
// Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }

void loop()
{

  int n = 0;
  int analogReading = analogRead(FSen);
  delay(500);
  Serial.print("Force sensor reading = ");
   Serial.println(analogReading);
  
 if(analogReading>=20)
{
 Serial.println("Success ");


Servo1.write(130); 
   delay(1000); 



n =1;
}

while(n==1)
{
Serial.println("BOOM");
delay(1000); 
digitalWrite(12, HIGH);
// Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
digitalWrite(A2, HIGH);
digitalWrite(A1, HIGH);
}

}


const int FSen = A4;
#include <Servo.h> 
int servoPin = 11; 
Servo Servo1; 
void setup() {
  Serial.begin(115200);
  pinMode(FSen, INPUT);
Serial.println("Hey!");
Servo1.attach(servoPin);
pinMode(12,OUTPUT);
digitalWrite(12, LOW);
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
}

}

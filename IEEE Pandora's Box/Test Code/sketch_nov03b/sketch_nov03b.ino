void setup() {
  // put your setup code here, to run once:
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(A1,130);
analogWrite(A2,0);
delay(10000);
analogWrite(A1,0);
analogWrite(A1,0);
delay(10000);
analogWrite(A1,0);
analogWrite(A2,130);
delay(10000);
}

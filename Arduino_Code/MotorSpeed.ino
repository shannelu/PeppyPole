int motorPin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motorPin, LOW);
  delay(2000);
  analogWrite(motorPin, 255);
  delay(2000);
}                                                                              

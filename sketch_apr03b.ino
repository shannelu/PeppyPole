int motorPin_1 = 5;
int motorPin_2 = 3;
float InputNum[] = {0, 0};
void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin_1, OUTPUT);
  pinMode(motorPin_2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available() > 0){
//    delay(400);
    InputNum[0] = Serial.parseFloat();
    InputNum[1] = Serial.parseFloat();
    while (Serial.available() > 0){
      Serial.read();
    }
//    when pole is tired:
    if (InputNum[1] == 1){
       for (int i = 0; i < 3; i++){
        analogWrite(motorPin_1, 40);
        delay(300);
        analogWrite(motorPin_1, 255);
        delay(500);
        analogWrite(motorPin_2, 0);
        delay(100);
        digitalWrite(motorPin_2, 255);
        delay(100);
      }
    }
    else    //when pole is happy
    if (InputNum[1] == 2){
      for (int i = 0; i < 3; i++){
        analogWrite(motorPin_1, 0);
        delay(2000);
        analogWrite(motorPin_1, 255);
        delay(1000);
      }
    }
    else  // when hiker is tired
    if (InputNum[0] == 1){
      for (int i = 0; i < 3; i++){
        analogWrite(motorPin_2, 0);
        delay(100);
        digitalWrite(motorPin_2, 255);
        delay(500);
      }
    }
    else // when hiker is happy
    if (InputNum[0] == 2){
      for (int i = 0; i < 2; i++){
        analogWrite(motorPin_2, 255);
        analogWrite(motorPin_1, 0);
        delay(1000);
        analogWrite(motorPin_1, 255);
        delay(500);
      }
    }
    else  // when hiker is neutral
    if (InputNum[0] == 3){
        analogWrite(motorPin_1, 255);
        analogWrite(motorPin_2, 255);
        delay(500);
    }
    else  // when pole is neutral
    if (InputNum[1] == 3){
        analogWrite(motorPin_1, 255);
        analogWrite(motorPin_2, 255);
        delay(500);
    }
    else  // when pole is bored after a while
    if (InputNum[1] == 4){
        analogWrite(motorPin_1, 0);
        delay(1000);
        analogWrite(motorPin_1, 255);
        delay(500);
        analogWrite(motorPin_1, 0);
        delay(500);
        analogWrite(motorPin_1, 255);
        delay(500);
    }
//    delay(5000);
  }
  else{
       analogWrite(motorPin_1, 255);
       analogWrite(motorPin_2, 255);
  }
}

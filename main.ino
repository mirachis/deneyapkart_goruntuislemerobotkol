#include <Deneyap_Servo.h>

Servo servoX;
Servo servoY;
Servo servoA;
Servo servoKol;

void setup() {
  Serial.begin(115200);
  servoX.attach(D9); 
  servoY.attach(D1);
  servoA.attach(D0);
  servoKol.attach(D8);
}
void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    int commaIndex = data.indexOf(',');
    int commaIndex2 = data.indexOf(',', commaIndex + 1);
    if (commaIndex != -1) {

      int servoXdeger = data.substring(0, commaIndex).toInt();
      int servoYdeger = data.substring(commaIndex + 1).toInt();
      int parmak_aciklik = data.substring(commaIndex2 + 1).toInt(); 

      int servoXaci = map(servoXdeger, 0, 180, 0, 180);
      int servoYaci = map(servoYdeger, 0,180, 360, 0);
      int servoAaci = map(servoYdeger, 0,180, 180, 0);
     
      if(parmak_aciklik==1)
      {
        servoKol.write(180);
      }else if(parmak_aciklik==0)
      {
        servoKol.write(0);
      }
      servoX.write(servoXaci);
      servoY.write(servoYaci);
      servoA.write(servoAaci);
    }
  }
}

// Link no TinkerCad: https://www.tinkercad.com/things/h4uqnZMsKx0
#include <Servo.h>
Servo MeuServo;	

int angulo = 90;

void setup()
{
  MeuServo.attach(13); // Servo no pino 13
  Serial.begin(9600);
  MeuServo.write(90);
  delay(1000);
}

void loop()
{
  int ldr1 = analogRead(A0);
  int ldr2 = analogRead(A1);
  ldr1 = map(ldr1,49,969,0,180);
  ldr2 = map(ldr2,49,969,0,180);
  int dif = ldr1 - ldr2;
  if(dif > 0){
    angulo += 10;
    MeuServo.write(angulo);
    if (angulo > 180) angulo = 180;
  }
  else if (dif < 0){
    angulo -= 10;
    MeuServo.write(angulo);
    if (angulo <= 0) angulo = 0;
  }
  else if (dif < 10 && dif > -10){
    if (angulo > 90){
      angulo -= 10;
      MeuServo.write(angulo);
    }
    else if (angulo < 90) {
      angulo += 10;
      MeuServo.write(angulo);
    }
    else if (angulo = 90) {
      angulo = 90;
      MeuServo.write(angulo);
    }
  }
  
  Serial.print("dif: ");
  Serial.println(dif);
  Serial.print ("angulo: ");
  Serial.println(angulo);
  //MeuServo.write(ldr1);
  delay(1000); 
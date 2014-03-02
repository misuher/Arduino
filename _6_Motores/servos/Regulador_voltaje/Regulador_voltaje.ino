/*  
  servo = pin 9

*/
#include<Servo.h>

const int servoPin = 9;

void setup(){
  Servo miServo; //crea un objeto tipo Servo
  miServo.attach(servoPin); //linka el pin al objeto creado

}

void loop(){
  //1.Giramo el servo de 0 a 180 en intervalos de 20 cada segundo
  for(int i=0;i<=180; i=i+20){
    miServo.write(i);
    delay(1000);
  }
  
  //Un buen ejemplo es mapear valores analogicos a 0-180 para controlar el servo
}

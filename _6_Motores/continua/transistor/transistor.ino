/*
Los motores de continua son los que giran al recibi una señal de voltaje continua
Cuanto mayor es el voltaje mayor la velocidad

También se puede usar PWD para variar la velocidad de giro, pero la velocidad máxima
vendrá determinado por el voltaje máximo

Los motores consumen mucho y pueden dañar la electrónica, por eso se aislan
los circuitos a dos voltajes diferentes con el uso de un transistor

Vamos a hacer un programa que lo acelere y los desacelere

  transistor -> pin 11
*/

const int motor = 11;

void setup(){
  pinMode(motor, OUTPUT);
}

void loop(){
  //acelera de 0 a 255
  for(int i=0; i<=255; i++){
    analogWrite(motor, i);
    delay(10);
  }
  //mantemos la velocidad
  delay(500);
  //deasceleramos de 255 a 0
  for(int i=255; i>=0; i--){
    analogWrite(motor, i);
    delay(10);
  }
  //mantenemos velocidad
  delay(500);
}

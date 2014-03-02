/*
   SDA = A5;
   SCL = A4;
*/
#include<Wire.h>

const int Slave_address = 72;

void setup(){
  Serial.begin(9600);
  Wire.begin();
}

void loop(){
  //Master solicita hablar con 72
  Wire.beginTransmission(Slave_address);
  //master pide registro 0
  Wire.send(0);
  // transmision completada de master
  Wire.endTransmission();
  //Pide 1 byte
  Wire.requestFrom(Slave_address, 1);
  //Espera respuesta
  while(Wire.available()== 0); 
  //almacenamos lo que le llega
  int temp = Wire.receive();
  
  Serial.print(temp);
  Serial.println(ºC);
  delay(1000);
}

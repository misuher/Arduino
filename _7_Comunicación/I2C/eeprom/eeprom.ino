/*
Programa para ilustrar como escribir en un IC de EEPROM, en concreto
el 24CL256 por I2C
*/

#include <Wire.h>

#define ADDRESS 0x50 //dirección del chip

void setup(){
 Serial.begin(9600);
 Wire.begin(); //como arduino es master no recive argumentos
 eepromWrite(0, 0, 125); //escribe 125 en la dirección 00
 Serial.println(eepromRead(0, 0)); //deberia devolver 125
}

void eepromWrite(byte highAddress, byte lowAddress, byte data){
  /*
  Mirando el datasheet del 24LC256 viene como ha de hacerse el guardado de datos
  Para escribir un byte hay que mandar:
    1.bit de inicio
    2.byte de control
    3.byte con highAddress
    4.byte con lowAddress
    5.byte con los datos a escribir
    6.bit de cierre de comunicación 
  */
  //1.bit de inicio + 2.byte de control
  Wire.beginTransmission(ADDRESS);
  //3.Byte de highAddress
  Wire.write(highAddress);
  //4.Byte de lowAddress
  Wire.write(lowAddress);
  //5.datos
  Wire.write(data);
  //6.bit de cierre de comunicación
  Wire.endTransmission();
}

byte eepromRead(byte highAddress, byte lowAddress){
  /*
  Para leer un byte se necesita:
    1.bit de inicio
    2.byte de control
    3.byte highAddress
    4.byte lowAdress
    5.bit de final de comunicación
  */
  byte c;
  //1.bit de inicio + 2.byte de control
  Wire.beginTransmission(ADDRESS);
  //3.Byte de highAddress
  Wire.write(highAddress);
  //4.Byte de lowAddress
  Wire.write(lowAddress);
  //5.bit de cierre de comunicación
  Wire.endTransmission();
  //6.Recibir datos
  Wire.requestFrom(ADDRESS, 1); //si pedimos mas bytes de 1 nos 
                                //devuelve lo de las siguientes direcciones de memoria

  while(Wire.available());
  c = Wire.read();
  return c;

}

void loop(){

}

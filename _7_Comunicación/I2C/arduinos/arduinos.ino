/*
Ejemplo de comunicación entre dos arduinos
El único arduino conectado a corriente es el uno que suministra la energia al leonardo

  Arduino uno -> master
  Arduino Leonardo -> Slave
  
Queremos ser capaces de enviar la instrucción de encender un led conectado a arduino leonardo 
desde el uno

Código para Master(Arduino uno)
*/
#include<Wire.h>

void setup(){
  Serial.begin(9600);
  Wire.begin();
}

void loop(){
  //enviar datos
  while()Serial.available()){
    char c = Serial.read();
    
    if(c == 'H'){
      Wire.beginTransmission(5);
      Wire.write('H');
      Wire.endTransmission();
    }else if(c == 'L'){
      Wire.beginTransmission(5);
      Wire.write('L');
      Wire.endTransmission();
    }
  }
  //pedir datos
  Wire.requestFrom(5, 5); // pide al slave 5 que mande 5 bytes
  while(Wire.available()){
    char c = Wire.read();
    Serial.println(c);
  }
}

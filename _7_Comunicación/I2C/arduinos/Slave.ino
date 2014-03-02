/*
Usamos eventos para capturar los inicios de transmisión

  led = pin 2
*/

#include <Wire.h>

const int led = 2;

void setup(){
  Wire.begin(5); //el parámetro 5 es el elegido en el codigo de master
  Wire.onReceive(recibirEvento);
  Wire.onRequest(pedirEvento);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void recibirEvento(int cantidad){
  /*
  Handler para el evento transmision I2C
  */
  while(Wire.available()){
    char c = Wire.read();
    
    if(c == 'H'){
      digitalWrite(led, HIGH);
    }else if(c == 'L'){
      digitalWrite(led, LOW);
    }
  }
}

void pedirEvento(){
  /*
  Handler para la información a enviar si master me pide algo
  */
  Wire.write("123456789"); //master decide cuantos números leerá
}

void loop(){
  delay(1000);
}

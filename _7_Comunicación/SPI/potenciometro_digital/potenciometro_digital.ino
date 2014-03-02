/*
Usando potenciómetro digital que usa comunicación SPI
Hemos hecho las siguientes conexiones con los puertos digitales de arduino:
  __
  CS = pin 10
  SCK = pin 13
  SDI = pin 11(MOSI)
  SDO = pin 12(MISO)
Estos pines son definidos por la libreria SPI.h automaticamente, solo hay que definir CS
*/
#include <SPI.h>

const int Slave1 = 10;

void setup(){
  pinMode(Slave1, OUTPUT);
  SPI.begin();
}

void ledConfig(int led, int brillo){
  /*
  Función que selecciona un led y le pone un nivel de brillo
  */
  digitalWrite(Slave1, LOW);
  SPI.transfer(led);
  SPI.transfer(brillo);
  digitalWrite(Slave1, HIGH);
}

void loop(){
  /*
  Queremos hacer un programa que seleccione un led, le lleve poco a poco
  de 0 a brillo total y luego al revés, despues seleccione otro led y repita el proceso
  */
  for(int i=0;i<=1; i++){ //número de led, 0 o 1
    for(int j=50;j<=255; j++){ //brillo de led, empieza en 50 porque para bajos voltajes no brilla
      ledConfig(i,j);
      delay(20);
    }
    delay(500);
    for(int j=255;j>=50; j--){ 
      ledConfig(i,j);
      delay(20);
    }
  }
}

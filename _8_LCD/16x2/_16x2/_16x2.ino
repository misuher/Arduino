/*
Programa para usar una pantalla LCD 16x2 con las siguientes conexiones:
 
 RS = pin 34
 EN = pin 36
 D4 = pin 38
 D5 = pin 40
 D6 = pin 42
 D7 = pin 44
 */
#include<LiquidCrystal.h>

byte p20[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};

byte p40[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};
byte p60[8] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
};
byte p80[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
};
byte p100[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

//0.crea objeto LCD cuyos parametros son los pines
LiquidCrystal lcd(34, 36, 38, 40, 42, 44);

void setup(){ 
  //1.Comenzar conexión con lcd
  lcd.begin(16, 2); //parámetros son el tamaño de la pantalla
  //2.Escribir en la pantalla
  lcd.print("Carlos Castillo");
  //3.Establecer caracteres personalizados
  lcd.createChar(0,p20); //si mando un 0 al lcd escribira lo que definimos en p20
  lcd.createChar(1,p40);
  lcd.createChar(2,p60);
  lcd.createChar(3,p80);
  lcd.createChar(4,p100);
}

void loop(){
  //cambiar el cursos donde se escribe en la pantalla
  lcd.setCursor(0, 1);
  //borrar la linea del cursor
  lcd.print("                ");
  //animación barra de carga
  for(int i=0; i<16; i++){
    for(int j=0; j<5; j++){
      lcd.setCursor(i,1);
      lcd.write(j);
      delay(100);
    }
  }

}


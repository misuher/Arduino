/*
Escribir y leer datos de un modulo de tarjeta SD conectado por SPI
vamos a leer de un archivo que ya hay dentro config.txt el valor del tiempo de delay
despues vamos a crear otro archivo en el que escribir una frase repetidamente con el valor obtenido del config
*/
#include<SD.h>//MOSI, MISO, SCLK establecidos por defecto

int const CS_pin = 10;
int const pow_pin = 8;
float tiempo = 200.0;

void setup(){
  Serial.begin(9600);
  pinMode(CS_pin, OUTPUT);
  //El modulo obtiene la energia por el pin 8, hay que activarlo
  pinMode(pow_pin, OUTPUT);
  digitalWrite(pow_pin, HIGH);
  
  if(!SD.begin(CS_pin)){
    Serial.println("SDcard no disponible");
    return;
  }
  Serial.println("SDcard lista");
  
  //abrimos el archivo de configuracion
  File configuracion = SD.open("config.txt");
  if(configuracion){
    Serial.println("leyendo la SD");
    while(configuracion.available()){
      tiempo = configuracion.read() - '0'; //el cero convierte a ASCII
    }
    Serial.println("Tiempo de refresto fijado en: ");
    Serial.println(tiempo);
  }else{
    Serial.println("No se ha podido leer del archivo de config.");
  }
}

void loop(){
  String texto = "esto va para la SD";
  //creamos un archivo en la SD
  File archivo = SD.open("miArchivo.txt", FILE_WRITE);
  //comprobamos que se ha creado y escribimos
  if(archivo){
    archivo.println(texto);
    archivo.close();
  }else{
    Serial.println("No se puede abrir el archivo");
  }
  delay(tiempo);
}

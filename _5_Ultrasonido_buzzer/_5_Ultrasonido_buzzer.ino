/*
Programa para programar un sensor por ultrasonidos que según la distancia haga sonar
un buzzer y encienda un led con más frecuencia según se acerca el objeto.

Vamos a usar una libreria externa para aprender a usarlas, la libreria ping
Una vez bajado usamos Sketch > importar libreria > add library
Y seleccionamos la carpeta donde esta la libreria
Despues de eso podemos incluirla con un sencillo #include <libreria.h>

El sensor típico que vende parallax es PING, tiene 3 pines, es facil de conectar
funciona igual que el sistema de visión de los murcielagos.
  Pines:
    buzzer -> pin 4
    led(PWD) -> pin 3
    Sensor ultra -> pin 2
*/

#include <Ping.h>

//1.vbles
const int buzzer = 4;
const int led = 3;
const int ultra = 2;

int distancia;  //guarda la distancia del sensor a un objeto
int intervalo;  //guarda el intervalo de tiempo entre pitidos

//2.Definir configuració
void setup(){
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  //el sensor se establece con la libreria 
}

//3.Bucle del programa
void loop(){
  //ahora hay que consultar la documentación de la libreria para saber
  //que funciones tiene para poder usarlas
  Ping miSensor = Ping(ultra); //establece el pin de ultra como el sensor ultrasonico PING
  miSensor.fire();
  distancia = miSensor.centimeters();
  
  if(distancia < 100){
    intervalo = distancia * 10;
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);  
    delay(intervalo);
  }
  
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
  delay(intervalo);
}

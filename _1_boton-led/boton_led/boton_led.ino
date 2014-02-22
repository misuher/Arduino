/*
Programa para usar los pines digitales de entrada y salida del arduino
Entrada digital -> botón
Salida digital -> led

Pines:
	LED = 13
	Botón = 8
*/

//1.Definición de variables:
int boton = 8;
int led = 13;
boolean ledOn = false;
boolean esDebounce = LOW; 
boolean esPulsado = LOW;

//2.Definición de comportamiento de los pines
void setup(){
	pinMode(boton,INPUT);
	pinMode(led,OUTPUT);
}

//3.Funciones
boolean debounce(boolean esDebounce){
  /*
  boolean -> boolean
  Función para evitar el debounce al pulsar el botón
  Debounce = al pulsar el botón hay un tiempo en el cual aunque lo pulsemos muy rápido
             arduino es capaz de leer falsos valores positivos dado a su velocidad de trabajo.
  */
	boolean valorActual = digitalRead(boton);
	if(esDebounce != valorActual){
		delay(5);
		valorActual = digitalRead(boton);
	}
	return valorActual;
}

//4.Define el bucle infino de ejecución del programa
void loop(){
	esPulsado = debounce(esDebounce);
	if(esDebounce == LOW && esPulsado == HIGH){
		ledOn != ledOn;
	}else{
		esDebounce = esPulsado;
	}
		digitalWrite(led, ledOn);
}

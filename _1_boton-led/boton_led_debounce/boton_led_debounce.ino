/*
Poner un delay para arreglar el debounce es una práctica muy básica pero no efectiva
Aqui vamos a ver una mejor forma de solucionarlo

  boton = pin 8
*/

//1.Variables
const int boton = 8;
const int tiempoDebounce = 10;
int contadorPulsaciones = 0;
boolean esPresionado = LOW;
boolean esPresionadoAnterior = LOW;

//2.Definicion de caracteristicas
void setup(){
  Serial.begin(9600);  //inicio comunicación con el ordenador
  pinMode(boton ,INPUT);
}

//3.Funciones
boolean debounce(int pin){
  /*
  int -> boolean
  Función que compara el valor del voltaje con el justo anterior, si coinciden 10 valores iguales consecutivos
  se devuelve ese voltaje, si no llega a 10 suponemos que son pulsos de debounce y reseteamos el contador.
  */
  int contador = 0;
  boolean estado;
  boolean estadoAnterior;
  
  do{
    estado = digitalRead(pin);
    if(estado != estadoAnterior){
      contador = 0;
      estadoAnterior = estado;
    }else{
      contador++;
    }
    delay(1);
  }while(contador < tiempoDebounce);
  
  return estado;
}

//4.bucle del programa
void loop(){
  esPresionado = digitalRead(boton);
  if( esPresionado != esPresionadoAnterior && debounce(boton) ){
    //codigo a ejecutar al pulsar el boton
    //debemos ver por el monitor serial solo un incremento por pulsacion de boton
    //en caso contrario aumentar el tiempoDebounce
    contadorPulsaciones++;
    Serial.println(contadorPulsaciones);
  }
  
  esPresionadoAnterior = esPresionado;
}

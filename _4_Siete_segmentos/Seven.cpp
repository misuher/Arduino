#include "Seven.h"


bool debounce(int pin){
  /*
  int -> boolean
  Función que compara el valor del voltaje con el justo anterior, si coinciden 10 valores iguales consecutivos
  se devuelve ese voltaje, si no llega a 10 suponemos que son pulsos de debounce y reseteamos el contador.
  */
  const int tiempoDebounce = 10;
  int contador = 0;
  bool estado;
  bool estadoAnterior;
  
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
//-------------------------------------------------------------------------------------------------
bool obtenerEstado(short digito, int numero){
  /*
  int,short -> String
  Funcion que recibe un numero binario de 8 bit y un digito que representa la posicion del bit
  que se quiere aislar siendo las posiciones del byte:  01234567
    si es 1 devuelve 'HIGH'
    si es 0 devuelve 'LOW'
  */
  String pin = "LOW";

  short division = numero / 10^(8 - digito);
  short resto = division % 10;

  if (resto == 1){
    pin = "HIGH";
  }
  return pin;
}
//-------------------------------------------------------------------------------------------------
void sevIlumina(int numero){
  /*
  Funcion que recibe como parámetro de 7digitos con 0/1 que indican para cada pin
  si el led del siete segmentos debe estar apagado o encendido
  */
  for(int c = 97; c < 104; c++){
    for(short i=0; i <= 7; i++){
      digitalWrite( char(c) , obtenerEstado(i, numero) );
    }
  }
}
//-------------------------------------------------------------------------------------------------
void sevBorrar(){
  /*
  Funcion para apagar todos los leds del Siete segmentos
  */
  sevIlumina(B00000000);
}
//-------------------------------------------------------------------------------------------------
void sevNum(int num){
  /*
  Función que recive como parámetro el número que queremos pintar en el siete segmentos y enciende los 
  leds correspondientes
  */
  int numeros[] = {11111100,01100000,11011010,11110010,01100110,10110110,10111110,11100000,11111110,11100110};
  switch(num){
    case 0:
      sevIlumina(numeros[0]);
      break;
    case 1:
      sevIlumina(numeros[1]);
      break;
    case 2:
      sevIlumina(numeros[2]);
      break;
    case 3:
      sevIlumina(numeros[3]);
      break;
    case 4:
      sevIlumina(numeros[4]);
      break;
    case 5:
      sevIlumina(numeros[5]);
      break;
    case 6:
      sevIlumina(numeros[6]);
      break;
    case 7:
      sevIlumina(numeros[7]);
      break;
    case 8:
      sevIlumina(numeros[8]);
      break;
    case 9:
      sevIlumina(numeros[9]);
      break;
  }

}

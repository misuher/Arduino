/*
Las librerias incluyen simplemente el mapeo de las direcciones de memoria asignadas a unos nombres
En ocasiones tambien traen función de acciones que se usan muy habitualmente

¿De donde saco las librerias?
Si estás trabajando con el IDE del fabricante basta con incluirlas con #define, pero cada IDE tiene una libreria diferente, la forma de
llamar a los puertos es diferente, lo mejor es coger una y acostumbrarse a ella
Para aprender a usarla puedes abrirla y leer lo que hay dentro o consultar la documentación que corresponda.
*/


//Para Atmel
#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB = 0xFF; //Todo los pines del puerto C como salida
  while(1) 
  {
    PORTB = 0xFF; //Encender todos los pines del puerto C
    _delay_ms(1000); //Esperar 1 segundo
    PORTB= 0x00; //Apagar todos los pines del puerto C
    _delay_ms(1000); //Esperar 1 segundo
  }
}

//Para PIC con MPLAB  compilador = HITECH 
#include <htc.h>
#define _XTAL_FREQ 8000000
void main()
{
  TRISB=0X00;
  PORTB=0X00;
  while(1)
  { 
    PORTB=0XFF;
    _delay_ms(100);
    PORTB=0X00;
    _delay_ms(100);
  }
}
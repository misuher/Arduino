/*
Libreria chorra para ilustrar como separar en archivos e importar funciones en un proyecto para arduino 
para usar un único Siete segmentos

De momento es solo una colección de funciones, en un ejemplo futuro se hablara de la creación de una clase

Las librerias en C se dividen en 2 archivos:
	*.h -> definición de funciones
	*.cpp -> implementación del algorritmo

*/

#ifndef Seven_h
#define Seven_h

#include "arduino.h"



bool debounce(int);
bool obtenerEstado(short, int);
void sevIlumina(int);
void sevBorrar();
void sevNum(int);

#endif

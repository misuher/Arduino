/*
Programa para controlar un bloque de siete segmentos conectado en los puertos 
digitales del 2 al 8 nombrandolo desde el superior en sentido horario

Tambien quiero desglosar el proyecto en varios archivos para tener funciones en un archivo y 
el programa que las usa en otro, no van a ser incluidas en las librerias de arduino asi que los
tipos de las variables tienen que ir en puro C.

quiero dibujar numeros de 0 al 9 incrementandolo o decrementandolo con 2 botones.
  botonInc = pin 9
  botonDec = pin 10
  
OJO: programa y libreria no testeadas, puede haber errores
*/
#include "Seven.h"

const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int botonInc = 9;
const int botonDec = 10;


int digito = 0;


void setup(){
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop(){
  if( digitalRead(botonInc) && debounce(botonInc) && digito <= 9){
    digito++;
    sevNum(digito);
  }
  if( digitalRead(botonDec) && debounce(botonDec) && digito >= 0 ){
    digito--;
    sevNum(digito);
  }
}


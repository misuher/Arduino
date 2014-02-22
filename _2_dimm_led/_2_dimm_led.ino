/*
Programa para manejar entradas y salidas analógicas, con analógico que entiende que pueden tomar
muchos valores, no solo 0 o 1 como los digitales
Entrada analógica --> Potenciómetro
Salida analógica --> Led (debe estar conectado a un puerto PMW representado por ~)

  Potenciómetro -> pin A0
  Led -> pin 3
*/
const int pot = A0;  //es lo mismo que pot = 14
const int led = 3;

int dimm;

void setup(){
  //los pines analógicos están configurados como entrada por defecto
  pinMode(led, OUTPUT);
}

void loop(){
  dimm = analogRead(pot);
  //en dimm hay un valor entre 0-1023, pero el led solo puede recivir uno entre 0-255
  //hacemos la conversión entre rangos con la función map, aunque tambien se podria hacer dimm/4
  dimm = map(dimm,0,1023,0,255);
  analogWrite(led, dimm);
}

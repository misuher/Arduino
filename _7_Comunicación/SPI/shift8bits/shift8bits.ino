#include <SPI.h>

const byte LATCH = 12;

byte c;

void setup ()
{
  SPI.begin ();
}  // end of setup


void loop ()
{
  c++;
  digitalWrite (LATCH, LOW);
  //ahora mandamos los bytes que queramos, como solo tenemos un 74H mandamos un byte
  //pero podemos mandar tantos como queramos antes de volver a poner el LACH en HIGH
  SPI.transfer (c);
  digitalWrite (LATCH, HIGH);
  delay (20);
}  // end of loop

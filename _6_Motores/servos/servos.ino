/*
Son motores que giran de 0 a 180º, los valores son estandard:
  para 0 los pulsos deben ser de 1ms
  para 180 los pulsos deben ser 2ms
Aun así los fabricantes no siempre las cumplen.    
    
Los servos tienen 3 cables, se controlan por PWD+transistor o salida analógica, pero no usar PWD directamente
y suelen consumir mucha potencia por lo que se les alimenta con una fuente diferente a la del arduino(clavija jack)

Además los servos se diferencian por su torque
*/

#include <Servo.h> //al usarla se desactiva PWD en los pines 9 y 10

const int pot = A0;
const int servo = 2;

int potVal;
int angulo;

void setup(){

}

void loop(){
  Servo miServo;
  miServo.attach(servo); //sino el servo no va a 0 y 180 la funcion tiene
                         //dos parametros mas para definir el ancho de pulso adecuado para 
                         //cada posicion
  valor = analogRead(pot);
  angulo = map(valor, 1023, 0, 0, 180); //se invierte los valores de pot para que el sentido de giro coincidad con el del servo
  miServo.write(angulo);
  delay(20);  //para compensar el retraso del motor al mover carga
}

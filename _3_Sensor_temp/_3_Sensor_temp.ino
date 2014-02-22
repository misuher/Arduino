/*
Programa para leer la temperatura con un sensor LM35
LM35 es el modelo típico por su sencillez de uso
Solo hay que saber que leemos un valor de 10mV por cada grado centigrado

  LM35 -> pin A0
*/

//1.variables
const int sensorT = 0;
long mV;
long temp;

//2.Definir configuracion
void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

//3.Funciones

//4.loop del programa
void loop(){
  //el sensor me da un valor entre 0-1023 pero yo quiere un rango de 0-5V o de 0-5000mV:
  //aplicamos una regla de 3:
  mV = analogRead(sensorT);
  mV = map(mV, 0, 1023, 0, 5000);  
  temp = mV / 10;
  
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" ºC");
  delay(500);
  
  
}

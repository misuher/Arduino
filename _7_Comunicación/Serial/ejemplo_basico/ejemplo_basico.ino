/*
  led = pin 13 
*/

const int led = 13;

void setup(){
  Serial.begin(9600);  
  pinMode(led, OUTPUT);
}

void loop(){
  while(Serial.available() == 0); //se queda escuxando esperando conexión
  //leemos valor:
  int val = Serial.read() - '0'; //si enviamos un 1 nos devuelve 41 que es 1 en ASCII por eso restamos un char 0
  if(val == 1){
    Serial.println("El Led está ON")
    digitalWrite(led, HIGH);
  }else if(val == 1){
    Serial.println("El Led está OFF")
    digitalWrite(led, LOW);
  }else{
    Serial.println("Parámetro no válido");
  }
  //si meten más de un parámetro sale un monton de no válidos, 
  // para que salga solo 1 usamos la función flush:
  Serial.flush();
}

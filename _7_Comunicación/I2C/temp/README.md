Vamos a conectar por I2C el sensor de temperaturaTC74A0 que tiene un registro interno donde guarda el valor leido

La conexión se hace siguiendo estos pasos:
	Master solicita conectar con slave de id=temp
	Master solicita valor del Registro 0
	Master se calla y espera una respuesta de 1byte

Mapa de pines de TC74:

		|	|	 |	  |	  |
		|	|	 |	  |	  |
	   NC  SDA  GND SCLK VDD	

	   	NC = no conection.



Las resitencias entre SDA/SCL y el voltaje se ponen como resistencias pull-up.

![Alt text](https://raw.github.com/misuher/arduino/master/_7_Comunicación/I2C/temp/esquema.jpg?raw=true)
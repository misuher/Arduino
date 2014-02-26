/*
Lo primero que debemos hacer es bajar el datasheet del componente que queremos progrmar
Como  queremos encender un LED tenemos que saber 2 cosas:
	1.Como establecer un pin como entrada o salida
	2.Como activar/desactivar el pin
    3.Como usar la resistencia interna

Tanto si vas a usar libreria como si no, has de saber la nomeclatura de registros de cada chip
    Si usas libreria la nomenclatura es el nombre que se le asigna a la vble
    Si no la usas debes de saber como lo llaman para consultar las direcciones de memoria en el datasheet
Nombre de los registros para cada caso:

			Atmel 			PIC
			--------------------
I/O         DDR             TRIS     
act/des     PORT            PORT



*/
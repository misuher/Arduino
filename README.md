Repositorio para programación de Arduino, algunos con el IDE de arduino y otro en C

Resumen de las funciones incluidas en la libreria standard:
==========================================================

FUNCIONES INCLUIDAS
-------------------
	sizeof(vble)

I/O Digital:
	pinMode(pin,[INPUT, OUTPUT, INPUT_PULLUP])    	//INPUT_PULLUP=con resistencia interna
	digitalWrite(pin, [HIGH, LOW])
	digitalread(pin)  --> [HIGH, LOW]  				//Devuelve HIGH o LOW

I/O Analógico:
	analogRead(pin) --> int  //0-1024
	analogWrite(pin, valor)  //PWM--> valor va de 0-255
    analogReference([DEFAULT, INTERNAL, EXTERNAL])
    analogReference([DEFAULT, INTERNAL1V1, INTERNAL2V56, EXTERNAL])  //Para arduino MEGA

I/O avanzado:
	tone(pin, freqhz_uint, [duracion_ms])  //genera una onda cuadrada de la freq especificada durante el tiempo establecido
	noTone(pin)  // Para la generación de la onda cuadrada
	shiftOut(pinDatos, pinReloj, [MSBFIRST, LSBFIRST], valor)
	pulseIn(pin, [HIGH, LOW], [timeout_ms]) --> ulong  //devuelve la long del pulso en ms

Tiempo:
    delay(ms)
	delayMicroseconds(us)
    millis() --> ulong  //devuelve el tiempo que lleva el programa en ejecución en ms, hace overflow en 50 dias
    micros() --> ulong  //devuelve el tiempo que lleva el programa en ejecución en us, hace overflow en 70 min

Matemáticas:
	min(x, y)
	max(x, y)
	abs(x)
	sin(rad) --> double
	cos(rad) --> double
	tan(rad) --> double
	sqrt(x) --> double
	pow(base, exponente) --> double
	constrain(x, valMin, valMax) //limita valores a uno entre valMin y valMax
	map(valor, fromLow, FromHigh, toLow, toHigh) --> int //remapea un valor de un rango de valores a otro, devuelve el valor remapeado

Random:
	random([min], max) --> long  //min,max=rango de valores entre los que puede estar el num aleatorio
    randomSeed(semilla) //la semilla es un número long o int

Bits y bytes:
	lowByte(x) --> byte //devuelve el byte mas a la derecha 
	highByte(x) --> byte //devuelve el byte mas a la izquierda
	bitRead(x, bitn) --> 0,1  //devuelve el bit en la posición n, n=0 es el de mas a la izq
	bitWrite(x, bitn, bit) //escribir en el byte x, en el bit n, el valor de bit
 	bitSet(x, bitn)  //escribir en el byte x, en el bit n, el valor de 1
	bitClear(x, bitn)  //escribir en el byte x, en el bit n, el valor de 0
	bit(bitn) --> int  // bitn--> n=0->1, n=1->2, n=2->4, n=3->8...

interrupciones Externas:
	attachInterrupt(interrupcion, funcion, [LOW, CHANGE, RISING, FALLING])
        //interrupcon = un int que identifica el num de interrupcion
        //funcion = nombre de la funcion manejadora de la interrupcion
        //LOW = cuando el pin esta en LOW
        //CHANGE = cuando el pin cambia de valor
        //RISING = cambio de low a high
        //FALLING = cambio de high a low
    detachInterrupt(interrupcion)

interrupciones:
    interrupts()  //activa las interrupciones
    noInterrupts()  //desactiva todas las interrupciones

Serial
------
	begin([300, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, 115200])
	end()
	int aviable()
	byte read()
	byte peek()
	flush()
	print(misDatos)
	println(misDatos)
	write(misBytes)



Wire.h  //I2C
------
    begin()         //Se une a un master
    begin(addr)     //Se une a un slave
    requestFrom(direccion, cuenta)
    beginTransmission(dir)
    send(miByte)
    send(char * miCadena)
    send(byte * datos, tamaño)
    endTransmission()
    byte available()
    byte receive()
    onReceive(manejador)
    onRequest(manejador)
    

SoftwareSerial.h
----------------
    SoftwareSerial()
    available()
    begin(long velocidad)
    isListening()
    overflow()
    peek()
    char read()
    print(misDatos)
    println(misDatos)
    listen()
    write()
    
SPI.h
-----
    begin()
    end()
    setBitOrder()
    setClockDivider()
    setDataMode()
    transfer()

EEPROM.h
--------
    read(dirInterna) --> byte
    write(dirInterna, valorByte)

Servo.h
-------
    Servo myServo //declara una vble de tipo Servo
    attach(pin, [min_us, max_us]) //une una vble tipo Servo con un pin, solo 9 o 10
    write(angulo)  //angulo= 0-180 
    writeMicroseconds(us)  //us = 1000-2000
    read() --> int //devuelve angulo de 0-180
    attached() --> bool 
    detach()  //lo desenlaza del pin 9 o 10 y pueden volverse a usar como PWD


Stepper.h
---------
    Stepper(steps, pin1, pin2)
    Stepper(steps, pin1, pin2, pin3, pin4)
    setSpeed(rpm)
    step(pasos)
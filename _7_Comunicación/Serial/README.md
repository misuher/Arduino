Es una comunicación asíncrona de dos canales, se usan los puertos Rx y Tx en el siguiente esquema:


	Emisor 							Receptor
	------							--------
	Rx <---------------------------> Tx	

	Tx <---------------------------> Rx

Las señales son niveles de voltage, pero no todos los dispositivos usan los mismos niveles, por ejemplo:

	Arduino: 0 - 5V (TTL(transistor-transistor logic) ) 
	PC: -15V - 15V  (RS232)

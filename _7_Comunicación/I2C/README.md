Es un bus de comunicación donde se pueden conectar varios elementos a dos cables
	Uno con señal de reloj (SCL)
	Otro con Datos (SDA)

Un elemento se configura como master y los demas como slave con una id

Si usamos la libreria de arduino Wire.h tenemos que saber que los pines asociados son:
	SCL = A5
	SDA = A4
Es un IC que no permite controlar 8 bits gastando solo 3 pines del arduino
El esquema de patillas del 74HC595 es:

	Q1-- 		--Vcc
	Q2--		--Q0
	Q3--		--Ds
				  __
	Q4-- 		--OE
	Q5--		--STCP
	Q6-- 		--SHCP
				  __
	Q7--        --MR
   GND--        --Q7'

Explicación de los pines:

    Qx = son los pines de salida
    Q7' = iria conectado a otro chip para tener aun más salidas, se le pasa el primer byte
    SHCP = el reloj, controla la frecuencia del registro
    STCP = lach, coordina entre recibir datos y mandarlos por las salidas
    OE = Output Enabled, parecido a write protection
    DS = canal de datos
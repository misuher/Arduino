Vamos a usar el MCP42xx por ser uno de los que me salen en Fritzing
el chip tiene 14 pines que siguen el siguiente esquema:

		
		__
		CS -- 		--Vdd
		SCK-- 		--SDO
                      ____
		SDI--		--SHDN
                      __
        Vss--       --WP
        P1B--       --P0B
        P1W--       --P0W
        P1A--       --P0A

Explicación:
    __
    CS = para activar comunicación, al estar negado quiere decir que si no recibe
         corriente entonces se activa
    __
    WP = Write Protection, sino metemos voltaje no se deja cambiar valores de los pot

    SDI = Slave Data In
    SDO = Slave Data Out
    SCK = Clock Signal
    PxA = V del pot.
    PxB = GND del pot
    PxW = Washer, fija el valor del pot
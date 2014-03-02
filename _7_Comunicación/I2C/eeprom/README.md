El 24LC256 sigue el siguiente esquema de pines:

	A0-- 	 --Vcc
    A1--     --WP
    A2--     --SCL
   Vss--     --SDA

Explicación de elementos desconocidos:
    Ax = pines para introducir dirección de memoria
    WP = write protection, por si queremos que sea solo lectura

Formato de la dirección:

    S 1010 A2 A1 A0 R/W ACK

        S = start bit
        1010 = dirección del slave, en decimal es 80(sacado de datasheet)
        A2 A1 A0 = dirección dentro del slave
        R/W = read write bit
        ACK = acknowledge bit
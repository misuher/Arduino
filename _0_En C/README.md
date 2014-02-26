Qué ventaja puede tener aprender C respecto a usar arduino?
Arduino tienes unas librerias acomodadas a los microcontroladores que ellos distribuyen, si en algún momento quieres salirte de su gama o quieres hacerte una solución personalizada necesitas saber hacerlo en C
aunque puedes seguir usando las librerias de arduino necesitas saber como hacer el setup de tu nuevo chip
La verdad es que la gama de arduino es tan amplia que realmente es dificil encontrar una situación en la que no sea la mejor opción

Existen dos grandes tipos de chips:
	
	Atmel -> usado en arduino y raspberry pi
	PIC -> usado en pinguino 

Cada una de las empresas distribuidoras ofrecen en su web un IDE con librerias de sus chip para programarlos:

	Atmel -> Atmel studio
	PIC -> MPlab, CCS(es de terceros pero es muy famoso)

Esto lo hace más cómodo pero no son realmente necesarios

A la hora de trabajar con un chip u otro lo que más cambia es la nomenclatura de sus puertos a las que hay que acostumbrarse
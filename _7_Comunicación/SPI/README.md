La comunicación SPI es síncrona donde se establece un dispositivo como master y los demás como slave
Se conectan con el siguiente esquema:

    SCLK <----------------------->SCLK slave

    MOSI <----------------------->MOSI slave

    MISO <----------------------->MISO slave

    CS1  <----------------------->CS slave1

    CS2  <----------------------->CS slave2


Tiene que haber un puerto CS en el Master por cada Slave para 
elegir con quien comunicarse, debido a ello no necesitamos resistencias pull-up en el canal

SCLK es para la señal de reloj
MOSI es Master Out Slave In, canal por el que el Master manda datos
MISO es Master In Slave Out, canal por el que el slave manda datos


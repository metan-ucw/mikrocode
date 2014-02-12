Thermometer
-----------

Uses HD44780U is compatible display controler and ds18b20 one wire sensor with
sw one wire. Atmega8 runs on internal 8Mhz clock.

Consult you display datasheed for pinout and don't forget to connect VCC and
GND right.

         10K
  VCC---/\/\/--- GND
          ^    +------------------+              DS18B20
	  |    |  _____   _____   |              -----
 -------  |    | |     \_/     |  |       GND---| GND |\
|    V0 |-+    +-| PC6     PC5 |--|----+--------| DQ  | |
|    D0 |--------| PD0     PC4 |  |    |  VCC---| VCC |/
|    D1 |--------| PD1     PC3 |  |    |         -----
|    D2 |--------| PD2     PC2 |  |    |
|    D3 |--------| PD3     PC1 |  |    +--\/\/\---VCC
|    D4 |        | PD4     PC0 |  +-+      4K7
|    D5 |        | VCC     GND |-+  |
|    D6 |        | GND    AREF | |  +----
|    D7 |        | PB6    AVCC | +------- | PROG
|       |        | PB7     PB5 |--------- |
|    R/W|--------| PD5     PB4 |--------- | HEADR
|       |        | PD6     PB3 |---------
|    E  |--------| PD7     PB2 |     //   330
|    R/S|--------| PB0     PB1 |----|>|--\/\/\--- GND
 -------          _____________


To load the code into the microcontroller do:

make (to build the code)
make load (to load firmware)
make load_fuses (to set the internall oscillator to 8Mhz)

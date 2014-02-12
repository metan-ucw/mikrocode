HD44780U display test/example
-----------------------------

HD44780U is compatible display controler for nearly all text LCD displays.

This is demo how to use common HD44780U driver with atmega8 and 2x8 HD44780U
compatible display. Atmega8 runs on internal 1Mhz clock.

Consult you display datasheed for pinout and don't forget to connect VCC and
GND right.

         10K
  VCC---/\/\/--- GND
          ^    +------------------+
	  |    |  _____   _____   |
 -------  |    | |     \_/     |  |
|    V0 |-+    +-| PC6     PC5 |  |
|    D0 |--------| PD0     PC4 |  |
|    D1 |--------| PD1     PC3 |  |
|    D2 |--------| PD2     PC2 |  |
|    D3 |--------| PD3     PC1 |  |
|    D4 |        | PD4     PC0 |  +-+
|    D5 |        | VCC     GND |-+  |
|    D6 |        | GND    AREF | |  +----
|    D7 |        | PB6    AVCC | +------- | PROG
|       |        | PB7     PB5 |--------- |
|    R/W|--------| PD5     PB4 |--------- | HEADR
|       |        | PD6     PB3 |---------
|    E  |--------| PD7     PB2 |     //   330
|    R/S|--------| PB0     PB1 |----|>|--\/\/\--- GND
 -------          _____________


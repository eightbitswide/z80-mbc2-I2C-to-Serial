# z80-mbc2-I2C-to-Serial
Use the IOEXP port on the Z80-MBC2 to establish a I2C to Serial via an Arduino.

This provides a terminal program which will compile using Turbo Pascal 3,
and a I2C-to-Serial program for any Arduino.  

Connect the Arduino's I2C pins directly to the Z80-MBC2's IOEXP port along with +5/Gnd.
The Arduino's program is set for I2C address 0x20 so it requires no change of the Z80-MBC2 firmware.

It is recommended to pull the MCP23017 (which also uses address 0x20) to prevent interference on the address.

Notes: 
This is not yet tested for speed, although I'd be shocked if it worked over 9600bps.
I've established both sides as half-duplex, but altering that is straightforward.
This is intended for use with wifi-serial modem emulators for BBSing.  I doubt it will handle transfers correctly in it's present state.

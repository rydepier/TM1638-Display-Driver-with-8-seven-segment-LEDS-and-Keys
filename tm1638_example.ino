/*
TM1638 8 x Seven Segment Display ith Keys and LEDs

Tests some functions

No key pressed displays decimal number
Key 1 pressed displays HEX value
Key 2 pressed displays binary value
Key 3 pressed clears displayed
Key 4 pressed displays a text string

Connections::

Vcc to Arduino 5 volts
Gnd to Arduino Gnd
Strobe, Digital I/O and clock are defined in the sketch

*/

#include <TM1638.h>
const int strobe = 7;
const int clock = 9;
const int data = 8;
int dots = 0x0; // display all decimal points, value in hexadecimal
int leds = 0xFF; // mask to display LEDS
byte keys; // key value
double number; // number to display

// define a module
TM1638 module(data, clock, strobe);

void setup() {
  Serial.begin(9600);
  module.clearDisplay(); // clear the display
  number = 12345678; // decimal number
}

void loop() {
  
  // display a number
  switch(keys){
    case 0:
    module.setDisplayToDecNumber(number, dots);
    break;
    
    case 1:
    module.setDisplayToHexNumber(number, dots);
    break;
    
    case 2:
    module.setDisplayToBinNumber(number, dots);
    break;
   
    case 4:
    module.clearDisplay(); // clear the display 
    break;
    
    case 8:
    module.setDisplayToString("testing ");
    break;
    
    case 16:
    
    break;
    
    case 32:
    
    break;
    
    case 64:
    
    break;
    
    case 128:
    
    break;
    
    default:
   
    break;
  } 
  //
  
  // get a key press
  getKeyPressed();
  //
}

void getKeyPressed(){
  keys = module.getButtons();
  Serial.println(keys);
  // light the LED
  module.setLEDs(keys & leds);
}

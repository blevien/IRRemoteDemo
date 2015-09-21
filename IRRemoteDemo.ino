/*Mofied IRRecvDemo to assist with Assigning and Handling key presses on the Adafruit Universal Remote
 *
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  

  if (irrecv.decode(&results)) {
    
    //If there are results to decode, switch on the results.value. Remember
    //They are returned as HEX codes so include the 0x prefix!      

    switch(results.value){
     
      case 0xFD50AF:
        Serial.println("Right");
        break;
      
      case 0xFDA05F:
        Serial.println("Up");
        break;
     
      case 0xFD08F7:
        Serial.println("Number 1");
        break;
       

      //If none of the switch cases are met, print the HEX code to Serial to assist in mapping
      default:
         Serial.println(results.value, HEX);
   
      
    }
    
    irrecv.resume(); // Receive the next value
  }
  
  delay(100);
}

#include <IRremote.h>
int receiver = 13; // Initialize Pin 13 as the receiver pin
IRrecv irrecv(receiver); // Create new instance of receiver
decode_results results;

void setup() {

  Serial.begin(9600);
  irrecv.enableIRIn(); //Start the receiver

}

void loop() {

  if (irrecv.decode(&results)) { //IF IR signal received:

    Serial.println (results.value, HEX);
    irrecv.resume();

  }

}

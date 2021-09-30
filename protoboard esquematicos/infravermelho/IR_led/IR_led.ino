#include <IRremote.h>
#include <IRremoteInt.h>



const int irReceiverPin = 2; //pin the receiver is connected to
const int ledPin = 13; 
IRrecv irrecv(irReceiverPin); //create an IRrecv object
decode_results decodedSignal; //stores results from IR detector

// IR remote control library
const int numberOfKeys = 1;
const int firstKey = 4;
// the first pin of the 5 sequential pins connected to buttons
boolean buttonState[numberOfKeys];
boolean lastButtonState[numberOfKeys];
long irKeyCodes[numberOfKeys] = {
0x18E758A7, //0 key

};
IRsend irsend;


void setup()
{
for (int i = 0; i < numberOfKeys; i++){
buttonState[i]=true;
lastButtonState[i]=true;
int physicalPin=i + firstKey;
pinMode(physicalPin, INPUT);
digitalWrite(physicalPin, HIGH); // turn on pull-ups

pinMode(ledPin, OUTPUT);
irrecv.enableIRIn();
}
Serial.begin(9600);
}

boolean lightState = false;
unsigned long last = millis();
void loop() {
for (int keyNumber=0; keyNumber<numberOfKeys; keyNumber++)
{
int physicalPinToRead=keyNumber+4;
buttonState[keyNumber] = digitalRead(physicalPinToRead);
if (buttonState[keyNumber] != lastButtonState[keyNumber])
{
if (buttonState[keyNumber] == LOW)
{
irsend.sendSony(irKeyCodes[keyNumber], 32);
Serial.println("Sending");
}
lastButtonState[keyNumber] = buttonState[keyNumber];
}
}



if (irrecv.decode(&decodedSignal) == true) //this is true if a message has been received
{
  
Serial.println(irrecv.decode(&decodedSignal));
if (millis() - last > 250) {
//has it been 1/4 sec since last message
lightState = !lightState;
//toggle the LED
Serial.println(lightState);
digitalWrite(ledPin, lightState);
}
last = millis();
irrecv.resume();
// watch out for another message
}
}







/*
 Hall Effect Switch
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when Hall Effect Sensor attached to pin 2 is triggered by a magnet
 
 Hall effect sensor used is the A1120EUA from Allegro Microsystems
 
 This example code is in the public domain.
 
 http://www.hobbytronics.co.uk/arduino-tutorial8-hall-effect
*/

// constants won't change. They're used here to set pin numbers:
const int hallPin = A0;     // the number of the hall effect sensor pin
// variables will change:
int hallState = 0;          // variable for reading the hall sensor status

void setup() {
  Serial.begin(9600);
  // initialize the hall effect sensor pin as an input:
  pinMode(hallPin, INPUT);     
}

void loop(){
  // read the state of the hall effect sensor:
  hallState = analogRead(hallPin); //analog reading or digital?

  
    Serial.println(hallState); // after testing, it appears that the sensor displays 1 if no magnet, 0 is yes.
  
}

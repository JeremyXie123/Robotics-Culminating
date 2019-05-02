#define ENCODER 2	// digital input to arduino from encoder; the Vcc and GND of encoder must be plugged into the arduino
#define SPOKES_IN_ENCODER 20

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ENCODER, OUTPUT);
  Serial.begin(9600);  
}


// this function calculates the time it takes for the wheel to turn once
// the function returns the time in milliseconds

unsigned long timeOfoneRevolution() {
  int value = 0;
  int reads = 0;  
  unsigned long timeStart = millis();
    do {
        value = digitalRead(ENCODER);
        do {
        } while (value == digitalRead(ENCODER));
        reads = reads + 1;
    } while (reads!=2*SPOKES_IN_ENCODER);
    unsigned long timeAfterOneRevolution = millis();
    return timeAfterOneRevolution - timeStart;
}


void loop() {
    timeOfoneRevolution;
}

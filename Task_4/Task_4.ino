#define ENCODER 2       // digital input to arduino from encoder; the Vcc and GND of encoder must be plugged into the arduino

define SPOKES_IN_ENCODER to 20

void setup() {
    set pin mode of LED_BUILTIN to OUTPUT
    set pin mode of ENCODER to INPUT
    initialize the serial monitor to 9600 bits per second (baud rate)
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

declare a function averageSpeed() that returns a double {
    call the function timeOfOneRevolution() ten times and accumulate all ten readings in a double variable
    calculate the average speed by using the total time accumulated and the circumference of the wheel
    return the average speed in meters per second
}


void loop() {
    print the result of averageSpeed() and the units m/s

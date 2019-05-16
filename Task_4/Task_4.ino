#define ENCODER 2       // digital input to arduino from encoder; the Vcc and GND of encoder must be plugged into the arduino
#define SPOKES_IN_ENCODER 20
#define RADIUS 10
#define CIRCUMFERENCE 2*PI*RADIUS
#define Iterations 10

void setup() {
    pinMode(LED_BUILTIN, INPUT);
    pinMode(ENCODER, INPUT);
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

double averageSpeed() {
    double totalTime = 0;
    int i;
    for (i = 0; i <= Iterations; i++) {
    totalTime += timeOfoneRevolution();
    } 
    int totalDist = Iterations*CIRCUMFERENCE;
    return totalDist/totalTime;
}


void loop() {
    Serial.print(averageSpeed());
    Serial.print("m/s");
    Serial.println("");
}

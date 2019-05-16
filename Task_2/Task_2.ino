#define ENCODER 2	// digital input to arduino from encoder; the Vcc and GND of encoder must be plugged into the arduino
#define SPOKES_IN_ENCODER 20

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ENCODER, INPUT);
  Serial.begin(9600);  
}


void oneRevolution() {
  int value = 0;
  int reads = 0;
    do {
        value = digitalRead(ENCODER);
        do {
        } while (value == digitalRead(ENCODER));
        reads = reads + 1;
        //Serial.print(reads);
    } while (reads!=2*SPOKES_IN_ENCODER);

    Serial.print(reads);
}

void loop(){
  oneRevolution();
}

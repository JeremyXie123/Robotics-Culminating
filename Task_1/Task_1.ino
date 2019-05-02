#define ENCODER 2	// digital input to arduino from encoder; the Vcc and GND of encoder must be plugged into the arduino
#define LED_BUILTIN 3
#define ENCODER 4


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ENCODER, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
    int value = 0;
    value = digitalRead(ENCODER);
    Serial.print(ENCODER);
}

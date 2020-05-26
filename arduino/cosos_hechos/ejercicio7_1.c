int led = 13;
int analogpin = A0;
int val = 0;
int umbral = 512;

// Condiciones iniciales
void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    val = analogRead(analogpin);

    if (val >= umbral) {
        digitalWrite(led,HIGH);
    } 
    else {
        digitalWrite(led, LOW);
    }
}
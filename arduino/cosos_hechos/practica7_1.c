int led = 13;
int analogpin = A0;
int val = 0;
int umbral = 512;

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;


// Apaga todos
void setAllLow() {
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, LOW);
	digitalWrite(pinE, LOW);
	digitalWrite(pinF, LOW);
	digitalWrite(pinG, LOW);
}

// Condiciones iniciales
void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
}

void loop() {
    Serial.println(analogRead(A0));
    val = analogRead(analogpin);

    if (val >= umbral) {
        digitalWrite(led,HIGH);
    } 
    else {
        digitalWrite(led,LOW);
    }
}
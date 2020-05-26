const int pin_echo=8;
const int pin_trigger=9;
int led13=13;

unsigned int tiempo, distancia;

void setup() {
    pinMode(pin_echo, INPUT);
    pinMode(pin_trigger, OUTPUT);
    pinMode(led13,OUTPUT);
}

void loop() {
    digitalWrite(pin_trigger, LOW);
    delayMicroseconds(2);

    digitalWrite(pin_trigger, HIGH);
    delayMicroseconds(10);

    digitalWrite(pin_trigger, LOW);

    tiempo=pulseIn(pin_echo,HIGH);
    distancia=tiempo/58;

    if(distancia>=15) {
        digitalWrite(led13,HIGH);
    } else {
        digitalWrite(led13,LOW);
    }
}
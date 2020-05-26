int motor_a = 3;
int motor_a1 = 4;

void setup()
{
    pinMode(motor_a, OUTPUT);
    pinMode(motor_a1, OUTPUT);
}

void go_a(int ms){
    digitalWrite(motor_a, HIGH);
    digitalWrite(motor_a1, LOW);
    delay(ms);
}

void reverse_a(int ms){
    digitalWrite(motor_a, LOW);
    digitalWrite(motor_a1, HIGH);
    delay(ms);
}

void stop(int ms){
    digitalWrite(motor_a, LOW);
    digitalWrite(motor_a1, LOW);
}

void loop()
{
    go_a(1000);
    stop(1000);
    reverse_a(1000);
}
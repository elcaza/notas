int led = 13;
int analogpin = A0;
int val = 0;
int umbral = 640;

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

// 0
void put0(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	delay(delay_time);
}

// 1
void put1(int delay_time) {
	setAllLow();
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	delay(delay_time);
}

// 2
void put2(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinD, HIGH);
	delay(delay_time);
}

// 3
void put3(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	delay(delay_time);
}

// 4
void put4(int delay_time) {
	setAllLow();
	digitalWrite(pinF, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinG, HIGH);
	digitalWrite(pinC, HIGH);
	delay(delay_time);
}

// 5
void put5(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// 6
void put6(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// 7
void put7(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	delay(delay_time);
}

// 8
void put8(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// 9
void put9(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// A
void putA(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// B
void putB(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// C
void putC(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	delay(delay_time);
}

// D
void putD(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	delay(delay_time);
}

// E
void putE(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// F
void putF(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// G
void putG(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// H
void putH(int delay_time) {
	setAllLow();
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// I
void putI(int delay_time) {
	setAllLow();
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	delay(delay_time);
}

// J
void putJ(int delay_time) {
	setAllLow();
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	delay(delay_time);
}

// L
void putL(int delay_time) {
	setAllLow();
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	delay(delay_time);
}

// N
void putN(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	delay(delay_time);
}

// O
void putO(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	delay(delay_time);
}

// P
void putP(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// Q
void putQ(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// B
void putR(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	delay(delay_time);
}

// S
void putS(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// U
void putU(int delay_time) {
	setAllLow();
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinF, HIGH);
	delay(delay_time);
}

// Y
void putY(int delay_time) {
	setAllLow();
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinF, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

// Z
void putZ(int delay_time) {
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinD, HIGH);
	digitalWrite(pinE, HIGH);
	digitalWrite(pinG, HIGH);
	delay(delay_time);
}

void saluda(int delay_time) {
  putH(delay_time);
  putO(delay_time);
  putL(delay_time);
  putA(delay_time);
}


// Condiciones iniciales
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  val = analogRead(analogpin);

  if (val >= umbral) {
    saluda(500);
  } 
  else {
    setAllLow();
  }
}
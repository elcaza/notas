// Buzzer

int LedIzqA=13;
int LedIzqB=12;
int LedIzqC=11;

int LedDerA=10;
int LedDerB=9;
int LedDerC=8;

int Buzzer=7;

int BotonIzq=5;
int BotonDer=6;

int valIzq=0;
int valDer=0;

// Declaración de condiciones iniciales

void setup(){
	pinMode(LedIzqA, OUTPUT);
	pinMode(LedIzqB, OUTPUT);
	pinMode(LedIzqC, OUTPUT);
	
	pinMode(LedDerA, OUTPUT);
	pinMode(LedDerB, OUTPUT);
	pinMode(LedDerC, OUTPUT);

	pinMode(Buzzer, OUTPUT);

	pinMode(BotonIzq, OUTPUT);
	pinMode(BotonDer, OUTPUT);
}

// Secuencia Loop
void loop() {
	valIzq=digitalRead(BotonIzq);

	if(valIzq==HIGH) 
	{
		digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, LOW);
		delay(500);

		digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, HIGH);
		digitalWrite(LedIzqC, LOW);
		delay(500);

		digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, HIGH);
		digitalWrite(LedIzqC, HIGH);
		digitalWrite(Buzzer, HIGH);
		delay(500);
	} else 
	{
		digitalWrite(LedIzqA, LOW);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, LOW);
		digitalWrite(Buzzer, LOW);
	}

	valDer=digitalRead(BotonDer);

	if(valDer==HIGH) 
	{
		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, HIGH);
		delay(500);

		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, HIGH);
		digitalWrite(LedDerC, HIGH);
		delay(500);

		digitalWrite(LedDerA, HIGH);
		digitalWrite(LedDerB, HIGH);
		digitalWrite(LedDerC, HIGH);
		digitalWrite(Buzzer, HIGH);
		delay(500);
	} else 
	{
		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, LOW);
		digitalWrite(Buzzer, LOW);
	}
}
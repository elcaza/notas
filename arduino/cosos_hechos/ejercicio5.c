// Buzzer

int LedIzqA=13;
int LedIzqB=12;
int LedIzqC=11;
int LedIzqD=3;

int LedDerA=10;
int LedDerB=9;
int LedDerC=8;
int LedDerD=2;

int Buzzer=7;

int BotonStop=4;
int BotonIzq=5;
int BotonDer=6;

int valIzq=0;
int valDer=0;
int valStop=0;

// Declaración de condiciones iniciales

void setup(){
	pinMode(LedIzqA, OUTPUT);
	pinMode(LedIzqB, OUTPUT);
	pinMode(LedIzqC, OUTPUT);
    pinMode(LedIzqD, OUTPUT);
	
	pinMode(LedDerA, OUTPUT);
	pinMode(LedDerB, OUTPUT);
	pinMode(LedDerC, OUTPUT);
    pinMode(LedDerD, OUTPUT);

	pinMode(Buzzer, OUTPUT);

	pinMode(BotonIzq, OUTPUT);
	pinMode(BotonDer, OUTPUT);
    pinMode(BotonStop, OUTPUT);
}

// Secuencia Loop
void loop() {
	valIzq=digitalRead(BotonIzq);

	if(valIzq==HIGH) 
	{
		digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, LOW);
        digitalWrite(LedIzqD, LOW);
		delay(500);

		digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, HIGH);
		digitalWrite(LedIzqC, LOW);
        digitalWrite(LedIzqD, LOW);
		delay(500);

		digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, HIGH);
		digitalWrite(LedIzqC, HIGH);
        digitalWrite(LedIzqD, LOW);
		delay(500);

        digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, HIGH);
		digitalWrite(LedIzqC, HIGH);
        digitalWrite(LedIzqD, HIGH);

        digitalWrite(Buzzer, HIGH);
		delay(500);
	} else 
	{
		digitalWrite(LedIzqA, LOW);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, LOW);
        digitalWrite(LedIzqD, LOW);
		digitalWrite(Buzzer, LOW);
	}

	valDer=digitalRead(BotonDer);

	if(valDer==HIGH) 
	{
		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, LOW);
        digitalWrite(LedDerD, HIGH);
		delay(500);

		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, HIGH);
        digitalWrite(LedDerD, HIGH);
		delay(500);

        digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, HIGH);
		digitalWrite(LedDerC, HIGH);
        digitalWrite(LedDerD, HIGH);
        delay(500);

		digitalWrite(LedDerA, HIGH);
		digitalWrite(LedDerB, HIGH);
		digitalWrite(LedDerC, HIGH);
        digitalWrite(LedDerD, HIGH);
		digitalWrite(Buzzer, HIGH);
		delay(500);
	} else 
	{
		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, LOW);
        digitalWrite(LedDerD, LOW);
		digitalWrite(Buzzer, LOW);
	}

    // Stop

    valStop=digitalRead(BotonStop);

	if(valStop==HIGH) 
	{
        digitalWrite(Buzzer, HIGH);

        digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, LOW);
        digitalWrite(LedIzqD, LOW);

		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, LOW);
        digitalWrite(LedDerD, HIGH);
		
        delay(500);

        digitalWrite(LedIzqD, LOW);
        digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, LOW);

		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, HIGH);
        digitalWrite(LedDerD, LOW);
		
        delay(500);

        digitalWrite(LedIzqD, LOW);
        digitalWrite(LedIzqA, LOW);
		digitalWrite(LedIzqB, HIGH);
		digitalWrite(LedIzqC, LOW);

		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, HIGH);
		digitalWrite(LedDerC, LOW);
        digitalWrite(LedDerD, LOW);
		
        delay(500);

        digitalWrite(LedIzqD, LOW);
        digitalWrite(LedIzqA, LOW);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, HIGH);

		digitalWrite(LedDerA, HIGH);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, LOW);
        digitalWrite(LedDerD, LOW);
		
		delay(500);

        digitalWrite(LedIzqD, LOW);
        digitalWrite(LedIzqA, LOW);
		digitalWrite(LedIzqB, HIGH);
		digitalWrite(LedIzqC, LOW);

		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, HIGH);
		digitalWrite(LedDerC, LOW);
        digitalWrite(LedDerD, LOW);
		
        delay(500);

        digitalWrite(LedIzqD, LOW);
        digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, LOW);

		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, HIGH);
        digitalWrite(LedDerD, LOW);
		
        delay(500);

        digitalWrite(LedIzqA, HIGH);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, LOW);
        digitalWrite(LedIzqD, LOW);

		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, LOW);
        digitalWrite(LedDerD, HIGH);
		
        delay(500);
	} else 
	{
        digitalWrite(LedIzqA, LOW);
		digitalWrite(LedIzqB, LOW);
		digitalWrite(LedIzqC, LOW);
        digitalWrite(LedIzqD, LOW);

		digitalWrite(LedDerA, LOW);
		digitalWrite(LedDerB, LOW);
		digitalWrite(LedDerC, LOW);
        digitalWrite(LedDerD, LOW);
		
        digitalWrite(Buzzer, LOW);
	}
}
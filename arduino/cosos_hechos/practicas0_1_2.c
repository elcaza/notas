/*
####################################
####################################
####################################
Práctica 0

*/

// Práctica 0 blink

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

/*
####################################
####################################
####################################
Práctica 1

*/

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

// Programa 1

int LED=13;

void setup() {
    pinMode(LED,OUTPUT);
}

void loop() {
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);
    
}

// programa 2

int LEDA=13;
int LEDB=12;


void setup() {
    pinMode(LEDA,OUTPUT);
    pinMode(LEDB,OUTPUT);
}

void loop() {
    digitalWrite(LEDA,HIGH);
    digitalWrite(LEDB,LOW);
    delay(2000);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    delay(1000);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,HIGH);
    delay(2000);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    delay(1000);

}

// Programa 3

int LEDA=13;
int LEDB=12;
int LEDC=11;
int LEDD=10;


void setup() {
    pinMode(LEDA,OUTPUT);
    pinMode(LEDB,OUTPUT);
    pinMode(LEDC,OUTPUT);
    pinMode(LEDD,OUTPUT);
}

void loop() {
    digitalWrite(LEDA,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    delay(2000);
    
    digitalWrite(LEDA,LOW);
    delay(1000);
    
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    delay(2000);
    
    digitalWrite(LEDB,LOW);
    delay(1000);

    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDD,LOW);
    delay(2000);
    
    digitalWrite(LEDC,LOW);
    delay(1000);

    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDA,LOW);
    delay(2000);
    
    digitalWrite(LEDD,LOW);
    delay(1000);
}

/*
####################################
####################################
####################################
Ejercicio 1

*/

// Programa 1

int LEDA=13;
int LEDB=12;
int LEDC=11;
int LEDD=10;


void setup() {
    pinMode(LEDA,OUTPUT);
    pinMode(LEDB,OUTPUT);
    pinMode(LEDC,OUTPUT);
    pinMode(LEDD,OUTPUT);
}

void loop() {
    digitalWrite(LEDA,HIGH);
    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDD,LOW);
    delay(1000);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    delay(1000);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDD,HIGH);
    delay(1000);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    delay(1000);
    
}

// Programa 2

int LEDA=13; // MOVIMIENTO
int LEDB=12;
int LEDC=11;
int LEDD=10;
int LEDE=9;
int LEDF=8;


void setup() {
    pinMode(LEDA,OUTPUT);
    pinMode(LEDB,OUTPUT);
    pinMode(LEDC,OUTPUT);
    pinMode(LEDD,OUTPUT);
    pinMode(LEDE,OUTPUT);
    pinMode(LEDF,OUTPUT);
}

void apaga_todos() {
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
}

void loop() {
    digitalWrite(LEDA,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    delay(500);
    
    apaga_todos();
    digitalWrite(LEDF,HIGH);
    delay(500);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    delay(500);
    
    apaga_todos();
    digitalWrite(LEDF,HIGH);
    delay(500);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    delay(500);
    
    apaga_todos();
    digitalWrite(LEDF,HIGH);
    delay(500);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    delay(500);
    
    apaga_todos();
    digitalWrite(LEDF,HIGH);
    delay(500);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,LOW);
    delay(500);
    
    apaga_todos();
    digitalWrite(LEDF,HIGH);
    delay(500);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    delay(500);
    
    apaga_todos();
    digitalWrite(LEDF,HIGH);
    delay(500);
}


/*
####################################
####################################
####################################
Práctica 2

*/

// Programa 2

int LEDA=13; // MOVIMIENTO
int LEDB=12;
int LEDC=11;


void setup() {
    pinMode(LEDA,OUTPUT);
    pinMode(LEDB,OUTPUT);
    pinMode(LEDC,OUTPUT);
}

void apaga_todos() {
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
}

void loop() {
    digitalWrite(LEDA,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    delay(5000);
    
    apaga_todos();

    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDC,LOW);
    delay(2000);
    
    apaga_todos();

    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDA,LOW);
    delay(5000);
    
    apaga_todos();
}


// Programa 2

int LEDA=13; // MOVIMIENTO
int LEDB=12;
int LEDC=11;
int LEDD=10;
int LEDE=9;
int LEDF=8;
int LEDG=7;
int LEDH=6;

void setup() {
    pinMode(LEDA,OUTPUT);
    pinMode(LEDB,OUTPUT);
    pinMode(LEDC,OUTPUT);
    pinMode(LEDD,OUTPUT);
    pinMode(LEDE,OUTPUT);
    pinMode(LEDF,OUTPUT);
    pinMode(LEDG,OUTPUT);
    pinMode(LEDH,OUTPUT);
}

void apaga_todos() {
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDH,LOW);
}

void loop() {
    digitalWrite(LEDA,HIGH);
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDH,LOW);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,HIGH);
    delay(200);
}



/*
####################################
####################################
####################################
Ejercicio 2


*/

// Programa 2

int LEDA=13; // MOVIMIENTO
int LEDB=12;
int LEDC=11;
int LEDD=10;
int LEDE=9;
int LEDF=8;
int LEDG=7;
int LEDH=6;
int LEDI=5;

void setup() {
    pinMode(LEDA,OUTPUT);
    pinMode(LEDB,OUTPUT);
    pinMode(LEDC,OUTPUT);
    pinMode(LEDD,OUTPUT);
    pinMode(LEDE,OUTPUT);
    pinMode(LEDF,OUTPUT);
    pinMode(LEDG,OUTPUT);
    pinMode(LEDH,OUTPUT);
    pinMode(LEDI,OUTPUT);
}

void apaga_todos() {
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDH,LOW);
    digitalWrite(LEDI,LOW);
}

void loop() {
    digitalWrite(LEDA,HIGH);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDH,HIGH);
    digitalWrite(LEDI,LOW);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,LOW);
    digitalWrite(LEDI,LOW);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDH,LOW);
    digitalWrite(LEDI,LOW);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,HIGH);
    digitalWrite(LEDE,HIGH);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDH,LOW);
    digitalWrite(LEDI,HIGH);
    delay(200);

    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,LOW);
    digitalWrite(LEDC,HIGH);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,HIGH);
    digitalWrite(LEDG,LOW);
    digitalWrite(LEDH,LOW);
    digitalWrite(LEDI,LOW);
    delay(200);
    
    digitalWrite(LEDA,LOW);
    digitalWrite(LEDB,HIGH);
    digitalWrite(LEDC,LOW);
    digitalWrite(LEDD,LOW);
    digitalWrite(LEDE,LOW);
    digitalWrite(LEDF,LOW);
    digitalWrite(LEDG,HIGH);
    digitalWrite(LEDH,LOW);
    digitalWrite(LEDI,LOW);
    delay(200);
}


/*
####################################
####################################
####################################
Práctica 3

*/

/*
####################################
####################################
####################################
Ejercicio 3

*/

/*
####################################
####################################
####################################
Práctica 4

*/

/*
####################################
####################################
####################################
Ejercicio 4

*/

/*
####################################
####################################
####################################
Práctica 5

*/

/*
####################################
####################################
####################################
Ejercicio 5

*/
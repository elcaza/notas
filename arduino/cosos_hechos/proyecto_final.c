/**
* ====================================================================
* ====================================================================
* Music
*/
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

const int buzzerPin = 13; // Digital Pin 13
const int ledPin3 = 8;  // Digital Pin 9
const int ledPin1 = 9;  // Digital Pin 9
const int ledPin2 = 10;  // Digital Pin 10 Built In Led can Change it if you want

int counter = 0;
int acciona = 0;


/**
* ====================================================================
* ====================================================================
* Motores
*/
int motor_vas = 1;
int motor_regresa = 0;
int ldr_rango = 512;

/**
* ====================================================================
* ====================================================================
* Password
*/
int counter_password = 0; // 0 = input; 1 = 1er digito; 2 = 2do digito; 3 = 3er digito; 4 = 4to digito;
//int password = 3112;
int the_password_value_1 = 3;
int the_password_value_2 = 1;
int the_password_value_3 = 1;
int the_password_value_4 = 2;

int password_setting = 0;
int password_value_1 = 0;
int password_value_2 = 0;
int password_value_3 = 0;
int password_value_4 = 0;

/**
* ====================================================================
* ====================================================================
* Botones 1 - 5
*/
int button0 = 4;
int button1 = 3;
int button2 = 5;
int button3 = 6;

/**
* ====================================================================
* ====================================================================
* Display 7 segmentos
*/
int pinA = 2;
int pinB = 7;
int pinC = 11;
int pinD = 12;

// LDR
int LDR = A0;

void setup()
{
	// Setup pin modes
	pinMode(buzzerPin, OUTPUT); // Digital Pin 8
	pinMode(ledPin1, OUTPUT);  // Digital Pin 12
	pinMode(ledPin2, OUTPUT); // Digital Pin 13 Built In Led can Change it if you want

	// Motor
	pinMode(motor_vas, OUTPUT);
	pinMode(motor_regresa, OUTPUT);

	// Botones
	pinMode(button0, INPUT);
	pinMode(button1, INPUT);
	pinMode(button2, INPUT);
	pinMode(button3, INPUT);

	// Display 7 segmentos
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
	pinMode(pinC, OUTPUT);
	pinMode(pinD, OUTPUT);

	
	
}

void loop()
{
	// play_music();
	//enter_password(1000);
	// motor_vas_a(1000);
	// motor_vas_b(1000);

	password_setting = 0;

	// Primer valor del password
	while (password_setting != 1){
		enter_password_1(500);
		if ( digitalRead(button0) == HIGH )
		{
			password_value_1 = 0;
			password_setting = 1;
		} 
		if ( digitalRead(button1) == HIGH )
		{
			password_value_1 = 1;
			password_setting = 1;
		}
		if ( digitalRead(button2) == HIGH )
		{
			password_value_1 = 2;
			password_setting = 1;
		}
		if ( digitalRead(button3) == HIGH )
		{
			password_value_1= 3;
			password_setting = 1;
		}
	}

	password_setting = 0;

	// Segundo valor del password
	while (password_setting != 1){
		enter_password_2(500);
		if ( digitalRead(button0) == HIGH )
		{
			password_value_2 = 0;
			password_setting = 1;
		} 
		if ( digitalRead(button1) == HIGH )
		{
			password_value_2 = 1;
			password_setting = 1;
		}
		if ( digitalRead(button2) == HIGH )
		{
			password_value_2 = 2;
			password_setting = 1;
		}
		if ( digitalRead(button3) == HIGH )
		{
			password_value_2= 3;
			password_setting = 1;
		}
	}

	password_setting = 0;

	// Tercer valor del password
	while (password_setting != 1){
		enter_password_3(500);
		if ( digitalRead(button0) == HIGH )
		{
			password_value_3 = 0;
			password_setting = 1;
		} 
		if ( digitalRead(button1) == HIGH )
		{
			password_value_3 = 1;
			password_setting = 1;
		}
		if ( digitalRead(button2) == HIGH )
		{
			password_value_3 = 2;
			password_setting = 1;
		}
		if ( digitalRead(button3) == HIGH )
		{
			password_value_3= 3;
			password_setting = 1;
		}
	}

	password_setting = 0;

	// Cuarto valor del password
	while (password_setting != 1){
		enter_password_4(500);
		if ( digitalRead(button0) == HIGH )
		{
			password_value_4 = 0;
			password_setting = 1;
		} 
		if ( digitalRead(button1) == HIGH )
		{
			password_value_4 = 1;
			password_setting = 1;
		}
		if ( digitalRead(button2) == HIGH )
		{
			password_value_4 = 2;
			password_setting = 1;
		}
		if ( digitalRead(button3) == HIGH )
		{
			password_value_4 = 3;
			password_setting = 1;
		}
	}

	if ( check_password() == 1 ){
		apaga_sonido(100);
		digitalWrite(ledPin1, HIGH);
		abre_puerta();
	} else {
		reset_password_value();
		setAllLow();
		digitalWrite(ledPin1, LOW);
	}

}

// Check password
int check_password() {
	if ( password_value_1 == the_password_value_1 && password_value_2 == the_password_value_2 && password_value_3 == the_password_value_3 && password_value_4 == the_password_value_4) {
		counter_password = 0;
		return 1;
	} else {
		counter_password++;
		if (counter_password > 2){
			password_incorrecto();
		}
		return 0;
	}
}

// Reset passwords values
void reset_password_value() {
	int password_value_1 = 0;
	int password_value_2 = 0;
	int password_value_3 = 0;
	int password_value_4 = 0;
}

// Funciones de motor

void motor_vas_a(int delay_time){
	digitalWrite(motor_vas, HIGH);
	digitalWrite(motor_regresa, LOW);
	delay(delay_time);
}

// Funciones de motor

void motor_vas_b(int delay_time){
	digitalWrite(motor_vas, LOW);
	digitalWrite(motor_regresa, HIGH);
	delay(delay_time);
}

void motor_para(int ms){
	digitalWrite(motor_vas, LOW);
	digitalWrite(motor_regresa, LOW);
	delay(ms);
}

void play_music()
{
	//Play first section
  firstSection();

  //Play second section
  secondSection();

  //Variant 1
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 350);  
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);  
  beep(cH, 125);
  beep(eH, 650);

  delay(500);

  //Repeat second section
  secondSection();

  //Variant 2
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 650);  

  delay(650);
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);

  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
	// digitalWrite(ledPin1, HIGH);
	delay(duration);
	digitalWrite(ledPin1, LOW);
  }else
  {
	// digitalWrite(ledPin2, HIGH);
	delay(duration);
	digitalWrite(ledPin2, LOW);
  }

  //Stop tone on buzzerPin
  noTone(buzzerPin);

  delay(50);

  //Increment counter
  counter++;
}

void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);
}

void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);

  delay(325);

  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  

  delay(350);
}

// Apaga todos
void setAllLow() {
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	digitalWrite(pinC, LOW);
	digitalWrite(pinD, LOW);
}

void enter_password(int delay_time){
	setAllLow();
	delay(delay_time);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinD, HIGH);
	delay(delay_time);
}

void enter_password_1(int delay_time){
	setAllLow();
	digitalWrite(pinA, HIGH);
	delay(delay_time);
}

void enter_password_2(int delay_time){
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	delay(delay_time);
}

void enter_password_3(int delay_time){
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	delay(delay_time);
}

void enter_password_4(int delay_time){
	setAllLow();
	digitalWrite(pinA, HIGH);
	digitalWrite(pinB, HIGH);
	digitalWrite(pinC, HIGH);
	digitalWrite(pinD, HIGH);
	delay(delay_time);
}

// Abrir puerta

void abre_puerta(){
	while( analogRead(LDR) > ldr_rango ){
		motor_vas_a(200);
	}
	motor_para(100);
	espera_auto();
}

// Cierra puerta

void cierra_puerta(){
	delay(1000);
	while( analogRead(LDR) > ldr_rango ){
		motor_vas_b(200);
	}
	motor_para(100);
	play_music();
	
}

void espera_auto(){
	delay(1000);
	while( analogRead(LDR) > ldr_rango ){
		digitalWrite(ledPin2, HIGH);
		digitalWrite(ledPin3, HIGH);
	}
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin3, LOW);
	cierra_puerta();
	//cierra_puerta();
	
}

void apaga_sonido(int ms) {
	digitalWrite(buzzerPin, LOW);
	delay(ms);
}

void prende_sonido(int ms) {
	digitalWrite(buzzerPin, HIGH);
	delay(ms);
}

void password_incorrecto(){
	prende_sonido(300);
	apaga_sonido(300);
	prende_sonido(300);
	apaga_sonido(300);
	prende_sonido(300);
	apaga_sonido(300);
	prende_sonido(300);
}
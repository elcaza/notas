/*
  LiquidCrystal Library - display() and noDisplay()

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch prints "Hello World!" to the LCD and uses the
  display() and noDisplay() functions to turn on and off
  the display.

  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008
  by David A. Mellis
  library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  example added 9 Jul 2009
  by Tom Igoe
  modified 22 Nov 2010
  by Tom Igoe
  modified 7 Nov 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Boton
int boton_start = 6;

// Leds
int led1 = 10;
int led2 = 9;
int led3 = 8;

// Buzzeer
int buzzer = 13;

// Motores
int motor_vas = 1;
int motor_regresa = 0;

// LDR
int LDR    = A0;

// variables
int direccion = 1;
int es_limite = 0;
int ldr_rango = 512;
int acciona = 0;
int estacion_actual = 1;



/////////////////////////////////
/////////////////////////////////
/////////////////////////////////


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  // lcd.print("> Lala Love You!");

  pinMode(boton_start, INPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buzzer, OUTPUT);
  
  pinMode(motor_vas, OUTPUT);
  pinMode(motor_regresa, OUTPUT);
}

void to_toreo(){
	lcd.clear();
	lcd.print("TOREO");
}

void to_taxquena(){
	lcd.clear();
	lcd.print("TAXQUENA");
}

void set_estacion_1(int ms){ 
	lcd.clear();
	lcd.print("Estacion 1");
	delay(ms);
}

void set_estacion_2(int ms){ 
	lcd.clear();
	lcd.print("Estacion 2");
	delay(ms);
}

void set_estacion_3(int ms){ 
	lcd.clear();
	lcd.print("Estacion 3");
	delay(ms);
}

void cronometro_puertas(int ms){
	lcd.clear();
	lcd.print("10");
	delay(ms);

	lcd.clear();
	lcd.print("9");
	delay(ms);

	lcd.clear();
	lcd.print("8");
	delay(ms);

	lcd.clear();
	lcd.print("7");
	delay(ms);

	lcd.clear();
	lcd.print("6");
	delay(ms);

	lcd.clear();
	lcd.print("5");
	delay(ms);

	lcd.clear();
	lcd.print("4");
	delay(ms);

	lcd.clear();
	lcd.print("3 CORRE GOKU!");
	delay(ms);

	lcd.clear();
	lcd.print("2 CORRE");
	delay(ms);

	lcd.clear();
	lcd.print("1 CORRE GOKU");
	delay(ms);

	lcd.clear();
	lcd.print("0 MUY TARDE GOKU");
	delay(ms);
}

void leds_stop_tren(int ms){
	digitalWrite(led1,HIGH);
	digitalWrite(led2,LOW);
	digitalWrite(led3,LOW);
	delay(ms);

	digitalWrite(led1,HIGH);
	digitalWrite(led2,HIGH);
	digitalWrite(led3,LOW);
	delay(ms);

	digitalWrite(led1,HIGH);
	digitalWrite(led2,HIGH);
	digitalWrite(led3,HIGH);
	delay(ms);
}

void leds_run_tren(int ms){
	digitalWrite(led1,HIGH);
	digitalWrite(led2,HIGH);
	digitalWrite(led3,HIGH);
	delay(ms);

	digitalWrite(led1,HIGH);
	digitalWrite(led2,HIGH);
	digitalWrite(led3,LOW);
	delay(ms);

	digitalWrite(led1,HIGH);
	digitalWrite(led2,LOW);
	digitalWrite(led3,LOW);
	delay(ms);
}

void leds_off(int ms) {
	digitalWrite(led1,LOW);
	digitalWrite(led2,LOW);
	digitalWrite(led3,LOW);
	delay(ms);
}

void apaga_sonido(int ms) {
	digitalWrite(buzzer, LOW);
	delay(ms);
}

void prende_sonido(int ms) {
	digitalWrite(buzzer, HIGH);
	delay(ms);
}

void motor_vas_a(int ms){
	digitalWrite(motor_vas, HIGH);
	digitalWrite(motor_regresa, LOW);
	delay(ms);
}

void motor_vas_b(int ms){
	digitalWrite(motor_vas, LOW);
	digitalWrite(motor_regresa, HIGH);
	delay(ms);
}

void motor_para(int ms){
	digitalWrite(motor_vas, LOW);
	digitalWrite(motor_regresa, LOW);
	delay(ms);
}

int es_vuelta(){
	if(es_limite == 1) {
		es_limite = 0;
		return 1;
	} else {
		return 0;
	}
}

void inicia_recorrido_toreo() {
	direccion = 1;
	to_toreo();

	if( es_vuelta() ) {
		inicia_recorrido_taxquena();
	}

	if( estacion_actual > 3 ){
		es_limite = 1;
		if( es_vuelta() ) {
			es_limite =0;
			inicia_recorrido_taxquena();
		}
	}

	while( analogRead(LDR) > ldr_rango ){
		motor_vas_a(200);
	}
	motor_para(100);

	leds_stop_tren(500);
	prende_sonido(100);
	leds_off(100);
	apaga_sonido(100);

	if (estacion_actual == 1){
		set_estacion_1(2000);
	} else if( estacion_actual == 2) {
		set_estacion_2(2000);
	} else if ( set_estacion_3 == 3 ) {
		set_estacion_3(2000);
	}
	
	cronometro_puertas(1000);
	to_toreo();
	leds_run_tren(500);
	leds_off(100);
	prende_sonido(100);
	apaga_sonido(100);
	estacion_actual++;
}

void inicia_recorrido_taxquena() {
	direccion = 0;
	to_taxquena();

	if( es_vuelta() ) {
		inicia_recorrido_toreo();
	}

	if( estacion_actual == 0 ){
		es_limite = 1;
		if( es_vuelta() ) {
			inicia_recorrido_toreo();
		}
	}

	while( analogRead(LDR) > ldr_rango ){
		motor_vas_b(200);
	}
	motor_para(100);

	leds_stop_tren(500);
	prende_sonido(100);
	leds_off(100);
	apaga_sonido(100);

	if (estacion_actual == 1){
		set_estacion_1(2000);
	} else if( estacion_actual == 2) {
		set_estacion_2(2000);
	} else if ( set_estacion_3 == 3 ) {
		set_estacion_3(2000);
	}
	
	cronometro_puertas(1000);
	to_toreo();
	leds_run_tren(500);
	leds_off(100);
	prende_sonido(100);
	apaga_sonido(100);
	estacion_actual--;
}


void loop() {
	// Turn off the display:
	lcd.noDisplay();
	delay(500);
	// Turn on the display:
	lcd.display();
	delay(500);

	// inicia_recorrido_taxquena();
	acciona=digitalRead(boton_start);//se le asigna al Boton el estado de val e inicia la secuencia 
	if(acciona==HIGH){
		// digitalWrite(led1,HIGH);
		if (direccion == 1){
				inicia_recorrido_toreo();
			} else {
				inicia_recorrido_taxquena();
			// }
		}
	}
}
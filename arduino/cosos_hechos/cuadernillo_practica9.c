// Sensor proximidad garage
const int pin_echo=8;
const int pin_trigger=9;
int led13=13;
unsigned int tiempo, distancia;
int choque_cortinilla;

// Subiendo
int led_subiendo=7;
int boton_subir=5;

// Bajando
int led_bajando=6;
int boton_bajar=4;

void setup() {
	pinMode(pin_echo, INPUT);
	pinMode(pin_trigger, OUTPUT);
	pinMode(led13,OUTPUT);

	pinMode(led_subiendo,OUTPUT);
	pinMode(led_bajando,OUTPUT);

	pinMode(boton_subir,INPUT);
	pinMode(boton_bajar,INPUT);
}

// Return 1 if cortinilla pegando
int checha_sensor(){
	digitalWrite(pin_trigger, LOW);
	delayMicroseconds(2);

	digitalWrite(pin_trigger, HIGH);
	delayMicroseconds(10);

	digitalWrite(pin_trigger, LOW);

	tiempo=pulseIn(pin_echo,HIGH);
	distancia=tiempo/58;

	if(distancia>=15) {
		digitalWrite(led13,LOW);
		return 0;
	} else {
		digitalWrite(led13,HIGH);
		return 1;
	}
}

void loop() {
	if( digitalRead(boton_subir) ) 
	{
		digitalWrite(led_subiendo,HIGH);
		choque_cortinilla = checha_sensor();
		while(!choque_cortinilla)
		{
			choque_cortinilla = checha_sensor();
		}
		digitalWrite(led_subiendo,LOW);
	}
	else if ( digitalRead(boton_bajar) ) 
	{
		digitalWrite(led_bajando,HIGH);
		choque_cortinilla = checha_sensor();
		while(!choque_cortinilla)
		{
			choque_cortinilla = checha_sensor();
		}
		digitalWrite(led_bajando,LOW);
	}
	
}
//Declaracion de variables
int led1=7;
int led2=6;
int led3=5;
int led4=4;
int ledB=3;
int Boton=2;
int buzzer=8;
int LDR=A0;
int val=0;
int val1=0;
int rango=512;

//Declaracion de condiciones iniciales
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(ledB,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(Boton,INPUT);
}
  //lop de programacion
void loop() {
  val1=digitalRead(Boton);
  
  if(val1==HIGH){
    digitalWrite(ledB,HIGH);
   val=analogRead(LDR);
   if(val<=rango){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    delay(500);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    delay(500);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    delay(500);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    delay(500);

    digitalWrite(buzzer,HIGH);
    delay(500);
    
    digitalWrite(buzzer,LOW);
    delay(500);

    digitalWrite(buzzer,HIGH);
    delay(500);

    digitalWrite(buzzer,LOW);
    delay(500);

    digitalWrite(buzzer,HIGH);
    delay(500);

    digitalWrite(buzzer,LOW);
    delay(500);

    digitalWrite(buzzer,HIGH);
    delay(500);

    digitalWrite(buzzer,LOW);
    delay(500);

   }
   else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(buzzer,LOW);
   }
  }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(ledB,LOW);
    digitalWrite(buzzer,LOW);
    }
}

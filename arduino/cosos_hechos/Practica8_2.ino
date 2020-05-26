//Declaracion de variables
int led=2;
int LDR=A0;
int val=0;
int rango=512;

//Declaracion de condiciones iniciales
void setup() {
  pinMode(led,OUTPUT);
}
  //lop de programacion
void loop() {
   val=analogRead(LDR);
   if(val<=rango){
    digitalWrite(led,HIGH);
   }
   else{
    digitalWrite(led,LOW);
   }
}

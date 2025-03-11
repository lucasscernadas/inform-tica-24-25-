// C++ code
//
/* el potenciometro permite elegir entre seis colores distintos,
estos colores se encuentran entre los valores 38000 y 125000 
del potenciometro*/

int verde=7;
int azul=6;
int rojo=5;
int valor;

void setup()
{
 pinMode(verde,OUTPUT);
 pinMode(azul,OUTPUT);
 pinMode(rojo,OUTPUT); 
 Serial.begin(9600); 
}

void loop()
{
  valor = map(analogRead(A5),0,1023,0,70);
 if ((valor>0) and (valor<=10))
 {
   digitalWrite(verde,HIGH);
   digitalWrite(azul,LOW);
   digitalWrite(rojo,LOW);
   Serial.print("verde:");
   Serial.println(valor);
   delay(500);
 }
  
   if ((valor>10) and (valor<=20))
 {
   digitalWrite(verde,LOW);
   digitalWrite(azul,HIGH);
   digitalWrite(rojo,LOW);
   Serial.print("azul:");
   Serial.println(valor);
   delay(500);
 }
  
  if ((valor>20) and (valor<=30))
 {
   digitalWrite(verde,LOW);
   digitalWrite(azul,LOW);
   digitalWrite(rojo,HIGH);
   Serial.print("rojo:");
   Serial.println(valor);
   delay(500);
 }
  
   if ((valor>30) and (valor<=40))
 {
   digitalWrite(verde,HIGH);
   digitalWrite(azul,HIGH);
   digitalWrite(rojo,LOW);
   Serial.print("cian:");
   Serial.println(valor);
   delay(500);
 }
  
   if ((valor>40) and (valor<=50))
 {
   digitalWrite(verde,HIGH);
   digitalWrite(azul,LOW);
   digitalWrite(rojo,HIGH);
   Serial.print("amarillo:");
   Serial.println(valor);
   delay(500);
 }
  
   if ((valor>50) and (valor<=60))
 {
   digitalWrite(verde,LOW);
   digitalWrite(azul,HIGH);
   digitalWrite(rojo,HIGH);
   Serial.print("magenta:");
   Serial.println(valor);
   delay(500);
 }
}

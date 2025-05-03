//lucas cerndas martinez

#include<Servo.h>                     
Servo Servo;                           //SERVO
int const PotPin=A0;                   //POTNECIOMETRO
int PotVal;                            //POTENCIOMETRO
int angulo;                            //SERVO

void setup()
{
  Servo.attach(2);                     //SERVO
  Serial.begin(9600);
}
void loop()
{
	PotVal=analogRead(PotPin);         //LEER EL POTENCIOMETRO
	Serial.print("Valor del potenciometro:");
    Serial.print(PotVal);
	Serial.print("\n");
	angulo=map(PotVal,0,1023,0,179);   //""LEER EL SERVO""
	Serial.print("Valor del angulo=");
	Serial.println (angulo);
    Servo.write(angulo);               //HACERL QUE EL SERVO IMITE AL POTENCIOMETRO
	delay(200);
}

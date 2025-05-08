// Lucas Cernadas Martínez

#include <Servo.h>

//entradas
int pot1;
int pot2;
int pot3;

//salidas
Servo servo1;
Servo servo2;
Servo servo3;
 

void setup()
{
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);  
}

void loop()
{
  pot1 = map (analogRead(A0),0, 1023, 0, 180);
  servo1.write(pot1);
  delay(15); 
  
  pot2 = map (analogRead(A1),0, 1023, 0, 180);
  servo2.write(pot2);
  delay(15); 
  
  pot3 = map (analogRead(A2),0, 1023, 0, 180);
  servo3.write(pot3);
  delay(15); 
}

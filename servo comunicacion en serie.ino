//lucas cernadas martinez

#include<Servo.h>  

Servo uno;

void setup(){
  uno.attach(2);
  Serial.begin(9600);
  Serial.println("control servo");
}

void loop(){

uno.write(90);
delay(1000);
uno.write(0);
delay(1000);

}

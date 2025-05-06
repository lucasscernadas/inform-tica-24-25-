//Lucas Cernadas Martínez

#define POTENCIOMETRO A5
#include <Servo.h>

Servo servoMotor;

int val;              
int angulo = 0;      
bool modoSerial = false;
unsigned long ultimoTiempoSerie = 0;

void setup() {
  servoMotor.attach(9);
  Serial.begin(9600);
  Serial.println("Modo inicial: Potenciómetro.");
  Serial.println("Escribe un ángulo (0-180) para control desde el Monitor Serie.");
}

void loop() {
 
  if (Serial.available() > 0) {
    int entrada = Serial.parseInt();
    if (entrada >= 0 && entrada <= 180) {
      angulo = entrada;
      modoSerial = true;
      ultimoTiempoSerie = millis();
      Serial.print("Modo serie: ángulo = ");
      Serial.println(angulo);
    } else {
      Serial.println("Ángulo inválido. Debe estar entre 0 y 180.");
    }
  }

 
  if (!modoSerial) {
    val = analogRead(POTENCIOMETRO);
    angulo = map(val, 0, 1023, 0, 180);
  }

  
  servoMotor.write(angulo);
  delay(15);

  
  if (modoSerial && (millis() - ultimoTiempoSerie > 5000)) {
    modoSerial = false;
    Serial.println("Sin entrada en serie. Volviendo a control por potenciómetro.");
  }
}

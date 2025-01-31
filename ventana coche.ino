// C++ code
//activanción do motor dunha xanela
//
#define PULS 13
#define RELE_ARRIBA 12
#define RELE_ABAIXO 11

//declaración de variables globais
bool arriba = false;
int tempo = 20;
int contador = -1;

void setup(){
  pinMode(PULS, INPUT);
  pinMode(RELE_ARRIBA, OUTPUT);
  pinMode(RELE_ABAIXO, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  //leer pulsador
  if(digitalRead(PULS)){
    arriba = !arriba;
    while(digitalRead(PULS)) {
      delay(tempo/2);
    }
    contador = 350;
    Serial.println("Pulsador premido");
  }
  // si pulsador premido una vez, motor arriba. Se premido dúas veces
  //motor abaixo
  //motor debe esperar 7 segundos antes de parar
  if(contador > 0){
    if(arriba == true){
      digitalWrite(RELE_ARRIBA, HIGH);
      digitalWrite(RELE_ABAIXO, LOW);
      delay(tempo);
    }
    else {
      digitalWrite(RELE_ARRIBA, LOW);
      digitalWrite(RELE_ABAIXO, HIGH);
      delay(tempo);
    }
      contador = contador -1;
  }
  else {
    digitalWrite(RELE_ARRIBA, LOW);
    digitalWrite(RELE_ABAIXO, LOW);
  }
}

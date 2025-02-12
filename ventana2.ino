/*progrma que imita o funcionamento simplificado dunha ventana dun
coche.
cando prememos unha vez, o pulsador activa un motor que move 
o vdrio cara arriba; ao premer unha segunda vez, o pulsador
activa outro motor que move o vidrio cara abaixo.
Tanto as entradas como as saídas son dixitais, polo que ímos 
activar os motores mediante dous relés.
cada un dos motores para ao estar aceso 7 segundos.
Durante ese tempo, o pulsador pode en calquera momento parar o motor activo. 
Cada pulsación do (volver atrás, sen pasar por paro).
Hai que asegurar que o pulsadoré reactivo ante calquer accionamento do usuario
autor: cernadas
*/
#define PULS 10
#define RELE_ARRIBA 11
#define RELE_ABAIXO 12
#define FC_SUPERIOR 8
#define FC_INFERIOR 9

//declaración de variables globais
int estado = 1;


void setup(){
  pinMode(PULS, INPUT);
  pinMode(RELE_ARRIBA, OUTPUT);
  pinMode(RELE_ABAIXO, OUTPUT);
  pinMode(FC_SUPERIOR, INPUT);
  pinMode(FC_INFERIOR, INPUT);
  
  Serial.begin(9600);
}

void loop(){
  testSensores();
  switch(estado) {
    case 0:
    impulsoSubida();
    break;
    case 2:
      impulsoBaixada();
    break;
    default:
    paro();
  }
  Serial.print("Estado: "); Serial.println(estado);
}
void impulsoSubida(){
  digitalWrite(RELE_ARRIBA, HIGH);
  digitalWrite(RELE_ABAIXO, LOW);
  delay(70);
}
  void impulsoBaixada(){
    digitalWrite(RELE_ARRIBA, LOW);
    digitalWrite(RELE_ABAIXO, HIGH);
    delay(70);
  }
  void paro(){
    digitalWrite(RELE_ARRIBA, LOW);
    digitalWrite(RELE_ABAIXO, LOW);
    if(estado == 0 || estado ==2){
      estado +=1;
    }
    delay(70);
  }
   void testSensores(){
      if(digitalRead(PULS)){
      estado = (estado = 1) % 4;
        while(digitalRead(PULS)){
          delay(20);
        }
      }
     if(digitalRead(FC_SUPERIOR)){
       if(estado != 2){
         estado -1;
       }
     }
     if(digitalRead(FC_INFERIOR)){
       if(estado != 0){
         estado -3;
       }
     }
   }
            

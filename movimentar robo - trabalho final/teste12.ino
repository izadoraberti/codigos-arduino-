//BOTOES}---------------------------------------------------------
#define pinB1 18//botao 1 (direita)
#define pinB2 19//botao 2 (esquerda)
//MOTOR}---------------------------------------------------------
//PONTE H - pinos para controlar o motor
#define DIR_pwm   5    //pino de pwm do arduino para motor da direita
#define N4_DIR  6      //n4 direita - pino do arduino para acionar motor da direita
#define N3_ESQ  7      //n3 esquerda - pino do arduino para acionar motor da esquerda
#define N2_DIR 8       //n2 direita - pino do arduino para acionar motor da direita 
#define N1_ESQ  9      //n1 esquerda - pino do arduino para acionar motor da esquerda
#define ESQ_pwm   10   // pino de pwm do arduino para motor da esquerda 
//VELOCIDADE (valores de PWM)
#define NORMAL_VEL 70  // Valor constante para alimentar os motores. Valores de 0 à 255.
#define NORMAL_VELe 70  // Valor constante para alimentar os motores. Valores de 0 à 255.
#define PARA_VEL 0
//SONAR}---------------------------------------------------------
//FRONTAL
#define ECHOf  35 // Pino 19 do Arduino - eco (rx) - onda refletida pelo objeto é capturada.
#define TRIGf  34 // Pino 18 Arduino - Trig (tx) - transmitido como ultrassom pelo ar.
//ESQUERDO
#define ECHOe  22 // Pino 14 do Arduino - eco (rx) - onda refletida pelo objeto é capturada.
#define TRIGe  23 // Pino 15 Arduino - Trig (tx) - transmitido como ultrassom pelo ar.
//DIREITA
#define ECHOd  44 // Pino 17 do Arduino - eco (rx) - onda refletida pelo objeto é capturada.
#define TRIGd  45 // Pino 16 Arduino - Trig (tx) - transmitido como ultrassom pelo ar.
#define minD 18   // distancia minima

void setup(){
  Serial.begin(9600);
  pinMode(TRIGf,OUTPUT);
  pinMode(ECHOf,INPUT);
  pinMode(TRIGd,OUTPUT);
  pinMode(ECHOd,INPUT);
  pinMode(TRIGe,OUTPUT);
  pinMode(ECHOe,INPUT);
  pinMode(DIR_pwm,OUTPUT);
  pinMode(N4_DIR,OUTPUT);
  pinMode(N3_ESQ,OUTPUT);
  pinMode(N2_DIR,OUTPUT);
  pinMode(N1_ESQ,OUTPUT);
  pinMode(ESQ_pwm,OUTPUT);
  pinMode(pinB1,INPUT);
  pinMode(pinB2,INPUT);
}

void loop(){
  int distF,distD,distE;

  distD=SONAR_D();
  distE=SONAR_E();
  distF=SONAR_F();
      
  botao();
  if(distD>minD){
    botao();
    direita();
    distF=SONAR_F();
    if(distF>minD){
      frente();
    }
    botao();
  }else{
    if(distF>minD)
      frente();
    else{
      if(distE>minD){
        esquerda();
        distF=SONAR_F();
        if(distF>minD)
          frente();
        botao();
      }else{
        distD=SONAR_D();
        distE=SONAR_E();
        distF=SONAR_F();
        if(distE<minD&&distD<minD&&distF<minD)
          vira();
      }
    }
  }
}

unsigned int SONAR_F(){
 unsigned int distfF; 
 digitalWrite(TRIGf, LOW); // Seta trigger como baixo(0) por 2uS
 delayMicroseconds(2);
 digitalWrite(TRIGf, HIGH); // coloca trigger em estado alto
 delayMicroseconds(10); // por 10uS, pode uasr tbm delay (1) que equivale a 10uS
 digitalWrite(TRIGf, LOW); // coloca em estado baixo
 distfF = pulseIn(ECHOf, HIGH); //deixa eco em alto e retorna o tempo em milissegundos
 distfF = distfF/58; // Calcula a distância do pelo tempo do pulso
 Serial.println(distfF);
 return distfF;
}
unsigned int SONAR_D(){
 unsigned int distD; 
 digitalWrite(TRIGd, LOW); // Seta trigger como baixo(0) por 2uS
 delayMicroseconds(2);
 digitalWrite(TRIGd, HIGH); // coloca trigger em estado alto
 delayMicroseconds(10); // por 10uS, pode uasr tbm delay (1) que equivale a 10uS
 digitalWrite(TRIGd, LOW); // coloca em estado baixo
 distD = pulseIn(ECHOd, HIGH); //deixa eco em alto e retorna o tempo em milissegundos
 distD = distD/58; // Calcula a distância do pelo tempo do pulso
 Serial.println(distD);
 return distD;
}
unsigned int SONAR_E(){
 unsigned int distE; 
 digitalWrite(TRIGe, LOW); // Seta trigger como baixo(0) por 2uS
 delayMicroseconds(2);
 digitalWrite(TRIGe, HIGH); // coloca trigger em estado alto
 delayMicroseconds(10); // por 10uS, pode uasr tbm delay (1) que equivale a 10uS
 digitalWrite(TRIGe, LOW); // coloca em estado baixo
 distE = pulseIn(ECHOe, HIGH); //deixa eco em alto e retorna o tempo em milissegundos
 distE = distE/58; // Calcula a distância do pelo tempo do pulso
 Serial.println(distE);
 return distE;
}
void parar(){
  analogWrite(ESQ_pwm, NORMAL_VELe);
  analogWrite(DIR_pwm, NORMAL_VEL);
  digitalWrite(N1_ESQ, LOW);
  digitalWrite(N3_ESQ, LOW);
  digitalWrite(N2_DIR, LOW);
  digitalWrite(N4_DIR, LOW);
  delay(200);
}
void frente(){
  parar();
  analogWrite(ESQ_pwm, NORMAL_VELe);
  analogWrite(DIR_pwm, NORMAL_VEL);
  digitalWrite(N1_ESQ, LOW);
  digitalWrite(N3_ESQ, HIGH);
  digitalWrite(N2_DIR, LOW);
  digitalWrite(N4_DIR, HIGH);
  delay(500);
  parar();
}
void tras(){
  parar();
  analogWrite(ESQ_pwm, NORMAL_VELe);
  analogWrite(DIR_pwm, NORMAL_VEL);
  digitalWrite(N1_ESQ, HIGH);
  digitalWrite(N3_ESQ, LOW);
  digitalWrite(N2_DIR, HIGH);
  digitalWrite(N4_DIR, LOW);
  delay(250);
  parar();
}
void esquerda(){
  parar();
  analogWrite(ESQ_pwm, NORMAL_VELe);
  analogWrite(DIR_pwm, NORMAL_VEL);
  digitalWrite(N1_ESQ, LOW);
  digitalWrite(N3_ESQ, HIGH);
  digitalWrite(N2_DIR, HIGH);
  digitalWrite(N4_DIR, LOW);
  delay(180);
  parar();
}
void direita(){
  parar();
  analogWrite(ESQ_pwm, NORMAL_VELe);
  analogWrite(DIR_pwm, NORMAL_VEL);
  digitalWrite(N1_ESQ, HIGH);
  digitalWrite(N3_ESQ, LOW);
  digitalWrite(N2_DIR, LOW);
  digitalWrite(N4_DIR, HIGH);
  delay(180);
  parar();
}
void vira(){
  parar();
  analogWrite(ESQ_pwm, NORMAL_VELe);
  analogWrite(DIR_pwm, NORMAL_VEL);
  digitalWrite(N1_ESQ, LOW);
  digitalWrite(N3_ESQ, HIGH);
  digitalWrite(N2_DIR, HIGH);
  digitalWrite(N4_DIR, LOW);
  delay(330);
  parar();
}
void esquerdabotao(){
  parar();
  analogWrite(ESQ_pwm, NORMAL_VELe);
  analogWrite(DIR_pwm, NORMAL_VEL);
  digitalWrite(N1_ESQ, LOW);
  digitalWrite(N3_ESQ, HIGH);
  digitalWrite(N2_DIR, HIGH);
  digitalWrite(N4_DIR, LOW);
  delay(120);
  parar();
}
void direitabotao(){
  parar();                                                               
  analogWrite(ESQ_pwm, NORMAL_VELe);
  analogWrite(DIR_pwm, NORMAL_VEL);
  digitalWrite(N1_ESQ, HIGH);
  digitalWrite(N3_ESQ, LOW);
  digitalWrite(N2_DIR, LOW);
  digitalWrite(N4_DIR, HIGH);
  delay(120);
  parar();
}
void botao(){
  int estadoBotaoE = 0;
  int estadoBotaoD = 0;
  estadoBotaoE = digitalRead(pinB1);
  estadoBotaoD = digitalRead(pinB2);
  if(estadoBotaoE == LOW || estadoBotaoD == LOW){
    if(estadoBotaoE == LOW){
      tras();
      esquerdabotao();
    }
    if(estadoBotaoD == LOW){
      tras();
      direitabotao();
     }
  }
}

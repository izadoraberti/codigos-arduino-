//MOTOR}---------------------------------------------------------
//PONTE H - pinos para controlar o motor
#define DIR_pwm   5    //pino de pwm do arduino para motor da direita
#define N4_DIR  6      //n4 direita - pino do arduino para acionar motor da direita
#define N3_ESQ  7      //n3 esquerda - pino do arduino para acionar motor da esquerda
#define N2_DIR 8       //n2 direita - pino do arduino para acionar motor da direita 
#define N1_ESQ  9      //n1 esquerda - pino do arduino para acionar motor da esquerda
#define ESQ_pwm   10   // pino de pwm do arduino para motor da esquerda 


void setup(){
  pinMode(DIR_pwm,OUTPUT);
  pinMode(N4_DIR,OUTPUT);
  pinMode(N3_ESQ,OUTPUT);
  pinMode(N2_DIR,OUTPUT);
  pinMode(N1_ESQ,OUTPUT);
  pinMode(ESQ_pwm,OUTPUT);
}

void loop(){
  frente();
  tras();
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

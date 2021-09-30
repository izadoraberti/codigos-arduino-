
int potenciometro = 2,tempoDeEspera = 0,gre=12,ye=11,red=10;

byte seven_seg_digits[16][7] = { { 1,1,1,1,1,1,0 },  // = Digito 0
                                 { 0,1,1,0,0,0,0 },  // = Digito 1
                                 { 1,1,0,1,1,0,1 },  // = Digito 2
                                 { 1,1,1,1,0,0,1 },  // = Digito 3
                                 { 0,1,1,0,0,1,1 },  // = Digito 4
                                 { 1,0,1,1,0,1,1 },  // = Digito 5
                                 { 1,0,1,1,1,1,1 },  // = Digito 6
                                 { 1,1,1,0,0,0,0 },  // = Digito 7
                                 { 1,1,1,1,1,1,1 },  // = Digito 8
                                 { 1,1,1,0,0,1,1 },  // = Digito 9
                                 { 1,1,1,0,1,1,1 },  // = Digito A
                                 { 0,0,1,1,1,1,1 },  // = Digito B
                                 { 1,0,0,1,1,1,0 },  // = Digito C
                                 { 0,1,1,1,1,0,1 },  // = Digito D
                                 { 1,0,0,1,1,1,1 },  // = Digito E
                                 { 1,0,0,0,1,1,1 }   // = Digito F
                                 };


void setup() 
{  
  pinMode(2, OUTPUT); //Pino 2 do Arduino ligado ao segmento A  
  pinMode(3, OUTPUT); //Pino 3 do Arduino ligado ao segmento B
  pinMode(4, OUTPUT); //Pino 4 do Arduino ligado ao segmento C
  pinMode(5, OUTPUT); //Pino 5 do Arduino ligado ao segmento D
  pinMode(6, OUTPUT); //Pino 6 do Arduino ligado ao segmento E
  pinMode(7, OUTPUT); //Pino 7 do Arduino ligado ao segmento F
  pinMode(8, OUTPUT); //Pino 8 do Arduino ligado ao segmento G
  pinMode(9, OUTPUT); //Pino 9 do Arduino ligado ao segmento PONTO
  writePonto(0);  // Inicia com o ponto desligado
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(ye,OUTPUT);
  pinMode(gre,OUTPUT);
}

void writePonto(byte dot)   //Funcao que aciona o ponto no display
{  
  digitalWrite(9, dot);
}

void sevenSegWrite(byte digit)  //Funcao que aciona o display
{
  byte pin = 2;
  //Percorre o array ligando os segmentos correspondentes ao digito
  for (byte segCount = 0; segCount < 7; ++segCount){ 
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
    writePonto(1);  //Liga o ponto
    delay(100);   //Aguarda 100 milisegundos
    writePonto(0);  //Desliga o ponto
}

void loop() 
{

  
  tempoDeEspera = analogRead(potenciometro);
  Serial.println(tempoDeEspera);

  if(tempoDeEspera<115)
    sevenSegWrite(0);
   if(tempoDeEspera>128&&tempoDeEspera<220)
    sevenSegWrite(1);
   if(tempoDeEspera>220&&tempoDeEspera<320)
    sevenSegWrite(2);
   if(tempoDeEspera>320&&tempoDeEspera<420)
    sevenSegWrite(3);
   if(tempoDeEspera>420&&tempoDeEspera<520)
    sevenSegWrite(4);
   if(tempoDeEspera>520&&tempoDeEspera<620)
    sevenSegWrite(5);
   if(tempoDeEspera>620&&tempoDeEspera<720)
    sevenSegWrite(6);
   if(tempoDeEspera>720&&tempoDeEspera<820)
    sevenSegWrite(7);
   if(tempoDeEspera>820&&tempoDeEspera<920)
    sevenSegWrite(8);
   if(tempoDeEspera>920&&tempoDeEspera<1024)
    sevenSegWrite(9);
   
  if(tempoDeEspera<720){
    analogWrite(gre,255);
    analogWrite(ye,0);
    analogWrite(red,0);
  }
   if(tempoDeEspera>720&&tempoDeEspera<920){
    analogWrite(gre,0);
    analogWrite(ye,255);
    analogWrite(red,0);
  }
   if(tempoDeEspera>920){
    analogWrite(gre,0);
    analogWrite(ye,0);
    analogWrite(red,255);
  }

 
}

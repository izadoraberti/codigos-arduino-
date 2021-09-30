   #include  <irremote.h> // incluindo a biblioteca do infravermelho  
  
  const int RECEBE_PINO = 2; // pino 6 no arduino 
   
  int ledverde = 7;// led no pino 10   
  int ledamarelo = 6;   
  int ledvermelho = 5;   
 
  IRrecv ir_recebe(RECEBE_PINO); // declarando a variável do sensor   
  decode_results codigo_recebido; // resultado   
 
  void setup()   
  {   
    Serial.begin(9600); //mostra o resultado no computador   
    ir_recebe.enableIRIn(); // inicia a recepção  
  
    pinMode(ledverde, OUTPUT); //declarado led como saída   
    pinMode(ledamarelo, OUTPUT);   
    pinMode(ledvermelho, OUTPUT);   
  }   
 
  void loop() {   
////////////////////////////////////////////////////////
// comando para ler o codigo de cada tecla e enviar para o Terminal do arduino
  if (ir_recebe.decode(&codigo_recebido)) {  //verifica se um codigo foi recebido   
     if (codigo_recebido.value != 0 ){  
     Serial.println(codigo_recebido.value, HEX); //mostra no serial o resultado   
   }  
 
////////////////////////////////////////////////////////
 
  //tem que colocar o 0x antes do numero hexadecimal, pois só assim para poder comparar no if   
  
 //liga led verde   
   if (codigo_recebido.value == 0x39C618E7){// verifica se foi pressionado o numero 1 dos comandos
     digitalWrite(ledverde, HIGH);   
     delay(500);   
   }   
   //desliga led verde   
   if (codigo_recebido.value == 0x39C658A7) {// verifica se foi pressionado o numero 4 dos comandos  
     digitalWrite(ledverde, LOW);   
     delay(500);   
   }   
 
   //liga led amarelo   
   if (codigo_recebido.value == 0x39C69867) {// verifica se foi pressionado o numero 2 dos comandos   
     digitalWrite(ledamarelo, HIGH);   
     delay(500);   
   }   
 
   //desliga led amarelo   
   if (codigo_recebido.value == 0x39C628D7) {// verifica se foi pressionado o numero 5 dos comandos  
     digitalWrite(ledamarelo, LOW);   
     delay(500);   
   }   
 
   //liga led vermelho   
   if (codigo_recebido.value == 0x39C6D02F) {// verifica se foi pressionado o numero 3 do comando 
     digitalWrite(ledvermelho, HIGH);  
     delay(500);   
   }   
 
   //desliga led vermelho   
   if (codigo_recebido.value == 0x39C6E01F) {// verifica se foi pressionado o numero 6 do comando
     digitalWrite(ledvermelho, LOW);   
     delay(500);   
   }   
   ir_recebe.resume(); // recebe o próximo código  
   delay(200);   
  }   
  }  
</irremote.h>


int PonteEntrada1 = 10;
int PonteSaida1 = 12;
int PonteEntrada2 = 11;
int PonteSaida2 = 13;

void setup(){
pinMode(PonteEntrada1,OUTPUT);
pinMode(PonteSaida1,OUTPUT);
pinMode(PonteEntrada2,OUTPUT);
pinMode(PonteSaida2,OUTPUT);

digitalWrite(PonteEntrada1, HIGH);
digitalWrite(PonteSaida1, LOW);
digitalWrite(PonteEntrada2, LOW);
digitalWrite(PonteSaida2, LOW);
}

void loop(){

AtivaFrente();
delay(5000);
AtivaRe();
delay(5000);

}

void parar(){
digitalWrite(PonteEntrada2, HIGH);
digitalWrite(PonteSaida2, HIGH);
digitalWrite(PonteEntrada1, LOW);
digitalWrite(PonteSaida1, LOW);
delay(200);
}
void AtivaFrente(){
  parar();
digitalWrite(PonteEntrada1, HIGH);
digitalWrite(PonteSaida1, LOW);
digitalWrite(PonteEntrada2, HIGH);
digitalWrite(PonteSaida2, HIGH);
delay(2000);
parar();
}

void AtivaRe(){
  parar();
digitalWrite(PonteEntrada2, LOW);
digitalWrite(PonteSaida2, HIGH);
digitalWrite(PonteEntrada1, LOW);
digitalWrite(PonteSaida1, LOW);
delay(2000);
parar();
}



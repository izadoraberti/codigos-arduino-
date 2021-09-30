int ledAzul = 8;         
int potenciometro = 2;
int tempoDeEspera = 0;
 
void setup() {
  pinMode(ledAzul,OUTPUT);  
  Serial.begin(9600);
}
 
void loop() {
  //Leitura do valor do potenciômetro que é usada como delay
  tempoDeEspera = analogRead(potenciometro);
  Serial.println(tempoDeEspera);
  digitalWrite(ledAzul, HIGH);
  delay(tempoDeEspera);
  digitalWrite(ledAzul, LOW);
  delay(tempoDeEspera);
}

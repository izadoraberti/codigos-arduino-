
int const potenciometroPin = 0;  
int valPotenciometro;          
int motorPin = A1;


void setup(){
pinMode(motorPin, OUTPUT);
analogWrite(motorPin, 0);
Serial.begin(9600);
}


void loop(){ 
  int valPotenciometro = analogRead(potenciometroPin); 
  Serial.println(valPotenciometro);
 // delay(100);
  analogWrite(motorPin, valPotenciometro);
}

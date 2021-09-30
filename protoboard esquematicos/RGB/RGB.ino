/*int red=6,gre=5,blu=3;
void setup() {
  pinMode(red,OUTPUT);
  pinMode(gre,OUTPUT);
  pinMode(blu,OUTPUT);
}

void setColor(int ver, int green, int blue){
analogWrite(red, ver);
analogWrite(gre, green);
analogWrite(blu, blue);
}
void loop() {
  setColor(255,255,255);
}
*/







/*
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup()
{
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
}

void loop()
{
setColor(255, 0, 0); // red
delay(1000);
setColor(0, 255, 0); // green
delay(1000);
setColor(0, 0, 255); // blue
delay(1000);
setColor(255, 255, 0); // yellow
delay(1000);
setColor(80, 0, 80); // purple
delay(1000);
setColor(0, 255, 255); // aqua
delay(1000);
}

void setColor(int red, int green, int blue)
{
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}
*/







/*
#define START_COLOR_CHAR '^'
#define END_COLOR_CHAR '$'
#define COLOR_SIZE 8
#define PIN_RED 9
#define PIN_GREEN 11
#define PIN_BLUE 10

char serialMessage[COLOR_SIZE];
unsigned int readChar;
unsigned int count;
unsigned long color;
unsigned int r;
unsigned int g;
unsigned int b;
boolean readingSerial;

void setup() {
  Serial.begin(9600);
  readingSerial = false;
}

void loop() {
  if (Serial.available() > 0 && !readingSerial) {
    if (Serial.read() == START_COLOR_CHAR) {
      serialReadColor();
    }
  }
}

void serialReadColor() {
  readingSerial = true;
  count = 0;
  
  iniReading:
  if (Serial.available() > 0) {
    readChar = Serial.read();
    if (readChar == END_COLOR_CHAR || count == COLOR_SIZE) {
      goto endReading;
    } else {
      serialMessage[count++] = readChar;
      goto iniReading;
    }
  }
  goto iniReading;
  
  endReading:
  readingSerial = false;
  serialMessage[count] = '\0';
  
  setColor(serialMessage);
}

void setColor(char* value)
{
  // Convert Char* to Long
  color = atol(value);
  
  // Extract RGB
  r = color >> 16 & 0xFF;
  g = color >>  8 & 0xFF;
  b = color >>  0 & 0xFF;
  
  // Send values to analog pins
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
}

*/












const int ledAzul = 8;      //refere-se ao pino digital 8.
const int ledVerde = 9;     //refere-se ao pino digital 9.
const int ledVermelho = 10; //refere-se ao pino digital 10.
 
//Método setup, executado uma vez ao ligar o Arduino.
void setup() {
  //Definindo os pinos digitais (8, 9, 10) como de saída.
  pinMode(ledAzul,OUTPUT);   
  pinMode(ledVerde,OUTPUT);   
  pinMode(ledVermelho,OUTPUT);    
}
 
//Método loop, executado enquanto o Arduino estiver ligado.
void loop() {   
  //Acendendo cada cor individualmente.  
  digitalWrite(ledAzul,HIGH);
  delay(500);
  digitalWrite(ledAzul,LOW);
   
  digitalWrite(ledVerde,HIGH);
  delay(500);
  digitalWrite(ledVerde,LOW);
   
  digitalWrite(ledVermelho,HIGH);
  delay(500);
  digitalWrite(ledVermelho,LOW);    
   
  //Misturando as cores do led para obter cores diferentes.
  digitalWrite(ledAzul,HIGH);     
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,HIGH);
  delay(1500);    
  digitalWrite(ledAzul,HIGH);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,LOW);  
  delay(1500);      
  digitalWrite(ledAzul,LOW);
  digitalWrite(ledVerde,HIGH);
  digitalWrite(ledVermelho,HIGH);
  delay(1500);      
  digitalWrite(ledAzul,HIGH);
  digitalWrite(ledVerde,LOW);
  digitalWrite(ledVermelho,HIGH);
  delay(1500);
}

#include "Servo.h"
  
//Criando um objeto da classe Servo
Servo servoMotorObj;  
  
int const potenciometroPin = 0;  
int const servoMotorPin    = 3;  
int valPotenciometro;            
  
void setup(){ 
  servoMotorObj.attach(servoMotorPin); //associando o pino digital ao objeto da classe Servo
} 
  
void loop(){ 
  valPotenciometro = analogRead(potenciometroPin); 
 
  //mapeando o valor para a escala do servo (entre 0 e 180)
  valPotenciometro = map(valPotenciometro, 0, 1023, 0, 180); 
 
  servoMotorObj.write(valPotenciometro); 
 // delay(15);   
}

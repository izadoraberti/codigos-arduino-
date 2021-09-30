#define receptorIR A0 //Define receptorIR como A0 

long valor_sensor; //Variável para armazenar o valor do sensor 

void setup() 
{   

Serial.begin(9600); //Inicia a serial com um baud rate de 9600 

} 

void loop() 
{      

valor_sensor=0; //Zera a variável para nova leitura      

for(int i=0;i<100;i++) //Laço para pegar 100 amostras   
  valor_sensor = valor_sensor + analogRead(receptorIR); //Soma o valor lido com o valor anterior   

valor_sensor = valor_sensor/100; //Divide a somatória por 100, tirando a média      
//valor_sensor=analogRead(receptorIR);
Serial.println(valor_sensor); //Imprime na serial o valor do sensor   
//delay(500); 

}

#include <LiquidCrystal.h> 
// Incluindo a biblioteca do LCD
#define RS 2
#define EN 3
#define DB4 4
#define DB5 5
#define DB6 6
#define DB7 7
// Definição dos pinos do LCD no arduino
LiquidCrystal lcd(RS,EN,DB4,DB5,DB6,DB7);

int pinoTemperatura = A0; // Pino do sensor de temperatura sendo A0
int pinoRele = 10; // Pino do relé = 10
int buzzer = 9; // Pino do buzzer = 9
unsigned long tempoInicio; // Tempo desde que o programa iniciou
unsigned long tempoMsg = 5000;  // Tempo que as mensagens ficam no LCD - 5 segundos
const unsigned long tempoIrrigar = 30000; // Tempo até ser feita a irrigação - 30 segundos (Em um contexto real, este tempo seria em horas, dependendo de qual planta podendo durar mais ou menos, assim como o tempo de irrigação também)
const unsigned long tempoIrrigacao = 15000; // Tempo que dura a irrigação - 15 segundos
const unsigned long intervaloTotal = tempoIrrigar + tempoIrrigacao; // Soma do tempo até irrigar e o tempo que dura a irrigação

void setup(){  
  
  lcd.begin(16,2); // Liga a interface do LCD
  Serial.begin(9600);
  pinMode(A1, INPUT); // Pino A1 como entrada 
  pinMode(pinoRele, OUTPUT); // Pino do relé como saída
  pinMode (pinoTemperatura, INPUT); // Pino do sensor de temperatura como entrada
  pinMode(buzzer, OUTPUT); // Pino do Buzzer como saída
  
}

void loop(){
  
  int sensorPH = analogRead(A1); // Recebe o valor do sensor de pH (Neste caso usamos um potenciômetro)
  float ph = sensorPH * (14.0/1023.0); // Potenciômetro irá variar de 0 até 14
  int temperatura = analogRead(pinoTemperatura); // Recebe o valor do sensor de temperatura
  double conversor = temperatura*5; // Conversor de temperatura para Celsius
  conversor = conversor/1024;
  double tempCelsius = (conversor-0.5)*100; // Temperatura após convertida em celsius armazenada na variável tempCelsius
  tempoInicio = millis(); // Tempo desde que o programa começou usando a função millis()
  
  if (tempCelsius >= 18 && tempCelsius <= 23 && 6.5 >= ph && ph >= 5.5){
    noTone(buzzer); // Se a temperatura e o pH estiverem nos conformes, o buzzer não ativa
  }
  
  else if (tempCelsius < 18 or tempCelsius > 23 or ph > 6.5 or ph < 5.5){
    tone(buzzer, 1500); // Se a temperatura e o pH não estiverem nos conformes, o buzzer ativa
  }
  
  if (tempoInicio % intervaloTotal < tempoIrrigar){
    // Desativa o relé e o sistema de irrigação
    
    digitalWrite(pinoRele, LOW);
    
    lcd.setCursor(0,0); // Altera a linha que será utilizada no lcd para os próximos comandos
    lcd.print("Irrigacao"); // Escreve no lcd a ação que está sendo realizada pelo sistema
	lcd.setCursor(0,1);
    lcd.print("inativa");
    
    delay(tempoMsg); //Delay de 5 segundos até a próxima mensagem no LCD

    lcd.setCursor(0,0);
    lcd.print("pH da agua:");
    lcd.setCursor(12,0);
    lcd.print(ph); // Exibe no LCD o valor da variável do pH
    lcd.setCursor(0,1);
    
    if (6.5 >= ph && ph >= 5.5){
      lcd.print("pH Recomendado!"); // Se o pH estiver entre 6.5 e 5.5, ele estará no valor recomendado
    }
    else{
      lcd.print("pH Inadequado!");
    }

    delay(tempoMsg);

    lcd.clear(); // Limpa a tela do LCD
    lcd.print("Temp: ");
    lcd.print(tempCelsius); // Exibe no LCD o valor da variável da temperatura em Celsius
    
    if (tempCelsius < 18){ // Se a temperatura estiver abaixo dos 18 graus, ela estará abaixo do recomendado
      lcd.setCursor(0,1);
      lcd.print("Temp. Baixa!");
    }
    
    else if (tempCelsius > 23){ // Se a temperatura estiver acima dos 23 graus, ela estará acima do recomendado
      lcd.setCursor(0,1);
      lcd.print("Temp. Alta!");
    }
    
    else{ // Se a temperatura estiver entre 18 e 23 graus, ela estará no nível recomendado
      lcd.setCursor(0,1);
      lcd.print("Temp. Boa!");
    }

    delay(tempoMsg);
    lcd.clear(); // Limpa o LCD
    
  }
  
  else{
    // Ativa o relé e o sistema de irrigação
    
    digitalWrite(pinoRele, HIGH);
    lcd.setCursor(0,0); 
    lcd.print("Irrigando...");

    delay(tempoMsg);

    lcd.setCursor(0,0);
    lcd.print("pH da agua:");
    lcd.setCursor(12,0);
    lcd.print(ph);
    lcd.setCursor(0,1);
    
    if (6.5 >= ph && ph >= 5.5){
      lcd.print("pH Recomendado!");
    }
    else{
      lcd.print("pH Inadequado!");
    }

    delay(tempoMsg);

    lcd.clear();
    lcd.print("Temp: ");
    lcd.print(tempCelsius);
    
    if (tempCelsius < 18){
      lcd.setCursor(0,1);
      lcd.print("Temp. Baixa!");
    }
    
    else if (tempCelsius > 23){
      lcd.setCursor(0,1);
      lcd.print("Temp. Alta!");
    }
    
    else{
      lcd.setCursor(0,1);
      lcd.print("Temp. Boa!");
    }
    
    delay(tempoMsg);
    lcd.clear();
  }

}


//Define o DHT11
#include <DHT.h>
DHT dht(8, DHT11);

//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Define os pinos que serão usados para ativar o display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Define o sensor de Distância
int echoPin = 10;
int trigPin = 9;
long duration, cm, inches;

//Define os leds
#define ledVermelho 6
#define ledAmarelo 7

//Define o buzzer
int buzzer = 13;

void setup() {
  //Inicialização do Sensor de Distância 
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  //Inicialização dos LEDS
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  
  //Inicialização do DHT11
  dht.begin();
   
  //Inicialização do LCD com o número de colunas e linhas
  lcd.begin(16, 2);

}

void loop() {
  //DHT11
  float temperatura;
  float umidade;
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();

  if (temperatura > 26){
    digitalWrite(ledVermelho, HIGH);
    delay(100);
    
    pinMode(buzzer, OUTPUT);
    // Aciona o buzzer na frequencia relativa ao Dó em Hz
    tone(buzzer,261);    
    // Espera um tempo para Desativar
    delay(200);
    //Desativa o buzzer
    noTone(buzzer); 
    // Aciona o buzzer na frequencia relativa ao Ré em Hz   
    tone(buzzer,293);             
    delay(200);    
    noTone(buzzer); 
    // Aciona o buzzer na frequencia relativa ao Mi em Hz
    tone(buzzer,329);      
    delay(200);
    noTone(buzzer);     
    // Aciona o buzzer na frequencia relativa ao Fá em Hz
    tone(buzzer,349);    
    delay(200);    
    noTone(buzzer); 
    // Aciona o buzzer na frequencia relativa ao Sol em Hz
    tone(buzzer,392);            
    delay(200);
    noTone(buzzer);
  } else {
      digitalWrite(ledVermelho, LOW);
      delay(100);

      pinMode(buzzer, OUTPUT);
      noTone(buzzer);
  }
  // ---------------------------------------
  
  //LCD
  //Limpa a tela
  lcd.clear();

  //Posiciona o cursor na coluna 3, linha 0
  lcd.setCursor(0, 0);
  //Envia o texto para o LCD
  lcd.print("OLA ABESTADO!");
  
  lcd.setCursor(0, 1);
  lcd.print("LCD FUNCIONANDO!");
  delay(3000);

  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Temper: ");
  lcd.print(temperatura);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Umidade: ");
  lcd.print(umidade);
  lcd.print(" %");  
  delay(3000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(inches);
  lcd.print(" polegadas");
  lcd.setCursor(0, 1);
  lcd.print(cm);
  lcd.print(" centímetros");
  delay(3000);
  //--------------------------------------------

  //SensorDistância

  digitalWrite(trigPin, LOW);
  delay(50);
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;
  if (inches <= 4) {
     digitalWrite(ledAmarelo, HIGH);
     delay(100);

     pinMode(buzzer, OUTPUT);
    // Aciona o buzzer na frequencia relativa ao Dó em Hz
    tone(buzzer,261);
    delay(200);
    noTone(buzzer); 
    // Aciona o buzzer na frequencia relativa ao Ré em Hz   
    tone(buzzer,293);             
    delay(200);    
    noTone(buzzer); 
    // Aciona o buzzer na frequencia relativa ao Mi em Hz
    tone(buzzer,329);      
    delay(200);
    noTone(buzzer);     
    // Aciona o buzzer na frequencia relativa ao Fá em Hz
    tone(buzzer,349);    
    delay(200);    
    noTone(buzzer); 
    // Aciona o buzzer na frequencia relativa ao Sol em Hz
    tone(buzzer,392);            
    delay(200);
    noTone(buzzer);
  } else {
      digitalWrite(ledAmarelo, LOW);
      delay(100);

      pinMode(buzzer, OUTPUT);
      noTone(buzzer);
  }
  //-----------------------------------------------
  
}

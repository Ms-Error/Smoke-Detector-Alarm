#include<LiquidCrystal.h>
LiquidCrystal lcd(3,2,11,10,9,5);
int const pins = A1;
int LED_V = 7;
int LED_A = 6;
int sensor = A2;
int LED_R = 4;

void setup(){
  	pinMode(LED_V, OUTPUT);
    pinMode(LED_A, OUTPUT);
    pinMode(LED_R, OUTPUT);
    Serial.begin(9600);
  	lcd.begin(16,2);
}

void loop(){
    int sensorReading = analogRead(pins);
    int valor = map(sensorReading, 300, 750, 0, 3);
  switch(valor){
    case 0:
    digitalWrite(LED_V,HIGH);
     digitalWrite(LED_A,LOW);
     digitalWrite(LED_R,LOW);
  	lcd.setCursor(0,0);
	lcd.write("Low Smoke Lvl");     	
    lcd.setCursor(0,1);
    lcd.write("Safe");
   
  	break;
    
  	case 1:
    digitalWrite(LED_A,HIGH);
     digitalWrite(LED_R,LOW);
    digitalWrite(LED_V,LOW);
    lcd.setCursor(0,0);
    lcd.write("Medium Smoke Lvl"); 
    lcd.setCursor(0,1);
    lcd.write("Cautious");    
      break;
    
  	case 2:
      digitalWrite(LED_R,HIGH);
    digitalWrite(LED_V,LOW);
    digitalWrite(LED_A,LOW);
    lcd.setCursor(0,0);
    lcd.write("High Smoke Lvl");
    lcd.setCursor(0,1);
    lcd.write("Danger");
    break;
  }

  
  delay(500);
}

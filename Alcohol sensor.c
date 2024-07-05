#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16 , 2);
 
 int MQ3= A0;
 int Relay=6;
 int buzzer=5;
 int red_led=3;
 int green_led=4;
 
 
int value;

void setup() {
   Serial.begin(9600);
   lcd.init();
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("welcm 2 Alcohol");
   lcd.setCursor(3, 1);
   lcd.print("Detection!");
    
   delay(10000);
   lcd.clear();
   pinMode(MQ3, INPUT);
   pinMode(Relay, OUTPUT);
   pinMode(buzzer, OUTPUT);
   pinMode(red_led, OUTPUT);
   pinMode(green_led, OUTPUT);
     pinMode(2,INPUT);
   digitalWrite(Relay,LOW);
   digitalWrite(2,LOW);
 }

void loop()
{
  value= analogRead(MQ3);
  Serial.println(value);
  lcd.setCursor(0 ,0);
  lcd.print("AlcoholZone:");
  lcd.print(value);
  
  
  if(value>100)
  {
    digitalWrite(Relay,LOW);
   digitalWrite(buzzer,LOW);
   digitalWrite(red_led,LOW);
   digitalWrite(green_led,HIGH);
   lcd.setCursor(0 ,1);
   lcd.print("HAPPY JOURNEY :)");
   
  }else{
       lcd.setCursor(0 ,1);
       lcd.print("Alcohol Detected");
       digitalWrite(red_led,HIGH);
       digitalWrite(buzzer,HIGH);
       digitalWrite(green_led,LOW);
       delay(2000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 10!!!!");
       delay(1000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 09!!!!");
        delay(1000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 08!!!!");
        delay(1000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 07!!!!");
        delay(1000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 06!!!!");
        delay(1000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 05!!!!");
        delay(1000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 04!!!!");
        delay(1000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 03!!!!"); 
       delay(1000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 02!!!!"); 
        delay(1000);
       lcd.setCursor(0 ,1);
        lcd.print("STOP'S IN 01!!!!"); 
        delay(1000);
       lcd.setCursor(0 ,1);
       lcd.print("STOP'S IN 00!!!!"); 
       digitalWrite(Relay,HIGH);
       digitalWrite(buzzer,HIGH);
        delay (9000);
       lcd.clear();
     }

  delay (900);
}
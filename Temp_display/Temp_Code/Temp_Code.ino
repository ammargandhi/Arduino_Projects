#include<LiquidCrystal.h>
LiquidCrystal lcd(2,4,9,10,11,12);
int temp=A1;
int LED=0;

float temp_final;
void setup()
{
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
 pinMode(temp,INPUT);
 pinMode(LED,OUTPUT);
 
}

void loop()
{
  digitalWrite(LED,LOW);
   temp_final = analogRead(temp)*0.488 ;     
 lcd.setCursor(0,1);
lcd.print("Temperature:");
lcd.print(temp);

lcd.print("Celsius");

if(int(temp)>21)
{
  digitalWrite(LED,HIGH);
}
else
{
  digitalWrite(LED,LOW);
}

}



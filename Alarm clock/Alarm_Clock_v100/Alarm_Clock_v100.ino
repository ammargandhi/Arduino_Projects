
#include <virtuabotixRTC.h>  
#include<toneAC.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(14, 15, 5, 4, 3, 16);
                                        
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978                                                                                                      

// Creation of the Real Time Clock Object
int a,x;
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
virtuabotixRTC myRTC(6, 7, 8);
int val,hours1,minut;
int cursorx=11;    
int up=12;
int SET_ALARM=17;
int HOUR,MINUT,SECOND;
 
void setup()
{

 lcd.begin(16,2);
 pinMode(up, INPUT);
 pinMode(cursorx, INPUT);
 pinMode(SET_ALARM, INPUT);
 digitalWrite(cursorx, HIGH);
 digitalWrite(SET_ALARM, HIGH);
 digitalWrite(up, HIGH);
 
   lcd.setCursor(2,0);
   lcd.print("Alarm Clock");
   delay(2000);
    

}
 
void loop()
{
   int val=0;
   myRTC.updateTime();
   if(digitalRead(SET_ALARM)== 0)      
   { 
     lcd.setCursor(0,0);
     lcd.print("  Set Alarm  ");
    delay(2000);
    defualt();
    time();
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  Alarm time ");
    lcd.setCursor(0,1);
    lcd.print(" has been set  ");
    delay(2000);
 }
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Time:");
 lcd.setCursor(6,0);
 lcd.print(HOUR=myRTC.hours); 
 lcd.print(":");
 lcd.print(MINUT=myRTC.minutes);
 lcd.print(":");
 lcd.print(SECOND=myRTC.seconds);
 lcd.setCursor(0,1);
 lcd.print("Date: ");
 lcd.print(myRTC.dayofmonth);
 lcd.print("/");
 lcd.print(myRTC.month);
 lcd.print("/");
 lcd.print(myRTC.year);
 match();
 delay(200);
}
void defualt()
{
  lcd.setCursor(0,1);
  lcd.print(HOUR);
  lcd.print(":");
  lcd.print(MINUT);
  lcd.print(":");
  lcd.print(SECOND);
}
/*Function to set alarm time and feed time into Internal eeprom*/
void time()                             
{
  int val=1;
    while(val==1)
    {
     if(digitalRead(up)==0)
     {
      HOUR++;
      if(HOUR==24)
      {
       HOUR=0;
      }
      while(digitalRead(up)==0);
     }
     lcd.clear();
      lcd.setCursor(0,0);
    lcd.print("Set Alarm Time ");
   //lcd.print(x); 
    lcd.setCursor(0,1);
    lcd.print(HOUR);
    lcd.print(":");
    lcd.print(MINUT);
    lcd.print(":");
    lcd.print(SECOND);
    delay(100);
    if(digitalRead(cursorx)==0)
    {
      hours1=HOUR;
           val=2;
     while(digitalRead(cursorx)==0);
    }
    }
    
    while(val==2)
    {
     if(digitalRead(up)==0)
     {
      MINUT++;
      if(MINUT==60)
      {MINUT=0;}
      while(digitalRead(up)==0);
     }
     // lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(HOUR);
    lcd.print(":");
    lcd.print(MINUT);
    lcd.print(":");
    lcd.print(SECOND);
    delay(100);
      if(digitalRead(cursorx)==0)
      {
       minut=MINUT;
       val=0;
       while(digitalRead(cursorx)==0);
      }
    }
    delay(1000);
}
/* Function to chack medication time */
void match()
{
  if(HOUR == hours1 && MINUT == minut) 
  {
  lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("BEEPP!!!");
   beep();
   beep();
   
  }
}
/* function to buzzer indication */
void beep()
{
   a = analogRead(A5);
    x= map(a,0,1023,0,10);
  
      for (int thisNote = 0; thisNote < 8; thisNote++) {

  
    int noteDuration = 1000 / noteDurations[thisNote];
   //tone(9, melody[thisNote], noteDuration);
    toneAC(melody[thisNote], x, noteDuration, true);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
}
}

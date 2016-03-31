#include <openGLCD.h>
#include "fonts/allFonts.h"

int flag=1;
int i,j;
void setup() {
   GLCD.Init();   
 GLCD.ClearScreen();
 GLCD.SelectFont(System5x7, BLACK);
 
 pinMode(2,OUTPUT);
 pinMode(1,OUTPUT);
 analogWrite(9,127);
GLCD.DrawCircle(64,10,50,BLACK);
GLCD.DrawLine(64,0,64,50,BLACK);
}

void loop() {
  
if(flag =1){
  digitalWrite(2,HIGH);
  for(i=64,j=50; i>10, j>0 ;i--,j--){
    GLCD.ClearScreen();
  GLCD.DrawCircle(64,10,50,BLACK);
GLCD.DrawLine(64,0,i,j,BLACK);
delay(200);
  }
  digitalWrite(2,LOW);
 delay(2000);
 flag =0;
 i=0;
 j=0;
}
if(flag==0){
 digitalWrite(1,HIGH);
 for(i=64, j=50; i<114, j>0 ;i++,j--){
 GLCD.ClearScreen();
  GLCD.DrawCircle(64,10,50,BLACK);
GLCD.DrawLine(64,0,i,j,BLACK);
delay(200);
 }
  digitalWrite(1,LOW);
 delay(2000);
}

}

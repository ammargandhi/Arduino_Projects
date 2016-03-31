#include <virtuabotixRTC.h>                                                                              //|
                                                                                                        //|
virtuabotixRTC myRTC(2, 3, 4);

#include <SPI.h>
#include <SD.h>

int seconds;
const int chipSelect = 10;
int a1,a2=0;
void setup()
{
  
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}

void loop()
{
   myRTC.updateTime();   
  

seconds=myRTC.seconds;
Serial.print("Current Date / Time: ");                                                                 //| 
  Serial.print(myRTC.dayofmonth);                                                                        //| 
  Serial.print("/");                                                                                     //| 
  Serial.print(myRTC.month);                                                                             //| 
  Serial.print("/");                                                                                     //| 
  Serial.print(myRTC.year);                                                                              //| 
  Serial.print("  ");                                                                                    //| 
  Serial.print(myRTC.hours);                                                                             //| 
  Serial.print(":");                                                                                     //| 
  Serial.print(myRTC.minutes);                                                                           //| 
  Serial.print(":");                                                                                     //| 
  Serial.println(myRTC.seconds);                                                                         //| 
  
a1=analogRead(0);

a2=analogRead(1);

  
  if(seconds==59){

  File dataFile = SD.open("DATALOG.TXT", FILE_WRITE);


  if (dataFile) {
    dataFile.print("Current Date / Time: ");                                                                 //| 
  dataFile.print(myRTC.dayofmonth);                                                                        //| 
  dataFile.print("/");                                                                                     //| 
  dataFile.print(myRTC.month);                                                                             //| 
  dataFile.print("/");                                                                                     //| 
  dataFile.print(myRTC.year);                                                                              //| 
  dataFile.print("  ");                                                                                    //| 
  dataFile.print(myRTC.hours);                                                                             //| 
  dataFile.print(":");                                                                                     //| 
  dataFile.print(myRTC.minutes);                                                                           //| 
  dataFile.print(":");                                                                                     //| 
  dataFile.print(myRTC.seconds);
dataFile.print("CNG sensor:");
dataFile.print(a1);
dataFile.print("Humidity sensor:");
dataFile.print(a2);
dataFile.println("");
    dataFile.close();

  }
  else {
    Serial.println("error opening datalog.txt");

  
}
  }
  delay(1000);
}










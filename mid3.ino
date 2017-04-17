
#include <SevSeg.h>
#include <Keypad.h>
SevSeg sevseg; 

void setup() {
  Serial.begin(9600);
  Serial.println("7 04053124 04053106");
   byte numDigits =4;
   byte digitPins[] ={8,9,12,13};
   byte segmentPins[] = {6,3,10,11,4,7,5};
   sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  
}

void loop() 
{
 
   int val,n=0,x;
    if (Serial.available()) 
    { 
         val = Serial.parseInt();
         if(val<=9999 && val >=0)
          {
            Serial.println(val);
            sevseg.setNumber(val);
            sevseg.refreshDisplay();
          }
     
        else 
       {
            Serial.println("range error");
       }
    }   
   else
   sevseg.refreshDisplay();
   
   
   }

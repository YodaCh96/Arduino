/*******************************************************************************
Company     : Siemens Schweiz AG
Author      : Roshat Yilmaz/Ioannis Christodoulakis
            
Project     : Digitale Uhr
Version     : 1.0
Filename    : digital_Uhr.c
Created     : 01.01.2001 01:01

********************************************************************************
Release Notes:
Version  Date        Author                   Comment/Reason for change
1.0      28.02.2018  Roshat Yilmaz            First release      
1.0      28.02.2018  Ioannis Christodoulakis  First release  
*******************************************************************************/

// Bibliotheken für RTC-Modul
#include <Wire.h>
#include "RTClib.h" // Sketch --> Include Library

RTC_DS1307 rtc;

int UHR[4];
int Zahl; // dargestellte Zahl

int Delay = 5; // Verzoegerungszeit
int n, i, j, k; // Variablen für die for-Schleife

//I/O Pin Definitionen
int BCD_0 = 10, BCD_1 = 11, BCD_2 = 12, BCD_3 = 13;
int Segment_A = 2, Segment_B = 3, Segment_C = 4, Segment_D = 5;

//Arrays
int Segmente[]={Segment_A, Segment_B, Segment_C, Segment_D};
int BCD[]={BCD_0, BCD_1, BCD_2, BCD_3};

void setup (){
  
  while (!Serial);
            
  Serial.begin(9600);
  
  if (! rtc.begin()){ Serial.println("Couldn't find RTC"); while (1);}//if

  if (! rtc.isrunning()){ Serial.println("RTC is NOT running!");
    //  rtc.adjust(DateTime(2018, 2, 28, 9, 52, 0));  //Einstellung für die Zeit RTC
  }//if

   for(i=0; i<4; i++){ // Output für 7 Segmente
       pinMode(Segmente[i], OUTPUT);
      }
      
    for(i=0; i<4; i++){ // Output für 7 Segmente
        pinMode(BCD[i], OUTPUT);
       }
}// setup

void loop (){

    DateTime now = rtc.now();
                
              UHR[0] = now.hour(), DEC;       
              UHR[0] = UHR[0] / 10;           // Erste Ziffer für Stunden: Zehner
              UHR[1] = now.hour(), DEC;
              UHR[1] = UHR[1] % 10;           // Zweite Ziffer für Stunden: Einer
              UHR[2] = now.minute(), DEC;
              UHR[2] = UHR[2] / 10;           // Dritte Ziffer für Minuten: Zehner
              UHR[3] = now.minute(), DEC;
              UHR[3] = UHR[3] % 10;           // Vierte Ziffer für Minuten: Einer        
                  
           /* Serial.print("Uhrzeit: ");
              Serial.print(now.hour());
              Serial.print(":");
              Serial.println(now.minute()); */
          
              for(n=0;n<4;n++){
                
              Zahl = UHR[n];
              
              switch(Zahl){
                
                  case 0: digitalWrite(BCD_0, LOW );     //BCD Code 0 = 0000
                          digitalWrite(BCD_1, LOW );
                          digitalWrite(BCD_2, LOW );
                          digitalWrite(BCD_3, LOW );
                          break;
                          
                  case 1: digitalWrite(BCD_0, HIGH );     //BCD Code 1 = 0001
                          digitalWrite(BCD_1, LOW );
                          digitalWrite(BCD_2, LOW );
                          digitalWrite(BCD_3, LOW );
                          break;
                          
                  case 2: digitalWrite(BCD_0, LOW );     //BCD Code 2 = 0010
                          digitalWrite(BCD_1, HIGH );
                          digitalWrite(BCD_2, LOW );
                          digitalWrite(BCD_3, LOW );
                          break; 
                          
                  case 3: digitalWrite(BCD_0, HIGH );     //BCD Code 3 = 0011
                          digitalWrite(BCD_1, HIGH );
                          digitalWrite(BCD_2, LOW );
                          digitalWrite(BCD_3, LOW );
                          break;
                          
                  case 4: digitalWrite(BCD_0, LOW );     //BCD Code 4 = 0100
                          digitalWrite(BCD_1, LOW );
                          digitalWrite(BCD_2, HIGH );
                          digitalWrite(BCD_3, LOW );
                          break;
                          
                  case 5: digitalWrite(BCD_0, HIGH );     //BCD Code 5 = 0101
                          digitalWrite(BCD_1, LOW );
                          digitalWrite(BCD_2, HIGH );
                          digitalWrite(BCD_3, LOW );
                          break;  
                                  
                  case 6: digitalWrite(BCD_0, LOW );                   //BCD Code 6 = 0110
                          digitalWrite(BCD_1, HIGH );
                          digitalWrite(BCD_2, HIGH );
                          digitalWrite(BCD_3, LOW );
                          break;
                          
                  case 7: digitalWrite(BCD_0, HIGH );                  //BCD Code 7 = 0111
                          digitalWrite(BCD_1, HIGH ); 
                          digitalWrite(BCD_2, HIGH );
                          digitalWrite(BCD_3, LOW );
                          break;
                          
                  case 8: digitalWrite(BCD_0, LOW );                   //BCD Code 8 = 1000
                          digitalWrite(BCD_1, LOW );
                          digitalWrite(BCD_2, LOW );
                          digitalWrite(BCD_3, HIGH );
                          break;
                          
                  case 9: digitalWrite(BCD_0, HIGH );                 //BCD Code 9 = 1001
                          digitalWrite(BCD_1, LOW );
                          digitalWrite(BCD_2, LOW );
                          digitalWrite(BCD_3, HIGH );
                          break;  
                            
                  default:
                             for(k=0; k<4; k++){                     // 7.Segment Blank
                                 digitalWrite(BCD[k], HIGH);       
                                }//for
                          break;
                 }//switch
      
                 switch(n){
                   case 0 : digitalWrite(Segment_A, HIGH);           //Multiplex 1. 7 Segment anzeigen
                            digitalWrite(Segment_B, LOW);
                            digitalWrite(Segment_C, LOW);
                            digitalWrite(Segment_D, LOW);
                            break;
                            
                   case 1 : digitalWrite(Segment_A, LOW);
                            digitalWrite(Segment_B, HIGH);           //Multiplex 2. 7 Segment anzeigen
                            digitalWrite(Segment_C, LOW);
                            digitalWrite(Segment_D, LOW);
                            break;
                            
                   case 2 : digitalWrite(Segment_A, LOW);
                            digitalWrite(Segment_B, LOW);
                            digitalWrite(Segment_C, HIGH);          //Multiplex 3. 7 Segment anzeigen
                            digitalWrite(Segment_D, LOW);
                            break;
                            
                   case 3 : digitalWrite(Segment_A, LOW);
                            digitalWrite(Segment_B, LOW);
                            digitalWrite(Segment_C, LOW);
                            digitalWrite(Segment_D, HIGH);          //Multiplex 4. 7 Segment anzeigen
                            break;   
                               
                   default: 
                              for(j=0; j<4; j++){                  // Bei Fehler kein 7 Segment anzeigen
                                  digitalWrite(Segmente[j], LOW);       
                                 }//for
                            break;
                 }//switch
                 
                 delay(Delay);
                
             }//for
}//loop   

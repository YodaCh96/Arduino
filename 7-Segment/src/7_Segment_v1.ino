// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int UHR[4];
int DATUM[4];
int STOPP[4];
int MODE;
int MSchalter = 7;
int SSchalter = 6;
int Zahl;
int BCD0 = 10;
int BCD1 = 11;
int BCD2 = 12;
int BCD3 = 13;
int ZIF0 = 2;
int ZIF1 = 3;
int ZIF2 = 4;
int ZIF3 = 5;
int Multipl;
int Delay = 5;
int n;
int Punkt = 9;
int Dpunkt = 8;
int SUhr;
int SSTaster= A0;

void setup () {
  while (!Serial);
  MODE = 1 ;           // MODE 1 = Zeit anzeigen

              
  
  Serial.begin(9600);
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");

    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
     // rtc.adjust(DateTime(2018, 2, 20, 13, 20, 0));  //Zeit einmal einstellen für den RTC
  }

    pinMode(ZIF0, OUTPUT);      // Output für 1. 7 Segment
    pinMode(ZIF1, OUTPUT);      // Output für 2. 7 Segment
    pinMode(ZIF2, OUTPUT);      // Output für 3. 7 Segment
    pinMode(ZIF3, OUTPUT);      // Output für 4. 7 Segment
    pinMode(BCD0, OUTPUT);      // Output für BCD Code 4 Stelle
    pinMode(BCD1, OUTPUT);      // Output für BCD Code 3 Stelle
    pinMode(BCD2, OUTPUT);      // Output für BCD Code 2 Stelle
    pinMode(BCD3, OUTPUT);      // Output für BCD Code 1 Stelle
    pinMode(Punkt, OUTPUT);     // Output für Punkt bei Datum
    pinMode(Dpunkt, OUTPUT);    // Output für Doppelpunkt bei Zeit
    pinMode(MSchalter, INPUT);  // Input für Schalter für Modus

    STOPP[0] = 0;
    STOPP[1] = 0;
    STOPP[2] = 0;
    STOPP[3] = 0;
} // setup

void loop () 
{
    if(digitalRead(MSchalter) == HIGH){
      MODE = 1;
    }else{
      MODE = 2;
    }
    DateTime now = rtc.now();
/*
*******************************************************************************************************
START MODE ZEIT
*******************************************************************************************************
*/
    switch(MODE){
      case 1:                                 // Modus ZEIT
              UHR[0] = now.hour(), DEC;       
              UHR[0] = UHR[0] / 10;           // Erste Ziffer für Stunden: Zehner
              UHR[1] = now.hour(), DEC;
              UHR[1] = UHR[1] % 10;           // Zweite Ziffer für Stunden: Einer
              UHR[2] = now.minute(), DEC;
              UHR[2] = UHR[2] / 10;           // Dritte Ziffer für Minuten: Zehner
              UHR[3] = now.minute(), DEC;
              UHR[3] = UHR[3] % 10;           // Vierte Ziffer für Minuten: Einer        
                  
          
              for(n=0;n<4;n++){
              Zahl = UHR[n];
              switch(Zahl){
                  case 0: digitalWrite(BCD0, LOW );     //BCD Code 0 = 0000
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, LOW );
                          break;
                  case 1: digitalWrite(BCD0, LOW );     //BCD Code 1 = 0001
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, HIGH );
                          break;
                  case 2: digitalWrite(BCD0, LOW );     //BCD Code 2 = 0010
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, LOW );
                          break; 
                  case 3: digitalWrite(BCD0, LOW );     //BCD Code 3 = 0011
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, HIGH );
                          break;
                  case 4: digitalWrite(BCD0, LOW );     //BCD Code 4 = 0100
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, LOW );
                          break;
                  case 5: digitalWrite(BCD0, LOW );     //BCD Code 5 = 0101
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, HIGH );
                          break;          
                  case 6: digitalWrite(BCD0, LOW );     //BCD Code 6 = 0110
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, LOW );
                          break;
                  case 7: digitalWrite(BCD0, LOW );     //BCD Code 7 = 0111
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, HIGH );
                          break;
                  case 8: digitalWrite(BCD0, HIGH );    //BCD Code 8 = 1000
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, LOW );
                          break;
                  case 9: digitalWrite(BCD0, HIGH );    //BCD Code 9 = 1001
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, HIGH );
                          break;    
                  default:digitalWrite(BCD0, HIGH );    //BCD Code F = 1111
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, HIGH );
                          break;
                 }//switch
      
                 switch(n){
                   case 0 : digitalWrite(ZIF0, HIGH);      //Multiplex 1. 7 Segment anzeigen
                            digitalWrite(ZIF1, LOW);
                            digitalWrite(Dpunkt, LOW);
                            digitalWrite(ZIF2, LOW);
                            digitalWrite(ZIF3, LOW);
                            break;
                   case 1 : digitalWrite(ZIF0, LOW);
                            digitalWrite(ZIF1, HIGH);      //Multiplex 2. 7 Segment anzeigen
                            digitalWrite(Dpunkt, HIGH);
                            digitalWrite(ZIF2, LOW);
                            digitalWrite(ZIF3, LOW);
                            break;
                   case 2 : digitalWrite(ZIF0, LOW);
                            digitalWrite(ZIF1, LOW);
                            digitalWrite(Dpunkt, LOW);
                            digitalWrite(ZIF2, HIGH);      //Multiplex 3. 7 Segment anzeigen
                            digitalWrite(ZIF3, LOW);
                            break;
                   case 3 : digitalWrite(ZIF0, LOW);
                            digitalWrite(ZIF1, LOW);
                            digitalWrite(Dpunkt, LOW);
                            digitalWrite(ZIF2, LOW);
                            digitalWrite(ZIF3, HIGH);      //Multiplex 4. 7 Segment anzeigen
                            break;      
                   default: digitalWrite(ZIF0, LOW);       // Bei Fehler kein 7 Segment anzeigen
                            digitalWrite(ZIF1, LOW);
                            digitalWrite(Dpunkt, LOW);
                            digitalWrite(ZIF2, LOW);
                            digitalWrite(ZIF3, LOW);
                            break;
                 }//switch
                 delay(Delay);
                  STOPP[0] = 0;
                  STOPP[1] = 0;
                  STOPP[2] = 0;
                  STOPP[3] = 0;
             }//for
              break;
/*
*******************************************************************************************************
ENDE MODE ZEIT
*******************************************************************************************************
START MODE DATUM
*******************************************************************************************************        
*/
   
    case 2:                                   // Modus Datum
              DATUM[0] = now.day(), DEC;
              DATUM[0] = DATUM[0] / 10;       // Erste Ziffer für Tage: Zehner
              DATUM[1] = now. day(), DEC;
              DATUM[1] = DATUM[1] % 10;       // Zweite Ziffer für Tage: Einer
              DATUM[2] = now.month(), DEC;
              DATUM[2] = DATUM[2] / 10;       // Dritte Ziffer für Monate: Zehner
              DATUM[3] = now.month(), DEC;
              DATUM[3] = DATUM[3] % 10;       // Vierte Ziffer für Monate: Einer   
              
          
              for(n=0;n<4;n++){
              Zahl = DATUM[n];
              switch(Zahl){
                  case 0: digitalWrite(BCD0, LOW );      //BCD Code 0 = 0000
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, LOW );
                          break;
                  case 1: digitalWrite(BCD0, LOW );      //BCD Code 1 = 0001
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, HIGH );
                          break;
                  case 2: digitalWrite(BCD0, LOW );      //BCD Code 2 = 0010
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, LOW );
                          break; 
                  case 3: digitalWrite(BCD0, LOW );      //BCD Code 3 = 0011
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, HIGH );
                          break;
                  case 4: digitalWrite(BCD0, LOW );      //BCD Code 4 = 0100
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, LOW );
                          break;
                  case 5: digitalWrite(BCD0, LOW );      //BCD Code 5 = 0101
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, HIGH );
                          break;          
                  case 6: digitalWrite(BCD0, LOW );      //BCD Code 6 = 0110
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, LOW );
                          break;
                  case 7: digitalWrite(BCD0, LOW );      //BCD Code 7 = 0111
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, HIGH );
                          break;
                  case 8: digitalWrite(BCD0, HIGH );     //BCD Code 8 = 1000
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, LOW );
                          break;
                  case 9: digitalWrite(BCD0, HIGH );     //BCD Code 9 = 1001
                          digitalWrite(BCD1, LOW );
                          digitalWrite(BCD2, LOW );
                          digitalWrite(BCD3, HIGH );
                          break;    
                  default:digitalWrite(BCD0, HIGH );     //BCD Code F = 1111
                          digitalWrite(BCD1, HIGH );
                          digitalWrite(BCD2, HIGH );
                          digitalWrite(BCD3, HIGH );
                          break;
                 }//switch
      
                 switch(n){
                   case 0 : digitalWrite(ZIF0, HIGH);      //Multiplex 1. 7 Segment anzeigen
                            digitalWrite(ZIF1, LOW);
                            digitalWrite(Punkt, LOW);
                            digitalWrite(ZIF2, LOW);
                            digitalWrite(ZIF3, LOW);
                            break;
                   case 1 : digitalWrite(ZIF0, LOW);
                            digitalWrite(ZIF1, HIGH);      //Multiplex 2. 7 Segment anzeigen
                            digitalWrite(Punkt, HIGH);
                            digitalWrite(ZIF2, LOW);
                            digitalWrite(ZIF3, LOW);
                            break;
                   case 2 : digitalWrite(ZIF0, LOW);
                            digitalWrite(ZIF1, LOW);
                            digitalWrite(Punkt, LOW);
                            digitalWrite(ZIF2, HIGH);      //Multiplex 3. 7 Segment anzeigen
                            digitalWrite(ZIF3, LOW);
                            break;
                   case 3 : digitalWrite(ZIF0, LOW);
                            digitalWrite(ZIF1, LOW);
                            digitalWrite(Punkt, LOW);
                            digitalWrite(ZIF2, LOW);
                            digitalWrite(ZIF3, HIGH);      //Multiplex 4. 7 Segment anzeigen
                            break;      
                   default: digitalWrite(ZIF0, LOW);       // Bei Fehler kein 7 Segment anzeigen
                            digitalWrite(ZIF1, LOW);
                            digitalWrite(Punkt, LOW);
                            digitalWrite(ZIF2, LOW);
                            digitalWrite(ZIF3, LOW);
                            break;
                 }//switch
                 delay(Delay);
                 STOPP[0] = 0;
                 STOPP[1] = 0;
                 STOPP[2] = 0;
                 STOPP[3] = 0;
             }//for
             break;
    }//switch
}//loop   
/*
*******************************************************************************************************
ENDE MODE DATUM
*******************************************************************************************************
*/

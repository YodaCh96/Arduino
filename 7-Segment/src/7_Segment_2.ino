// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

int UHR[4];
int Zahl;

int BCD0A = 10;
int BCD1A = 11;
int BCD2A = 12;
int BCD3A = 13;

int BCD0B = 9;
int BCD1B = 8;
int BCD2B = 7;
int BCD3B = 6;

int BCD0C = 5;
int BCD1C = 4;
int BCD2C = 3;
int BCD3C = 2;

int BCD0D = 14;
int BCD1D = 15;
int BCD2D = 16;
int BCD3D = 17;

int Multipl;
int Delay = 5;
int n;
int Punkt = 9;
int Dpunkt = 8;
int SUhr;


int Position[4][4]{
  
  {BCD0A,BCD1A,BCD2A,BCD3A},
  {BCD0B,BCD1B,BCD2B,BCD3B},
  {BCD0C,BCD1C,BCD2C,BCD3C},
  {BCD0D,BCD1D,BCD2D,BCD3D},
  
  };

void setup () {
  while (!Serial);
  Serial.begin(9600); 
  if (! rtc.begin()) {
    while (1);
  }
  if (! rtc.isrunning()) {
      rtc.adjust(DateTime(2018, 2, 20, 14, 57, 0));  // Zeit einmal einstellen für den RTC
  }
    pinMode(BCD0A, OUTPUT); // Output für BCD Code 4 Stelle
    pinMode(BCD1A, OUTPUT); // Output für BCD Code 3 Stelle
    pinMode(BCD2A, OUTPUT); // Output für BCD Code 2 Stelle
    pinMode(BCD3A, OUTPUT); // Output für BCD Code 1 Stelle
    pinMode(BCD0B, OUTPUT); // Output für BCD Code 4 Stelle
    pinMode(BCD1B, OUTPUT); // Output für BCD Code 3 Stelle
    pinMode(BCD2B, OUTPUT); // Output für BCD Code 2 Stelle
    pinMode(BCD3B, OUTPUT); // Output für BCD Code 1 Stelle
    pinMode(BCD0C, OUTPUT); // Output für BCD Code 4 Stelle
    pinMode(BCD1C, OUTPUT); // Output für BCD Code 3 Stelle
    pinMode(BCD2C, OUTPUT); // Output für BCD Code 2 Stelle
    pinMode(BCD3C, OUTPUT); // Output für BCD Code 1 Stelle
    pinMode(BCD0D, OUTPUT); // Output für BCD Code 4 Stelle
    pinMode(BCD1D, OUTPUT); // Output für BCD Code 3 Stelle
    pinMode(BCD2D, OUTPUT); // Output für BCD Code 2 Stelle
    pinMode(BCD3D, OUTPUT); // Output für BCD Code 1 Stelle
    pinMode(Punkt, OUTPUT); // Output für Punkt bei Datum
    pinMode(Dpunkt, OUTPUT); // Output für Doppelpunkt bei Zeit
} // setup

void loop () 
{
    DateTime now = rtc.now();
              // Modus ZEIT
              UHR[0] = now.hour(), DEC;       
              UHR[0] = UHR[0] / 10; // Erste Ziffer für Stunden: Zehner
              UHR[1] = now.hour(), DEC;
              UHR[1] = UHR[1] % 10; // Zweite Ziffer für Stunden: Einer
              UHR[2] = now.minute(), DEC;
              UHR[2] = UHR[2] / 10; // Dritte Ziffer für Minuten: Zehner
              UHR[3] = now.minute(), DEC;
              UHR[3] = UHR[3] % 10; // Vierte Ziffer für Minuten: Einer    

              // Serial.println(now.minute());
              for(n=0;n<4;n++){
              Zahl = UHR[n];
              switch(Zahl){
                  case 0: digitalWrite(Position[n][0], LOW ); // BCD Code 0 = 0000
                          digitalWrite(Position[n][1], LOW );
                          digitalWrite(Position[n][2], LOW );
                          digitalWrite(Position[n][3], LOW );
                          break;
                  case 1: digitalWrite(Position[n][0], HIGH ); // BCD Code 1 = 0001
                          digitalWrite(Position[n][1], LOW );
                          digitalWrite(Position[n][2], LOW );
                          digitalWrite(Position[n][3], LOW );
                          break;
                  case 2: digitalWrite(Position[n][0], LOW ); // BCD Code 2 = 0010
                          digitalWrite(Position[n][1], HIGH );
                          digitalWrite(Position[n][2], LOW );
                          digitalWrite(Position[n][3], LOW );
                          break; 
                  case 3: digitalWrite(Position[n][0], HIGH ); // BCD Code 3 = 0011
                          digitalWrite(Position[n][1], HIGH );
                          digitalWrite(Position[n][2], LOW );
                          digitalWrite(Position[n][3], LOW );
                          break;
                  case 4: digitalWrite(Position[n][0], LOW ); // BCD Code 4 = 0100
                          digitalWrite(Position[n][1], LOW );
                          digitalWrite(Position[n][2], HIGH );
                          digitalWrite(Position[n][3], LOW );
                          break;
                  case 5: digitalWrite(Position[n][0], HIGH ); // BCD Code 5 = 0101
                          digitalWrite(Position[n][1], LOW );
                          digitalWrite(Position[n][2], HIGH );
                          digitalWrite(Position[n][3], LOW );
                          break;          
                  case 6: digitalWrite(Position[n][0], LOW ); // BCD Code 6 = 0110
                          digitalWrite(Position[n][1], HIGH );
                          digitalWrite(Position[n][2], HIGH );
                          digitalWrite(Position[n][3], LOW );
                          break;
                  case 7: digitalWrite(Position[n][0], HIGH ); // BCD Code 7 = 0111
                          digitalWrite(Position[n][1], HIGH );
                          digitalWrite(Position[n][2], HIGH );
                          digitalWrite(Position[n][3], LOW );
                          break;
                  case 8: digitalWrite(Position[n][0], LOW ); // BCD Code 8 = 1000
                          digitalWrite(Position[n][1], LOW );
                          digitalWrite(Position[n][2], LOW );
                          digitalWrite(Position[n][3], HIGH );
                          break;
                  case 9: digitalWrite(Position[n][0], HIGH ); // BCD Code 9 = 1001
                          digitalWrite(Position[n][1], LOW );
                          digitalWrite(Position[n][2], LOW );
                          digitalWrite(Position[n][3], HIGH );
                          break;    
                 } // switch
                 delay(5); 
             } // for
    }

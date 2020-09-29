/****************************************************************************
* Programm:    Roulette                                                                  
* uC:          Arduino UNO 
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    1.0                                                        
* Datum:      10.10.2017
*
* Totalzeit: 60'                                   
****************************************************************************
*
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
****************************************************************************/
                                                                           // Roulette Code fuer Arduino Uno
                                                                           //
#define zeit 50                                                            // Blinkgeschwindigkeit
#define stopp 10                                                           //
#define start 1000                                                         // 
                                                                           //
int pin [] = {2,3,4,5,6,7,8,9,10,11,12,13};                                // LEDs Pins Ausgaenge
int tasterPin = 0;                                                         //
int tasterWert = 0;                                                        // Taster Pin
int letzteZahl = 1;                                                        //
                                                                           //
void setup (){                                                             //
                                                                           //
                                                                           // Damit es auch wirklich ein 
																		                                       // Zufallsgenerator ist, ist A2 als 
																		                                       // Eingang fuer randomSeed definiert.
                                                                           // Da hier immer eine kleine Spannungsaenderung 
                                                                           // vorhanden ist, kommt immer eine andere Zahl
																		                                       // heraus.
           randomSeed(analogRead(2));                                      //
           for(int i = 0; i <12; i++)                                      //
               pinMode(pin[i], OUTPUT);                                    //
              }                                                            //
                                                                           //
void loop(){                                                               //
         if(analogRead(tasterPin) > start)                                 // Taster auslesen
            gameStart(random(1,stopp));                                    //
           }                                                               //
                                                                           //
void gameStart(int zahl){                                                  // Roulette startet
               digitalWrite(letzteZahl + 1,LOW);                           //
               letzteZahl = zahl;                                          //
               int k = 1;                                                  //
               for(int i = 0; i < 6; i++){                                 //
                   if(i > 2) k++;                                          //
                     for(int j = 0; j < 12; j++){                          //
                         digitalWrite(pin[j], HIGH);                       //
                         if((i == 5)&&(j + 1 == zahl)) break;              //
                         delay(zeit * k);                                  //
                         digitalWrite(pin[j], LOW);                        //
                        }                                                  //
                   }                                                       //
              }                                                            // Ende und Neustart


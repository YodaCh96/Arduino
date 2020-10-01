/******************************************************************************* 
Company     : Siemens Schweiz AG - Berufsbildung Elektronik PE-BTHQ
Author      : Ioannis Christodoulakis (Ic) 	 	 	 
Project     : Leuchtschrift-SIEMENS
Version     : 1.0 
Filename 	: leuchtschrift.c 
Created 	: 07.11.2017 21:04:03
 
******************************************************************************** 
Release Notes:        Version Date  	Author     Comment/Reason for change 
1.0.0                 13.11.2017        Ic     First release  
*******************************************************************************/                                           
                                        
/************************Anfang Programmeinstellungen *******************************************/
                                                                                                //
#define VerzoegerungsZeit 50                                                                    // Verzoegerungszeit selber einstellen.
#define TasterZeit 50                                                                           //
                                                                                                // Pin Definitionen 
int LedPins[7] = {4,5,6,7,8,9,10};                                                              //
                                                                                                //
#define TasterEffekt 2                                                                          //
#define TasterHelligkeit 3                                                                      //
#define TasterIndex 9                                                                           // Anzahl Betriebsmodi
                                                                                                //
int AnzahlLeds = 7;                                                                             //
                                                                                                //
                                                                                                //
//Anfangswerte                                                                                  //
int TasterState = 0;                                                                            //
int AlterZustandTaster = 0;                                                                     //
int TasterZaehler = 0;                                                                          //
int Zaehler;                                                                                    //
                                                                                                //
/************************************Setup*******************************************************/
                                                                                                //
void setup(){                                                                                   //
                                                                                                //
           attachInterrupt(0,TasterFunktion,HIGH);                                              // Löst aus wenn sich der Wert von LOW auf HIGH ändert.
                                                                                                //
           pinMode(TasterEffekt,INPUT);                                                         //
                                                                                                //
           for(Zaehler = 0; Zaehler < AnzahlLeds; Zaehler++){                                   //
               pinMode(LedPins[Zaehler],OUTPUT);                                                //
              }//for_loop                                                                       //
                                                                                                //
           }//setup                                                                             //
                                                                                                //
/********************************Hauptprogramm***************************************************/
                                                                                                //
void loop(){                                                                                    //
                                                                                                //
                                                                                                //
            switch (TasterZaehler) {                                                            //
                    case 1:                                                                     //
                           //Effekt_1                                                           //
                           Effekt1();                                                           //
                                                                                                //
                           break;                                                               //
                    case 2:                                                                     //
                            //Effekt_2                                                          //
                            Effekt2();                                                          //
                                                                                                //
                            break;                                                              //
                    case 3:                                                                     //
                            //Effekt_3                                                          //
                            Effekt3();                                                          //
                                                                                                //
                            break;                                                              //
                    case 4:                                                                     //
                            //Effekt_4                                                          //
                            Effekt4();                                                          //
                                                                                                //
                             break;                                                             //
                    case 5:                                                                     //
                            //Effekt_5                                                          //
                            Effekt5();                                                          //
                                                                                                //
                            break;                                                              //
                    case 6:                                                                     //
                            //Effekt_6                                                          //
                            Effekt6();                                                          //
                                                                                                //
                            break;                                                              //
                    case 7:                                                                     //
                            //Effekt_7                                                          //
                            Effekt7();                                                          //
                                                                                                //
                            break;                                                              //
                                                                                                //
                    case 8:                                                                     //
                            //Effekt_8                                                          //
                            Effekt8();                                                          //
                                                                                                //
                            break;                                                              //
                                                                                                //
                    case 9:                                                                     //
                            //Effekt_9                                                          //
                            Effekt9();                                                          //
                                                                                                //
                            break;           
                            
                    }//switch_case                                                              //
                                                                                                //
                  }//void_loop                                                                  //
                                                                                                //
/*********************************FUNKTIONEN*****************************************************/
                                                                                                //
void TasterFunktion(){                                                                          //
                                                                                                //
                   TasterState = digitalRead(TasterEffekt);                                     //
                   if (TasterState != AlterZustandTaster){                                      //
                       if (TasterState == HIGH){                                                //
                           TasterZaehler++;                                                     //
                           if(TasterZaehler>=TasterIndex){                                      //
                              TasterZaehler = 0;                                                //
                             }                                                                  //
                                                                                                //
                            }                                                                   //
                          delay(TasterZeit);                                                    //
                          }                                                                     //
                     AlterZustandTaster = TasterState;                                          //
                    }//TasterFunktion                                                           //
                                                                                                //
                                                                                                //
void Effekt1(){                                                                                 //
               for (Zaehler = 0; Zaehler <AnzahlLeds; Zaehler++){                               // Alles ausschalten
                                                                                                //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                                                                                                //
                    }//for_loop                                                                 //
              }//Effekt_1                                                                       //
                                                                                                //
void Effekt2(){                                                                                 //
               for (Zaehler = 0; Zaehler <AnzahlLeds; Zaehler++){                               // Alles einschalten
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                  
                    }//for_loop                                                                 //
              }//Effekt_2                                                                       //
                                                                                                //
void Effekt3(){                                                                                 //
               for (Zaehler = 0; Zaehler <AnzahlLeds; Zaehler++){                               //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                    }//for_loop                                                                 //
                                                                                                //
               for (Zaehler = 0; Zaehler <AnzahlLeds; Zaehler ++){                              //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                    }//for_loop                                                                 //
              }//Effekt_3                                                                       //
                                                                                                //
void Effekt4(){                                                                                 //
               for (Zaehler = AnzahlLeds;  Zaehler >= 0; Zaehler--){                            //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                                                                                                //
               for (Zaehler = AnzahlLeds;  Zaehler >= 0; Zaehler--){                            //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
             }//Effekt_4                                                                        //
                                                                                                //
void Effekt5(){                                                                                 //
               for (Zaehler = 0; Zaehler < AnzahlLeds; Zaehler++){                              //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    digitalWrite(LedPins[Zaehler+1], HIGH);                                     //
                   }                                                                            //
                                                                                                //
              for (Zaehler = AnzahlLeds; Zaehler >= 0; Zaehler--){                              //
                   digitalWrite(LedPins[Zaehler], HIGH);                                        //
                   delay(VerzoegerungsZeit);                                                    //
                   digitalWrite(LedPins[Zaehler], LOW);                                         //
                   digitalWrite(LedPins[Zaehler-1], HIGH);                                      //
                  }//for_loop                                                                   //
             }//Effekt_5                                                                        //
                                                                                                //
void Effekt6(){                                                                                 //
                for (Zaehler =0; Zaehler <= AnzahlLeds; Zaehler++){                             //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler+1], HIGH);                                     //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
              }//Effekt_6                                                                       //
                                                                                                //
void Effekt7(){                                                                                 //
                for(Zaehler = 0; Zaehler < 3; Zaehler++){                                       //
                                  for (Zaehler = 0; Zaehler < AnzahlLeds; Zaehler++){           // Alle LEDs leuchten 
                                       digitalWrite(LedPins[Zaehler], HIGH);                    //
                                      }//for_loop                                               //
                                       delay(VerzoegerungsZeit*5);                              //
                                                                                                //
                                 for (Zaehler = 0; Zaehler < AnzahlLeds; Zaehler++){            // Alle LEDs leuchten nicht 
                                      digitalWrite(LedPins[Zaehler], LOW);                      //
                                     }//for_loop                                                //
                                      delay(VerzoegerungsZeit*5);                               //
                                }//for_loop                                                     //
             }//Effekt_7                                                                        //
                                                                                                //
void Effekt8(){                                                                                 //
               char Spiegel= AnzahlLeds-1;                                                      //
               for (Zaehler = 0; Zaehler < AnzahlLeds/2; Zaehler++){                            //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    digitalWrite(LedPins[Spiegel - Zaehler], HIGH);                             //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    digitalWrite(LedPins[Spiegel - Zaehler], LOW);                              //
                   }//for_loop                                                                  //
                                                                                                //
               for (Zaehler = AnzahlLeds/2; Zaehler >= 0; Zaehler--){                           //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    digitalWrite(LedPins[Spiegel - Zaehler], HIGH);                             //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    digitalWrite(LedPins[Spiegel - Zaehler], LOW);                              //
                   }//for_loop                                                                  //
              }//Effekt_8                                                                       //
                                                                                                //
void Effekt9(){                                                                                 //
                for (Zaehler = 0; Zaehler < AnzahlLeds-1; Zaehler++){                           //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler+1], HIGH);                                     //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                    digitalWrite(LedPins[AnzahlLeds-1], HIGH);                                  //
                                                                                                //
               for (Zaehler = 0; Zaehler < AnzahlLeds-2; Zaehler++){                            //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler+1], HIGH);                                     //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                    digitalWrite(LedPins[AnzahlLeds-1], HIGH);                                  //
                    digitalWrite(LedPins[AnzahlLeds-2], HIGH);                                  //
                                                                                                //
             for (Zaehler = 0; Zaehler < AnzahlLeds-3; Zaehler++){                              //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler+1], HIGH);                                     //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                   for(Zaehler = 1; Zaehler < 4; Zaehler++){                                    //
                       digitalWrite(LedPins[AnzahlLeds-Zaehler], HIGH);                         //
                   }                                                                            //
                                                                                                //
             for (Zaehler = 0; Zaehler < AnzahlLeds-4; Zaehler++){                              //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler+1], HIGH);                                     //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                   for(Zaehler = 1; Zaehler < 5; Zaehler++){                                    //
                       digitalWrite(LedPins[AnzahlLeds-Zaehler], HIGH);                         //
                   }                                                                            //
                                                                                                //
           for (Zaehler = 0; Zaehler < AnzahlLeds-5; Zaehler++){                                //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler+1], HIGH);                                     //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                   for(Zaehler = 1; Zaehler < 6; Zaehler++){                                    //
                       digitalWrite(LedPins[AnzahlLeds-Zaehler], HIGH);                         //
                   }                                                                            //
                                                                                                //
            for (Zaehler = 0; Zaehler < AnzahlLeds-6; Zaehler++){                               //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler+1], HIGH);                                     //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                   for(Zaehler = 1; Zaehler < 7; Zaehler++){                                    //
                       digitalWrite(LedPins[AnzahlLeds-Zaehler], HIGH);                         //
                   }                                                                            //
                                                                                                //
           for (Zaehler = 0; Zaehler < AnzahlLeds-7; Zaehler++){                                //
                    digitalWrite(LedPins[Zaehler], HIGH);                                       // 
                    delay(VerzoegerungsZeit);                                                   //     
                    digitalWrite(LedPins[Zaehler+1], HIGH);                                     //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //                               
                   for(Zaehler = 1; Zaehler < 8; Zaehler++){                                    //
                       digitalWrite(LedPins[AnzahlLeds-Zaehler], HIGH);                         //
                   }                                                                            //
                                                                                                //
          for (Zaehler = AnzahlLeds; Zaehler >= 0; Zaehler--){                                  // LEDs langsam auf LOW setzen
               digitalWrite(LedPins[Zaehler], LOW);                                             //
               delay(VerzoegerungsZeit*2);                                                      //
              }//for_loop                                                                       //
               delay(VerzoegerungsZeit*3);                                                      //
}//Effekt_9                                                                                     //

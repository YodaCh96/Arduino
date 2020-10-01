//SIEMENS_Leuchtschrift
                                                 
//Author 2017 I.Christodoulakis                                          
//Simulation anschalten eines Leuchtschriftes                                                                                                     
//Programm für Arduino.                                                  
//Simulation von x Bucstaben mit 7 verschiedenen Effekten.                                              
                                        
/************************Anfang Programmeinstellungen *******************************************/
                                                                                                //
#define VerzoegerungsZeit 50                                                                    // Verzoegerungszeit selber einstellen.
#define TasterZeit 50                                                                           //
                                                                                                // Pin Definitionen 
int LedPins[7] = {4,5,6,7,8,9,10};                                                              //
int IntensitaetsStufe[4] = {300,100,170,255};                                                     //
                                                                                                //
#define TasterEffekt 2                                                                          //
#define TasterHelligkeit 3                                                                      //
#define TasterIndex 8                                                                           //
#define HelligkeitsIndex 5                                                                      //
                                                                                                //
int AnzahlLeds = 7;                                                                             //
                                                                                                //
                                                                                                //
//Anfangswerte                                                                                  //
int TasterState = 0;                                                                            //
int AlterZustandTaster = 0;                                                                     //
int TasterZaehler = 0;                                                                          //
int HelligkeitState = 0;                                                                        //
int AlterZustandHelligkeit = 0;                                                                 //
int HelligkeitZaehler = 1;                                                                      //
                                                                                                //
int HelligkeitsStufe;                                                                           //
int Zaehler;                                                                                    //
                                                                                                //
/************************************Setup*******************************************************/
                                                                                                //
void setup(){                                                                                   //
                                                                                                //
           attachInterrupt(0,TasterFunktion,HIGH);                                              // Löst aus wenn sich der Wert von LOW auf HIGH ändert.
           attachInterrupt(1,TasterIntensitaet,HIGH);                                           // Löst aus wenn sich der Wert von LOW auf HIGH ändert.
                                                                                                //
           pinMode(TasterEffekt,INPUT);                                                         //
           pinMode(TasterHelligkeit,INPUT);                                                     //
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
          TasterIntensitaet();                                                                  //
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
                    }//switch_case                                                              //
                                                                                                //
            switch (HelligkeitZaehler) {                                                        //
                    case 1:                                                                     //
                           //Helligkeit_1                                                       //
                           HelligkeitsStufe = IntensitaetsStufe[0];                             //
                           break;                                                               //
                    case 2:                                                                     //
                            //Helligkeit_1                                                      //
                            HelligkeitsStufe = IntensitaetsStufe[1];                            //
                            break;                                                              //
                    case 3:                                                                     //
                            //Helligkeit_1                                                      //
                            HelligkeitsStufe = IntensitaetsStufe[2];                            //
                            break;                                                              //
                    case 4:                                                                     //
                            //Helligkeit_1                                                      //
                            HelligkeitsStufe = IntensitaetsStufe[3];                            //
                             break;                                                             //
                     }//switch_case                                                             //
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
 void TasterIntensitaet(){                                                                      //
                          HelligkeitState = digitalRead(TasterHelligkeit);                      //
                   if (HelligkeitState != AlterZustandHelligkeit){                              //
                       if (HelligkeitState == HIGH){                                            //
                           HelligkeitZaehler++;                                                 //
                           if(HelligkeitZaehler>=HelligkeitsIndex){                             //
                              HelligkeitZaehler = 1;                                            //
                             }                                                                  //
                                                                                                //
                            }                                                                   //
                          delay(TasterZeit);                                                    //
                          }                                                                     //
                     AlterZustandHelligkeit = HelligkeitState;                                  //
  }//TasterIntensitaet                                                                          //
                                                                                                //
void Effekt1(){                                                                                 //
               for (Zaehler = 0; Zaehler <AnzahlLeds; Zaehler++){                               //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                    }//for_loop                                                                 //
                                                                                                //
               for (Zaehler = 0; Zaehler <AnzahlLeds; Zaehler ++){                              //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                    }//for_loop                                                                 //
              }//Effekt_1                                                                       //
                                                                                                //
void Effekt2(){                                                                                 //
               for (Zaehler = AnzahlLeds;  Zaehler >= 0; Zaehler--){                            //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                                                                                                //
               for (Zaehler = AnzahlLeds;  Zaehler >= 0; Zaehler--){                            //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
             }//Effekt_2                                                                        //
                                                                                                //
void Effekt3(){                                                                                 //
               for (Zaehler = 0; Zaehler < AnzahlLeds; Zaehler++){                              //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    analogWrite(LedPins[Zaehler+1], HelligkeitsStufe);                          //
                   }                                                                            //
                                                                                                //
              for (Zaehler = AnzahlLeds; Zaehler >= 0; Zaehler--){                              //
                   analogWrite(LedPins[Zaehler], HelligkeitsStufe);                             //
                   delay(VerzoegerungsZeit);                                                    //
                   digitalWrite(LedPins[Zaehler], LOW);                                         //
                   analogWrite(LedPins[Zaehler-1], HelligkeitsStufe);                           //
                  }//for_loop                                                                   //
             }//Effekt_3                                                                        //
                                                                                                //
void Effekt4(){                                                                                 //
                for (Zaehler =0; Zaehler <= AnzahlLeds; Zaehler++){                             //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                    analogWrite(LedPins[Zaehler+1], HelligkeitsStufe);                          //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
              }//Effekt_4                                                                       //
                                                                                                //
void Effekt5(){                                                                                 //
                for(Zaehler = 0; Zaehler < 3; Zaehler++){                                       //
                                  for (Zaehler = 0; Zaehler < AnzahlLeds; Zaehler++){           // Alle LEDs leuchten 
                                       analogWrite(LedPins[Zaehler], HelligkeitsStufe);         //
                                      }//for_loop                                               //
                                       delay(VerzoegerungsZeit*5);                              //
                                                                                                //
                                 for (Zaehler = 0; Zaehler < AnzahlLeds; Zaehler++){            // Alle LEDs leuchten nicht 
                                      digitalWrite(LedPins[Zaehler], LOW);                      //
                                     }//for_loop                                                //
                                      delay(VerzoegerungsZeit*5);                               //
                                }//for_loop                                                     //
             }//Effekt_5                                                                        //
                                                                                                //
void Effekt6(){                                                                                 //
               char Spiegel= AnzahlLeds-1;                                                      //
               for (Zaehler = 0; Zaehler < AnzahlLeds/2; Zaehler++){                            //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    analogWrite(LedPins[Spiegel - Zaehler], HelligkeitsStufe);                  //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    digitalWrite(LedPins[Spiegel - Zaehler], LOW);                              //
                   }//for_loop                                                                  //
                                                                                                //
               for (Zaehler = AnzahlLeds/2; Zaehler >= 0; Zaehler--){                           //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    analogWrite(LedPins[Spiegel - Zaehler], HelligkeitsStufe);                  //
                    delay(VerzoegerungsZeit);                                                   //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    digitalWrite(LedPins[Spiegel - Zaehler], LOW);                              //
                   }//for_loop                                                                  //
              }//Effekt_6                                                                       //
                                                                                                //
void Effekt7(){                                                                                 //
                for (Zaehler = 0; Zaehler < AnzahlLeds-1; Zaehler++){                           //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                    analogWrite(LedPins[Zaehler+1], HelligkeitsStufe);                          //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                    analogWrite(LedPins[AnzahlLeds-1], HelligkeitsStufe);                       //
                                                                                                //
               for (Zaehler = 0; Zaehler < AnzahlLeds-2; Zaehler++){                            //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                    analogWrite(LedPins[Zaehler+1], HelligkeitsStufe);                          //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                    analogWrite(LedPins[AnzahlLeds-1], HelligkeitsStufe);                       //
                    analogWrite(LedPins[AnzahlLeds-2], HelligkeitsStufe);                       //
                                                                                                //
             for (Zaehler = 0; Zaehler < AnzahlLeds-3; Zaehler++){                              //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                    analogWrite(LedPins[Zaehler+1], HelligkeitsStufe);                          //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                   for(Zaehler = 1; Zaehler < 4; Zaehler++){                                    //
                       analogWrite(LedPins[AnzahlLeds-Zaehler], HelligkeitsStufe);              //
                   }                                                                            //
                                                                                                //
             for (Zaehler = 0; Zaehler < AnzahlLeds-4; Zaehler++){                              //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                    analogWrite(LedPins[Zaehler+1], HelligkeitsStufe);                          //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                   for(Zaehler = 1; Zaehler < 5; Zaehler++){                                    //
                       analogWrite(LedPins[AnzahlLeds-Zaehler], HelligkeitsStufe);              //
                   }                                                                            //
                                                                                                //
           for (Zaehler = 0; Zaehler < AnzahlLeds-5; Zaehler++){                                //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                    analogWrite(LedPins[Zaehler+1], HelligkeitsStufe);                          //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                   for(Zaehler = 1; Zaehler < 6; Zaehler++){                                    //
                       analogWrite(LedPins[AnzahlLeds-Zaehler], HelligkeitsStufe);              //
                   }                                                                            //
                                                                                                //
            for (Zaehler = 0; Zaehler < AnzahlLeds-6; Zaehler++){                               //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            //
                    delay(VerzoegerungsZeit);                                                   //
                    analogWrite(LedPins[Zaehler+1], HelligkeitsStufe);                          //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //
                   for(Zaehler = 1; Zaehler < 7; Zaehler++){                                    //
                       analogWrite(LedPins[AnzahlLeds-Zaehler], HelligkeitsStufe);              //
                   }                                                                            //
                                                                                                //
           for (Zaehler = 0; Zaehler < AnzahlLeds-7; Zaehler++){                                //
                    analogWrite(LedPins[Zaehler], HelligkeitsStufe);                            // 
                    delay(VerzoegerungsZeit);                                                   //     
                    analogWrite(LedPins[Zaehler+1], HelligkeitsStufe);                          //
                    digitalWrite(LedPins[Zaehler], LOW);                                        //
                    delay(VerzoegerungsZeit);                                                   //
                   }//for_loop                                                                  //                               
                   for(Zaehler = 1; Zaehler < 8; Zaehler++){                                    //
                       analogWrite(LedPins[AnzahlLeds-Zaehler], HelligkeitsStufe);              //
                   }                                                                            //
                                                                                                //
          for (Zaehler = AnzahlLeds; Zaehler >= 0; Zaehler--){                                  // LEDs langsam auf LOW setzen
               digitalWrite(LedPins[Zaehler], LOW);                                             //
               delay(VerzoegerungsZeit*2);                                                      //
              }//for_loop                                                                       //
               delay(VerzoegerungsZeit*3);                                                      //
}//Effekt_7                                                                                     //

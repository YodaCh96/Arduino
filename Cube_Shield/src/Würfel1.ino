/*******************************************************************************
* Programm:   Elektronischer Wuerfel-Shield                                                                   
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    1.0                                                        
* Datum:      11.10.2017   
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0, 11.10.2017, Ioannis Christodoulakis, Elektronischer Wuerfel
* 
* Totalzeit: 120'                                    
********************************************************************************
*
* Verwendungszweck: Elektronischer Wuerfel-Shield
*
* Beschreibung: 
*     
* 
* Precondition:  -
*
* Postcondition: -
*
* BenÃ¶tigte Libraries:
* - 
*
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
*****************************************************************************/

int Led[] = {3,4,5,6,7,8,9};                                                // Variablen für die LEDs
int Data[4] = {10,11,12,13};                                                //
                                                                            //
int Augen[6][7] = {{0,0,0,1,0,0,0},                                         // Wuerfelzahl 1
                   {1,0,0,0,0,0,1},                                         // Wuerfelzahl 2
                   {1,0,0,1,0,0,1},                                         // Wuerfelzahl 3
                   {1,0,1,0,1,0,1},                                         // Wuerfelzahl 4
                   {1,0,1,1,1,0,1},                                         // Wuerfelzahl 5
                   {1,1,1,0,1,1,1}};                                        // Wuerfelzahl 6             
                                                                            //
                                                                            //
#define Button 2                                                            // Variable fuer den Taster
#define Verzoegerungszeit 50                                                //
                                                                            //
int ButtonStatus = 0;                                                       // Statusabfrage des Tasters
int Zahl;                                                                   //
int Zufall;                                                                 //
int index;                                                                  // 
int index1;                                                                 //
int index2;                                                                 //
                                                                            //
void setup(){                                                               //
                                                                            // Serial.begin(9600);
                                                                            //
             for(index = 0; index <= 6; index++){                           //                                                                                   
                 pinMode(Led[index],OUTPUT);                                // LEDs als Ausgang definieren
                }                                                           //
                                                                            //
             for(index = 0; index <= 3; index++){                           //                                     
                 pinMode(Data[index],OUTPUT);                               // LEDs als Ausgang definieren
                }                                                           //
                                                                            //
                 pinMode(Button, INPUT);                                    // Taster als Eingang
                                                                            // definieren                             
              }                                                             //
                                                                            //
//**************************************************************************//
//******************************* HAUPTPROGRAMM ****************************//
//**************************************************************************//
                                                                            //
void loop(){                                                                //
                                                                            //
            ButtonStatus = digitalRead(Button);                             // Status des Tasters abfragen
                                                                            //
            if (ButtonStatus == HIGH){                                      // Wenn Taster gedrueckt
                                                                            //
                for(index1 = 0; index1 <= 50; index1++){                    // Liefer 51 Zufallszahlen
                    Zufall = random(0,6);                                   // Gib eine zufaellige Zahl
                                                                            // zwischen 1 und 6 an
                                                                            //
                    for(index2 = 0; index2 <= 6; index2++){                 //
                        digitalWrite(Led[index2], Augen[Zufall][index2]);   //
                       }                                                    //
                        delay(Verzoegerungszeit);                           //
                   }                                                        //
                                                                            //
            Zahl = Zufall + 1;                                              //
                                                                            // Serial.println(Zahl);                                      
            switch (Zahl) {                                                 //
                           case 1:                                          //
                                  digitalWrite(Data[0],HIGH);               //
                                  digitalWrite(Data[1],LOW);                //
                                  digitalWrite(Data[2],LOW);                //
                                  digitalWrite(Data[3],LOW);                //
                                  break;                                    //
                                                                            //
                           case 2:                                          //
                                   digitalWrite(Data[0],LOW);               //
                                   digitalWrite(Data[1],HIGH);              //
                                   digitalWrite(Data[2],LOW);               //
                                   digitalWrite(Data[3],LOW);               //
                                   break;                                   //
                                                                            //
                            case 3:                                         //
                                   digitalWrite(Data[0],HIGH);              //
                                   digitalWrite(Data[1],HIGH);              //
                                   digitalWrite(Data[2],LOW);               //
                                   digitalWrite(Data[3],LOW);               //
                                   break;                                   //
                                                                            //
                             case 4:                                        //
                                   digitalWrite(Data[0],LOW);               //
                                   digitalWrite(Data[1],LOW);               //
                                   digitalWrite(Data[2],HIGH);              //
                                   digitalWrite(Data[3],LOW);               //
                                   break;                                   //
                                                                            //
                             case 5:                                        //
                                   digitalWrite(Data[0],HIGH);              //
                                   digitalWrite(Data[1],LOW);               //
                                   digitalWrite(Data[2],HIGH);              //
                                   digitalWrite(Data[3],LOW);               //
                                   break;                                   //
                                                                            //
                             case 6:                                        //
                                   digitalWrite(Data[0],LOW);               //
                                   digitalWrite(Data[1],HIGH);              //
                                   digitalWrite(Data[2],HIGH);              //
                                   digitalWrite(Data[3],LOW);               //
                                   break;                                   //
                            }                                               //
                        }                                                   //                                                                                                          
                   }                                                        //


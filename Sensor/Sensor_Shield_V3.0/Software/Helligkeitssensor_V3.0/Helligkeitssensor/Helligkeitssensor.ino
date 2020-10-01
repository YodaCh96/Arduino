/****************************************************************************
* Programm:    Helligkeitssensor                                                              
* uC:          Arduino UNO 
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    3.0                                                        
* Datum:      27.02.2018
*
* Totalzeit: 40'                                   
****************************************************************************
*
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
****************************************************************************/

int led[]= {18,19,2,3,4,5,6,7,8,9};                       // Array fuer die LEDs
int analogPin=A0;                                         // Pin A0
int ldrWert=0;                                            // Variable fuer den an. Wert 0 bis 1024
int leseWert=0;                                           // Variable fuer den an. Wert 0-255
char i;                                                   // Zaehlervariable;
int Intensitaet[]={10,20,30,40,50,60,70,80,90,100};       // Intensitaet Array
                                                          //
                                                          //
void setup(){                                             // Setup
                                                          //
   for(i=0;i<10;i++){                                     //
                                                          //
       pinMode(led[i], OUTPUT);                           // LEDs als Ausgang setzen
                                                          //
   }//for                                                 //
                                                          //
   pinMode(analogPin,INPUT);                              // Photowiderstand als Ausgang definieren
   Serial.begin(9600);                                    // Serial Monitor 
}//setup                                                  //                         
                                                          //
void loop(){                                              //
                                                          //
   ldrWert = analogRead(analogPin);                       // den Wert an Pin A0 lesen
   leseWert = ldrWert/4;                                  // leseWert 0-255 
                                                          //
  for(i=0; i<10; i++){                                    //
                                                          //
if (Intensitaet[i] <= leseWert){                          // Ist Intensitaet kleiner als den leseWert?
           digitalWrite (led[i], HIGH);                   // LED auf HIGH setzen
}//if                                                     //
       else{                                              //
           digitalWrite (led[i], LOW);                    // sonst auf LOW 
       }//else                                            //
    }//for                                                //
                                                          //
     for(i=0; i<10; i++){                                 //
           digitalWrite (led[i], LOW);                    // Alle LEDs auf LOW setzen
    }//for                                                //
  
                                                                   
                         
    
}//loop                                                      
 

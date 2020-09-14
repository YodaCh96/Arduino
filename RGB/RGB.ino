/*******************************************************************************
* Programm: RGB_Test                                                                   
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    3.0                                                        
* Datum:      20.09.2017
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0, 20.09.2017, Ioannis Christodoulakis, RGB_Potentiometer
* 2.0, 20.09.2017, Ioannis Christodoulakis, RGB_ohne Potentiometer 
* 3.0, 20.09.2017, Ioannis Christodoulakis, RGB_mit Schalter
* 
* Totalzeit: ca. 3h                                     
* 
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
*/

#define Zeit 1                                    // Verzögerungszeit von 1ms

// Program variables
int redPin = 9;                                   // rote LED, digital pin 9
int grnPin = 10;                                  // gruene LED, digital pin 10
int bluPin = 11;                                  // blaue LED, digital pin 11
int Schalter = 2;

/******************************************************************************/
                                                                              
int redVal = 0;                                                              
int grnVal = 0;                                                               
int bluVal = 0;                                                               
int SchalterState = 0;//
int potVal = 0;     //        
int Durchlauf = 0;//

/******************************************************************************/

void setup()
{
  pinMode(redPin, OUTPUT);  
  pinMode(grnPin, OUTPUT);   
  pinMode(bluPin, OUTPUT); 
  pinMode(Schalter, OUTPUT);
  
  Serial.begin(9600);
}

/******************************************************************************/

void loop(){                 // Main program

          SchalterState = digitalRead(Schalter);

         if(SchalterState == 1){
           for(Durchlauf =0; Durchlauf < 1023; Durchlauf++){              
  
          /*Serial.print("Durchlauf: ");
          Serial.print(Durchlauf);
          */
          if (Durchlauf < 341){                          // Durchlauf von 0-340
                       
              potVal = (Durchlauf * 3) / 4;              // Durchlauf von 0-255
                                                    
              redVal = 256 - potVal;                     // rote LED --
              grnVal = potVal;                           // Gruene LED ++
              bluVal = 0;                                // Blaue LED auf null setzen

              delay(Zeit);
             }
        else if (Durchlauf < 682){                      // Durchlauf von 341-681
  
              potVal = ( (Durchlauf-341) * 3) / 4;      // Durchlauf von 0-255

              redVal = 0;                               // Red off
              grnVal = 256 - potVal;                    // gruene LED --
              bluVal = potVal;                          // blaue LED ++
   
              delay(Zeit);
             }
        else{                                          // (Durchlauf von 682-1023)
  
              potVal = ( (Durchlauf-683) * 3) / 4;     // Durchlauf von 0-255
              
              redVal = potVal;                         // rote LED ++
              grnVal = 0;                              // Gruene LED auf null setzen
              bluVal = 256 - potVal;                   // Blaue LED --
  
             delay(Zeit);
            }
       /* Serial.print(". Red: ");
          Serial.print(redVal);
          Serial.print(". Gruen: ");
          Serial.print(grnVal);
          Serial.print(". Blau: ");
          Serial.print(bluVal);
          Serial.println(".");
       */ 
 
          analogWrite(redPin, redVal);                // Werte von LEDs ausgeben
          analogWrite(grnPin, grnVal); 
          analogWrite(bluPin, bluVal);  
       }
      }
 
    else if (SchalterState == 0){
      
            Durchlauf = 1023;
           analogWrite(redPin, 0);                    // Werte von LEDs ausgeben
           analogWrite(grnPin, 0); 
           analogWrite(bluPin, 0); 
        }
      }


 
  
 

  



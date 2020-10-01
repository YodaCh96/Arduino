/****************************************************************************
* Programm:    Balkenanzeige-Sensor                                                                
* uC:          Arduino UNO 
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    2.0                                                        
* Datum:      18.10.2017
*
* Totalzeit: 40'                                   
****************************************************************************
*
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
****************************************************************************/

#define Verzoegerungszeit 100
#define Zeit 1000

int ledPin[] = {0,1,2,3,4,5,6,7,8,9};

void setup(){
             for (int i =0;i<10;i++){
                  pinMode(ledPin[i], OUTPUT);
			     }
            }

void loop(){
	
  AufUnten();
  delay(Zeit);
  OneAtTime();
  delay(Zeit);

}

void AufUnten(){
                for (int i =0;i<10;i++){
                     digitalWrite(ledPin[i], HIGH);
                     delay(Verzoegerungszeit);
                    }
					
                 for (int i=9;i>=0;i--){
                      digitalWrite(ledPin[i], LOW);
                      delay(Verzoegerungszeit);
                    }
                }
				
void OneAtTime(){
                 for (int i =0;i<10;i++){
                      digitalWrite(ledPin[i], HIGH);
                      delay(Verzoegerungszeit);
                      digitalWrite(ledPin[i], LOW);
                      delay(Verzoegerungszeit);
                     }  
                }

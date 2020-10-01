/****************************************************************************
* Programm:    Buzzer                                                                
* uC:          Arduino UNO 
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    2.0                                                        
* Datum:      18.10.2017
*
* Totalzeit: 15'                                   
****************************************************************************
*
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
****************************************************************************/

const int buzzer = 10; // Buzzer auf pin 10


void setup(){
 
  pinMode(buzzer, OUTPUT); // Setzen Buzzer auf pin 10 als Ausgang

}

void loop(){
 
  tone(buzzer, 1000); // 1kHz Tonsignal 
  delay(1000);        // 1 Sekunde warten
  noTone(buzzer);     // Stop Ton
  delay(1000);        // 1 Sekunde warten
  
}

/****************************************************************************
* Programm:    Balkenanzeige mit Buzzer-Sensor                                                                
* uC:          Arduino UNO 
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    2.0                                                        
* Datum:      18.10.2017
*
* Totalzeit: 30'                                   
****************************************************************************
*
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
****************************************************************************/

int buzzerPin = 10;

int tempo = 150;

int ledPin[] = {0,1,2,3,4,5,6,7,8,9};

int notes[] = {262,294,330,349,392,440,494,523,587,659};

int tunelength = 14;

int tune[] = {0,0,4,4,5,5,4,3,3,2,2,1,1,0};

int beats[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2};

void setup(){
             for (int i =0;i<10;i++){
                  pinMode(ledPin[i], OUTPUT);
                 }
             pinMode(buzzerPin, OUTPUT);
            }

void loop(){
            for (int i =0; i<tunelength; i++){
                 tone(buzzerPin, notes[tune[i]], beats[i]*tempo);
                 digitalWrite(ledPin[tune[i]], HIGH);
                 delay(beats[i]*tempo);
                 digitalWrite(ledPin[tune[i]], LOW);
                 delay(tempo/10);
                }
          }


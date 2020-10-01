/****************************************************************************
* Programm:    Temperatursensor                                                             
* uC:          Arduino UNO 
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    2.0                                                        
* Datum:      19.10.2017
*
* Totalzeit: 40'                                   
****************************************************************************
*
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
****************************************************************************/

const int sensorPin = A1;

void setup(){
             Serial.begin(9600);
            }

void loop(){
            int sensorVal = analogRead(sensorPin);
            float voltage = (sensorVal/1024.0)*5;
            float temperature = (voltage - .5)*100; // Temperatur_Berechnung
  
            Serial.println(temperature); // Serial Monitor
            Serial.print("Temperatur: "); // Serial Monitor
  
  }



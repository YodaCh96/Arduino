/****************************************************************************
* Programm:    Abstandsensor                                                              
* uC:          Arduino UNO 
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    2.0                                                        
* Datum:      23.10.2017
*
* Totalzeit: 30'                                   
****************************************************************************
*
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
****************************************************************************/

#define TrigPin 13
#define EchoPin 12
#define Verzoegerungszeit 500
#define Maximum 200
#define Minimum 0

long Dauer, Distanz;

void setup() {
Serial.begin (9600);
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
}

void loop() {

digitalWrite(TrigPin, LOW);
delayMicroseconds(Verzoegerungszeit/250);

digitalWrite(TrigPin, HIGH);
delayMicroseconds(Verzoegerungszeit/50);

digitalWrite(TrigPin, LOW);
Dauer = pulseIn(EchoPin, HIGH);


Distanz = Dauer/58.2;

if (Distanz >= Maximum || Distanz <= Minimum){

Serial.println("Kein Signal!");

}
else {

Serial.print("Distanz = " );
Serial.print(Distanz);
Serial.println(" cm" );

}

delay(Verzoegerungszeit/10);
}


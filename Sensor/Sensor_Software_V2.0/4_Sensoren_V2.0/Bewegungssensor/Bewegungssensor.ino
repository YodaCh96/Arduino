/****************************************************************************
* Programm:    Bewegungssensor                                                            
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

int buzzer=10; //Der Pin mit dem Piezo (Pin 10) ist jetzt ein Ausgang.
int bewegung=11; //Der Pin mit dem Bewegungssensor (Pin 11) ist jetzt ein Eingang.
int bewegungsstatus=0;

void setup(){
  
pinMode(buzzer, OUTPUT);
pinMode(bewegung, INPUT);
Serial.begin(9600);

}//setup

void loop(){
bewegungsstatus=digitalRead(bewegung);
//Hier wird der Pin11 ausgelesen. Das Ergebnis wird unter der Variablen 
//„bewegungsstatus“ mit dem Wert „HIGH“ für 5 Volt oder „LOW“ für 0 Volt gespeichert.


if (bewegungsstatus == HIGH){
//Wenn eine Bewegung detektiert wird
Serial.println("Signal");
tone(buzzer, 1000); // 1kHz Tonsignal 

}//if
else{
Serial.println("nix");  
noTone(buzzer);     // Stop Ton

 }//else
}//loop

// Deklaration von Konstanten und Variablen
#define DataPinR 7                                  //Data Pin des 16Bit Schieberegisters
#define ShiftPinR 6                                 //Shift Pin des 16Bit Schieberegisters
#define StorePinR 5                                 //Store Pin des 16Bit Schieberegisters
#define DataPinS 3                                  //Data Pin des 8Bit Schieberegisters
#define ShStPinS 4                                  //Store und Shift Pin des 8Bit Schieberegisters
#define MaxZeile 16                                 //Anzahl Zeilen der Anzeige einstellen
#define MaxSpalte 8                                 //Anzahl Spalten der Anzeige einstellen
#define Anzeigedauer 200                           //Verzoegrungszeit einstellen, wie lange eine Farbe leuchten soll
#define Zeit 500                                   //Verz�gerungszeit f�r Shiftregister


int i,                                             //F�r die For-Schlaufe
    n,                                             //F�r die For-Schlaufe
    a,                                              //F�r die For-Schlaufe
    dauer;

// Array definieren welches dann angezeigt werden soll auf dem Dysplay
  bool AnzeigeRot [8][16] = {               //Array f�r die Aufwaertstaste 
    {0,0,0,0,0,0,0,0 ,1,1,1,1,1,1,1,1}, 
    {1,1,1,1,1,1,1,1 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,1,1,1,1,1,1,1,1}, 
    {1,1,1,1,1,1,1,1 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,1,1,1,1,1,1,1,1}, 
    {1,1,1,1,1,1,1,1 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,1,1,1,1,1,1,1,1}, 
    {1,1,1,1,1,1,1,1 ,0,0,0,0,0,0,0,0},
    };
  bool AnzeigeGruen [16] = { 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 };


void setup() {
//ArduiPins als Output deklarieren
  pinMode(DataPinR, OUTPUT);
  pinMode(ShiftPinR, OUTPUT);
  pinMode(StorePinR, OUTPUT);
  pinMode(DataPinS, OUTPUT);
  pinMode(ShStPinS, OUTPUT);
//Sicherheitshalber Pin auf Low setzten
  digitalWrite(ShStPinS, LOW);
  
}

void loop() {
    digitalWrite(DataPinS,HIGH);
    digitalWrite(ShStPinS,HIGH);
    digitalWrite(DataPinS,LOW);
    digitalWrite(ShStPinS,LOW);
    for(a=0; a<MaxSpalte-1; a++){
      EinlesenR(a);
      digitalWrite(ShStPinS, HIGH);
      digitalWrite(ShStPinS, LOW);
      delay(Zeit);
    }
    EinlesenR(a+1);
}



void EinlesenR(int x){
  for (n=0; n<MaxZeile; n++){                 // For schleife zum Setzten einer Reihe und das Ausgeben dieser Reihe
    digitalWrite(ShiftPinR, LOW);
    digitalWrite(DataPinR, AnzeigeRot[x][n]);
    digitalWrite(ShiftPinR, HIGH);
  }
  digitalWrite(StorePinR, HIGH);
  digitalWrite(StorePinR, LOW);
}
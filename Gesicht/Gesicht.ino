// Deklaration von Konstanten und Variablen
#define DataPinR 7                                  //Data Pin des 16Bit Schieberegisters
#define ShiftPinR 6                                 //Shift Pin des 16Bit Schieberegisters
#define StorePinR 5                                 //Store Pin des 16Bit Schieberegisters
#define DataPinS 3                                  //Data Pin des 8Bit Schieberegisters
#define ShStPinS 4                                  //Store und Shift Pin des 8Bit Schieberegisters
#define MaxZeile 16                                 //Anzahl Zeilen der Anzeige einstellen
#define MaxSpalte 8                                 //Anzahl Spalten der Anzeige einstellen
#define Anzeigedauer 40                           //Verzoegrungszeit einstellen, wie lange eine Farbe leuchten soll
#define Zeit 0.0001                                   //Verzögerungszeit für Shiftregister
#define EinleseZeit 0.00002  


int temp,                                            //Für die For-Schlaufe
    dauer;

// Array definieren welches dann angezeigt werden soll auf dem Dysplay
  bool AnzeigeOben [8][16] = {               //Array für die Aufwaertstaste 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0}, 
    {1,1,1,1,1,1,1,1 ,0,1,0,1,0,1,0,1}, 
    {1,0,0,1,1,0,0,1 ,0,1,1,0,0,1,1,0}, 
    {1,1,1,1,1,1,1,1 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0}, 
    {0,1,0,0,0,0,1,0 ,0,0,0,0,0,0,0,0}, 
    {0,0,1,1,1,1,0,0 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0},
    };

  bool AnzeigeMitte [8][16] = {               //Array für die Aufwaertstaste 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0}, 
    {1,1,1,1,1,1,1,1 ,0,0,0,0,0,0,0,0}, 
    {1,0,0,1,1,0,0,1 ,0,1,1,0,0,1,1,0}, 
    {1,1,1,1,1,1,1,1 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0}, 
    {0,1,1,1,1,1,1,0 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0},
    };

  bool AnzeigeUnten [8][16] = {               //Array für die Aufwaertstaste 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0}, 
    {1,1,1,1,1,1,1,1 ,0,0,0,0,0,0,0,0}, 
    {1,0,0,1,1,0,0,1 ,0,1,1,0,0,1,1,0}, 
    {1,1,1,1,1,1,1,1 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0}, 
    {0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0}, 
    {0,0,1,1,1,1,0,0 ,0,0,0,0,0,0,0,0}, 
    {0,1,0,0,0,0,1,0 ,0,0,0,0,0,0,0,0},
    };
    
  bool AnzeigeGruen [16] = { 0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 };


void setup() {
//ArduiPins als Output deklarieren
//Sicherheitshalber Pin auf Low setzten
  digitalWrite(ShStPinS, LOW);
  DDRD = B11111100;
  
}

void loop() {
  for(int i=0; i<Anzeigedauer+400; i++){
    PORTD = B00001000;
    delay(EinleseZeit);
    PORTD = B00111000;
    delay(EinleseZeit);
    PORTD = B00000000;
    for(int a=0; a<MaxSpalte-1; a++){
      EinlesenR(a);
      PORTD = B00110000;
      delay(EinleseZeit);
      PORTD = B00000000;
      temp = a+1;
    }
 EinlesenR(temp);
  }

  for(int i=0; i<Anzeigedauer; i++){
    PORTD = B00001000;
    delay(EinleseZeit);
    PORTD = B00111000;
    delay(EinleseZeit);
    PORTD = B00000000;
    for(int a=0; a<MaxSpalte-1; a++){
      EinlesenE(a);
      PORTD = B00110000;
      delay(EinleseZeit);
      PORTD = B00000000;
      temp = a+1;
    }
    EinlesenE(temp);
  }
    
  for(int i=0; i<Anzeigedauer+200; i++){
    PORTD = B00001000;
    delay(EinleseZeit);
    PORTD = B00111000;
    delay(EinleseZeit);
    PORTD = B00000000;
    for(int a=0; a<MaxSpalte-1; a++){
      EinlesenN(a);
      PORTD = B00110000;
      delay(EinleseZeit);
      PORTD = B00000000;
      temp = a+1;
    }
    EinlesenN(temp);
  }

  for(int i=0; i<Anzeigedauer; i++){
    PORTD = B00001000;
    delay(EinleseZeit);
    PORTD = B00111000;
    delay(EinleseZeit);
    PORTD = B00000000;
    for(int a=0; a<MaxSpalte-1; a++){
      EinlesenE(a);
      PORTD = B00110000;
      delay(EinleseZeit);
      PORTD = B00000000;
      temp = a+1;
    }
    EinlesenE(temp);
}
}



void EinlesenR(int x){
  for (int n=0; n<MaxZeile; n++){                 // For schleife zum Setzten einer Reihe und das Ausgeben dieser Reihe
    digitalWrite(ShiftPinR, LOW);
    digitalWrite(DataPinR, AnzeigeOben[x][n]);
    digitalWrite(ShiftPinR, HIGH); 
  }
}

void EinlesenE(int x){
  for (int n=0; n<MaxZeile; n++){                 // For schleife zum Setzten einer Reihe und das Ausgeben dieser Reihe
    digitalWrite(ShiftPinR, LOW);
    digitalWrite(DataPinR, AnzeigeMitte[x][n]);
    digitalWrite(ShiftPinR, HIGH); 
  }
}

void EinlesenN(int x){
  for (int n=0; n<MaxZeile; n++){                 // For schleife zum Setzten einer Reihe und das Ausgeben dieser Reihe
    digitalWrite(ShiftPinR, LOW);
    digitalWrite(DataPinR, AnzeigeUnten[x][n]);
    digitalWrite(ShiftPinR, HIGH); 
  }
}





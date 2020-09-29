/* Konstanten ------------------------------------------------------------------ */
#define DATENEINGANG    3
#define SHIFTREGISTER   0
#define STORAGEREGISTER 1
#define AUSGANG_EIN     2
#define D16             4  // Ebene 1
#define D17             5  // Ebene 2
#define D18             6  // Ebene 3
#define D19             7  // Ebene 4
#define MAX_EBENEN      4

/* ----------------------------------------------------------------------------- */




/* Variablen ------------------------------------------------------------------- */
bool Wuerfelwerte[MAX_EBENEN][16] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

int Ebenen[MAX_EBENEN] = {D16, D17, D18, D19},
    Ebenen_ausgeben,
    Zeilen_ausgeben,
    a;

int Wartezeit = 0;

/* ------------------------------------------------------------------------------ */




/* Funktionsdeklaration --------------------------------------------------------- */
void HIGH_Impuls(char DigitalPin);

/* ------------------------------------------------------------------------------ */




/* Setup ------------------------------------------------------------------------ */
void setup(){
  /* Ausgaenge ------------------------------------------------------------------ */
  pinMode(DATENEINGANG,    OUTPUT);
  pinMode(SHIFTREGISTER,   OUTPUT);
  pinMode(STORAGEREGISTER, OUTPUT);
  pinMode(AUSGANG_EIN,     OUTPUT);
  pinMode(D16,             OUTPUT);
  pinMode(D17,             OUTPUT);
  pinMode(D18,             OUTPUT);
  pinMode(D19,             OUTPUT);
  //Serial.begin(9600);

}
/* ------------------------------------------------------------------------------ */




/* Hauptprogramm ---------------------------------------------------------------- */
void loop(){ 
  for(Ebenen_ausgeben = 0; Ebenen_ausgeben < MAX_EBENEN; Ebenen_ausgeben++){
    for(Zeilen_ausgeben = 15; Zeilen_ausgeben > -1; Zeilen_ausgeben--){
      //Serial.print(Ebenen_ausgeben);
      //Serial.print("  ");
      //Serial.println(Zeilen_ausgeben);
      digitalWrite(DATENEINGANG, Wuerfelwerte[Ebenen_ausgeben][Zeilen_ausgeben]);
      HIGH_Impuls(SHIFTREGISTER);
    }
    digitalWrite(AUSGANG_EIN, HIGH);
    if(Ebenen_ausgeben == 0){
      digitalWrite(Ebenen[MAX_EBENEN - 1], HIGH);
    }
    else{
      digitalWrite(Ebenen[Ebenen_ausgeben-1], HIGH);
    }
    HIGH_Impuls(STORAGEREGISTER);
    digitalWrite(Ebenen[Ebenen_ausgeben], LOW);
    digitalWrite(AUSGANG_EIN, LOW);
    delay(Wartezeit);
  }
}
/* ------------------------------------------------------------------------------ */

/* Funktionsdefinition ---------------------------------------------------------- */
void HIGH_Impuls(char DigitalPin){
  digitalWrite(DigitalPin, HIGH);
  digitalWrite(DigitalPin, LOW);
}
/* ------------------------------------------------------------------------------ */


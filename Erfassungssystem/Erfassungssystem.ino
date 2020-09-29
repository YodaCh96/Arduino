int const ANZAHL_SPALTEN = 3;
int const ANZAHL_REIHEN = 3;
int const UMSCHALTWERT = 300;
int const ANZAHL_AUSGAENGE = 9;
int const VERSATZ = 2;

int Input_1 = A0;
int Input_2 = A1;
int Input_3 = A2;
int Input_4 = A3;
int Input_5 = A4;
int Input_6 = A5;
int LED_Test = 0;

int Wert_1 = 0;
int Wert_2 = 0;
int Wert_3 = 0;
int Wert_4 = 0;
int Wert_5 = 0;
int Wert_6 = 0;

int Werte_Array [3][3];
int Ausgabe_Zaehler = 0;
int X_Position = 0;
int Y_Position = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Input_1, INPUT);
  pinMode(Input_2, INPUT);
  pinMode(Input_3, INPUT);
  pinMode(Input_4, INPUT);
  pinMode(Input_5, INPUT);
  pinMode(Input_6, INPUT);
  pinMode(2, OUTPUT);

  //Serial.begin(9600);

}

void loop() {
//**************Einlesen der Sensorwerte**********************//
 Wert_1 = analogRead(Input_1);
 Wert_2 = analogRead(Input_2);
 Wert_3 = analogRead(Input_3);
 Wert_4 = analogRead(Input_4);
 Wert_5 = analogRead(Input_5);
 Wert_6 = analogRead(Input_6);



//*************Beschreiben vom Array************************//
//Spalte 1
if (Wert_1 < UMSCHALTWERT){
  for (int i =0; i < 3; i++){
    Werte_Array [i][0] = 1;
  }//Array Spalte füllen 
} else{
  for (int i = 0; i < 3; i++){
    Werte_Array [i][0] = 0;
  }//Array Spalte leeren
}
//Spalte 2
if (Wert_2 < UMSCHALTWERT){
  for (int i =0; i < 3; i++){
    Werte_Array [i][1] = 1;
  }//Array Spalte füllen 
} else{
  for (int i = 0; i < 3; i++){
    Werte_Array [i][1] = 0;
  }//Array Spalte leeren
}
//Spalte 3
if (Wert_3 < UMSCHALTWERT){
  for (int i =0; i < 3; i++){
    Werte_Array [i][2] = 1;
  }//Array Spalte füllen 
} else{
  for (int i = 0; i < 3; i++){
    Werte_Array [i][2] = 0;
  }//Array Spalte leeren
}
//Reihe 1
if(Wert_4 > UMSCHALTWERT){
  for (int i = 0; i < 3; i++){
    Werte_Array [2][i] = 0;
  }//Array Spalte leeren
}
//Reihe 2
if(Wert_5 > UMSCHALTWERT){
  for (int i = 0; i < 3; i++){
    Werte_Array [1][i] = 0;
  }//Array Spalte leeren
}
//Reihe 3
if(Wert_6 > UMSCHALTWERT){
  for (int i = 0; i < 3; i++){
    Werte_Array [0][i] = 0;
  }//Array Spalte leeren
}


/*Serial.print(Werte_Array[0][0]);
Serial.print(Werte_Array[0][1]);
Serial.println(Werte_Array[0][2]);
Serial.print(Werte_Array[1][0]);
Serial.print(Werte_Array[1][1]);
Serial.println(Werte_Array[1][2]);
Serial.print(Werte_Array[2][0]);
Serial.print(Werte_Array[2][1]);
Serial.println(Werte_Array[2][2]);
Serial.println("ENDE");
*/

//****************Ausgeben auf LEDs**************//
for(int Ausgabe_Zaehler = 2; Ausgabe_Zaehler < 11; Ausgabe_Zaehler++){
  digitalWrite(Ausgabe_Zaehler, Werte_Array[Y_Position][X_Position]);
  X_Position++;
  if(X_Position == ANZAHL_SPALTEN){
    X_Position = 0;
    Y_Position++;
    if(Y_Position == ANZAHL_REIHEN){
      Y_Position = 0;
    }//if2
  }//if
}








delay(10);
}//Endlos

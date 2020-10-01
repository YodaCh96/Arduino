
/* ========================================================================== */
/*                                                                            */
/*   SIEMENS_Leuchtschrift                                                    */
/*   Author 2017 I.Christodoulakis                                            */
/*                                                                            */
/*   Simulation anschalten eines Leuchtschriftes                              */
/*   22.12.17 U. Häsler Debuging, Helligkeitssteuerung in Betrieb genommen    */
/*            Einfügen eines Effektes (Dauer - Ein)                           */
/*            Alle Schlaufenzähler auf byte geändert                          */
/*            Gray Code - Effekt eingefügt                                    */
/*   8. 1 .18 Umschalten der Programme erfolgt unmittelbar nach Interrupt-    */
/*            routine   Funktionen werden nach Umschalten beendet             */
/*            Testimplementation in Funktion1 und Funktion9                   */
/*            offen: delay funktion ohne warten einbauen.                     */
/*                   interrupt sauber programmieren (ein/ausschalten)         */
/*                   HW prüfen: Ausgänge als low -side Treiber                */
/*                              Eingänge mit internem Pull-up.                */
/*                              Taster gegen Masse                            */
/*   siehe https://arduino.stackexchange.com/questions/23126/breaking-a-switch-case-from-an-isr   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* ========================================================================== */

/* ========================================================================== */
/* Anfang Programmeinstellungen                                               */
/* ========================================================================== */

// Konstante für Zeiten.
#define Zeit_T 50
#define Zeit_1 600
#define Zeit_2 50

// Konstante für Helligkeit
#define Helligkeit_100 255
#define Helligkeit_70 170
#define Helligkeit_30 90
#define Helligkeit_10 10

// Definition der aktiven Pins für diesen Sketch.

#define AnzahlLeds 7
#define AnzahlModi 9

#define board_type 2   // 1 = Arduino, 2 = Wemos

#if board_type == 1    // Steuert Compiler abhängig von der Zielhardware
 #define Taster 2  // Verwendete Eingänge Arduino
 #define Helligkeit 3
 int LedPins[7] = {4,5,6,7,8,9,10};   // Verwendete Ausgänge Arduino

#else
 #define Taster 16  // Verwendete Eingänge Wemos D1 R2
 #define Helligkeit 5
int LedPins[7] = {4,0,2,14,12,13,15};   // Verwendete Ausgänge Wemos D1 R2

#endif



//Anfangswerte
boolean Funktionswahl_changed =0;
byte Gray_Pattern =0;
int TasterState = 0;
int AlterZustandTaster = 0; 
int TasterZaehler = 0; 
int HelligkeitState = 0;
int AlterZustandHelligkeit = 0; 
int HelligkeitZaehler = 4;   
int Hell;
int Kombinationen = 128; //pow(2, AnzahlLeds);



void setup(){

  Serial.begin(9600);
           
           attachInterrupt(digitalPinToInterrupt(Taster),TasterFunktion,HIGH);     //Löst aus wenn sich der Wert von LOW auf HIGH ändert.
           attachInterrupt(digitalPinToInterrupt(Helligkeit),HelligkeitFunktion,HIGH); //Löst aus wenn sich der Wert von LOW auf HIGH ändert.
           
           pinMode(Taster,INPUT);
           pinMode(Helligkeit,INPUT);
           
           for(char a=0; a<AnzahlLeds; a++){
               pinMode(LedPins[a],OUTPUT);
              }//for_loop
             
           }//void_setup()

void loop(){
//TasterZaehler = 3;  // Test
//HelligkeitZaehler =1; // Test
  Serial.print(TasterZaehler);
  Serial.print("    ");
  Serial.println(HelligkeitZaehler);
  Serial.print("    ");  
//  Serial.print(LedPins[0], LedPins[1], LedPins[2], LedPins[3], LedPins[4], LedPins[5], LedPins[6]);
  
             switch (TasterZaehler) {
                    case 1:
                           //Effekt_1
                           HelligkeitFunktion();
                           Effekt1();
                           
                           break;
                    case 2:
                            //Effekt_2
                            HelligkeitFunktion();
                            Effekt2();
                           
                            break;
                    case 3:
                            //Effekt_3
                            HelligkeitFunktion();
                            Effekt3(); 
                           
                            break;
                    case 4:
                            //Effekt_4
                            HelligkeitFunktion();
                            Effekt4();
                          
                             break;
                    case 5:
                            //Effekt_5
                            HelligkeitFunktion();
                            Effekt5();
                        
                            break;
                    case 6:
                            //Effekt_6
                            HelligkeitFunktion();
                            Effekt6();
                           
                            break;
                    case 7:
                            //Effekt_7
                            HelligkeitFunktion();
                            Effekt7();
                           
                            break;  
                    case 8:
                            //Effekt_8
                            HelligkeitFunktion();
                            Effekt8();
                           
                            break;  
                    case 9:
                            //Effekt_9
                            HelligkeitFunktion();
                            Effekt9();
                    
                            break;  
                            default:  // Alle EIN
                                for (int x=0; x <AnzahlLeds; x++){
                                    analogWrite(LedPins[x], Hell); 
                                    delay(Zeit_1); 
                                    }//for_loop
                            break;
                    }//switch_case

            switch (HelligkeitZaehler) {
                    case 1:
                           //Helligkeit_1
                           Helligkeit1();
                         
                           break;
                    case 2:
                            //Helligkeit_1
                            Helligkeit2();   
                            break;
                    case 3:
                            //Helligkeit_1
                            Helligkeit3();   
                            break;
                    case 4:
                            //Helligkeit_1
                            Helligkeit4();  
                            break;
                            default:
                            break;
                     }//switch_case        
                  }//void_loop()
 
/*********************************FUNKTIONEN***********************************/

void TasterFunktion(){
                  
                   TasterState = digitalRead(Taster);  
                   if (TasterState != AlterZustandTaster){
                       if (TasterState == HIGH){
                           TasterZaehler++;
                           if(TasterZaehler>=AnzahlModi+1){
                              TasterZaehler = 0;
                             }
                                                         } 
                          delay(Zeit_T);
                          }
                     AlterZustandTaster = TasterState;
                     Funktionswahl_changed = 1;
                    }//TasterFunktion()

 void HelligkeitFunktion(){
                          HelligkeitState = digitalRead(Helligkeit);  
                   if (HelligkeitState != AlterZustandHelligkeit){
                       if (HelligkeitState == HIGH){
                           HelligkeitZaehler++;
                           if(HelligkeitZaehler>=5){
                              HelligkeitZaehler = 1;
                             }
                             } 
                          delay(Zeit_T);
                          }
                     AlterZustandHelligkeit = HelligkeitState;
  }//HelligkeitFunktion()                   

void Effekt1(){
               for (int a=0; a <AnzahlLeds; a++){
                    digitalWrite(LedPins[a], LOW); 
                    delay(Zeit_1); 
                    }//for_loop
                               
                 }//void_Effekt1()
              
void Effekt2(){
               for (int b=0; b <AnzahlLeds; b++){
                    analogWrite(LedPins[b], Hell); 
                    if (Funktionswahl_changed){
                    Funktionswahl_changed =0;
                    return;}
                    delay(Zeit_1); 
                    }//for_loop
                
               for (int c=0; c <AnzahlLeds; c++){
                    digitalWrite(LedPins[c], LOW); 
                    delay(Zeit_1); 
                    }//for_loop
              }//void_Effekt2()

void Effekt3(){ 
               for (int d=AnzahlLeds;  d>=0; d--){
                    analogWrite(LedPins[d], Hell); 
                    delay(Zeit_1); 
                   }//for_loop
                 
               for (int e=AnzahlLeds;  e>=0; e--){
                    digitalWrite(LedPins[e], LOW); 
                    delay(Zeit_1); 
                   }//for_loop
             }//void_Effekt3()

void Effekt4(){ 
               for (int f=0; f<AnzahlLeds; f ++){
                    analogWrite(LedPins[f], Hell);
                    delay(Zeit_1); 
                    digitalWrite(LedPins[f], LOW);
                    analogWrite(LedPins[f+1], Hell);  
                   }
  
              for (int g=AnzahlLeds; g>=0; g--){
                   analogWrite(LedPins[g], Hell); 
                   delay(Zeit_1); 
                   digitalWrite(LedPins[g], LOW);
                   analogWrite(LedPins[g-1], Hell);
                  }//for_loop
             }//void_Effekt4()

void Effekt5(){
                for (int h=0; h<=AnzahlLeds; h++){
                    analogWrite(LedPins[h], Hell); 
                    delay(Zeit_1);
                    analogWrite(LedPins[h+1], Hell);
                    digitalWrite(LedPins[h], LOW);
                    delay(Zeit_1); 
                   }//for_loop
              }//void_Effekt5()

void Effekt6(){
                for(int i=0; i<3; i++){                       
                                  for (int j=0; j<AnzahlLeds; j++){  //Alle LEDs leuchten 
                                       analogWrite(LedPins[j], Hell); 
                                      }//for_loop
                                       delay(Zeit_1*5);

                                 for (int k=0; k<AnzahlLeds; k++){ //Alle LEDs leuchten nicht 
                                      digitalWrite(LedPins[k], LOW); 
                                     }//for_loop
                                      delay(Zeit_1*5);
                                }//for_loop         
             }//void_Effekt5()

void Effekt7(){
               char Spiegel= AnzahlLeds-1;
               for (int l=0; l<AnzahlLeds/2; l++){
                    analogWrite(LedPins[l], Hell); 
                    analogWrite(LedPins[Spiegel - l], Hell);
                    delay(Zeit_1); 
                    digitalWrite(LedPins[l], LOW);
                    digitalWrite(LedPins[Spiegel - l], LOW);
                   }//for_loop

               for (int m = AnzahlLeds/2; m>=0; m--){
                    analogWrite(LedPins[m], Hell); 
                    analogWrite(LedPins[Spiegel - m], Hell);
                    delay(Zeit_1); 
                    digitalWrite(LedPins[m], LOW);
                    digitalWrite(LedPins[Spiegel - m], LOW);
                   }//for_loop
              }//void_Effekt7()

void Effekt8(){
                for (int n=0; n<AnzahlLeds-1; n++){
                    analogWrite(LedPins[n], Hell); 
                    delay(Zeit_1);
                    analogWrite(LedPins[n+1], Hell);
                    digitalWrite(LedPins[n], LOW);
                    delay(Zeit_1); 
                   }//for_loop
                    analogWrite(LedPins[AnzahlLeds-1], Hell);

               for (int o=0; o<AnzahlLeds-2; o++){
                    analogWrite(LedPins[o], Hell); 
                    delay(Zeit_1);
                    analogWrite(LedPins[o+1], Hell);
                    digitalWrite(LedPins[o], LOW);
                    delay(Zeit_1); 
                   }//for_loop
                    analogWrite(LedPins[AnzahlLeds-1], Hell);
                    analogWrite(LedPins[AnzahlLeds-2], Hell);

             for (int p=0; p<AnzahlLeds-3; p++){
                    analogWrite(LedPins[p], Hell); 
                    delay(Zeit_1);
                    analogWrite(LedPins[p+1], Hell);
                    digitalWrite(LedPins[p], LOW);
                    delay(Zeit_1); 
                   }//for_loop
                   for(int z=1; z<4; z++){
                       analogWrite(LedPins[AnzahlLeds-z], Hell);
                   }               

             for (int q=0; q<AnzahlLeds-4; q++){
                    analogWrite(LedPins[q], Hell); 
                    delay(Zeit_1);
                    analogWrite(LedPins[q+1], Hell);
                    digitalWrite(LedPins[q], LOW);
                    delay(Zeit_1); 
                   }//for_loop
                   for(int y=1; y<5; y++){
                       analogWrite(LedPins[AnzahlLeds-y], Hell);
                   }                          

           for (int r=0; r<AnzahlLeds-5; r++){
                    analogWrite(LedPins[r], Hell); 
                    delay(Zeit_1);
                    analogWrite(LedPins[r+1], Hell);
                    digitalWrite(LedPins[r], LOW);
                    delay(Zeit_1); 
                   }//for_loop
                   for(int x=1; x<6; x++){
                       analogWrite(LedPins[AnzahlLeds-x], Hell);
                   } 

            for (int s=0; s<AnzahlLeds-6; s++){
                    analogWrite(LedPins[s], Hell); 
                    delay(Zeit_1);
                    analogWrite(LedPins[s+1], Hell);
                    digitalWrite(LedPins[s], LOW);
                    delay(Zeit_1); 
                   }//for_loop
                   for(int w=1; w<7; w++){
                       analogWrite(LedPins[AnzahlLeds-w], Hell);
                   }
                   
           for (int t=0; t<AnzahlLeds-7; t++){
                    analogWrite(LedPins[t], Hell); 
                    delay(Zeit_1);
                    analogWrite(LedPins[t+1], Hell);
                    digitalWrite(LedPins[t], LOW);
                    delay(Zeit_1); 
                   }//for_loop
                   for(char v=1; v<8; v++){
                       analogWrite(LedPins[AnzahlLeds-v], Hell);
                   }
                    
          for (int u=AnzahlLeds; u>=0; u--){  //LEDs langsam auf LOW setzen
               digitalWrite(LedPins[u], LOW);
               delay(Zeit_1*2);
              }//for_loop
               delay(Zeit_1*3);
}//void_Effekt8()

void Effekt9(){
               for (int v=0; v <Kombinationen; v++){
                 Gray_Pattern = binaryToGray( v);
                    
                    for (int w=0; w <AnzahlLeds; w++){
                      if (bitRead(Gray_Pattern, w)){
                      analogWrite(LedPins[w], Hell); 
                      }
                    else {
                      digitalWrite(LedPins[w], LOW); 
                      }  
                       if (Funktionswahl_changed){
                    Funktionswahl_changed =0;
                    return;}
                      delay(Zeit_1);
                    }//for_loop          */
                                  
                }//for_loop
              }//void_Effekt9()


void Helligkeit1(){
 Hell = Helligkeit_10;
  }//Helligkeit1()

void Helligkeit2(){
    Hell = Helligkeit_30;
   }//Helligkeit2()

void Helligkeit3(){
      Hell = Helligkeit_70; 
  }//Helligkeit3()

void Helligkeit4(){
    Hell = Helligkeit_100; 
  };//Helligkeit4()


/*
 * This function converts an binary
 * number to reflected binary Gray code.
 *
 * The operator >> is shift right. The operator ^ is exclusive or.
 */
byte binaryToGray(byte num)
{
    return num ^ (num >> 1);
}



/* Delay Funktion ohne CPU - Blockierung
 *  
 

void myDelay(int ms)
{
    uint32_t start = micros();
    while (ms > 0 && !expressionChanged)
    {
        //yield();not implemented in arduino
        if ( (micros() - start) >= 1000)
        {
            ms--;
            start += 1000;
        }
    }   
}
*/

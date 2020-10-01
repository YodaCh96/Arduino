
/* ========================================================================== */
/*                                                                            */
/*   SIEMENS_Leuchtschrift                                                    */
/*   Author 2017 I.Christodoulakis                                            */
/*                                                                            */
/*   Simulation anschalten eines Leuchtschriftes                              */
/*                                                                            */
/*                                                                            */
/*   Programm für AtTiny8x.                                                   */
/*   Simulation von x Neonröhren.                                             */
/*   Eine Neonröhre ist defekt,                                               */
/*   und startet ständig neu.                                                 */
/*   Ob es eine defekte Röhre gibt,                                           */
/*   kann per Zufall ermittelt werden.                                        */
/*   Defekte Röhre kann per Zufall                                            */
/*   ermittelt werden.                                                        */
/*                                                                            */
/* ========================================================================== */

/* ========================================================================== */
/* Anfang Programmeinstellungen                                               */
/* ========================================================================== */

// Konstante für Zeiten.
#define Zeit 50

// Definition der aktiven Pins für diesen Sketch.
int LedPins[7] = {4,5,6,7,8,9,10};   

//Anfangswerte
int TasterState = 0;
int AlterZustandTaster = 0; 
int TasterZaehler = 0; 
int HelligkeitState = 0;
int AlterZustandHelligkeit = 0; 
int HelligkeitZaehler = 1;   
int Hell;

#define Taster 2  
#define Helligkeit 3
#define AnzahlLeds 7
#define AnzahlModi 7

void setup(){

  Serial.begin(9600);
           
           attachInterrupt(0,TasterFunktion,HIGH);     //Löst aus wenn sich der Wert von LOW auf HIGH ändert.
           attachInterrupt(1,HelligkeitFunktion,HIGH); //Löst aus wenn sich der Wert von LOW auf HIGH ändert.
           
           pinMode(Taster,INPUT);
           pinMode(Helligkeit,INPUT);
           
           for(char a=0; a<AnzahlLeds; a++){
               pinMode(LedPins[a],OUTPUT);
              }//for_loop
             
           }//void_setup()

void loop(){

  Serial.print(TasterZaehler);
  Serial.print("    ");
  Serial.println(HelligkeitZaehler);

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
                          delay(50);
                          }
                     AlterZustandTaster = TasterState;
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
                          delay(50);
                          }
                     AlterZustandHelligkeit = HelligkeitState;
  }//HelligkeitFunktion()                   

void Effekt1(){
               for (char b=0; b <AnzahlLeds; b++){
                    analogWrite(LedPins[b], Hell); 
                    delay(Zeit); 
                    }//for_loop
                
               for (char c=0; c <AnzahlLeds; c++){
                    digitalWrite(LedPins[c], LOW); 
                    delay(Zeit); 
                    }//for_loop
              }//void_Effekt1()

void Effekt2(){ //2_Effekt
               for (char d=AnzahlLeds;  d>=0; d--){
                    analogWrite(LedPins[d], Hell); 
                    delay(Zeit); 
                   }//for_loop
                 
               for (char e=AnzahlLeds;  e>=0; e--){
                    digitalWrite(LedPins[e], LOW); 
                    delay(Zeit); 
                   }//for_loop
             }//void_Effekt2()

void Effekt3(){ //1_Effekt
               for (char f=0; f<AnzahlLeds; f ++){
                    analogWrite(LedPins[f], Hell);
                    delay(Zeit); 
                    digitalWrite(LedPins[f], LOW);
                    analogWrite(LedPins[f+1], Hell);  
                   }
  
              for (char g=AnzahlLeds; g>=0; g--){
                   analogWrite(LedPins[g], Hell); 
                   delay(Zeit); 
                   digitalWrite(LedPins[g], LOW);
                   analogWrite(LedPins[g-1], Hell);
                  }//for_loop
             }//void_Effekt3()

void Effekt4(){
                for (char h=0; h<=AnzahlLeds; h++){
                    analogWrite(LedPins[h], Hell); 
                    delay(Zeit);
                    analogWrite(LedPins[h+1], Hell);
                    digitalWrite(LedPins[h], LOW);
                    delay(Zeit); 
                   }//for_loop
              }//void_Effekt4()

void Effekt5(){
                for(char i=0; i<3; i++){                       
                                  for (char j=0; j<AnzahlLeds; j++){  //Alle LEDs leuchten 
                                       analogWrite(LedPins[j], Hell); 
                                      }//for_loop
                                       delay(Zeit*5);

                                 for (char k=0; k<AnzahlLeds; k++){ //Alle LEDs leuchten nicht 
                                      digitalWrite(LedPins[k], LOW); 
                                     }//for_loop
                                      delay(Zeit*5);
                                }//for_loop         
             }//void_Effekt5()

void Effekt6(){
               char Spiegel= AnzahlLeds-1;
               for (char l=0; l<AnzahlLeds/2; l++){
                    analogWrite(LedPins[l], Hell); 
                    analogWrite(LedPins[Spiegel - l], Hell);
                    delay(Zeit); 
                    digitalWrite(LedPins[l], LOW);
                    digitalWrite(LedPins[Spiegel - l], LOW);
                   }//for_loop

               for (char m = AnzahlLeds/2; m>=0; m--){
                    analogWrite(LedPins[m], Hell); 
                    analogWrite(LedPins[Spiegel - m], Hell);
                    delay(Zeit); 
                    digitalWrite(LedPins[m], LOW);
                    digitalWrite(LedPins[Spiegel - m], LOW);
                   }//for_loop
              }//void_Effekt6()

void Effekt7(){
                for (char n=0; n<AnzahlLeds-1; n++){
                    analogWrite(LedPins[n], Hell); 
                    delay(Zeit);
                    analogWrite(LedPins[n+1], Hell);
                    digitalWrite(LedPins[n], LOW);
                    delay(Zeit); 
                   }//for_loop
                    analogWrite(LedPins[AnzahlLeds-1], Hell);

               for (char o=0; o<AnzahlLeds-2; o++){
                    analogWrite(LedPins[o], Hell); 
                    delay(Zeit);
                    analogWrite(LedPins[o+1], Hell);
                    digitalWrite(LedPins[o], LOW);
                    delay(Zeit); 
                   }//for_loop
                    analogWrite(LedPins[AnzahlLeds-1], Hell);
                    analogWrite(LedPins[AnzahlLeds-2], Hell);

             for (char p=0; p<AnzahlLeds-3; p++){
                    analogWrite(LedPins[p], Hell); 
                    delay(Zeit);
                    analogWrite(LedPins[p+1], Hell);
                    digitalWrite(LedPins[p], LOW);
                    delay(Zeit); 
                   }//for_loop
                   for(char z=1; z<4; z++){
                       analogWrite(LedPins[AnzahlLeds-z], Hell);
                   }               

             for (char q=0; q<AnzahlLeds-4; q++){
                    analogWrite(LedPins[q], Hell); 
                    delay(Zeit);
                    analogWrite(LedPins[q+1], Hell);
                    digitalWrite(LedPins[q], LOW);
                    delay(Zeit); 
                   }//for_loop
                   for(char y=1; y<5; y++){
                       analogWrite(LedPins[AnzahlLeds-y], Hell);
                   }                          

           for (char r=0; r<AnzahlLeds-5; r++){
                    analogWrite(LedPins[r], Hell); 
                    delay(Zeit);
                    analogWrite(LedPins[r+1], Hell);
                    digitalWrite(LedPins[r], LOW);
                    delay(Zeit); 
                   }//for_loop
                   for(char x=1; x<6; x++){
                       analogWrite(LedPins[AnzahlLeds-x], Hell);
                   } 

            for (char s=0; s<AnzahlLeds-6; s++){
                    analogWrite(LedPins[s], Hell); 
                    delay(Zeit);
                    analogWrite(LedPins[s+1], Hell);
                    digitalWrite(LedPins[s], LOW);
                    delay(Zeit); 
                   }//for_loop
                   for(char w=1; w<7; w++){
                       analogWrite(LedPins[AnzahlLeds-w], Hell);
                   }
                   
           for (char t=0; t<AnzahlLeds-7; t++){
                    analogWrite(LedPins[t], Hell); 
                    delay(Zeit);
                    analogWrite(LedPins[t+1], Hell);
                    digitalWrite(LedPins[t], LOW);
                    delay(Zeit); 
                   }//for_loop
                   for(char v=1; v<8; v++){
                       analogWrite(LedPins[AnzahlLeds-v], Hell);
                   }
                    
          for (char u=AnzahlLeds; u>=0; u--){  //LEDs langsam auf LOW setzen
               digitalWrite(LedPins[u], LOW);
               delay(Zeit*2);
              }//for_loop
               delay(Zeit*3);
}//void_Effekt7()



void Helligkeit1(){
 Hell = 10;
  }//Helligkeit1()

void Helligkeit2(){
    Hell = 40;
   }//Helligkeit2()

void Helligkeit3(){
      Hell = 100; 
  }//Helligkeit3()

void Helligkeit4(){
    Hell = 255; 
  }//Helligkeit4()

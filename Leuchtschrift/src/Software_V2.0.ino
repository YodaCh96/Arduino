/*******************************************************************************
* Programm:    SIEMENS-Leuchtschrift                                                                 
* uC:          Arduino UNO Rev3
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    1.0                                                        
* Datum:      25.09.2017
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt):
* 1.0 25.09.2017, Ioannis Christodoulakis, SIEMENS Buchstaben ansteuern
* 
* Totalzeit: 5.30 h                                   
********************************************************************************
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
*/
/*******************************DEFINE*****************************************/
#define Pin  2      //erste_LED_auf_Pin_2
#define Led 7       // Anzahl_LEDs
#define Zeit 50    // Verzoegerungszeit_50ms
/*******************************************************************************/  
int i;             //Variable_1_for_loop  
int x;             //Variable_2_for_loop  
int Spiegel;       //Variable für Effekt_6
/*******************************************************************************/         
void setup()
           {
            for (i = Pin; i < Pin + Led; i ++){
                 pinMode(i, OUTPUT);
                }//for_loop
           }//void_setup()
/*******************************************************************************/  
void loop(){
              
            Effekt1(); //1_Effekt       
            Effekt2(); //2_Effekt
            Effekt3(); //3_Effekt
            Effekt4(); //4_Effekt
            Effekt5(); //5_Effekt
            Effekt6(); //6_Effekt
            Effekt7(); //7 _Effekt
                   
          }//void_loop()
/*******************************************************************************/  
void Effekt1(){ //1_Effekt
               for (i = Pin; i < Pin + Led; i ++){
                    digitalWrite(i, HIGH); 
                    delay(Zeit); 
                    }//for_loop
                
               for (i = Pin; i < Pin + Led; i ++){
                    digitalWrite(i, LOW); 
                    delay(Zeit); 
                    }//for_loop
              }//void_Effekt1()
/*******************************************************************************/  
void Effekt2(){ //2_Effekt
               for (i = Pin + Led ; i >= Pin; i --){
                    digitalWrite(i, HIGH); 
                    delay(Zeit); 
                   }//for_loop
                 
              for (int i = Pin + Led ; i >= Pin; i --){
                   digitalWrite(i, LOW); 
                   delay(Zeit); 
                  }//for_loop
             }//void_Effekt2()
/*******************************************************************************/  
void Effekt3(){ //1_Effekt
               for (i = Pin; i < Pin + Led; i ++){
                    digitalWrite(i, HIGH);
                    delay(Zeit); 
                    digitalWrite(i, LOW);
                    digitalWrite(i + 1, HIGH);  
                   }
  
              for (i = Pin + Led ; i >= Pin; i --){
                   digitalWrite(i, HIGH); 
                   delay(Zeit); 
                   digitalWrite(i, LOW);
                   digitalWrite(i - 1, HIGH);
                  }//for_loop
             }//void_Effekt3()
/*******************************************************************************/  
void Effekt4(){ //4_Effekt
               for (i = Pin; i <= Pin + Led; i ++){
                    digitalWrite(i, HIGH); 
                    delay(Zeit);
                    digitalWrite(i + 1, HIGH);
                    digitalWrite(i, LOW);
                    delay(Zeit); 
                   }//for_loop
              }//void_Effekt4()
/*******************************************************************************/  
void Effekt5(){ //5_Effekt
               for (i = Pin; i < Pin + Led -1; i ++){
                    digitalWrite(i, HIGH); 
                    delay(Zeit);
                    digitalWrite(i + 1, HIGH);
                    digitalWrite(i, LOW);
                    delay(Zeit); 
                   }//for_loop
                    digitalWrite(8, HIGH);

               for (i = Pin; i < Pin + Led-2; i ++){ 
                    digitalWrite(i, HIGH); 
                    delay(Zeit);
                    digitalWrite(i + 1, HIGH);
                    digitalWrite(i, LOW);
                    delay(Zeit); 
               }//for_loop
                 digitalWrite(8, HIGH);
                 digitalWrite(7, HIGH);

             for (i = Pin; i < Pin + Led-3; i ++){
                 digitalWrite(i, HIGH);
                 delay(Zeit);
                 digitalWrite(i + 1, HIGH);
                 digitalWrite(i, LOW);
                 delay(Zeit);
               }//for_loop
                 digitalWrite(8, HIGH);
                 digitalWrite(7, HIGH);
                 digitalWrite(6, HIGH);


           for (i = Pin; i < Pin + Led-4; i ++){
                 digitalWrite(i, HIGH); 
                 delay(Zeit);
                 digitalWrite(i + 1, HIGH);
                 digitalWrite(i, LOW);
                 delay(Zeit); 
               }//for_loop
                 digitalWrite(8, HIGH);
                 digitalWrite(7, HIGH);
                 digitalWrite(6, HIGH);
                 digitalWrite(5, HIGH);

           for (i = Pin; i < Pin + Led-5; i ++){
                 digitalWrite(i, HIGH); 
                 delay(Zeit);
                 digitalWrite(i + 1, HIGH);
                 digitalWrite(i, LOW);
                 delay(Zeit); 
               }//for_loop
                 digitalWrite(8, HIGH);
                 digitalWrite(7, HIGH);
                 digitalWrite(6, HIGH);
                 digitalWrite(5, HIGH);
                 digitalWrite(4, HIGH);

           for (i = Pin; i < Pin + Led-6; i ++){
                 digitalWrite(i, HIGH); 
                 delay(Zeit);
                 digitalWrite(i + 1, HIGH);
                 digitalWrite(i, LOW);
                 delay(Zeit);
               }//for_loop
                 digitalWrite(8, HIGH);
                 digitalWrite(7, HIGH);
                 digitalWrite(6, HIGH);
                 digitalWrite(5, HIGH);
                 digitalWrite(4, HIGH);
                 digitalWrite(3, HIGH);

          for (i = Pin; i < Pin + Led-7; i ++){
                digitalWrite(i, HIGH); 
                delay(Zeit);
                digitalWrite(i + 1, HIGH);
                digitalWrite(i, LOW);
                delay(Zeit);
              }//for_loop
                digitalWrite(8, HIGH);
                digitalWrite(7, HIGH);
                digitalWrite(6, HIGH);
                digitalWrite(5, HIGH);
                digitalWrite(4, HIGH);
                digitalWrite(3, HIGH);
                digitalWrite(2, HIGH);
               
          for (i = Pin + Led; i >= Pin; i --){  //LEDs langsam auf LOW setzen
               digitalWrite(i, LOW);
               delay(Zeit*2);
              }//for_loop
               delay(Zeit*3);
          }//void_Effekt5()
/*******************************************************************************/  
void Effekt6(){ //6_Effekt          
               Spiegel= Pin*2 + Led-1;
               for (i = Pin; i < Pin + Led/2; i ++){
                    digitalWrite(i, HIGH); 
                    digitalWrite(Spiegel - i, HIGH);
                    delay(Zeit); 
                    digitalWrite(i, LOW);
                    digitalWrite(Spiegel - i, LOW);
                   }//for_loop

               for (i = Pin + Led/2; i >= Pin; i --){
                    digitalWrite(i, HIGH); 
                    digitalWrite(Spiegel - i, HIGH);
                    delay(Zeit); 
                    digitalWrite(i, LOW);
                    digitalWrite(Spiegel - i, LOW);
                   }//for_loop
               }//void_Effekt6()
/*******************************************************************************/  
void Effekt7(){ //7_Effekt
               for(x=0; x<3; x++){                       
                                  for (int i = Pin; i < Pin + Led; i ++){  //Alle LEDs leuchten 
                                       digitalWrite(i, HIGH); 
                                      }//for_loop
                                       delay(Zeit*5);

                                 for (int i = Pin; i < Pin + Led; i ++){ //Alle LEDs leuchten nicht 
                                      digitalWrite(i, LOW); 
                                     }//for_loop
                                      delay(Zeit*5);
                                }//for_loop         
             }//void_Effekt7()

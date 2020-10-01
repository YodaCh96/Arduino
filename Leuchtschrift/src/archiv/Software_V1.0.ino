/*******************************************************************************
* Programm:    SIEMENS-Buchstaben                                                                  
* uC:          Arduino UNO Rev3
*                             
* Autor:      Ioannis Christodoulakis                                            
* Version:    1.0                                                        
* Datum:      25.09.2017
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt):
* 1.0 25.09.2017, Ioannis Christodoulakis, SIEMENS Buchstaben ansteuern
* 
* Totalzeit:                                     
********************************************************************************
*
* Copyright (c) 2017 by I.Christodoulakis, CH-6340 Baar
*******************************************************************************/

/*******************************DEFINE*****************************************/

#define Pin  2     //1. Pin auf Arduino
#define Led 7      // Anzahl-LEDs
#define Zeit 50    // Verzoegerungszeit 500ms

/**********************Variablen*********************************/

int i;           //for-Loop  
int x;           //for-Loop
int Spiegel;

/*****************************Setup***********************************************/         

void setup()
            {
             for (i = Pin; i < Pin + Led; i ++){
                  pinMode(i, OUTPUT);
                 }
            }

void loop(){
  
/*********************************1.Effekt****************************************/  
 
            for (i = Pin; i < Pin + Led; i ++){
                  digitalWrite(i, HIGH); 
                  delay(Zeit); 
                }
                
             for (i = Pin; i < Pin + Led; i ++){
                 digitalWrite(i, LOW); 
                 delay(Zeit); 
               }
                
/*********************************2.Effekt****************************************/                 
               
            for (i = Pin + Led ; i >= Pin; i --){
                  digitalWrite(i, HIGH); 
                  delay(Zeit); 
                 }
                 
             for (int i = Pin + Led ; i >= Pin; i --){
                  digitalWrite(i, LOW); 
                  delay(Zeit); 
                }
     
/*********************************3.Effekt****************************************/   

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
                }
    
/*********************************4.Effekt****************************************/   

           for (i = Pin; i <= Pin + Led; i ++){
                  digitalWrite(i, HIGH); 
                  delay(Zeit);
                  digitalWrite(i + 1, HIGH);
                  digitalWrite(i, LOW);
                  delay(Zeit); 
                }
    
/*********************************5.Effekt****************************************/ 
 
           for (i = Pin; i < Pin + Led -1; i ++){
                 digitalWrite(i, HIGH); 
                 delay(Zeit);
                 digitalWrite(i + 1, HIGH);
                 digitalWrite(i, LOW);
                 delay(Zeit); 
               }
                 digitalWrite(8, HIGH);

           for (i = Pin; i < Pin + Led-2; i ++){ 
                 digitalWrite(i, HIGH); 
                 delay(Zeit);
                 digitalWrite(i + 1, HIGH);
                 digitalWrite(i, LOW);
                 delay(Zeit); 
               }
                 digitalWrite(8, HIGH);
                 digitalWrite(7, HIGH);

           for (i = Pin; i < Pin + Led-3; i ++){
                 digitalWrite(i, HIGH);
                 delay(Zeit);
                 digitalWrite(i + 1, HIGH);
                 digitalWrite(i, LOW);
                 delay(Zeit);
               }
                 digitalWrite(8, HIGH);
                 digitalWrite(7, HIGH);
                 digitalWrite(6, HIGH);


           for (i = Pin; i < Pin + Led-4; i ++){
                 digitalWrite(i, HIGH); 
                 delay(Zeit);
                 digitalWrite(i + 1, HIGH);
                 digitalWrite(i, LOW);
                 delay(Zeit); 
               }
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
               }
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
               }
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
              }
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
               }
                delay(Zeit*3);
 
/*********************************6.Effekt****************************************/ 
  
             Spiegel= Pin*2 + Led-1;

          for (i = Pin; i < Pin + Led/2; i ++){
               digitalWrite(i, HIGH); 
               digitalWrite(Spiegel - i, HIGH);
               delay(Zeit); 
               digitalWrite(i, LOW);
               digitalWrite(Spiegel - i, LOW);
             }

          for (i = Pin + Led/2; i >= Pin; i --){
               digitalWrite(i, HIGH); 
               digitalWrite(Spiegel - i, HIGH);
               delay(Zeit); 
               digitalWrite(i, LOW);
               digitalWrite(Spiegel - i, LOW);
            }

/*********************************7.Effekt****************************************/ 

          for(x=0; x<3; x++){                          // 3-Mal Loop
              for (int i = Pin; i < Pin + Led; i ++){  //Alle LEDs leuchten 
                   digitalWrite(i, HIGH); 
                  }
                   delay(Zeit*5);

              for (int i = Pin; i < Pin + Led; i ++){ //Alle LEDs leuchten nicht 
                   digitalWrite(i, LOW); 
                  }
                   delay(Zeit*5);
            }         
}

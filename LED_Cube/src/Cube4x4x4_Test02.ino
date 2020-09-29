#define Ebene1 2
#define Ebene2 3
#define Ebene3 4
#define Ebene4 5
#define Zeit 5
#define data 8
#define shift 9
#define store 10

bool Ebene1Array[4] = {1,0,0,0},
     Ebene2Array[4] = {0,1,0,0},
     Ebene3Array[4] = {0,0,1,0},
     Ebene4Array[4] = {0,0,0,1};

bool Ebene1Anzeige[16] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0}; // Array 4x4

int a,
    b,
    c,
    d,
    e,
    f,
    g,
    h;

void setup() {

pinMode(Ebene1, OUTPUT);
pinMode(Ebene2, OUTPUT);
pinMode(Ebene3, OUTPUT);
pinMode(Ebene4, OUTPUT);

pinMode(data, OUTPUT);
pinMode(shift, OUTPUT);
pinMode(store, OUTPUT);

Serial.begin(9600);

}

void loop() {

//*************************************1.EBENE***********************************//

digitalWrite(Ebene1, Ebene1Array[0]);
digitalWrite(Ebene2, Ebene1Array[1]);
digitalWrite(Ebene3, Ebene1Array[2]);
digitalWrite(Ebene4, Ebene1Array[3]);

digitalWrite(store,LOW);

Ebene1Funktion();

}

//*********************************Funktionen**************************************//

//****************************** **1.EBENE-Funktion******************************//

void Ebene1Funktion(){
  
     for (a = 0; a < 16; a ++){             // 2 mal for Loop                                
  
          digitalWrite(data, LOW);                     
          digitalWrite(shift, LOW);                      
          digitalWrite(data, Ebene1Anzeige[a]);                                                          
          delay(Zeit);                                 
          digitalWrite(shift, HIGH);                                                                 
          delay(Zeit);                                  
        }
        
        digitalWrite(store, HIGH);
        digitalWrite(store, LOW);                                                                                                                        
    }

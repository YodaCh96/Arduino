#define Ebene1 2
#define Ebene2 3
#define Ebene3 4
#define Ebene4 5

bool Ebene1State = 0;
bool Ebene2State = 0;
bool Ebene3State = 0;
bool Ebene4State = 0;

#define data 8
#define shift 9
#define store 10

bool Ebene[4] = {1,0,1,0}; // bool Ebene[4] = {1. Ebene,2. Ebene,3.Ebene,4.Ebene};

void setup() {

pinMode(Ebene1,OUTPUT);
pinMode(Ebene2,OUTPUT);
pinMode(Ebene3,OUTPUT);
pinMode(Ebene4,OUTPUT);

pinMode(data,OUTPUT);
pinMode(shift,OUTPUT);
pinMode(store,OUTPUT);

Serial.begin(9600);

}

void loop() {

digitalWrite(Ebene1,Ebene[0]);
digitalWrite(Ebene2,Ebene[1]);
digitalWrite(Ebene3,Ebene[2]);
digitalWrite(Ebene4,Ebene[3]);

Ebene1State = digitalRead(Ebene1);
Ebene2State = digitalRead(Ebene2);
Ebene3State = digitalRead(Ebene3);
Ebene4State = digitalRead(Ebene4);
 
Serial.print("Ebene1: ");
Serial.print(Ebene1State);
Serial.print(". Ebene2: ");
Serial.print(Ebene2State);
Serial.print(". Ebene3: ");
Serial.print(Ebene3State);
Serial.print(". Ebene4: ");
Serial.print(Ebene4State);
Serial.println(".");

}

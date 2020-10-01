#define auf      A0          //Taster-Auf
#define rechts   A1          //Taster-Rechts
#define unten    A2          //Taster-Unten
#define links    A3          //Taster-Links

void setup(){                //Pins-Output deklarieren

  pinMode(auf,OUTPUT);
  pinMode(unten,OUTPUT);
  pinMode(links,OUTPUT);
  pinMode(rechts,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int switchStatea0 = digitalRead(A0);
  int switchStatea1 = digitalRead(A1);
  int switchStatea2 = digitalRead(A2);
  int switchStatea3 = digitalRead(A3);

            if ((switchStatea0 || switchStatea1 || switchStatea2 || switchStatea3) == LOW){
                Serial.println("Kein Signal!");
               }
           if(switchStatea0 == HIGH){
              Serial.println("Auf!");
              }
           if(switchStatea1 == HIGH){
              Serial.println("Rechts!");
              }
           if(switchStatea2 == HIGH){
              Serial.println("Unten!");
              }
           if(switchStatea3 == HIGH){
              Serial.println("Links!!");
             }
           }


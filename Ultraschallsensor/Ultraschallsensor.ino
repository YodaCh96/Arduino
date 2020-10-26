int echoPin =  7; // Der Echo Pin
int trigPin =  8; // Der Trigger Pin
int LEDPinrot = 2;
int LEDPingruen = 4;
int soundPin = 12; 

int maximumRange = 5;
int minimumRange = 0;
long duration, distance;

void setup() {
Serial.begin (9600); // Die serielle Kommunikation starten
pinMode(trigPin, OUTPUT); // Trigger Pin als Ausgang definieren
pinMode(echoPin, INPUT); // Echo Pin als Eingang definieren
pinMode(LEDPinrot, OUTPUT);
pinMode(LEDPingruen, OUTPUT);
}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);


distance = duration/58.2;

if (distance >= maximumRange || distance <= minimumRange){

Serial.println("Kein Signal!");
digitalWrite(LEDPinrot, LOW);
digitalWrite(LEDPingruen, HIGH);
}
else {

Serial.print("Distance = " );
Serial.print(distance);
Serial.println(" cm" );
digitalWrite(LEDPinrot, HIGH);
digitalWrite(LEDPingruen, LOW);
tone(soundPin, 500, 300);
delay(distance); 
noTone(soundPin);

}

delay(50);
}

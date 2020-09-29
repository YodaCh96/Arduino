#define trigger 9 // Arduino Pin an HC-SR04 Trig
#define echo 8 // Arduino Pin an HC-SR04 Echo
int LED_gruen = 5;
int LED_gelb = 6;
int LED_rot = 7;
long previousMillis = 0;
long interval = 10000;

void setup(void) {

pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
}

long duration = 0;
long distance = 0;
long distance_old = 0;

void loop() {

unsigned long currentMillis = millis();
  
digitalWrite(trigger, LOW);
delayMicroseconds(2);

digitalWrite(trigger, HIGH);
delayMicroseconds(10);

digitalWrite(trigger, LOW);
duration = pulseIn(echo, HIGH); // Echo-Zeit messen

// Echo-Zeit halbieren (weil hin und zurueck, der doppelte Weg ist)
duration = (duration / 2);
// Zeit des Schalls durch Luft in Zentimeter umrechnen
distance = duration / 29.1;

// Anzeige nur Aendern wenn neue Entfernung
if (distance != distance_old) {
Serial.print(distance);
Serial.println(" cm");
previousMillis = currentMillis;
}

distance_old = distance; // letze Entfernung speichern
delay(200);

//LED´s ansteuern
if ((distance > 50) || (currentMillis - previousMillis > interval))
{ digitalWrite(LED_gruen, HIGH); //Wenn Abstand zu groß, ist keine LED aktiv
digitalWrite(LED_gelb, LOW);
digitalWrite(LED_rot, LOW);
}

else if (distance > 35)
{ digitalWrite(LED_gruen, HIGH);
digitalWrite(LED_gelb, LOW);
digitalWrite(LED_rot, LOW);
}


else if (distance < 10)
{ digitalWrite(LED_gruen, LOW);
digitalWrite(LED_gelb, LOW);
digitalWrite(LED_rot, HIGH);
}

else
{
digitalWrite(LED_gruen, LOW);
digitalWrite(LED_gelb, HIGH);
digitalWrite(LED_rot, LOW);
}

}

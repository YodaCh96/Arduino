int ledPin = 13;                // LED liegt am Pin 13.
 
void setup()                    // Am Anfang der Sketch einmal laufen lassen.
{
  pinMode(ledPin, OUTPUT);      // Setzt den ledPin (Pin 13) als Ausgang
}
 
void loop()                     // Immer wieder durchlaufen lassen.
{
  digitalWrite(ledPin, HIGH);   // LED einschalten
  delay(15);                  // 1000 Milisekunden (= 1s) warten
  digitalWrite(ledPin, LOW);    // LED ausschalten
  delay(15);                  // 1000 Milisekunden (= 1s) warten
}

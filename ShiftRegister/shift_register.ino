//Pin verbunden mit SH_CP des 74HC595
int shiftPin = 8;
//Pin verbunden mit ST_CP des 74HC595
int storePin = 9;
//Pin verbunden mit DS des 74HC595
int dataPin = 10;
int counter = 0;
// Binärer Counter von 0 bis 255. 
// 1 = 000000001
// 2 = 000000010
// 3 = 000000011
// 4 = 000000100
// 5 = 000000101
// usw. Die LEDs zeigen alle Werte von 0 bis 255.
void setup() {
 // Pins 8,9,10 auf Ausgabe stellen
 pinMode(storePin, OUTPUT);
 pinMode(shiftPin, OUTPUT);
 pinMode(dataPin, OUTPUT);
}
void loop () {
 digitalWrite(storePin, LOW);
 shiftOut(dataPin, shiftPin, MSBFIRST, counter);
 digitalWrite(storePin, HIGH);
 delay(500);
 counter ++;
 if (counter > 255) {
   counter = 0;
 }
}

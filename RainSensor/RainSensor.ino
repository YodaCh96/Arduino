int rainsense = 0; // analog sensor input pin A0

void setup() {
  Serial.begin(9600);
  pinMode(rainsense, INPUT);
}

void loop() {
   int rainSenseReading = analogRead(rainsense);
   Serial.println(rainSenseReading);
   delay(1000);
}

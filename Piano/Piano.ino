int notes[] = {262,294,330,349};
int keyVal;
void setup() {
  Serial.begin(9600);
 }

void loop() {
  keyVal = analogRead(A0);
  Serial.println(keyVal);
  if(keyVal == 1023) {
  tone(8, 700);
  delay(50);
  tone(8, 900);
  delay(50);;
  }
  else if(keyVal >= 990 && keyVal <=1010) {
  tone(8, 350);
  delay(50);
  tone(8, 600);
  delay(50);
  }
  else if(keyVal >= 505 && keyVal <=515) {
    tone(8, 200);
  delay(50);
  tone(8, 100);
  delay(50);

  }
  else if(keyVal >= 5 && keyVal <=10) {
  tone(8, 150);
  delay(50);
  tone(8, 50);
  delay(50);
    
  
  }
  else {
  noTone(8);
  }

}

#define Zeit0 10000
#define Zeit1 1000
#define Zeit2 2000
#define Zeit3 3000

int ledpinrotauto = 7;
int ledpingelbauto = 6;
int ledpingruenauto = 5;
int ledpingruenfuss = 3;
int ledpinrotfuss = 2;
int tasterpinampel = 8;
int tasterampelwert = LOW;

const int sensorPin = A1;
const float baselineTemp = 30.0;



void setup() {
for(int i=9; i<12; i++){
  pinMode(i, OUTPUT);
  digitalWrite(i, LOW);
  pinMode(ledpinrotauto, OUTPUT);
  pinMode(ledpingelbauto, OUTPUT);
  pinMode(ledpingruenauto, OUTPUT);
  pinMode(ledpinrotfuss, OUTPUT);
  pinMode(ledpingruenfuss, OUTPUT);
  pinMode(tasterpinampel, INPUT);
  Serial.begin(9600);
}
}


void loop() {
 
tasterampelwert = digitalRead(tasterpinampel);
Serial.print(tasterampelwert);

if(tasterampelwert == LOW)
{
  digitalWrite(ledpingruenauto, HIGH);
  digitalWrite(ledpinrotfuss, HIGH);
  temperatur();
}
 
else if (tasterampelwert == HIGH)
{
  digitalWrite(ledpinrotfuss, HIGH);
  delay(10000);
  ampelumschaltung();
  }
}
  


void ampelumschaltung(){
  digitalWrite(ledpingruenauto, LOW);
  digitalWrite(ledpingelbauto, HIGH);
  delay(Zeit3);
  digitalWrite(ledpingelbauto, LOW);
  digitalWrite(ledpinrotauto, HIGH);
  delay(Zeit1);
  digitalWrite(ledpinrotfuss, LOW);
  digitalWrite(ledpingruenfuss, HIGH);
  delay(Zeit0);
  digitalWrite(ledpingruenfuss, LOW);
  digitalWrite(ledpinrotfuss, HIGH);
  delay(Zeit1);
  digitalWrite(ledpingelbauto, HIGH);
  delay(Zeit2);
  digitalWrite(ledpinrotauto, LOW);
  digitalWrite(ledpingelbauto, LOW);
  digitalWrite(ledpingruenauto, HIGH);
}

void temperatur(){
   int sensorVal = analogRead(sensorPin);
  //Serial.print("Sensor value: ");
  //Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0)*5;
  //Serial.print(", Volts: ");
  //Serial.print(voltage);

  Serial.print("I thermokrasia tou dwmatiou einai: ");

  float temperature = (voltage - .5)*100;
  Serial.print(temperature);
  Serial.println(" C.");
  
if (temperature > baselineTemp){
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}
else{
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
}



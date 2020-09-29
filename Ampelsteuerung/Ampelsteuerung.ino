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

void setup() 
{
pinMode(ledpinrotauto, OUTPUT);
pinMode(ledpingelbauto, OUTPUT);
pinMode(ledpingruenauto, OUTPUT);
pinMode(ledpinrotfuss, OUTPUT);
pinMode(ledpingruenfuss, OUTPUT);
pinMode(tasterpinampel, INPUT);
digitalWrite(ledpingruenauto, HIGH);
digitalWrite(ledpinrotfuss, HIGH);
Serial.begin(9600);
}
void loop() 
{
tasterampelwert = digitalRead(tasterpinampel);
Serial.println(tasterampelwert);
if(tasterampelwert == HIGH)
{
  delay(5000);
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


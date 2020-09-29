const int sensorPin = A1;
const float baselineTemp = 30.0;

void setup() {
Serial.begin(9600);
for(int i=9; i<12; i++)
{
  pinMode(i,OUTPUT);
}
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  //Serial.print("Sensor value: ");
  //Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0)*5;
  //Serial.print(", Volts: ");
  //Serial.print(voltage);

  Serial.print("I thermokrasia tou dwmatiou einai: ");

  float temperature = (voltage - .5)*100;
  Serial.print(temperature);

  if(baselineTemp < temperature)
  {
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    Serial.println(". LED: ON");
  }
  else{
     digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    Serial.println(".           LED: OFF");
  }
} 


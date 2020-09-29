# WEMOS D1

Reference: http://arduino.esp8266.com/stable/package_esp8266com_index.json

Tools &rarr; Board &rarr; Boards Manager &rarr; esp8266 by ESP8266 Community &rarr; install

Board: **WEMOS D1 (Retired)**

Code: 

```
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "auth";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "name";
char pass[] = "pass";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
```

Handy &rarr; Mobile Hotspot :  
Name: Ioannis Handy
Passwort: xxx

libraries in Ordner von x86 Programme 
libraries &rarr; blynk &rarr; examples &rarr; Boards_WiFi &rarr; ESP8266_Standalone

Example: D5 with slider...

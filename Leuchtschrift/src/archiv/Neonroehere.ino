
/* ========================================================================== */
/*                                                                            */
/*   neonroehre.ino                                                           */
/*   Author 2013 K. Büßer                                                     */
/*                                                                            */
/*   Simulation anschalten einer Bahnsteigbeleuchtung                         */
/*   aus Neonröhren.                                                          */
/*                                                                            */
/*   Programm für AtTiny8x.                                                   */
/*   Simulation von x Neonröhren.                                             */
/*   Eine Neonröhre ist defekt,                                               */
/*   und startet ständig neu.                                                 */
/*   Ob es eine defekte Röhre gibt,                                           */
/*   kann per Zufall ermittelt werden.                                        */
/*   Defekte Röhre kann per Zufall                                            */
/*   ermittelt werden.                                                        */
/*                                                                            */
/* ========================================================================== */


/* ========================================================================== */
/* Anfang Programmeinstellungen                                               */
/* ========================================================================== */
// Konstante für vereinfachte Zeiten.

unsigned long  Sekunde = 100;
unsigned long  Minute  = 60 * Sekunde;

// Konstane für die Dauer Startflackern.
unsigned long Startdauer =  3*Sekunde;
// Konstante für die Dauer der Nacht (für die Testphase kurz).
unsigned long Nachtdauer = 7*Sekunde;
// Konstante für die Dauer des Tages (für die Testphase kurz).
unsigned long Tagdauer   = 10*Sekunde;


// Definition der aktiven Pins für diesen Sketch.
byte Leds[] = {4,5,6,7,8,9,10};

byte PinAnz = sizeof(Leds);
// Definiere Arbeitsweise defekte LED.
// keine defekte LED: 0
// defekte LED durch zufall: 1
// immer defekte LED: 2
byte defdefLed = 1;
// Prozentuale chance auf defekte Led:
// Beispiele:
// bei 50:50 den Wert 1 speichern.
// bei 33:66 den Wert 2 speichern, etc.
byte defLedProz = 1;
// Variable zum Merken, ob es eine defekte LED gibt.
boolean defLEDjn;
// Variable zum Merken einer festen defekten LED.
// beim Wert 99 wird die defekte LED durch Zufall ermittelt.
byte fdefLed = 99;
// Variable zum Merken der durch Zufall ermittelten defekten LED.
// wenn fdefLed <> 99, wird die defekte LED in zdefLed übertragen,
// ist fdefled > PinAnz, wird PinAnz übertragen.
byte zdefLed = 0;
/* ========================================================================== */
/* Ende Programmeinstellungen                                               */
/* ========================================================================== */


/* ========================================================================== */
/* Anfang Datendefinition                                                     */
/* ========================================================================== */
// Variablen zum Merken von millis() flackern ein.
unsigned long Ledein[sizeof(Leds)];
// Variablen zum Merken von millis() flackern aus.
unsigned long Ledaus[sizeof(Leds)];
// Variablen zum Merken von millis() Flakern.
unsigned long Ledflackern[sizeof(Leds)];
// Variablen zum Merken der Einschaltreihenfolge.
byte Ledalleein[sizeof(Leds)];
// Variablen zum Merken der Einschaltverzögerung.
unsigned long Ledalleeinwarten[sizeof(Leds)];
/* ========================================================================== */
/* Ende Datendefinition                                                       */
/* ========================================================================== */


/* ========================================================================== */
/* Debug Blinken                                                              */
/* ========================================================================== */
void DebugBlink (byte LEDa,byte LEDb,boolean anaus)
{
  if (anaus)
  {
    digitalWrite (LEDa,HIGH);
    digitalWrite (LEDb,HIGH);     
  }
  else
  {
    delay (500);
    digitalWrite (LEDa,LOW);     
    digitalWrite (LEDb,LOW);     
    delay (500);
  }
}

/* ========================================================================== */
/* Anfang Standardprocedur Setup                                              */
/* ========================================================================== */
void setup()
{
// Alle AtTiny-Pins auf OUTPUT setzen.
  randomSeed(analogRead(0));
  for (int i=0;i<PinAnz;i++) pinMode(Leds[i], OUTPUT);
  for (int i=0;i<PinAnz;i++) digitalWrite(Leds[i], LOW);
}
/* ========================================================================== */
/* Ende Standardprocedur Setup                                                */
/* ========================================================================== */

/* ========================================================================== */
/* Anfang eigene Setup Proceduren                                             */
/* ========================================================================== */

/* ========================================================================== */
/* ermitteln, ob es eine defekte LED gibt                                     */
/* ========================================================================== */
void setzedefLEDjn ()
{
byte i;
  defLEDjn = false;
  i = random(0,1+defLedProz);
  if (i==1) defLEDjn = true;
}

/* ========================================================================== */
/* defekte LED setzen                                                         */
/* ========================================================================== */
void setzedefLed ()
{
// Setzen der defekten LED, wie in den Parametern eingestellt.  
  if (fdefLed==99)
  { zdefLed = random(sizeof(Leds));}
  else { if (fdefLed>PinAnz)
          {  zdefLed = PinAnz-1;}
         else {zdefLed = fdefLed;}
       }  
}

/* ========================================================================== */
/* Startflackern setzen                                                       */
/* ========================================================================== */
void setzeFlackern ()
{
// Setzen der Leuchtdauer der LEDs beim Starten.
  for (int i=0;i<sizeof(Leds);i++) Ledein[i]= random(70,120);
// Setzen der Dunkeldauer der LEDs beim Starten.
  for (int i=0;i<sizeof(Leds);i++) Ledaus[i]= random(350,550);
}

/* ========================================================================== */
/* Einschaltreihenfolge setzen                                                */
/* ========================================================================== */

void EinschaltenReihe()
{
boolean LedAn;
byte zLed;
byte Ledz;
byte sLed;

  zLed=0;
  Ledz=0;
  sLed=0;
// Initialisierung der Einschaltreihenfolge.
  for (int i=0;i<sizeof(Leds);i++) Ledalleein[i]=30;
// Einschaltreihenfolge für alle Leds erstellen.
  do
  {
// Zufallswert der anzuschaltenden Leds.
    sLed=random(0,sizeof(Leds));

// setzen Abfragevariable auf Standardja.
   if ((sLed>-1) && (sLed<=sizeof(Leds)))
   {

     LedAn=true;
// Prüfen, ob anzuschaltende LED schon angeschaltet ist.
// Wenn ja, Abfragevariable auf nein.
     for (zLed=0;zLed<sizeof(Leds);zLed++)
       if (Ledalleein[zLed]==sLed) LedAn = false;
// Wenn Led angeschaltet werden soll, Led in der
// Reihenfolgeliste speichern. Listenindex um 1
// erhöhen.
    if (LedAn)
    {
      Ledalleein[Ledz]=sLed;
      Ledz++;    
    }
   }    
  }
  while (Ledz<sizeof(Leds));
}

/* ========================================================================== */
/* Einschaltverzögerung setzen                                                */
/* ========================================================================== */
void Einschaltenwarten()
{
// setzen der Einschaltwartezeit per Zufall.    
  for (int i=0;i<sizeof(Leds);i++) Ledalleeinwarten[i]=random(50,80);
}

/* ========================================================================== */
/* eigene Procedur Setup                                                      */
/* ========================================================================== */

void eigenesSetup()
{
  for (byte i=0;i<sizeof(Leds);i++) Ledein[i]=0;
  for (byte i=0;i<sizeof(Leds);i++) Ledaus[i]=0;
  setzedefLEDjn ();
  setzedefLed ();
  setzeFlackern ();
  EinschaltenReihe();
  Einschaltenwarten();
}

/* ========================================================================== */
/* Ende eigene Setup Proceduren                                               */
/* ========================================================================== */

/* ========================================================================== */
/* Anfang Programmprozeduren                                                  */
/* ========================================================================== */

/* ========================================================================== */
/* alle Leds ausschalten                                                      */
/* ========================================================================== */
void Ledsaus ()
{
  for (int i=0;i<sizeof(Leds);i++) digitalWrite(Leds[i], LOW);
  for (int i=0;i<PinAnz;i++) digitalWrite(i, LOW);
}

/* ========================================================================== */
/* Flackern beim Starten                                                      */
/* ========================================================================== */
void Flackern ()
{
// Variable zum Speichern der Endzeit des Startflackerns.
// millis() sind die vergangenen Millisekunden seit einschalten des AtTiny.
// vergangene Zeit + Startdauer = Endzeit Startflackern.
long bisan;
  bisan = millis()+Startdauer;

// Bearbeiten bis Endezeit Startflackern.
  while (millis() < bisan)
  {
    for (int i=0;i<sizeof(Leds);i++)
    {
// Für jede LED prüfen, ob die nächste Schaltzeit erreicht ist.
      if (millis()> Ledflackern[i])
// Frage, ob LED dunkel ist.
      {  if (digitalRead(Leds[i])==LOW)
          {
// Led dunkel: LED einschalten, Ausschaltzeit speichern.
              digitalWrite(Leds[i], HIGH);
              Ledflackern[i]=millis()+Ledein[i];
          }
          else
          {
// Led hell: LED ausschalten, Einschaltzeit speichern.
              digitalWrite(Leds[i], LOW);
              Ledflackern[i]=millis()+Ledaus[i];
          }
      }
    }
  }
}

/* ========================================================================== */
/* defekte LED blinkt, solange Nacht ist                                    */
/* ========================================================================== */
void blinkdefLed ()
{
unsigned long bisaus;

// Endezeit Nacht berechnen.
  bisaus = millis()+Nachtdauer;

  if ((defdefLed == 0) or
     ((defdefLed == 1) and (not defLEDjn)))
    {
// keine defekte LED
      while (millis() < bisaus)
      {}
    }
  else
    {
// defekte LED ausschalten.
      digitalWrite(Leds[zdefLed], LOW);
  
  Ledflackern[zdefLed]=0;
// solange Nacht ist bearbeiten.
      while (millis() < bisaus)
      {
// Berechnen der Ein- und Ausschalzeit blinkende LED.
         Ledein[zdefLed]= random(40,90);
         Ledaus[zdefLed]= random(350,550);
// Einschalten der LED und berechnen der Anschaltdauer.
         digitalWrite(Leds[zdefLed], HIGH);
         Ledflackern[zdefLed]=millis()+Ledein[zdefLed];
// nichts tun, bis LED ausgegschaltet wird.
         while (millis() < Ledflackern[zdefLed])
           {
           }
// Ausschalten der LED und berechnen der Ausschaltdauer.
         digitalWrite(Leds[zdefLed], LOW);
         Ledflackern[zdefLed]=millis()+Ledaus[zdefLed];
// nichts tun, bis LED eingegschaltet wird.
         while (millis() < Ledflackern[zdefLed])
           {
           }
      }
    }
}

/* ========================================================================== */
/* alle LEDs einschalten                                                      */
/* ========================================================================== */
void Ledsein ()
{
  for (int i=0;i<sizeof(Leds);i++)
  {
    digitalWrite(Leds[Ledalleein[i]], HIGH);
    delay(Ledalleeinwarten[i]);
  }
}

/* ========================================================================== */
/* Ende Programmprozeduren                                                    */
/* ========================================================================== */

/* ========================================================================== */
/* Standardprozedur Loop. Endlosschleife für Prozeduraufrufe                  */
/* ========================================================================== */
void loop()
{
//  Ausführung egenes Setup.
   eigenesSetup();
// alle LEDs ausschalten.
 //  Ledsaus ();
// Startflackern.
  Flackern ();
// alle LEDs nach Startflackern einschalten.
//   Ledsein ();
// defekte Röhre simulieren.
  blinkdefLed ();
// alle LEDs ausschalten.
 //  Ledsaus ();
// warten, solange es Tag ist.
 //  delay(Tagdauer);
}


# CH340 Treiber für Arduino Boards installieren

Viele Arduino kompatiblen Boards benötigen einen USB Treiber, damit diese vom Computer richtig erkannt werden. 
Der beliebteste USB Chipsatz der oft Verwendung findet ist der **CH340G** bzw. **CH341SER** USB Chipsatz. 
Die Installation ist sehr einfach und dauert gerade einmal 3 Minuten.

* Passenden USB Treiber Downloaden
* USB Treiber installieren
* Arduino Uno oder Nano am PC oder Mac anschliessen

---

## Passenden USB Treiber für Deinen Computer

Wähle den für deinen Computer passenden USB Treiber zum Download aus. Entweder die **Windows Version**, **Mac OS** oder **Linux**.

* [CH341SER WIN USB Treiber](http://www.wch.cn/download/CH341SER_ZIP.html)
* [CH341SER MAC OS Treiber](http://www.wch.cn/download/CH341SER_MAC_ZIP.html)
* [CH341 Linux auf Github](https://github.com/juliagoda/CH341SER)

---

## CH340/CH341 Treiber installieren

Entweder ist der Treiber im ZIP Format gepackt, oder er wird als selbst-entpackendes Archiv angeboten. 
Es genügt in den meisten Fällen ein Klick auf den Treiber, um diesen direkt zu installieren.

Bei der Installation werden Administrationsrechte benätigt, so dass der Treiber sich vernünftig in das OS integrieren kann.

---

## Arduino Uno oder Nano anschliessen

Sobald die Treiber Installation erfolgreich war, muss der Computer in den meisten Fällen einmal neugestartet werden. 
Danach sollte der Treiber vollständig installiert sein. 
Sobald nun der Arduino Uno oder Nano, oder der USB Adapter per USB Kabel eingesteckt werden, 
sollte das entsprechende Gerät im Gerätemanager unter Windows oder bei MAC OS direkt erkannt werden.

Schliesslich kann man mit der gewünschten Software z.B. Arduino IDE seine Sketches wie gewohnt auf sein Board überspielen.

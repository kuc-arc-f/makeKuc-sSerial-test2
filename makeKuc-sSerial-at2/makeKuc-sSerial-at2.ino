
#include <SoftwareSerial.h>
#include <DHT.h>

SoftwareSerial mySerial(5, 6); /* RX:D5, TX:D6 */

#define DHTPIN 3     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

//
void setup() {
  Serial.begin( 9600 );
  mySerial.begin( 9600 );
  Serial.println("#Start-setup-SS");
  dht.begin();
}

//
void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (isnan(h) || isnan(t) ) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
   int iD1=int(t);
   int iD2=int(h);    
   /*
     String sTmp=String(t);
     String sHum=String(h);
Serial.print("sTmp=");
Serial.print(sTmp);
Serial.print(", Hum=");
Serial.println(sHum);
   */
  //sSerial
   char cD1[8+1];
   char cD2[8+1];   
   sprintf(cD1 , "d1%06d", iD1);
mySerial.print( cD1 );
Serial.print("cD1=");
Serial.println(cD1  );
    delay( 500);
    sprintf(cD2 , "d2%06d", iD2);
mySerial.print( cD2 );
//Serial.print("cD2=");
//Serial.println(cD2  );
    delay( 500);
}


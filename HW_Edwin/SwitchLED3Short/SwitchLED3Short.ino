#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>

#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"
#define HOST "km4.mobidapt.com"



void setup() {
  Serial.begin(9600);

  setupESP8266();

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {

  for (int i = 1; i <= 3; i++) {
    // haal stand van switch op
    String request = "/switches?userid=rolf&switchid=switch" + String(i);

    String response;
    int result = sendRequest(HOST, request, response);
    if (result < 0) {
      Serial.println(F("Failed to connect to server."));
    } else {
      Serial.println(response);
    }


    int ledPin = 9 + i;
    // zoek in de response naar 't woord 'off'
    if (response.indexOf("off") >= 0) {
      digitalWrite(ledPin, LOW);
    } else { // geen 'off'? dan blijkbaar 'on'...
      digitalWrite(ledPin, HIGH);
    }

    delay(100);
  }
}


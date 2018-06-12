#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"
#define HOST "studenthome.hku.nl"

int day = 0;
int hrs = 0;
int mins = 0;
int sec = 0;
int loc = 0;

String url;

volatile bool button = false;

Adafruit_7segment matrix = Adafruit_7segment();
bool blinkColon = true;

String getBodypart(const String& response, const String& unit) {
  int bodyStart = response.indexOf(unit);
  int bodyEnd = response.indexOf("<br>", bodyStart + 5);
  String body = response.substring(bodyStart + 5, bodyEnd);
  body.trim();
  return body;
}

void setup() {
  Serial.begin(9600);
  setupESP8266();
  matrix.begin(0x70);
  pinMode(2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), leavingISR, CHANGE);
  url.reserve(50); 
}

void loop() {
  if (button) {
    String SentResponse;
    Serial.print(F("Sending leaving Time: "));
    int leavingtime = ((day * 86400) + (hrs * 3600) + (mins * 60) + sec) * -1;

    
    url.concat("/~rolf.jurgens/PMblok4IAD/vt.php?l_id=");
    url.concat(loc);
    url.concat("&lt=");
    url.concat(leavingtime);

    Serial.println(url);
    int result = sendRequest(HOST, url, SentResponse);
    if (result == 1) {
      Serial.println(F("Succes!"));
      Serial.println(SentResponse); 
      url=""; 
    } else {
      Serial.print(F("Sending failed: "));
      Serial.println(result);
      url=""; 
    }
    button = false;
  }
  delay(200);
}

void leavingISR() {
  button = true;
}

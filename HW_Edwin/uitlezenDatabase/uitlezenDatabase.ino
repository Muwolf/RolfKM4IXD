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
}

void loop() {
  String response;
  int result;
  digitalWrite(LED_BUILTIN, LOW);

  result = sendRequest(HOST, "/~rolf.jurgens/PMblok4IAD/uitlezenAgenda.php", response);
  if (result == 1) {
    day = getBodypart(response, "day: ").toInt();
    hrs = getBodypart(response, "hrs: ").toInt();
    mins = getBodypart(response, "min: ").toInt();
    sec = getBodypart(response, "sec: ").toInt();
    loc = getBodypart(response, "loc: ").toInt();

    if (day > 0) {
      matrix.print((day * 100) + hrs, DEC);
    } else if (hrs > 0) {
      matrix.print((hrs * 100) + mins, DEC);
    } else if (mins > 0) {
      matrix.print((mins * 100) + sec, DEC);
    } else if (sec > 0) {
      matrix.print(sec, DEC);
    } else {
      matrix.print((mins * 100) + sec, DEC);
    }

    blinkColon != blinkColon;
    matrix.drawColon(blinkColon);

  } else {
    Serial.println(result);
    matrix.print(0xDEAD, HEX);
  }

  matrix.writeDisplay();

  if (button) {
    String SentResponse;
    Serial.print("Sending leaving Time: ");
    int leavingtime = ((day * 86400) + (hrs * 3600) + (mins * 60) + sec) * -1;

    String url = "/~rolf.jurgens/PMblok4IAD/vt.php?location_id=" + getBodypart(response, "loc: ");
    url += "&timepast=";
    url += leavingtime;

    Serial.println(url);
    int result = sendRequest(HOST, url, SentResponse);
    if (result == 1) {
      Serial.println("Succes!");
    } else {
      Serial.print("Sending failed: ");
      Serial.println(result);
    }
    button = false;
  }
  delay(200);
}

void leavingISR() {
  button = true;
}




#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>

#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"
#define HOST "km4.mobidapt.com"


void setup() {
  Serial.begin(9600);

  setupESP8266();


}

void loop() {
  String response;
  int result;

  result = sendRequest(HOST, "/rolf/reset", response);
  if (result == 1) {
    int hours = getHours(response).toInt() + HOUR_OFFSET;
    int minutes = getMinutes(response).toInt();
    int currentTime = hours * 100 + minutes;

    Serial.print("Hours: ");
    Serial.print(hours);
    Serial.print(" Minutes: ");
    Serial.print(minutes);
    Serial.print(" Current Time: ");
    Serial.println(currentTime);

    matrix.print(currentTime, DEC);
    matrix.writeDisplay();
  } else {

    Serial.println("Could not connect");
    Serial.print("Result: ");
    Serial.println(result);

    matrix.print(0xDEAD, HEX);
    matrix.writeDisplay();
  }
}



}

String getHours(const String& response) {

  int bodyEnd = response.indexOf("GMT") - 7;
  int bodyStart = bodyEnd - 2;
  String body = response.substring(bodyStart, bodyEnd);
  body.trim();
  return body;

}

String getMinutes(const String& response) {
  Serial.println(response);

  int bodyEnd = response.indexOf("GMT") - 4;
  int bodyStart = bodyEnd - 2;
  String body = response.substring(bodyStart, bodyEnd);
  body.trim();
  return body;

}




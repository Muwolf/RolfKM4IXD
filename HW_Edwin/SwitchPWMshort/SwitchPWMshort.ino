#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>

#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"
#define HOST "km4.mobidapt.com"



void setup() {
  Serial.begin(9600);

  setupESP8266();

  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);

  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(3, 0);
}

void loop() {
  String response;
  int result;

  result = sendRequest(HOST, "/sliders?userid=rolf&sliderid=slider1", response);
  if (result == 1) {
    int slider1 = getBody(response).toInt();
    Serial.print("Slider1 = ");
    Serial.println(slider1);
    analogWrite(6, slider1 / 8);
  }

  result = sendRequest(HOST, "/sliders?userid=rolf&sliderid=slider2", response);
  if (result == 1) {
    int slider2 = getBody(response).toInt();
    Serial.print("Slider2 = ");
    Serial.println(slider2);
    analogWrite(7, slider2 / 8);
  }

  result = sendRequest(HOST, "/sliders?userid=rolf&sliderid=slider3", response);
  if (result == 1) {
    int slider3 = getBody(response).toInt();
    Serial.print("Slider3 = ");
    Serial.println(slider3);
    analogWrite(3, slider3 / 8);
  }
}

String getBody(const String& response) {
  Serial.println(response);
  int bodyStart = response.indexOf("/r/n/r/n");
  Serial.print("Bodystart = ");
  Serial.println(bodyStart);
  int bodyEnd = response.indexOf("/n", bodyStart + 4);
  Serial.print("BodyEnd = ");
  Serial.println(bodyEnd);
  String body = response.substring(bodyStart + 4, bodyEnd);
  body.trim();
  Serial.print ("body = ");
  Serial.println (body);
  return body;
}


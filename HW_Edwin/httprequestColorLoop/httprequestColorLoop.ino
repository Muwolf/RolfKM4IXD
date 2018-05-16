#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>
#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"

bool colour = true;

void setup() {
  setupESP8266();
}

void loop() {

  ESP8266Client client;
  int result = client.connect("km4.mobidapt.com", 80);
  if (result <= 0) {
    Serial.println("Failed to connect to server");
    delay(1000);
  } else {

    Serial.println("Sent HTTP request");

    if (colour) {
      client.println("GET /lights?userid=rolf&lightid=light1&colour=green HTTP/1.1\n"
                     "Host: km4.mobidapt.com\n"
                     "Connection: close\n");
      Serial.println("Green!");
    }

    if (!colour) {
      client.println("GET /lights?userid=rolf&lightid=light1&colour=red HTTP/1.1\n"
                     "Host: km4.mobidapt.com\n"
                     "Connection: close\n");
      Serial.println("Red!");
    }

    Serial.println("Responce from server: ");
    while (client.available()) {
      Serial.write(client.read());
    }
    Serial.print("Colour is: ");
    Serial.println(colour);
    colour = ! colour;
    if (client.connected()) {
      client.stop();
    }
  }
  delay(500);
}

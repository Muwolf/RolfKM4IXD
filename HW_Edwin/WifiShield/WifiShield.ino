
#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>
#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"



void setup() {
  setupESP8266();

  /*
    Serial.begin(9600);
    int succes = esp8266.begin(9600);
    if (succes) {
      Serial.println("ESP8622 Shield found");
    } else {
      Serial.println("geen contact met ESP8266");
      while (1);
    }

    Serial.print("Trying to connect to: ");
    Serial.print(NETWORK_NAME);
    Serial.print(" with password: ");
    Serial.println(NETWORK_PASSWORD);
    int result = esp8266.connect(NETWORK_NAME, NETWORK_PASSWORD);
    if (result < 0) {
      Serial.print("ERROR connecting: ");
      Serial.print(result);
      while (1);
    }

    IPAddress myIP = esp8266.localIP();
    Serial.print("My IP: ");
    Serial.println(myIP);

    int wifiConnected = esp8266.status();*/
}

void loop() {

  ESP8266Client client;
  client.connect("km4.mobiapt.nl", 80);


  client.print("km4.mobidapt.com");

  while (client.available())
    Serial.print(client.read());
}

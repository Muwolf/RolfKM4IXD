
#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>
#define NETWORK_NAME "ziggo7D511"
#define NETWORK_PASSWORD "h4stUr07"

void setup() {

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
    // while(1);
  }

  if (result > 0) {
    IPAddress myIP = esp8266.localIP();
    Serial.print("My IP: ");
    Serial.println(myIP);

    int wifiConnected = esp8266.status();
  }



}

void loop() {


  /*  ESP8622Client client;
    client.connect("km4.mobiapt.nl", 80);

    //Versturen;
    client.print("verstuur");
    //Ontvangen;
    while (client.available())
      Serial.print(client.read());

  */

}

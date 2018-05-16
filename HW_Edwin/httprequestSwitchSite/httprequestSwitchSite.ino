#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>
#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"

bool colour = true;

void setup() {
  setupESP8266();
  pinMode(13, OUTPUT);
}

void loop() {

  ESP8266Client client;
  int result = client.connect("km4.mobidapt.com", 80);
  if (result <= 0) {
    Serial.println("Failed to connect to server");
    delay(1000);
  } else {
    String switchRequest = "/switches?userid=rolf&switchid=switch3";

    Serial.println("Sent HTTP request");
    client.println("GET " + switchRequest + " HTTP/1.1\n"
                   "Host: km4.mobidapt.com\n"
                   "Connection: close\n");


    Serial.println("Responce from server: ");
    String response; 
    while (client.available()) {
      response += (char)client.read(); 
    }
    //Serial.println(response); 

    if (response.indexOf("off")>0) {
      Serial.println("off"); 
      digitalWrite(13, LOW); 
    } else {
      Serial.println("on"); 
      digitalWrite(13, HIGH); 
    }
    
    if (client.connected()) {
      client.stop();
    }
  }
  delay(50);
}

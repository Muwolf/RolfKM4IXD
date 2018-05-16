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
    int potValue = analogRead(A0); 
    String sliderRequest = "/sliders?userid=rolf&sliderid=slider1&value="+ String(potValue);
    Serial.print("Pot value: ");
    Serial.println(potValue); 

    Serial.println("Sent HTTP request");
    client.println("GET " + sliderRequest + " HTTP/1.1\n"
                   "Host: km4.mobidapt.com\n"
                   "Connection: close\n");


    Serial.println("Responce from server: ");
    String response; 
    while (client.available()) {
      response += (char)client.read(); 
    }
    Serial.println(response);
    
    if (client.connected()) {
      client.stop();
    }
  }
  delay(200);
}

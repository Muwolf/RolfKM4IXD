
#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>
#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"



void setup() {
  setupESP8266();

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

    int wifiConnected = esp8266.status();
}

void loop() {

 
  ESP8266Client client;
  int result = client.connect("km4.mobidapt.com", 80);
  if (result <= 0) {
    Serial.println("Failed to connect to server");
    delay(1000);
  } else {
    int potValue = analogRead(A0); 
    String sliderRequest = "/sliders?userid=rolf&sliderid=slider1";
    
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

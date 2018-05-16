#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>
#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"
#include <Servo.h>

Servo servo;

bool colour = true;

void setup() {
  setupESP8266();
  servo.attach(7); 
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
    

    int val = response.toInt(); 
    Serial.print("String: ");
    Serial.print(response);
    Serial.print(" Int: "); 
    Serial.println(val);
    val = map(val, 0, 1023, 0, 180); 
    servo.write(val); 
    
    if (client.connected()) {
      client.stop();
    }
  }
  delay(200);
}

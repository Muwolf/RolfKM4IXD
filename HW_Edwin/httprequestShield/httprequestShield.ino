#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>
#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"

#define GREENBUTTON 2
#define BLUEBUTTON 3
#define PURPLEBUTTON 4
#define SWITCHLEFT 5
#define SWITCHRIGHT 6
#define POTMETER 0
#define LED1 10
#define LED2 11
#define LED3 12
#define TESTLED 13

unsigned long previousMillis = 0;
const long interval = 1000;

bool light1 = false; 
bool ligth2 = false; 
bool light3 = false; 

void setup() {
  setupESP8266();

  pinMode(GREENBUTTON, INPUT);
  pinMode(BLUEBUTTON, INPUT);
  pinMode(PURPLEBUTTON, INPUT);
  pinMode(SWITCHLEFT, INPUT);
  pinMode(SWITCHRIGHT, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(TESTLED, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    for (int i = 1; i <= 3; i++) {
      ESP8266Client client;
      int result = client.connect("km4.mobidapt.com", 80);
      if (result <= 0) {
        Serial.println("Failed to connect to server");
        delay(1000);
      } else {

        String switchRequest = "/switches?userid=rolf&switchid=switch" + String(i);

        Serial.println("Sent HTTP request");
        client.println("GET " + switchRequest + " HTTP/1.1\n"
                       "Host: km4.mobidapt.com\n"
                       "Connection: close\n");


        Serial.println("Responce from server: ");
        String response = "";
        while (client.available()) {
          response += (char)client.read();
        }

        Serial.print("Website switch number: " + String(i) + " is: ");
        if (response.indexOf("off") > 0) {
          Serial.println("OFF");
          digitalWrite(9 + i, LOW);
        } else {
          Serial.println("ON");
          digitalWrite(9 + i, HIGH);
        }

      }
      if (client.connected()) {
        client.stop();
      }
    }
  }
}



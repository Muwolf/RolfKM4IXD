#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>

#define NETWORK_NAME "AndroidAP"
#define NETWORK_PASSWORD "fwxp3871"
#define HOST "km4.mobidapt.com"

#define PIXELPIN 6
#define NUMPIXELS 12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIXELPIN, NEO_GRB + NEO_KHZ800);

int delayval = 50;
int red = 0;
int green = 0;
int blue = 0;


void setColor() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
  }
  pixels.show();
}


void setup() {
  Serial.begin(9600);

  setupESP8266();

  pixels.begin();

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    delay(10);
  }

}

void loop() {
  String response;
  int result;

  result = sendRequest(HOST, "/sliders?userid=rolf&sliderid=slider1", response);
  if (result == 1) {
    int slider1 = getBody(response).toInt();
    Serial.print("Slider1 = ");
    Serial.println(slider1);
    red = map(slider1, 0, 1023, 0, 255);
    setColor();
  }

  result = sendRequest(HOST, "/sliders?userid=rolf&sliderid=slider2", response);
  if (result == 1) {
    int slider2 = getBody(response).toInt();
    Serial.print("Slider2 = ");
    Serial.println(slider2);
    green = map(slider2, 0, 1023, 0, 255);
    setColor();
  }

  result = sendRequest(HOST, "/sliders?userid=rolf&sliderid=slider3", response);
  if (result == 1) {
    int slider3 = getBody(response).toInt();
    Serial.print("Slider3 = ");
    Serial.println(slider3);
    blue = map(slider3, 0, 1023, 0, 255);
    setColor();
  }
  
}

String getBody(const String& response) {
  Serial.println(response); 
  int bodyStart = response.indexOf("\r\n\r\n");
  int bodyEnd = response.indexOf("\n", bodyStart + 4);
  String body = response.substring(bodyStart + 4, bodyEnd);
  body.trim();
  return body;
}



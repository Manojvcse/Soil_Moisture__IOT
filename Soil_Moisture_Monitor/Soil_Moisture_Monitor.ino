#define BLYNK_TEMPLATE_ID "TMPL3pr4V2p1q"
#define BLYNK_TEMPLATE_NAME "Soil Moisture Monitor"
#define BLYNK_AUTH_TOKEN "Z8l7kctNd6MIy471ZR7ACr1lKU6riV_o"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Z8l7kctNd6MIy471ZR7ACr1lKU6riV_o"; //Enter your Auth token
char ssid[] = "Redmi 8"; //Enter your WIFI name
char pass[] = "lakshana";

BlynkTimer timer;

#define sensor A0

void setup() {
  Serial.begin(9600);
  
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  Serial.println("System Loading...");
  
  // Call the function
  timer.setInterval(100L, soilMoistureSensor);
}

void soilMoistureSensor() {
  int value = analogRead(sensor);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V0, value);
  Serial.print("Moisture: ");
  Serial.print(value);
  Serial.println("%");
}

void loop() {
  Blynk.run();
  timer.run();
}

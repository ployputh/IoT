#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// ------------------------------ EDIT here ------------------
#define WIFI_SSID "IOTLAB"
#define WIFI_PASSWORD "123456789"

// Ex. test-nodemcu-a331f.firebaseio.com
#define FIREBASE_HOST "test-nodemcu-a331f.firebaseio.com"

// Ex. 1UNMoos4vC0elO2IOGOoe4K7zbhLzQw107hTUc3M
#define FIREBASE_AUTH "7UNMoos4vC0elO2IOGOoe4K7zbhLzQw107hTUc3M"

int val;

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt("analog", 0);
}

void loop() {
  val = analogRead(A0);
  Serial.println(val);
  Firebase.setInt("analog", val);
  delay(1000);
}
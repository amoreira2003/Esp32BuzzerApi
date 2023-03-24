#include <WiFi.h>
#include <HTTPClient.h>
const char* id = "Apto 29";
const char* password =  "am02090303";

void setup() {
  pinMode(23, OUTPUT);
  Serial.begin(9600);
  Serial.println("Working");
  WiFi.begin(id,password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wifi...");
  }

      Serial.println("Connected to Wifi...");
}

void loop() {
  if(WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      delay(10);
      Serial.println(WiFi.localIP());
      String path = "http://192.168.15.4:3000/";
      Serial.println(path);
      http.begin(path.c_str());
      Serial.println("Connected to Backend");
      int code = http.GET();
      if(code > 0) {
        if(code == 200) {
          digitalWrite(23,HIGH);
          delay(500);
          digitalWrite(23,LOW);
        }
      }

  }

}

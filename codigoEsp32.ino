
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "correspondente a máquina que está sendo usada";
const char* password = "correspondente a máquina que está sendo usada";

const char* server = "api.tago.io";
const char* token = "correspondente ao codigo gerado pela Tago io";

#define RXD2  
#define TXD2  

void setup() {
  Serial.begin(9600);      
  Serial2.begin(9600, SERIAL_8N1, RX, TX); 

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("WiFi conectado!");
}

void loop() {
  if (Serial2.available()) {
    String data = Serial2.readStringUntil('\n');
    processData(data);
  }

  delay(1000); 
}

void processData(String data) {
  float temperature = 0;
  float humidity = 0;

  if (sscanf(data.c_str(), "T:%f,H:%f", &temperature, &humidity) == 2) {
    Serial.print("Temperatura: ");
    Serial.println(temperature);
    Serial.print("Umidade: ");
    Serial.println(humidity);

    sendToTagoIO(temperature, humidity);
  } else {
    Serial.println("Dados inválidos recebidos do Arduino.");
  }
}

void sendToTagoIO(float temperature, float humidity) {
  StaticJsonDocument<200> jsonDocument;

  jsonDocument["variable"] = "DHT22";
  jsonDocument["values"] = "Temperatura e Umidade";

  JsonObject location = jsonDocument.createNestedObject("data");
  location["temperature"] = temperature;
  location["humidity"] = humidity;

  String jsonString;
  serializeJson(jsonDocument, jsonString);

  HTTPClient http;
  http.begin("https://" + String(server) + "/data");
  http.addHeader("Content-Type", "application/json");
  http.addHeader("token", token);

  int httpResponseCode = http.POST(jsonString);

  if (httpResponseCode == 202) {
    Serial.println("Dados enviados com sucesso para a TagoIO!");
  } else {
    Serial.print("Erro ao enviar dados: ");
    Serial.println(httpResponseCode);
    Serial.println(http.getString());
  }

  http.end();
}

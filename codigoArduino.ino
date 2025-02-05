#include <DHT.h>

#define DHTPIN 2       
#define DHTTYPE DHT22  

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature(); 
  float humidity = dht.readHumidity();       

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Erro ao ler o sensor DHT!");
  } else {
    Serial.print("T:");
    Serial.print(temperature);
    Serial.print(",H:");
    Serial.println(humidity);
  }

  delay(2000); 
}

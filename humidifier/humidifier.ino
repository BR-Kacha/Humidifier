#include "DHT.h"
#define DHTPIN 2
int DEVICE_PIN = 7;
int LED = 13;
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(9600);
  dht.begin();
  delay(1500);
  pinMode(DEVICE_PIN, OUTPUT);
}

void loop()
{
 // ArduinoCloud.update();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if(humidity<80 && humidity>40)
  {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" Temperature: ");
    Serial.println(temperature);
    digitalWrite(DEVICE_PIN,1);
    digitalWrite(LED,1);
    delay(60000);
    digitalWrite(DEVICE_PIN,0);
    digitalWrite(LED,0);
    delay(60000);
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" Temperature: ");
    Serial.println(temperature);
    Serial.println("Fogger ON (pulse mode)");
  }
  if(humidity<40)
  {
    digitalWrite(DEVICE_PIN,1);
    digitalWrite(LED,1);
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" Temperature: ");
    Serial.println(temperature);
    Serial.println("Fogger ON continiusly");
    delay(1000);
  }
  if(humidity>80)
  {
    digitalWrite(DEVICE_PIN,0);
    digitalWrite(LED,0);
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" Temperature: ");
    Serial.println(temperature);
    Serial.println("Fogger off continiusly");
    delay(1000);

  }
}


#include <dht11.h>
#define sensor 7

dht11 mydht;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk = mydht.lastRead(sensor);
  Serial.print("Temperature = ");
  Serial.println(mydht.getTemperature());
  Serial.print("Humidity = ");
  Serial.println(mydht.getHumidity());
  delay(1000);
}

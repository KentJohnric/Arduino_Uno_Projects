#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <dht11.h>
#define sensor 4
LiquidCrystal_I2C lcd(0x27, 16, 2);
dht11 DHT;
void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  DHT.read(sensor);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
}

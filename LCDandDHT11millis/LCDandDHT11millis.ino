#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <dht11.h>
#define sensor 4
LiquidCrystal_I2C lcd(0x27, 16, 2);
dht11 DHT;
const unsigned long timeInterval = 100;
unsigned long previousTime = 0;
void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  unsigned long currentTime = millis();

  if(currentTime - previousTime >= timeInterval){
    DHT.read(sensor);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
    lcd.setCursor(0,1);
    unsigned long timer = currentTime - previousTime;
    lcd.print(timer);
    previousTime = currentTime;
  }
}

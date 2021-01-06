#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <dht11.h>
#define sensor 4
LiquidCrystal_I2C lcd(0x27, 16, 2);
dht11 DHT;
const unsigned long timeInterval = 500;
unsigned long previousTime = 0;
int hrs = 0;
int Min = 5;
int sec = 0;
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
    INIT();
    //lcd.setCursor(0,1);
    //unsigned long timer = currentTime - previousTime;
    //lcd.print(timer);
    //previousTime = currentTime;
  }
  sec = sec -1;
  delay(1000);
  if(sec == -1){
    sec = 59;
    Min = Min - 1;
  }
  if(Min == -1){
    Min = 59;
    hrs = hrs -1;
  }
  if(hrs == -1){
    hrs = 0;
  }
  lcd.setCursor(0,1);
  if(hrs <= 9){
    lcd.print('0');
  }
  lcd.print("hrs");
  lcd.print(':');
  if (Min <= 9)
  {
    lcd.print('0');
  }
  lcd.print(Min);
  lcd.print(':');
  if (sec <= 9)
  {
    lcd.print('0');
  }
  lcd.print(sec);
}
void INIT()
{
  lcd.setCursor(0,1);
  lcd.print("Timer");
  lcd.setCursor(4,1);
  if(hrs <=9){
    lcd.print('0');
  }
  lcd.print(hrs);
  lcd.print(':');
  if(Min <=9){
    lcd.print('0');
  }
  lcd.print(Min);
  lcd.print(':');
  if(sec <= 9){
    lcd.print('0');
  }
  lcd.print(sec);
}

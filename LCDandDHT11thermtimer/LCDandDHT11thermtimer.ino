#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <dht11.h>
#define sensor 4
#define thermistor 0
LiquidCrystal_I2C lcd(0x27, 16, 2);
dht11 DHT;
const unsigned long timeInterval = 500;
unsigned long previousTime = 0;
int hrs = 0;
int Min = 5;
int sec = 0;
int Vo;
float R1 = 1000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime - previousTime >= timeInterval){
    Vo = analogRead(thermistor);
    R2 = R1 * (1023.0 / (float)Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    Tc = T - 273.15;
    Tf = (Tc * 9.0)/ 5.0 + 32.0;
    DHT.read(sensor);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tp1:");
    lcd.print(DHT.temperature);
    lcd.print("Tp2:");
    lcd.print(Tf);
    Serial.print("\nTemperature DHT11:");
    Serial.println(DHT.temperature);
    Serial.print("\nTemperature Thermistor:");
    Serial.print(Tf);
    Serial.print("\nTemperature Thermistor C:");
    Serial.print(Tc);
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
  lcd.print("Timer:");
  lcd.setCursor(6,1);
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

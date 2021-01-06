#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define relay 3
#define thermistor 5

double Thermistor(int RawADC){
  double Temp;
  Temp = log(((10240000/RawADC) - 1000));
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15; // Convert Kelvin to Celcius
  return Temp;
}

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  int val;
  double temp;
  val=analogRead(thermistor);
  temp = Thermistor(val);
  Serial.print("Temperature: ");
  Serial.println(temp);
  delay(500);
  if(temp < 60){
    digitalWrite(relay,LOW);
  }
  else{
    digitalWrite(relay,HIGH);
  }
}

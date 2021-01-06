#include <LiquidCrystal_I2C.h>
#include <Wire.h>
//initialize the liquid crystal library
//the first parameter is the I2C address
//the second parameter is how many rows are on your screen
//the third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();
}
void loop() {
 delay(1000);
 lcd.clear();
 //tell the screen to write "hello, world" on the top row 
 lcd.setCursor(0,0);
 lcd.print("Hello, World!");
 lcd.setCursor(0,1);
 lcd.print("Tempt.");
}

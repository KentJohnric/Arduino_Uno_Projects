//Automatic NightLight
const int RLED = 9; //Red LED on pin 9 (PWM)
const int LIGHT = 0;  //Light Sensor on analog pin 0
const int MIN_LIGHT = 200;  //Minimum expected light value
const int MAX_LIGHT = 900;  //Maximum expected light value
int val = 0;  //variable to hold the analog reading

void setup() {
  pinMode(RLED, OUTPUT);  //Set LED pin as output
}

void loop() {
  val = analogRead(LIGHT);   //Read the Light sensor
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0); //Map the light reading
  val = constrain(val, 0, 255); //constrain light value
  analogWrite(RLED, val); //Control the LED
}

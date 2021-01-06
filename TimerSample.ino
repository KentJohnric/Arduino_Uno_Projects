const unsigned long timeInterval = 1000;
unsigned long previousTime = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long currentTime2 = millis();

  if(currentTime - previousTime >= timeInterval){
    Serial.println("Stage 1 Initiated");
    previousTime = currentTime;
    unsigned long timer2 = currentTime + timeInterval;
    unsigned long timer = timer2 - previousTime;
    Serial.println(timer);
  }
}

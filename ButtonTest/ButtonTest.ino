#define logicbE 12
#define logicbF 13
int bstateE = 0;
int bstateF = 0;
void setup() {
  pinMode(logicbE, INPUT);
  pinMode(logicbF, INPUT);
  Serial.begin(9600);
}

void loop() {
  button();
}
void button(){
  bstateE = digitalRead(logicbE);
  bstateF = digitalRead(logicbF);
  if(bstateE == LOW && bstateF == HIGH){
    Serial.print("Down Button pressed");
    Serial.println();
  }
  else if(bstateE == HIGH && bstateF == LOW){
    Serial.print("Select Button pressed");
    Serial.println();
  }
  else if(bstateE == HIGH && bstateF == HIGH){
    Serial.print("Up Button pressed");
    Serial.println();
  }
  else if(bstateE == LOW && bstateF == LOW){
    Serial.println();
  }
}

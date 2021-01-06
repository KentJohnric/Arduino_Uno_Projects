const int LED = 9;            //The LED is connected to pin 9
const int BUTTON = 2;         //The Button is connected to pin 2
boolean lastButton = LOW;     //Variable containing the previous button state
boolean currentButton = LOW;  //Variable containing the current button state
boolean ledOn = false;        //The present state of the LED (ON/OFF)
void setup() {
  pinMode(LED, OUTPUT);       //Set the LED pin as an output
  pinMode(LED, INPUT);        //Set the button as input

}
/*
 * Debouncing Function
 * Pass it the previous button state,
 * and get back the current debounced button state.
 */
boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);  //Read the button state
  if(last != current)                     //If it's different...
  {
    delay(5);                             //wait for 5ms
    current = digitalRead(BUTTON);        //read it again
  }
  return current;                         //return the current value
}
void loop() {
  currentButton = debounce(lastButton);   //read debounced state
  if(lastButton == LOW && currentButton == HIGH)  //if it was pressed....
  {
    ledOn = !ledOn;                       //toggle the LED value
  }
  lastButton = currentButton;             //reset button value

  digitalWrite(LED, ledOn);               //change the LED state

}

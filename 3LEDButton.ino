#include <Arduino.h>

int switchState = 0; //define empty variable for the power state of the button

void setup()
{
  // Initialize pins
  pinMode(3, OUTPUT); //green LED
  pinMode(4, OUTPUT); //red LED
  pinMode(5, OUTPUT); //red LED
  pinMode(2, INPUT); //button

}

void loop()
{

  switchState = digitalRead(2); //Read the power from the button pin
  
  if (switchState == LOW) //if the button is not pressed, only fire the green LED
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else 
  { 
    digitalWrite(3, LOW); //turn off green LED if the button is pressed
    
    digitalWrite(4, LOW); //turn off the red LED on pin 4
    digitalWrite(5, HIGH); //rapid-blink the red LED on pin 5
    delay(70);
    digitalWrite(5, LOW);
    delay(70);
    digitalWrite(5, HIGH);
    delay(70);
    digitalWrite(5, LOW);
    delay(70);
    digitalWrite(5, HIGH);
    delay(70);
    digitalWrite(5, LOW);
    
    delay(100); //pause between red LED alternation
    
    digitalWrite(5, LOW); //turn off the red LED on pin 5
    digitalWrite(4, HIGH); //rapid-blink the red LED on pin 4
    delay(70);
    digitalWrite(4, LOW);
    delay(70);
    digitalWrite(4, HIGH);
    delay(70);
    digitalWrite(4, LOW);
    delay(70);
    digitalWrite(4, HIGH);
    delay(70);
    digitalWrite(4, LOW);
    
    delay(100);
  }
}

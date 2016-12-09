class Pulse
{
	// Class Member Variables
	// These are initialized at startup
	int ledPin;      // the number of the LED pin
	long OnTime;     // milliseconds of on-time
	long OffTime;    // milliseconds of off-time
 
	// These maintain the current state
	int ledState;             		// ledState used to set the LED
	unsigned long previousMillis;  	// will store last time LED was updated
 
  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  public:
  Pulse(int pin, long on, long off)
  {
	ledPin = pin;
	pinMode(ledPin, OUTPUT);     
	  
	OnTime = on;
	OffTime = off;
	
	previousMillis = 0;
  }
 
  void Update()
  {
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();
     
    if((int ledState = 0 ; ledState <= 255; ledState += 5) && (currentMillis - previousMillis >= OnTime))
    {
      previousMillis = currentMillis;  // Remember the time
      analogWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((int ledState = 255 ; ledState >= 0; ledState -= 5) && (currentMillis - previousMillis >= OffTime))
    {
      previousMillis = currentMillis;   // Remember the time
      analogWrite(ledPin, ledState);	  // Update the actual LED
    }
  }
};
     
     
    Pulser led1(5, 30, 30);
    Pulser led2(6, 30, 30);
    Pulser led2(7, 30, 30);
     
    void setup()
    {
    }
     
    void loop()
    {
    	led1.Update();
    	led2.Update();
      led3.Update();
    }
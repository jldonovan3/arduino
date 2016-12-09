    class Pulser
    {
    	// Class Member Variables
    	// These are initialized at startup
    	int ledPin;      // the number of the LED pin
    	int brightness;     // amount of brightness
    	int fadeAmount;    // amount of fade effect
     
      // Constructor - creates a Pulser 
      // and initializes the member variables and state
      public:
      Pulser(int pin, int brightValue, int fadeValue)
      {
    	ledPin = pin;
    	pinMode(ledPin, OUTPUT);     
    	  
    	brightness = brightValue;
    	fadeAmount = fadeValue;
    	
      }
     
      void Update()
      {
        analogWrite(ledPin, brightness);

  // change the brightness for next time through the loop:
        brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
        if (brightness <= 0 || brightness >= 255) {
            fadeAmount = -fadeAmount;
            }
      }
    };
     
     
    Pulser led1(5, 0, 5);
    Pulser led2(6, 0, 5);
    Pulser led2(7, 0, 5);
     
    void setup()
    {
    }
     
    void loop()
    {
    	led1.Update();
    	led2.Update();
        led3.Update();
    }
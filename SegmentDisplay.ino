#include <Wire.h>

#define DISPLAY_ADDRESS1 0x72 //default address of the OpenSegment with both solder jumpers open
#define DISPLAY_ADDRESS2 0x73

void setup() 
{
  Wire.begin(); //Join the bus as master

  //By default .begin() will set I2C SCL to Standard Speed mode of 100kHz
  //Wire.setClock(400000)

  Serial.begin(9600); //Start serial communication at 9600 for debug
  Serial.println("OpenSegment Example Code");

  //Send the reset command to the display
  Wire.beginTransmission(DISPLAY_ADDRESS1);
  Wire.write('v');
  Wire.endTransmission();

  Wire.beginTransmission(DISPLAY_ADDRESS2);
  Wire.write('v');
  Wire.endTransmission();
}

void loop() 
{
  Wire.beginTransmission(DISPLAY_ADDRESS1);
  Wire.write(0x7A); // Brightness control command
  Wire.write(255); // Set brightness level: 0% to 100%
  Wire.endTransmission();
  i2cSendString1("3400"); //Send the four characters to the display
  delay(2000); 

  Wire.beginTransmission(DISPLAY_ADDRESS2);
  Wire.write(0x7A); // Brightness control command
  Wire.write(255); // Set brightness level: 0% to 100%
  Wire.endTransmission();
  i2cSendString2("0400"); //Send the four characters to the display
  delay(2000); 
}

//Given a string, i2cSendString chops up the string and sends out the first four characters over i2c
void i2cSendString1(char *toSend)
{
  Wire.beginTransmission(DISPLAY_ADDRESS1); // transmit to device #1
  for(byte x = 0 ; x < 4 ; x++)
    Wire.write(toSend[x]); //Send a character from the array out over I2C
  Wire.endTransmission(); //Stop I2C transmission
}

void i2cSendString2(char *toSend)
{
  Wire.beginTransmission(DISPLAY_ADDRESS2); // transmit to device #2
  for(byte x = 0 ; x < 4 ; x++)
    Wire.write(toSend[x]); //Send a character from the array out over I2C
  Wire.endTransmission(); //Stop I2C transmission
}

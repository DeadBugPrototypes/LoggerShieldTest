#include <Wire.h>
#include <SD.h>
#include <OneWire.h>

#define DS1307_ADDRESS      0x68
#define ONE_WIRE_BUS        10
#define SD_CHIPSELECT       8

String strLogline = "";

void setup()
{
//	pinMode(OE1,OUTPUT);
//	pinMode(OE2,OUTPUT);

	Serial.begin(9600);
	delay(1000);
	GetDate();
	getTemp();
        getLight();
        getVolt();
	WriteSD();
}

void loop()
{
	while (true)
	{
           /* if (underVoltage()) 
            {
              AlarmOff();
            } else {
              SetAlarm();
            } */
            
            SetAlarm();
            
	delay(500);
	}

}






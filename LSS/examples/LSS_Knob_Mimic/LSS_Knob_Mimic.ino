/*
 *	Author:			Sebastien Parent-Charette (support@robotshop.com)
 *	Version:		1.0.0
 *	Licence:		LGPL-3.0 (GNU Lesser General Public License version 3)
 *	
 *	Desscription:	Moves one LSS using the position of a second LSS.
*/

#include <LSS.h>

#define LSS_BAUD	(LSS_DefaultBaud)

// Create two LSS object; one for output (ID=0), one for input (ID=1)
LSS myLSS_Output = LSS(0);
LSS myLSS_Input = LSS(1);

void setup()
{
	// Initialize the LSS bus
	LSS::initBus(Serial, LSS_BAUD);
	
	// Initialize LSS output to position 0.0
	myLSS_Output.move(0);
	
	// Wait for it to get there
	delay(2000);
	
	// Lower output servo stiffness
	myLSS_Output.setAngularStiffness(4);
	myLSS_Output.setMaxSpeedRPM(15);
	
	// Make input servo limp (no active resistance)
	myLSS_Input.limp();
}

// Reproduces position of myLSS_Input on myLSS_Output
unsigned long startTime = millis();

void loop()
{
	// Wait ~20 ms before sending another command (update at most 50 times per second)
	if((millis() - startTime) > 20)
	{
		int16_t pos = (int16_t)myLSS_Input.getPosition();
		Serial.print("Input @ "); Serial.println(pos);
		
		// Send LSS to half a turn counter-clockwise from zero (assumes gyre = 1)
		myLSS_Output.move(pos);
		Serial.println("\r\n");
	}
}
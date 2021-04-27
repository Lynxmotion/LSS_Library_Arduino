/*
 *	Author:			Sebastien Parent-Charette (support@robotshop.com)
 *	Version:		1.1.0
 *	Licence:		LGPL-3.0 (GNU Lesser General Public License version 3)
 *	
 *	Description:	Basic example of the LSS moving back and forth.
 */

#include <LSS.h>

// ID set to default LSS ID = 0
#define LSS_ID		(0)
#define LSS_BAUD	(LSS_DefaultBaud)
// Choose the proper serial port for your platform
#define LSS_SERIAL	(Serial)	// ex: Many Arduino boards
//#define LSS_SERIAL	(Serial1)	// ex: Teensy


// Create one LSS object
LSS myLSS = LSS(LSS_ID);

void setup()
{
	// Initialize the LSS bus
	LSS::initBus(LSS_SERIAL, LSS_BAUD);

	// Initialize LSS to position 0.0 °
	myLSS.move(0);

	// Wait for it to get there
	delay(2000);
}

// Loops between -180.0° and 180°, taking 1 second pause between each half-circle move.
void loop()
{
	// Send LSS to half a turn counter-clockwise from zero (assumes gyre = 1)
	myLSS.move(-1800);

	// Wait for one second
	delay(2000);

	// Send LSS to half a turn clockwise from zero (assumes gyre = 1)
	myLSS.move(1800);

	// Wait for one second
	delay(2000);
}

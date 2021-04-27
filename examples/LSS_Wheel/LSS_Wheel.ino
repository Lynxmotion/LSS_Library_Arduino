/*
 *	Author:			Brahim Daouas (support@robotshop.com)
 *	Version:		1.1.0
 *	Licence:		LGPL-3.0 (GNU Lesser General Public License version 3)
 *	
 *	Description:	Basic example of the LSS rotating continuously.
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

	// Wait for the LSS to boot
	delay(2000);

	// Move the LSS continuously in one direction
	myLSS.wheelRPM(100);
}

void loop()
{
	// Nothing to do in loop
}

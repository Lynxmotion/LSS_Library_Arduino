/*
 *	Author:			Brahim Daouas (support@robotshop.com)
 *	Version:		1.0.0
 *	Licence:		LGPL-3.0 (GNU Lesser General Public License version 3)
 *	
 *	Desscription:	Basic example of the LSS rotating continuously.
*/

#include <LSS.h>

// ID set to default LSS ID = 0
#define LSS_ID		(0)
#define LSS_BAUD	(LSS_DefaultBaud)

// Create one LSS object
LSS myLSS = LSS(LSS_ID);

void setup()
{
	// Initialize the LSS bus
	LSS::initBus(Serial, LSS_BAUD);

	// Wait for the LSS to boot
	delay(2000);
	
	// Move the LSS continuously in one direction
	myLSS.wheelRPM(100);
}

void loop()
{
	// Nothing to do in loop
}

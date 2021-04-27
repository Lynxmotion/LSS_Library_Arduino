/*
 *	Author:			Sebastien Parent-Charette (support@robotshop.com)
 *	Version:		1.1.0
 *	Licence:		LGPL-3.0 (GNU Lesser General Public License version 3)
 *	
 *	Description:	Example of all the possible configurations for a LSS.
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

	// Uncomment any configurations that you wish to activate
	// You can see above each configuration a link to its description in the Lynxmotion wiki
	// Note: If you change a configuration to the same value that is already set,
	//       the LSS will ignore the operation since the value is not changed.

	// *** Basic configurations ***
	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#H6.OriginOffsetAction28O29
	//myLSS.setOriginOffset(0);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#H7.AngularRange28AR29
	//myLSS.setAngularRange(uint16_t value, LSS_SetType setType = LSS_SetConfig);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#H12.MaxSpeedinDegrees28SD29
	// Set maximum speed in (1/10°)/s
	//myLSS.setMaxSpeed(600, LSS_SetConfig);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#H13.MaxSpeedinRPM28SR29
	//myLSS.setMaxSpeedRPM(100, LSS_SetConfig);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#H14.LEDColor28LED29
	// Options are:
	// LSS_LED_Black = 0
	// LSS_LED_Red = 1
	// LSS_LED_Green = 2
	// LSS_LED_Blue = 3
	// LSS_LED_Yellow = 4
	// LSS_LED_Cyan = 5
	// LSS_LED_Magenta = 6
	// LSS_LED_White = 7
	//myLSS.setColorLED(LSS_LED_Black, LSS_SetConfig);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#H15.GyreRotationDirection28G29
	// Options are:
	// LSS_GyreClockwise = 1
	// LSS_GyreCounterClockwise = -1
	//myLSS.setGyre(LSS_ConfigGyre value, LSS_SetConfig);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#H19.FirstA0Position28Degrees29
	//myLSS.setFirstPosition(0);
	//myLSS.clearFirstPosition();

	// *** Advaned configurations ***
	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#HA1.AngularStiffness28AS29
	//myLSS.setAngularStiffness(0, LSS_SetConfig);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#HA2.AngularHoldingStiffness28AH29
	//myLSS.setAngularHoldingStiffness(4, LSS_SetConfig);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#HA3:AngularAcceleration28AA29
	//myLSS.setAngularAcceleration(100, LSS_SetConfig);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#HA4:AngularDeceleration28AD29
	//myLSS.setAngularDeceleration(100, LSS_SetConfig);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#HA5:MotionControl28EM29
	//myLSS.setMotionControlEnabled(bool value);

	//> https://www.robotshop.com/info/wiki/lynxmotion/view/lynxmotion-smart-servo/lss-communication-protocol/#HA6.ConfigureLEDBlinking28CLB29
	// Options are an arithmetic addition of the following values:
	// Limp	1
	// Holding	2
	// Accelerating	4
	// Decelerating	8
	// Free	16
	// Travelling	32
	// Therefore, 0 = no blinking and 63 = always blinking
	//myLSS.setBlinkingLED(0);

	// Reset motor to complete change of configurations
	myLSS.reset();

	// Wait for reboot
	delay(2000);
}

void loop()
{
	// Loop through each of the 8 LED color (black = 0, red = 1, ..., white = 7)
	for (uint8_t i = LSS_LED_Black; i <= LSS_LED_White; i++)
	{
		// Set the color (session) of the LSS
		myLSS.setColorLED((LSS_LED_Color) i);
		delay(1000);
	}
}

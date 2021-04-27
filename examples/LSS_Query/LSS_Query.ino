/*
 *	Author:			Sebastien Parent-Charette (support@robotshop.com)
 *	Version:		1.1.0
 *	Licence:		LGPL-3.0 (GNU Lesser General Public License version 3)
 *	
 *	Description:	Basic example of reading values from the LSS and placing
 *					them on the terminal.
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
}

void loop()
{
	// Header 1
	Serial.println("\r\nQuerying servo...");

	// Get LSS position, speed, current, voltage, temperature
	int32_t pos = myLSS.getPosition();
	uint8_t rpm = myLSS.getSpeedRPM();
	uint16_t current = myLSS.getCurrent();
	uint16_t voltage = myLSS.getVoltage();
	uint16_t temp = myLSS.getTemperature();

	// Header 2
	Serial.println("\r\n\r\n---- LSS telemetry ----");

	// Display LSS position, speed, current, voltage, temperature
	Serial.print("Position  (1/10 deg) = ");
	Serial.println(pos);
	Serial.print("Speed          (rpm) = ");
	Serial.println(rpm);
	Serial.print("Curent          (mA) = ");
	Serial.println(current);
	Serial.print("Voltage         (mV) = ");
	Serial.println(voltage);
	Serial.print("Temperature (1/10 C) = ");
	Serial.println(temp);

	// Read LSS telemetry once per second
	delay(1000);
}

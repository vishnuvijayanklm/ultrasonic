
#include "Ultrasonic.h"

Ultrasonic::Device ultrasonicDevice(3,4);
void setup() 
{
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
	Serial.print(ultrasonicDevice.mcfn_read());
	Serial.println(" cm");
	delay(1000);
}

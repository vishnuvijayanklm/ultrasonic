#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "Ultrasonic.h"

namespace Ultrasonic
{
	Device::Device(u8 triggerPin, u8 echoPin, u32 timeOut) 
	{
		this->meu8_triggerPin = triggerPin;
		this->meu8_echoPin = echoPin;
		pinMode(this->meu8_triggerPin,OUTPUT);
		pinMode(this->meu8_echoPin,INPUT);
		this->meu32_timeOut = timeOut;
		this->meb_threePins = this->meu8_triggerPin == this->meu8_echoPin ? true : false;
	}

	u16 Device::mefn_performAction()
	{
  		if(this->meb_threePins)
		{
    			pinMode(this->meu8_triggerPin, OUTPUT);
		}

  		digitalWrite(this->meu8_triggerPin,LOW);
  		delayMicroseconds(2);
  		digitalWrite(this->meu8_triggerPin,HIGH);
  		delayMicroseconds(10);
  		digitalWrite(this->meu8_triggerPin,LOW);

  		if(this->meb_threePins)
		{
    			pinMode(this->meu8_triggerPin,INPUT);
		}

		this->meu32_previousMicros = micros();
		while(!digitalRead(meu8_echoPin) && (micros() - this->meu32_previousMicros) <= this->meu32_timeOut); 
		this->meu32_previousMicros = micros();
		while(digitalRead(meu8_echoPin)  && (micros() - this->meu32_previousMicros) <= this->meu32_timeOut); 
		return micros() - this->meu32_previousMicros;
	}

	u16 Device::mcfn_read(u8 unit) 
	{
		return mefn_performAction() / unit / 2;
	}
}

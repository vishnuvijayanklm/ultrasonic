#ifndef Ultrasonic_h
#define Ultrasonic_h

#define CM 28
#define INC 71

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;
namespace Ultrasonic
{
	class  Device
	{
		public:
			Device(u8 signalPin) : Device(signalPin,signalPin) {};
			Device(u8 triggerPin, u8 echoPin, u32 timeOut = 20000UL);
			u16 mcfn_read(u8 unit = CM);
			void mcfn_setTimeout(u32 timeOut)
			{
				this->meu32_timeOut = timeOut;
			}
		private:
			boolean meb_threePins;
			u8 meu8_triggerPin;
			u8 meu8_echoPin;
			u8 meu8_readCount;
			u32 meu32_previousMicros;
			u32 meu32_timeOut;
			
			u16 mefn_performAction();
	};
}

#endif // Ultrasonic_h

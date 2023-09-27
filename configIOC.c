#include "constants.h"
void configIOC(void)
{
     PORTAbits.RA4 = HI; // RA4 pin 3 is an input for the switch debounce
     INTCONbits.IOCIE = HI; //enable IOC interrupts on RA4
     IOCAPbits.IOCAP4 = HI; // enable positive edge detections on RA4 pin 3
     IOCANbits.IOCAN4 = HI; // enable negative edge detections on RA4 pin 3
}

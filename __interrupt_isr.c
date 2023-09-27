
#include "constants.h"
//void __interrupt_isr(void)
//__interrupt() void MY_ISR(void)
__interrupt() void philippo(void)
{
    if(INTCONbits.TMR0IF == HI && INTCONbits.TMR0IE == HI )
    {
        //PORTCbits.RC5 = ~PORTCbits.RC5;
        
    }
    TMR0 = 0x82;// 1ms between TMR0 interrupts
    INTCONbits.TMR0IF = LO;
    
    if(IOCAFbits.IOCAF4 == HI) //&& IOCANbits.IOCAN4 == HI)
    {
       // PORTCbits.RC5 = ~PORTCbits.RC5;
        TMR0 = 0x82;        // preload timer0 with d'130 (125 counts until overflow at 255)
        INTCONbits.TMR0IE = HI; // start TMR0 counting
        while(INTCONbits.TMR0IF !=HI);  // wait for TMR0 to overflow (1ms has passed since button was pressed))
        INTCONbits.TMR0IE = LO; // disable TMR0
        newSwitchState = PORTAbits.RA4;
        PORTCbits.RC5 = newSwitchState;
       
    }
    INTCONbits.TMR0IF = LO;// clear TMR0 interrupt
    IOCAFbits.IOCAF4 = LO;// clear IOC interrupt
     TMR0 = 0x82;
}

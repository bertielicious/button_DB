#include "constants.h"
void configTMR0(void)
{
    /*TMR0 is used to generate an interrupt when TMR0 regfister
     overflows from 255 to 0*/
    OPTION_REGbits.TMR0CS = LO;     //Internal instruction cycle clock (FOSC/4)
    OPTION_REGbits.PSA = LO;        // Prescaler is allocated to TMR0
    OPTION_REGbits.PS2 = LO;        // prescaler set to 1:16
    OPTION_REGbits.PS1 = HI;        // time to overflow = 4us * 256 * 256 = 0.262144 seconds
    OPTION_REGbits.PS0 = HI;        // so LED should flash every 0.524288 seconds
    
    /* Setup TMR0 interrpt*/
    INTCONbits.PEIE = HI;
    INTCONbits.GIE = HI;          // Enables all active interrupts
    INTCONbits.TMR0IE = LO;       // HI Enables the Timer0 interrupt
    INTCONbits.TMR0IF = LO;
    TMR0 = 0x82;            // preload TMR0 with d'130 to achieve an overflow after 1ms
    /* system clock = 16MHz
     instruction cycle = 16MHz/4 = 4MHz
     Period = 0.25us so TMR0 increments by 1 every 0.25us
     */
    
}

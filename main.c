/*
 * File:   main.c
 * Author: User
 *
 * Created on 11 September 2023, 20:03
 */


#include <xc.h>
#include "configurationBits.h"
#include "constants.h"
#include "configOsc.h"
#include "configPorts.h"
#include "configTMR0.h"
#include "configIOC.h"
#include "configEUSART.h"
#include "debounce_switch.h"
#include <stdio.h>


void main(void) 
{
    configOsc();
    configPorts();
    configEUSART();
    configTMR0();
    configIOC();

    printf("Hello Phil\n");
    
 while(1)
 {
   //  if(newSwitchState != newSwitchState)
    // {
          printf("%d\n", newSwitchState);
    // }
 }
    return;
}

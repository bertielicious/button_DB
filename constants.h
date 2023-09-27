/* 
 * File:   constants.h
 * Author: User
 *
 * Created on 11 September 2023, 20:16
 */

#ifndef CONSTANTS_H
#define	CONSTANTS_H
#include <xc.h>
#include <stdbool.h>

enum{LO,
    HI};
    
volatile bool button = HI;
volatile bool oldSwitchState = LO;
volatile bool newSwitchState = LO;
#endif	/* CONSTANTS_H */


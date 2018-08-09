/* 
 * File:   TapeSensors.h
 * Author: Henry
 *
 * Created on November 20, 2015, 6:50 PM
 */

#ifndef TAPESENSORS_H
#define	TAPESENSORS_H

#ifdef	__cplusplus
extern "C" {
#endif
/**********************************************************************8**/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "pwm.h"
#include "AD.h"
 /*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
//#define TAPE1PIN AD_PORTV3
//#define TAPE2PIN AD_PORTV4
//#define TAPE3PIN AD_PORTV5
//#define TAPE4PIN AD_PORTV6
//#define TAPE5PIN AD_PORTV7
//#define TAPE6PIN AD_PORTV8
//#define TAPE7PIN AD_PORTW3
//#define TAPE8PIN AD_PORTW4   
//
//#define THRESHOLE_HI 920
//#define THRESHOLE_LO 300
#define THRESHOLE1 380
#define THRESHOLE2 380
#define THRESHOLE3 380
#define THRESHOLE4 380
#define THRESHOLE5 380
#define THRESHOLE6 380
#define THRESHOLE7 380
#define THRESHOLE8 380
    
    
    
    
    
    
    
/********************************************************************************/    
int TapesInit();


/********************************************************************************/
uint8_t ReadTapeValue();


#ifdef	__cplusplus
}
#endif

#endif	/* TAPESENSORS_H */


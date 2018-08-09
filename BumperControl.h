/* 
 * File:   BumperControl.h
 * Author: Henry
 *
 * Created on November 23, 2015, 6:11 PM
 */

#ifndef BUMPERCONTROL_H
#define	BUMPERCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "pwm.h"
#include "AD.h"

    
#define BUMPER_FL_PORT AD_PORTW3
#define BUMPER_FR_PORT AD_PORTW4
#define BUMPER_BL_PORT AD_PORTW5
#define BUMPER_BR_PORT AD_PORTW6
#define BUMPER_FL 1<<3
#define BUMPER_FR 1<<2
#define BUMPER_BL 1<<1
#define BUMPER_BR 1
#define PRESSED 1
#define RELEASED 0

/*******************************************************************************
 *This function initializes the bumpers for use and sets their pins.
 ******************************************************************************/

int BumperInit();

/*******************************************************************************
 *This function reads the front left bumper and returns either PRESSED or 
 * RELEASED
 ******************************************************************************/
uint8_t Bumper_Read_Front_Left();

/*******************************************************************************
 *This function reads the front right bumper and returns either PRESSED or 
 * RELEASED
 ******************************************************************************/
uint8_t Bumper_Read_Front_Right();

/*******************************************************************************
 *This function reads the back left bumper and returns either PRESSED or 
 * RELEASED
 ******************************************************************************/
uint8_t Bumper_Read_Back_Left();

/*******************************************************************************
 *This function reads the back right bumper and returns either PRESSED or 
 * RELEASED
 ******************************************************************************/
uint8_t Bumper_Read_Back_Right();

/*******************************************************************************
 This function reads all bumpers and returns a bitstring of each bump state
 ******************************************************************************/
uint8_t Bumper_ReadBumpers();



#ifdef	__cplusplus
}
#endif

#endif	/* BUMPERCONTROL_H */


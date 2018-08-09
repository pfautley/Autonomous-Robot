/* 
 * File:   MotorControl.h
 * Author: Henry
 *
 * Created on November 19, 2015, 6:44 PM
 */

#ifndef MOTORCONTROL_H
#define	MOTORCONTROL_H

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "pwm.h"
#include "AD.h"

#define FORWARD 1
#define STOP 0
#define REVERSE -1
#define LEFT 1
#define RIGHT 0
#define SLIGHT_DIFF 3
#define LEFT_MOTOR_OFFSET 0
#define RIGHT_MOTOR_OFFSET 0
#define DEG_30 30
#define DEG_45 45
#define DEG_90 90
#define DEG_180 180
#define LEFT_MOTOR_DIR_PIN PIN9
#define LEFT_MOTOR_PWM_PIN PWM_PORTY10
#define RIGHT_MOTOR_DIR_PIN PIN11
#define RIGHT_MOTOR_PWM_PIN PWM_PORTY12
#define PITCHING_MOTOR PWM_PORTZ06

/*******************************************************************************
 * USER DEFINED VARIABLES
 ******************************************************************************/
typedef enum turnTypes{
    TANK,
    PIVOT,
    SLIGHT
}turnType;

int MotorInit();

/*******************************************************************************
 *This function sets the motors to drive straight forward using the defined 
 *offsets.
 ******************************************************************************/

void Motor_ForwardStraight(int fwdSpeed);

/*******************************************************************************
 *This function sets the motors to reverse straight using the defined offsets.
 ******************************************************************************/

void Motor_ReverseStraight(int revSpeed);

/*******************************************************************************
 *This function tells the robot to turn using the parameters for turn type, 
 *direction and time. Turn time will be either tank, pivot or slight. 
 *Turn type: Tank sets the motors to equal speeds, but in opposite directions. 
 *           Pivot sets one motor on and the other off. 
*           Slight turns both motors on in the same direction, but one is 
 *           slightly slower than the other. 
 *Direction: 1 for Forward movement, 0 for reverse. These are #defined.
 
 ******************************************************************************/

int Motor_Turn(turnType turn, int direction, int speed);

/*******************************************************************************
 *This function instructs the robot to evade a bump received from the left side 
 *of the robot. This function assumes that the bump came from the front of the 
 *robot. Further iterations will take rear bumps into account.
 ******************************************************************************/

void Motor_EvadeLeft(int rightSpeed);

/*******************************************************************************
 *This function instructs the robot to evade a bump received from the right side 
 *of the robot. This function assumes that the bump came from the front of the 
 *robot. Further iterations will take rear bumps into account.
 ******************************************************************************/

void Motor_EvadeRight(int leftSpeed);

/*******************************************************************************
 *This function stops the motors.
 ******************************************************************************/

void Motor_Stop();

void Motor_Pitching_On();

void Motor_Pitching_Off();

void ServoLoad();

void ServoFire();




#ifdef	__cplusplus
extern "C" {
#endif
   



#ifdef	__cplusplus
}
#endif

#endif	/* MOTORCONTROL_H */


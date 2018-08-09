#include "MotorControl.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "pwm.h"
#include "AD.h"
#include "IO_Ports.h"
#include "RC_Servo.h"

unsigned int Get_PWM(int speed);

/*******************************************************************************
 *This function initializes the motors for use and sets their pins.
 ******************************************************************************/

int MotorInit(){
    int motorPins = (LEFT_MOTOR_PWM_PIN | RIGHT_MOTOR_PWM_PIN | PITCHING_MOTOR);
    IO_PortsSetPortOutputs(PORTY, LEFT_MOTOR_DIR_PIN);
    IO_PortsSetPortOutputs(PORTY, RIGHT_MOTOR_DIR_PIN);
    return motorPins;
}
void Motor_Pitching_On(void){
    PWM_SetDutyCycle(PITCHING_MOTOR, 250);
}
void Motor_Pitching_Off(void){
    PWM_SetDutyCycle(PITCHING_MOTOR, 0);
}

void ServoLoad(void){
    RC_SetPulseTime(RC_PORTW08, MINPULSE);
}

void ServoFire(void){
    RC_SetPulseTime(RC_PORTW08, MAXPULSE);
}

/*******************************************************************************
 *This function sets the motors to drive straight forward using the defined 
 *offsets.
 ******************************************************************************/

void Motor_ForwardStraight(int fwdSpeed){
    PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, Get_PWM(fwdSpeed+LEFT_MOTOR_OFFSET));
    PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, Get_PWM(fwdSpeed+RIGHT_MOTOR_OFFSET));
    IO_PortsSetPortBits(PORTY, LEFT_MOTOR_DIR_PIN);
    IO_PortsSetPortBits(PORTY, RIGHT_MOTOR_DIR_PIN);
}


/*******************************************************************************
 *This function sets the motors to reverse straight using the defined offsets.
 ******************************************************************************/

void Motor_ReverseStraight(int revSpeed){
    PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, Get_PWM(revSpeed+LEFT_MOTOR_OFFSET));
    PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, Get_PWM(revSpeed+RIGHT_MOTOR_OFFSET));
    IO_PortsClearPortBits(PORTY, LEFT_MOTOR_DIR_PIN);
    IO_PortsClearPortBits(PORTY, RIGHT_MOTOR_DIR_PIN);
}

/*******************************************************************************
 *This function tells the robot to turn using the parameters for turn type, 
 *direction and time. Turn time will be either tank, pivot or slight. 
 *Turn type: Tank sets the motors to equal speeds, but in opposite directions. 
 *           Pivot sets one motor on and the other off. 
 *           Slight turns both motors on in the same direction, but one is 
 *           slightly slower than the other. 
 *Direction: 1 for Forward movement, 0 for reverse. These are #defined.
 
 ******************************************************************************/

int Motor_Turn(turnType turn, int direction, int speed){
    if(turn == TANK){
        if (direction == LEFT){
            //Left Motor
            PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, Get_PWM(speed+LEFT_MOTOR_OFFSET));
            IO_PortsClearPortBits(PORTY, LEFT_MOTOR_DIR_PIN);
            
            //Right Motor
            PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, Get_PWM(speed+RIGHT_MOTOR_OFFSET));
            IO_PortsSetPortBits(PORTY, RIGHT_MOTOR_DIR_PIN);
        }else if(direction == RIGHT){
            //Left Motor
            PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, Get_PWM(speed+LEFT_MOTOR_OFFSET));
            IO_PortsSetPortBits(PORTY, LEFT_MOTOR_DIR_PIN);
            
            //Right Motor
            PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, Get_PWM(speed+RIGHT_MOTOR_OFFSET));
            IO_PortsClearPortBits(PORTY, RIGHT_MOTOR_DIR_PIN);
        }else return ERROR;
        
    }else if(turn == PIVOT){
        if (direction == LEFT){
            //Left Motor
            PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, 0);
            
            //Right Motor
            PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, Get_PWM(speed+RIGHT_MOTOR_OFFSET));
            IO_PortsSetPortBits(PORTY, RIGHT_MOTOR_DIR_PIN);
            
        }else if(direction == RIGHT){
            //Left Motor
            PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, Get_PWM(speed+LEFT_MOTOR_OFFSET));
            IO_PortsSetPortBits(PORTY, LEFT_MOTOR_DIR_PIN);
            
            //Right Motor
            PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, 0);
            
        }else return ERROR;
    }else if(turn == SLIGHT){
        if (direction == LEFT){
            //LEFT Motor
            PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, Get_PWM(speed - SLIGHT_DIFF+LEFT_MOTOR_OFFSET));
            IO_PortsSetPortBits(PORTY, LEFT_MOTOR_DIR_PIN);
            
            //Right Motor
            PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, Get_PWM(speed+RIGHT_MOTOR_OFFSET));
            IO_PortsSetPortBits(PORTY, RIGHT_MOTOR_DIR_PIN);
        }else if(direction == RIGHT){
            //LEFT Motor
            PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, Get_PWM(speed+LEFT_MOTOR_OFFSET));
            IO_PortsSetPortBits(PORTY, LEFT_MOTOR_DIR_PIN);
            
            //Right Motor
            PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, Get_PWM(speed - SLIGHT_DIFF+RIGHT_MOTOR_OFFSET));
            IO_PortsSetPortBits(PORTY, RIGHT_MOTOR_DIR_PIN);
        }else return ERROR;
    }else{
        return ERROR;
    }
}

/*******************************************************************************
 *This function instructs the robot to evade a bump received from the left side 
 *of the robot. This function assumes that the bump came from the front of the 
 *robot. Further iterations will take rear bumps into account.
 ******************************************************************************/

void Motor_EvadeLeft(int rightSpeed){
    //Left Motor
    PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, 0);

    //Right Motor
    PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, Get_PWM(rightSpeed+RIGHT_MOTOR_OFFSET));
    IO_PortsClearPortBits(PORTY, RIGHT_MOTOR_DIR_PIN);
}

/*******************************************************************************
 *This function instructs the robot to evade a bump received from the right side 
 *of the robot. This function assumes that the bump came from the front of the 
 *robot. Further iterations will take rear bumps into account.
 ******************************************************************************/

void Motor_EvadeRight(int leftSpeed){
    //Left Motor
    PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, Get_PWM(leftSpeed+LEFT_MOTOR_OFFSET));
    IO_PortsClearPortBits(PORTY, LEFT_MOTOR_DIR_PIN);

    //Right Motor
    PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, 0);
}

/*******************************************************************************
 *This function stops the motors.
 ******************************************************************************/

void Motor_Stop(){
    PWM_SetDutyCycle(LEFT_MOTOR_PWM_PIN, 0);
    PWM_SetDutyCycle(RIGHT_MOTOR_PWM_PIN, 0);
}

/*******************************************************************************
 * This function alllows the battery voltage to remain stable at a voltage relative
 * to the speed value. The speed can be changed to a float for more control of this voltage.
 *******************************************************************************/
unsigned int Get_PWM(int speed){
    unsigned int Bat_Voltage = AD_ReadADPin(BAT_VOLTAGE);
    float speedConvert = (speed / 33.0)*1023.0;
    return (unsigned int) ((speedConvert/Bat_Voltage)* 1000);
}
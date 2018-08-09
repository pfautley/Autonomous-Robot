/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/
#include "BumperControl.h"
#include "IO_Ports.h"
    
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

int BumperInit(){
    //int bumpPins = (BUMPER_FL_PORT|BUMPER_FR_PORT|BUMPER_BL_PORT|BUMPER_BR_PORT);
    int bumpPins = (PIN3|PIN4|PIN5|PIN7);
    //IO_PortsSetPortInputs(PORTW, bumpPins);
    return bumpPins;
}

/*******************************************************************************
 *This function reads the front left bumper and returns either PRESSED or 
 * RELEASED
 ******************************************************************************/
uint8_t Bumper_Read_Front_Left(){
    int temp = PORTZ03_BIT;
    if(temp == 1){
        temp = 1;
    }else{
        temp = 0;
    }
    return temp;
}

/*******************************************************************************
 *This function reads the front right bumper and returns either PRESSED or 
 * RELEASED
 ******************************************************************************/
uint8_t Bumper_Read_Front_Right(){
    int temp = PORTZ04_BIT;
    if(temp == 1){
        temp = 1;
    }else{
        temp = 0;
    }
    return temp;
}

/*******************************************************************************
 *This function reads the back left bumper and returns either PRESSED or 
 * RELEASED
 ******************************************************************************/
uint8_t Bumper_Read_Back_Left(){
    int temp = PORTZ05_BIT;
    if(temp == 1){
        temp = 1;
    }else{
        temp = 0;
    }
    return temp;
}

/*******************************************************************************
 *This function reads the back right bumper and returns either PRESSED or 
 * RELEASED
 ******************************************************************************/
uint8_t Bumper_Read_Back_Right(){
    int temp = PORTZ07_BIT;
    if(temp == 1){
        temp = 1;
    }else{
        temp = 0;
    }
    return temp;
}

uint8_t Bumper_ReadBumpers(){
    int tempFR = Bumper_Read_Front_Left();
    int tempFL = Bumper_Read_Front_Left();
    int tempBL = Bumper_Read_Back_Left();
    int tempBR = Bumper_Read_Back_Right();

    int temp = (tempFL<<3 | tempFR<<2 | tempBL<<1 | tempBR);
    return temp;
}

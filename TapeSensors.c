#include "MotorControl.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "pwm.h"
#include "AD.h"
#include "IO_Ports.h"
#include "TapeSensors.h"




/*******************************************************************************
 *This function initializes the TapesSensors for use and sets their pins.
 ******************************************************************************/

int TapesInit() {
   int tapePins = (AD_PORTV3 | AD_PORTV4 | AD_PORTV5 | AD_PORTV6 | AD_PORTV7 |AD_PORTV8);
   return tapePins;
}

uint8_t ReadTapeValue() {
    int Tape1, Tape2, Tape3, Tape4, Tape5, Tape6;
    int TapesValue;
    unsigned int Threshold = 0x17C;
    int myint = AD_ReadADPin(AD_PORTV3);
    //printf("my int is %d\n\n\n", myint);
    if (myint > Threshold) {
        Tape1 = 1;
    }else {
        Tape1 = 0;
    }

    if (AD_ReadADPin(AD_PORTV4) > Threshold) {
        Tape2 = 1;
    } else{
        Tape2 = 0;
    }

    if (AD_ReadADPin(AD_PORTV5) > Threshold) {
        Tape3 = 1;
    } else{
        Tape3 = 0;
    }

    if (AD_ReadADPin(AD_PORTV6) > Threshold) {
        Tape4 = 1;
    } else{
        Tape4 = 0;
    }

    if (AD_ReadADPin(AD_PORTV7) > Threshold) {
        Tape5 = 1;
    } else{
        Tape5 = 0;
    }

//    if (AD_ReadADPin(AD_PORTV8) > THRESHOLE6) {
//        Tape6 = 1;
//    } else
//        Tape6 = 0;
    
//
//    if (AD_ReadADPin(AD_PORTW3) > THRESHOLE7) {
//        Tape7 = 1;
//    } else
//        Tape7 = 0;
//
//    if (AD_ReadADPin(AD_PORTW4) > THRESHOLE8) {
//        Tape8 = 1;
//    } else
//        Tape8 = 0;
    TapesValue = (Tape5 <<4  | (Tape4 <<3) | (Tape3 << 2) | (Tape2 << 1)
            | (Tape1));
//            printf("TAPE1 is %d\t TAPE2 is %d\t TAPE3 is %d "
//                    "\t TAPE4 is %d \t TAPE5 is %d\t\n ", Tape1,Tape2,Tape3,
//                    Tape4,Tape5);

    return TapesValue;
}


#define _SUPPRESS_PLIB_WARNING

#include "xc.h"
#include <stdio.h>
#include "ES_Configure.h"


#include "RC_Servo.h"
#include "ES_Framework.h"
#include "serial.h"
#include "roach.h"
#include "BOARD.h"
#include "pwm.h"
#include "IO_Ports.h"
#include "AD.h"
#include "TapeSensors.h"
#include "MotorControl.h"
#include "BumperControl.h"
#include "BumperService.h"
#include "Beacon.h"

int main(void) {
    //while(1);
    ES_Return_t ErrorType;
    BOARD_Init();
    SERIAL_Init();
 //   printf("Starting Tinkerbot...\n");

    // Your hardware initialization function calls go here
    //Roach_Init();

    PWM_Init();
    AD_Init();
    RC_Init();
    int tapePins = TapesInit();
    int motorPins = MotorInit();
    int bumpPins = BumperInit();
    AD_AddPins(TAPELL_SENSOR_ADC_PIN | TAPELM_SENSOR_ADC_PIN | TAPEFC_SENSOR_ADC_PIN
            | TAPERM_SENSOR_ADC_PIN | TAPERR_SENSOR_ADC_PIN | TAPEBC_SENSOR_ADC_PIN
            | TAPEBL_SENSOR_ADC_PIN | TAPEBR_SENSOR_ADC_PIN | AD_PORTW7 | AD_PORTV8);
    PWM_AddPins(motorPins);
    Motor_Pitching_Off();
    IO_PortsSetPortInputs(PORTZ, bumpPins); //for the switches
    //Add RC servo pins
    RC_AddPins(RC_PORTW08);
    //     now initialize the Events and Services Framework and start it running
    ErrorType = ES_Initialize();
    printf("Initialized ES Framework with Error Type %d\n", ErrorType);
    if (ErrorType == Success) {

        ErrorType = ES_Run();

    }
//        char ch;
//
//        while(1)
//        {
//            ch = GetChar();
//            if(ch == 'T')
//                printf("Trackwire_Read: %d \n", AD_ReadADPin(AD_PORTW5));
//        }
    //    while(1){
    //
    //        if(AD_IsNewDataReady()){
    //            int bumpFL = Bumper_Read_Front_Left();
    //            int bumpFR = Bumper_Read_Front_Right();
    //            int bumpBL = Bumper_Read_Back_Left();
    //            int bumpBR = Bumper_Read_Back_Right();
    //            printf("\nFL: %d\tFR: %d\nBL: %d\tBR: %d\n" ,bumpFL ,bumpFR ,bumpBL ,bumpBR);
    //        }
    //        int i;
    //        for (i=0; i<1000; i++){
    //            ;
    //        }
    //    }
    //
    //    char ch;
    //    int a;
    //    while (1) {
    //        ch = GetChar();
    //
    //
    //        if (ch == 'Q') {
    //            printf("TAPE1 is %d\t TAPE2 is %d\t TAPE3 is %d "
    //                    "\t TAPE4 is %d \t TAPE5 is %d\t TAPE6 is %d\n", AD_ReadADPin(AD_PORTV3), AD_ReadADPin(AD_PORTV4), AD_ReadADPin(AD_PORTV5),
    //                    AD_ReadADPin(AD_PORTV6), AD_ReadADPin(AD_PORTV7), AD_ReadADPin(AD_PORTV8));
    //        }
    //        if (ch == 'Q') {
    //            if (AD_IsNewDataReady() == TRUE) {
    //                printf("TapeValue is  %d \n", ReadTapeValue());
    //                printf("Tape1 = %d \n", AD_ReadADPin(AD_PORTV3));
    //                printf("Tape2 = %d \n", AD_ReadADPin(AD_PORTV4));
    //                printf("Tape3 = %d \n", AD_ReadADPin(AD_PORTV5));
    //                printf("Tape4 = %d \n", AD_ReadADPin(AD_PORTV6));
    //                printf("Tape5 = %d \n", AD_ReadADPin(AD_PORTV7));
    //            }
    //        }
    //        if (ch == 'F')
    //            Motor_ForwardStraight(5);
    //
    //    if (ch == 'R') {
    //        Motor_ReverseStraight(5);
    //    }
    //    if (ch == 'S') {
    //        Motor_Stop();
    //    }
    //    if (ch == 'L') {
    //        Motor_Turn(TANK, LEFT, 4);
    //    }
    //    if (ch == 'T') {
    //        printf("Trackwire_Read:  %d \n", AD_ReadADPin(AD_PORTW5);
    //    }

}













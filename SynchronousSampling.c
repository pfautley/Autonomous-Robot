/*
 * File: TemplateService.h
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * File provides synchronous sampling of a single tape sensor without averaging
 * that is performed every SYNCRO_SAMPLE_PERIOD msec using a simple service.
 *
 * This is a solution to problem 9 on CMPE-118 F2015 Midterm
 *
 * Assume the polarity of the phototransistor is such that increasing light is a
 * smaller number on the ADC. IE: white background < black tape
 *
 * Created on 23/Oct/2011
 * Updated on 13/Nov/2013
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "IO_Ports.h"
#include "AD.h"
#include "SynchronousSampling.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/


/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/
/* You will need MyPriority and maybe a state variable; you may need others
 * as well. */

static uint8_t MyPriority;

static uint16_t LL_DarkReading = 0x00;
static uint16_t LL_IlluminatedReading = 0x00;

static uint16_t LM_DarkReading = 0x00;
static uint16_t LM_IlluminatedReading = 0x00;

static uint16_t FC_DarkReading = 0x00;
static uint16_t FC_IlluminatedReading = 0x00;

static uint16_t RM_DarkReading = 0x00;
static uint16_t RM_IlluminatedReading = 0x00;

static uint16_t RR_DarkReading = 0x00;
static uint16_t RR_IlluminatedReading = 0x00;

static uint16_t BC_DarkReading = 0x00;
static uint16_t BC_IlluminatedReading = 0x00;

static uint16_t BL_DarkReading = 0x00;
static uint16_t BL_IlluminatedReading = 0x00;

static uint16_t BR_DarkReading = 0x00;
static uint16_t BR_IlluminatedReading = 0x00;

static tape16_t tapeState = {.tape16 = 0x0000};

ES_Event EventToPost;

static enum {
    LEDs_OFF, LEDs_ON
} syncMode = LEDs_OFF;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitSynchroSamplingService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunSynchroSamplingService function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H. Elkaim, 2015.11.08 20:25 */
uint8_t InitSynchroSamplingService(uint8_t Priority) {
    ES_Event ThisEvent;

    MyPriority = Priority;

    TAPELL_LED_TRIS = 0; // set LED pin to an output
    TAPELL_LED_PIN = LED_OFF; // turn off LEDs

    TAPELM_LED_TRIS = 0;
    TAPELM_LED_PIN = LED_OFF;

    TAPEFC_LED_TRIS = 0;
    TAPEFC_LED_PIN = LED_OFF;

    TAPERM_LED_TRIS = 0;
    TAPERM_LED_PIN = LED_OFF;

    TAPERR_LED_TRIS = 0;
    TAPERR_LED_PIN = LED_OFF;

    TAPEBC_LED_TRIS = 0;
    TAPEBC_LED_PIN = LED_OFF;
//
//    TAPEBL_LED_TRIS = 0;
//    TAPEBL_LED_PIN = LED_OFF;
//
//    TAPEBR_LED_TRIS = 0;
//    TAPEBR_LED_PIN = LED_OFF;

    //    AD_AddPins(TAPELL_SENSOR_ADC_PIN | TAPELM_SENSOR_ADC_PIN | TAPEFC_SENSOR_ADC_PIN
    //            | TAPERM_SENSOR_ADC_PIN | TAPERR_SENSOR_ADC_PIN | TAPEBC_SENSOR_ADC_PIN); // get the ADC system running
    ES_Timer_InitTimer(SYNCHRO_TIMER, SYNCHRO_SAMPLE_PERIOD); // set service for periodic sample

    // post the initial transition event
    ThisEvent.EventType = ES_INIT;
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostSynchroSamplingService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H. Elkaim, 2015.11.08 20:25 */
uint8_t PostSynchroSamplingService(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunSynchroSamplingService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function will be called periodically (#defined) and will read
 *        the last ADC value for the tape sensor, coordinating when the LEDs are ON
 *        and when the LEDs are off to remove the background and check for an event.
 *        Returns ES_NO_EVENT
 * @author Gabriel H. Elkaim, 2015.11.08 20:25 */
ES_Event RunSynchroSamplingService(ES_Event ThisEvent) {
    static tape16_t prevTapeState = {.tape16 = 0x0000};
    int16_t measurementLL;
    int16_t measurementLM;
    int16_t measurementFC;
    int16_t measurementRM;
    int16_t measurementRR;
    int16_t measurementBC;
    int16_t measurementBL;
    int16_t measurementBR;

    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    if ((ThisEvent.EventType == ES_TIMEOUT) && (ThisEvent.EventParam == SYNCHRO_TIMER)) {
        ES_Timer_InitTimer(SYNCHRO_TIMER, SYNCHRO_SAMPLE_PERIOD); // reset trigger

        LL_IlluminatedReading = AD_ReadADPin(TAPELL_SENSOR_ADC_PIN);
        LM_IlluminatedReading = AD_ReadADPin(TAPELM_SENSOR_ADC_PIN);
        FC_IlluminatedReading = AD_ReadADPin(TAPEFC_SENSOR_ADC_PIN);
        RM_IlluminatedReading = AD_ReadADPin(TAPERM_SENSOR_ADC_PIN);
        RR_IlluminatedReading = AD_ReadADPin(TAPERR_SENSOR_ADC_PIN);
        BC_IlluminatedReading = AD_ReadADPin(TAPEBC_SENSOR_ADC_PIN);
        BL_IlluminatedReading = AD_ReadADPin(TAPEBL_SENSOR_ADC_PIN);
        BR_IlluminatedReading = AD_ReadADPin(TAPEBR_SENSOR_ADC_PIN);

        if (LL_IlluminatedReading > TAPE_THRESHOLD) {
            tapeState.leftLeftTape = ON_TAPE;
        }
        if (LL_IlluminatedReading < WHITE_THRESHOLD) { // ON to OFF event
            tapeState.leftLeftTape = OFF_TAPE;
        }

        if (LM_IlluminatedReading > TAPE_THRESHOLD) {
            tapeState.leftMiddleTape = ON_TAPE;
        }
        if (LM_IlluminatedReading < WHITE_THRESHOLD) { // ON to OFF event
            tapeState.leftMiddleTape = OFF_TAPE;
        }

        if (FC_IlluminatedReading > TAPE_THRESHOLD) {
            tapeState.centerFrontTape = ON_TAPE;
        }
        if (FC_IlluminatedReading < WHITE_THRESHOLD) { // ON to OFF event
            tapeState.centerFrontTape = OFF_TAPE;
        }

        if (RM_IlluminatedReading > TAPE_THRESHOLD) {
            tapeState.rightMiddleTape = ON_TAPE;
        }
        if (RM_IlluminatedReading < WHITE_THRESHOLD) { // ON to OFF event
            tapeState.rightMiddleTape = OFF_TAPE;
        }

        if (RR_IlluminatedReading > TAPE_THRESHOLD) {
            tapeState.rightRightTape = ON_TAPE;
        }
        if (RR_IlluminatedReading < WHITE_THRESHOLD) { // ON to OFF event
            tapeState.rightRightTape = OFF_TAPE;
        }

        if (BC_IlluminatedReading > TAPE_THRESHOLD) {
            tapeState.centerBackTape = ON_TAPE;
        }
        if (BC_IlluminatedReading < WHITE_THRESHOLD) { // ON to OFF event
            tapeState.centerBackTape = OFF_TAPE;
        }

        if (BL_IlluminatedReading > TAPE_THRESHOLD) {
            tapeState.leftBackTape = ON_TAPE;
        }
        if (BL_IlluminatedReading < WHITE_THRESHOLD) { // ON to OFF event
            tapeState.leftBackTape = OFF_TAPE;
        }

        if (BR_IlluminatedReading > TAPE_THRESHOLD) {
            tapeState.rightBackTape = ON_TAPE;
        }
        if (BR_IlluminatedReading < WHITE_THRESHOLD) { // ON to OFF event
            tapeState.rightBackTape = OFF_TAPE;
        }


        if(tapeState.leftLeftTape != prevTapeState.leftLeftTape){
            if(tapeState.leftLeftTape == ON_TAPE){
                EventToPost.EventType = TAPE_OFF_TO_ON;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
  //              printf("Tape Event: LL OFFON %x\n", tapeState);
            }else if(tapeState.leftLeftTape == OFF_TAPE){
                tapeState.leftLeftTape = OFF_TAPE;
                EventToPost.EventType = TAPE_ON_TO_OFF;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
 //               printf("Tape Event: LL ONOFF %x\n", tapeState);
            }
        }

        if(tapeState.leftMiddleTape != prevTapeState.leftMiddleTape){
            if(tapeState.leftMiddleTape == ON_TAPE){
                EventToPost.EventType = TAPE_OFF_TO_ON;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
 //               printf("Tape Event: LM OFF_ON %x\n", tapeState);
            }else if(tapeState.leftMiddleTape == OFF_TAPE){
                tapeState.leftMiddleTape = OFF_TAPE;
                EventToPost.EventType = TAPE_ON_TO_OFF;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
 //               printf("Tape Event: LM ON_OFF %x\n", tapeState);
            }
        }

        if(tapeState.centerFrontTape != prevTapeState.centerFrontTape){
            if(tapeState.centerFrontTape == ON_TAPE){
                EventToPost.EventType = TAPE_OFF_TO_ON;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
  //              printf("Tape Event: FC OFF_ON %x\n", tapeState);
            }else if(tapeState.centerFrontTape == OFF_TAPE){
                tapeState.centerFrontTape = OFF_TAPE;
                EventToPost.EventType = TAPE_ON_TO_OFF;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
//                printf("Tape Event: FC ON_OFF %x\n", tapeState);
            }
        }
        if(tapeState.rightMiddleTape != prevTapeState.rightMiddleTape){
            if(tapeState.rightMiddleTape == ON_TAPE){
                EventToPost.EventType = TAPE_OFF_TO_ON;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
                printf("Tape Event: RM OFF_ON %x\n", tapeState);
            }else if(tapeState.rightMiddleTape == OFF_TAPE){
                tapeState.rightMiddleTape = OFF_TAPE;
                EventToPost.EventType = TAPE_ON_TO_OFF;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
                printf("Tape Event: RM ON_OFF %x\n", tapeState);
            }
        }

        if(tapeState.rightRightTape != prevTapeState.rightRightTape){
            if(tapeState.rightRightTape == ON_TAPE){
                EventToPost.EventType = TAPE_OFF_TO_ON;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
               printf("Tape Event: RR OFF_ON %x\n", tapeState);
            }else if(tapeState.rightRightTape == OFF_TAPE){
                tapeState.rightRightTape = OFF_TAPE;
                EventToPost.EventType = TAPE_ON_TO_OFF;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
                printf("Tape Event: RR ON_OFF %x\n", tapeState);
            }
        }
        if(tapeState.centerBackTape != prevTapeState.centerBackTape){
            if(tapeState.centerBackTape == ON_TAPE){
                EventToPost.EventType = TAPE_OFF_TO_ON;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
  //              printf("Tape Event: BC OFF_ON %x\n", tapeState);
            }else if(tapeState.centerBackTape == OFF_TAPE){
                tapeState.centerBackTape = OFF_TAPE;
                EventToPost.EventType = TAPE_ON_TO_OFF;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
 //               printf("Tape Event: BC ON_OFF %x\n", tapeState);
            }
        }
        if(tapeState.leftBackTape != prevTapeState.leftBackTape){
            if(tapeState.leftBackTape == ON_TAPE){
                EventToPost.EventType = TAPE_OFF_TO_ON;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
 //               printf("Tape Event: BL OFF_ON %x\n", tapeState);
            }else if(tapeState.leftBackTape == OFF_TAPE){
                tapeState.leftBackTape = OFF_TAPE;
                EventToPost.EventType = TAPE_ON_TO_OFF;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
//                printf("Tape Event: BL ON_OFF %x\n", tapeState);
            }
        }
        if(tapeState.rightBackTape != prevTapeState.rightBackTape){
            if(tapeState.rightBackTape == ON_TAPE){
                EventToPost.EventType = TAPE_OFF_TO_ON;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
 //               printf("Tape Event: BR OFF_ON %x\n", tapeState);
            }else if(tapeState.rightBackTape == OFF_TAPE){
                tapeState.rightBackTape = OFF_TAPE;
                EventToPost.EventType = TAPE_ON_TO_OFF;
                EventToPost.EventParam = tapeState.tape16;
                PostNightFallHSM(EventToPost);
 //               printf("Tape Event: BR ON_OFF %x\n", tapeState);
            }
        }

        prevTapeState = tapeState;
        return ReturnEvent;

    }

    if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
    {
        // Nothing to do here.
    }

    return ReturnEvent;
}

/**
 * @Function GetTapeSensorState()
 * @param none
 * @return ON_TAPE or OFF_TAPE
 * @brief This function is a wrapper to the module level variable that keeps track
 *        of the tape state for other service functions. This would be modified to
 *        return a bit for each tape sensor used
 */
tape16_t GetTapeSensorState(void) {

    return tapeState;
}


/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/


/*******************************************************************************
 * TEST HARNESS                                                                *
 ******************************************************************************/

#ifdef SYNCHRO_SAMPLING_SERVICE_TEST // <-- change this name and define it in your MPLAB-X
//     project to run the test harness
#include <xc.h>
#include <stdio.h>

void main(void) {
    ES_Return_t ErrorType;
    BOARD_Init();
    // When doing testing, it is useful to annouce just which program
    // is running.

    printf("Starting the Synchronous Sampling Service Test Harness \r\n");
    printf("using the 2nd Generation Events & Services Framework\n\r");

    // Your hardware initialization function calls go here

    // now initialize the Events and Services Framework and start it running
    ErrorType = ES_Initialize();
    if (ErrorType == Success) {

        ErrorType = ES_Run();

    }

    //
    //if we got to here, there was an error
    //

    switch (ErrorType) {
        case FailedPointer:
            printf("Failed on NULL pointer");
            break;
        case FailedInit:
            printf("Failed Initialization");
            break;
        default:
            printf("Other Failure");
            break;
    }

    while (1) {
        ;
    }
}

#endif // TEMPLATESERVICE_TEST
/*
 * File: RoachBumperService.h
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Template file to set up a simple service to work with the Events and Services
 * Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that this file
 * will need to be modified to fit your exact needs, and most of the names will have
 * to be changed to match your code.
 *
 * This is provided as an example and a good place to start.
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
#include "RoachBumperService.h"
#include "RoachFrameworkEvents.h"
#include "BumperControl.h"
#include "NightFallHSM.h"



/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define MAIN_BUMPER_TIMER 3
//#define ESCAPE_BUMPER_TIMER 4

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


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitRoachBumperService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunRoachBumperService function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitRoachBumperService(uint8_t Priority)
{

    ES_Event ThisEvent;
    MyPriority = Priority;
    ES_Timer_InitTimer(MAIN_BUMPER_TIMER , 5);

    // in here you write your initialization code
    // this includes all hardware and software initialization
    // that needs to occur.
    // post the initial transition event
    ThisEvent.EventType = ES_INIT;
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostRoachBumperService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostRoachBumperService(ES_Event ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunRoachBumperService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunRoachBumperService(ES_Event ThisEvent)
{
    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    
    static int counter = 0;
    static int wasBumped = 0;
    //bumperstate = Roach_ReadBumpers();    
    if (ThisEvent.EventType == ES_TIMEOUT)
    {
        static uint32_t holdCheck, killCheck;
        unsigned char bumperstate = (Bumper_Read_Front_Left()| Bumper_Read_Front_Right() << 1|
        Bumper_Read_Back_Left() <<2 | Bumper_Read_Back_Right() <<3);
        ES_Event myEvent;
        
        
        if(bumperstate > 0){
            counter ++;
        }else{
            counter = 0;
            if(wasBumped == 1){
                wasBumped = 0;
                myEvent.EventType = UNBUMPED;
                myEvent.EventParam = bumperstate;
                PostNightFallHSM(myEvent);
                printf("UNBUMPED");
            }
        }
        if (counter == 3){
            myEvent.EventParam = bumperstate;
            myEvent.EventType = BUMPED;
            PostNightFallHSM(myEvent);
            printf("BUMPED");

            holdCheck = ES_Timer_GetTime();     //Used for escape event
            killCheck = holdCheck;
            wasBumped = 1;
        }
        if (counter > 3){
            killCheck = ES_Timer_GetTime();

            if ((killCheck - holdCheck) > 2500){
                //printf("HC:%d KC: %d\n", holdCheck, killCheck);
                myEvent.EventType = ESCAPE;
                myEvent.EventParam = bumperstate;
                printf("ESCAPE");
                PostNightFallHSM(myEvent);
            }
        }
        ES_Timer_InitTimer(MAIN_BUMPER_TIMER, 5);
    }

        
        
     

    return ReturnEvent;
}

/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/


/*******************************************************************************
 * TEST HARNESS                                                                *
 ******************************************************************************/

#ifdef RoachBumperService_TEST // <-- change this name and define it in your MPLAB-X
//     project to run the test harness
#include <stdio.h>

void main(void)
{
    ES_Return_t ErrorType;
    BOARD_Init();
    // When doing testing, it is useful to annouce just which program
    // is running.

    printf("Starting the Simple Service Test Harness \r\n");
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

#endif // RoachBumperService_TEST
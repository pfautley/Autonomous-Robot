/*
 * File: BumperService.h
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
#include "NightFallHSM.h"
#include "RoachFrameworkEvents.h"
#include "BumperControl.h"
#include "BumperService.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define BUMPER_SERVICE_TIMER 3
#define SAMPLE_RATE 5 // 5ms for 200Hz

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
static BumpServiceState_t CurrentState = BumpInit;

#define STRING_FORM(STATE) #STATE, //Strings are stringified and comma'd
static const char *StateNames[] = {
    BUMP_STATES(STRING_FORM)
};
/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */
static DebounceServiceState_t ParseBumpers(unsigned char bumperVal, DebounceServiceState_t bumpState);
static uint16_t getBumpedParam(DebounceStates_t debounceState);
 
/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitBumperService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunBumperService function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitBumperService(uint8_t Priority)
{
    ES_Event ThisEvent;

    MyPriority = Priority;

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
 * @Function PostBumperService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostBumperService(ES_Event ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunBumperService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the service,
 *        as this is called any time a new event is passed to the event queue. 
 * @note Remember to rename to something appropriate.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author J. Edward Carryer, 2011.10.23 19:25 */
ES_Event RunBumperService(ES_Event ThisEvent)
{
    ES_Event bumpEvent, ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors
    uint8_t makeTransition = FALSE; // use to flag transition
    BumpServiceState_t nextState; // <- need to change enum type here
    static DebounceStates_t debounceState;
    uint16_t bumpedParam = 0;
    static uint16_t prevBumpedParam = 0;
    switch (CurrentState) {
    case BumpInit: // If current state is initial Psedudo State
        if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
        {
            // this is where you would put any actions associated with the
            // transition from the initial pseudo-state into the actual
            // initial state
            ES_Timer_InitTimer(BUMPER_SERVICE_TIMER, SAMPLE_RATE);
 
            // init struct
            debounceState.bumperFL = SEEN_NONE;
            debounceState.bumperFR = SEEN_NONE;
            debounceState.bumperBL = SEEN_NONE;
            debounceState.bumperBR = SEEN_NONE;
 
            // now put the machine into the state you want to be first
            nextState = Bumping; //Pick the next state
            makeTransition = TRUE; //tell framework to transition to next state
            ThisEvent.EventType = ES_NO_EVENT; //consume the event
        }
        break;
 
    case Bumping: // in the first state, replace this with appropriate state
        switch (ThisEvent.EventType) {
 
        case ES_TIMEOUT:
            ES_Timer_InitTimer(BUMPER_SERVICE_TIMER, SAMPLE_RATE);
 
 
            // get new states of bumpers and if bumped set param and post
            debounceState.bumperFL = ParseBumpers(Bumper_Read_Front_Left(), debounceState.bumperFL);
            debounceState.bumperFR = ParseBumpers(Bumper_Read_Front_Right(), debounceState.bumperFR);
            debounceState.bumperBL = ParseBumpers(Bumper_Read_Back_Left(), debounceState.bumperBL);
            debounceState.bumperBR = ParseBumpers(Bumper_Read_Back_Right(), debounceState.bumperBR);
 
            bumpedParam = getBumpedParam(debounceState);
 
            if (bumpedParam != 0 && prevBumpedParam != bumpedParam) {
                bumpEvent.EventType = BUMPED;
                bumpEvent.EventParam = bumpedParam;
                PostNightFallHSM(bumpEvent);
            }
            prevBumpedParam = bumpedParam;
 
            // do we need to switch states?
            //nextState = Stopped;
            //makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            break;
 
        default: // all unhandled events pass the event back up to the next level
            break;
        }
        break;
 
    default: // all unhandled states fall into here
        break;
    } // end switch on Current State
    
    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunNightFallHSM(EXIT_EVENT);
        CurrentState = nextState;
        RunNightFallHSM(ENTRY_EVENT);
    }

    return ReturnEvent;
}

/*******************************************************************************
 * PRIVATE FUNCTIONs                                                           *
 ******************************************************************************/

static DebounceServiceState_t ParseBumpers(unsigned char bumperVal, DebounceServiceState_t bumpState)
{
    switch (bumpState) {
 
    case SEEN_NONE:
        if (bumperVal) {
            bumpState = SEEN_ONE;
        }
        break;
    case SEEN_ONE:
        if (bumperVal) {
            bumpState = SEEN_TWO;
        } else {
            bumpState = SEEN_NONE;
        }
        break;
    case SEEN_TWO:
        if (bumperVal) {
            bumpState = SEEN_BUMP;
        } else {
            bumpState = SEEN_NONE;
        }
        break;
    case SEEN_BUMP:
        if (bumperVal) {
            bumpState = SEEN_BUMP;
        } else {
            bumpState = SEEN_NONE;
            //this is where we'd flag that it was no longer pushed if we needed that
        }
        break;
    }
    return bumpState;
 
}
 
static uint16_t getBumpedParam(DebounceStates_t debounceState)
{
    uint16_t param = 0;
 
    if (debounceState.bumperFL == SEEN_BUMP) {
        param |= 0x1;
    }
    if (debounceState.bumperFR == SEEN_BUMP) {
        param |= 0x2;
    }
    if (debounceState.bumperBL == SEEN_BUMP) {
        param |= 0x4;
    }
    if (debounceState.bumperBR == SEEN_BUMP) {
        param |= 0x8;
    }
 
    return param;
}
/*******************************************************************************
 * TEST HARNESS                                                                *
 ******************************************************************************/

#ifdef BUMPER_SERVICE_TEST // <-- change this name and define it in your MPLAB-X
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

#endif // BUMPER_SERVICE_TEST
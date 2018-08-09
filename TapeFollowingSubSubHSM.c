/*
 * File: TapeFollowingSubSubHSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * TapeFollowingSub file to set up a Heirarchical State Machine to work with the Events and
 * Services Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that
 * this file will need to be modified to fit your exact needs, and most of the names
 * will have to be changed to match your code.
 *
 * There is for a substate machine. Make sure it has a unique name
 *
 * This is provided as an example and a good place to start.
 *
 * History
 * When           Who     What/Why
 * -------------- ---     --------
 * 09/13/13 15:17 ghe      added tattletail functionality and recursive calls
 * 01/15/12 11:12 jec      revisions for Gen2 framework
 * 11/07/11 11:26 jec      made the queue static
 * 10/30/11 17:59 jec      fixed references to CurrentEvent in RunTapeFollowingSubSM()
 * 10/23/11 18:20 jec      began conversion from SMTapeFollowingSub.c (02/20/07 rev)
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "TapeFollowingSubHSM.h"
#include "TapeFollowingSubSubHSM.h"
#include "OrientingSubHSM.h"
#include "MotorControl.h"
#include "NightFallHSM.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define BACKUP_TIME 600
#define BACKUP_SPEED 9

#define CCW_NINETY_TIME 900
#define CW_NINETY_TIME 900
#define NINETY_SPEED 8

#define FORWARD_SPEED 9
#define SHORT_LAUNCHER_TIME 810
#define LONG_LAUNCHER_TIME 800
#define EXTRA_LAUNCHER_TIME 500

#define LIST_OF_TapeFollowingSub_STATES(STATE) \
        STATE(InitPSubState) \
        STATE(MovingBack) /*Make sure state names are unique in their hierachy*/ \
        STATE(TurnCCW)       \
        STATE(ForwardTemp)  \
        STATE(TurnCW)\
        STATE(CheckingBump)\

#define ENUM_FORM(STATE) STATE, //Enums are reprinted verbatim and comma'd

typedef enum {
    LIST_OF_TapeFollowingSub_STATES(ENUM_FORM)
} SubTapeFollowingSubState_t;

#define STRING_FORM(STATE) #STATE, //Strings are stringified and comma'd
static const char *StateNames[] = {
    LIST_OF_TapeFollowingSub_STATES(STRING_FORM)
};

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static SubTapeFollowingSubState_t CurrentState; // <- change name to match ENUM
static uint8_t MyPriority;
static int bumpCount = 0;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTapeFollowingSubSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTapeFollowingSubFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitTapeFollowingSubSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunTapeFollowingSubSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunTapeFollowingSubSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the heirarchical state
 *        machine, as this is called any time a new event is passed to the event
 *        queue. This function will be called recursively to implement the correct
 *        order for a state transition to be: exit current state -> enter next state
 *        using the ES_EXIT and ES_ENTRY events.
 * @note Remember to rename to something appropriate.
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author J. Edward Carryer, 2011.10.23 19:25
 * @author Gabriel H Elkaim, 2011.10.23 19:25 */
ES_Event RunTapeFollowingSubSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SubTapeFollowingSubState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitPSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                // this is where you would put any actions associated with the
                // transition from the initial pseudo-state into the actual
                // initial state
                printf("I am in tape subsub state!!!!!");
                // now put the machine into the actual initial state
                nextState = MovingBack;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case MovingBack: // in the first state, replace this with correct names
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is still active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(TINKERBOT_TIMER, BACKUP_TIME);
                        Motor_ReverseStraight(BACKUP_SPEED);
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;

                    case ES_EXIT:
                        // this is where you would put any actions associated with the
                        // exit from this state
                        break;

                    case ES_KEYINPUT:
                        // this is an example where the state does NOT transition
                        // do things you need to do in this state
                        // event consumed
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    case ES_TIMEOUT:
                        // create the case statement for all other events that you are
                        // interested in responding to.
                        nextState = TurnCCW;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;

        case TurnCCW: // If current state is state OtherState
            // run sub-state machine for this state
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(TINKERBOT_TIMER, CCW_NINETY_TIME);
                        Motor_Turn(TANK, LEFT, NINETY_SPEED);
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;

                    case ES_EXIT:
                        // this is where you would put any actions associated with the
                        // exit from this state
                        break;

                    case ES_TIMEOUT:
                        // create the case statement for all other events that you are
                        // interested in responding to. This does a transition
                        nextState = ForwardTemp;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;

        case ForwardTemp: // example of a state without a sub-statemachine
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    // this is where you would put any actions associated with the
                    // entry to this state
                    Motor_ForwardStraight(FORWARD_SPEED);
                    if(bumpCount == 0){
                        ES_Timer_InitTimer(TINKERBOT_TIMER, SHORT_LAUNCHER_TIME);
                    }else if(bumpCount == 1){
                        ES_Timer_InitTimer(TINKERBOT_TIMER, LONG_LAUNCHER_TIME);
                    }else {
                        ES_Timer_InitTimer(TINKERBOT_TIMER, EXTRA_LAUNCHER_TIME);
                    }
                    break;

                case ES_EXIT:
                    // this is where you would put any actions associated with the
                    // exit from this state
                    break;

                case ES_TIMEOUT:
                    // create the case statement for all other events that you are
                    // interested in responding to. This one does a transition
                    nextState = TurnCW;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;

        case TurnCW: // example of a state without a sub-statemachine
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    // this is where you would put any actions associated with the
                    // entry to this state
                    ES_Timer_InitTimer(TINKERBOT_TIMER, CW_NINETY_TIME);
                    Motor_Turn(TANK, RIGHT, NINETY_SPEED);
                    break;

                case ES_EXIT:
                    // this is where you would put any actions associated with the
                    // exit from this state
                    break;

                case ES_TIMEOUT:
                    // create the case statement for all other events that you are
                    // interested in responding to. This one does a transition
                    nextState = CheckingBump;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;
        case CheckingBump: // example of a state without a sub-statemachine
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    // this is where you would put any actions associated with the
                    // entry to this state
                    bumpCount++;
                    ES_Timer_InitTimer(TINKERBOT_TIMER, 1100);
                    Motor_ForwardStraight(FORWARD_SPEED);
                    break;
                case BUMPED:
                    nextState = MovingBack;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
//                case TAPE_OFF_TO_ON:{
//                    ES_Event newEvent;
//                    newEvent.EventType = FOUND_T;
//                    newEvent.EventParam = RIGHT_T_FOUND;
//                    PostNightFallHSM(newEvent);
//                }
//                    break;
                case ES_EXIT:
                    // this is where you would put any actions associated with the
                    // exit from this state
                    break;

                case ES_TIMEOUT:{
                    ES_Event newEvent;
                    newEvent.EventType = FOUND_T;
                    newEvent.EventParam = RIGHT_T_FOUND;
                    PostNightFallHSM(newEvent);
                }
                    
                    // create the case statement for all other events that you are
                    // interested in responding to. This one does a transition
                    //            nextState = MovingBack;
                    //            makeTransition = TRUE;
                    //            ThisEvent.EventType = ES_NO_EVENT;
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
        RunTapeFollowingSubSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunTapeFollowingSubSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/


/*******************************************************************************
 * TEST HARNESS                                                                *
 ******************************************************************************/

#ifdef TapeFollowingSubSUBHSM_TEST // <-- change this name and define it in your MPLAB-X
//     project to run the test harness
#include <stdio.h>

void main(void) {
    ES_Return_t ErrorType;
    BOARD_Init();
    // When doing testing, it is useful to annouce just which program
    // is running.

    printf("Starting the Hierarchical State Machine Test Harness \r\n");
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

#endif // TapeFollowingSubSUBHSM_TEST

/*
 * File: OrientingSubHSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Orienting file to set up a Heirarchical State Machine to work with the Events and
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
 * 10/30/11 17:59 jec      fixed references to CurrentEvent in RunOrientingSM()
 * 10/23/11 18:20 jec      began conversion from SMOrienting.c (02/20/07 rev)
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "OrientingSubHSM.h"
#include "MotorControl.h"
#include "TapeSensors.h"
#include "FoundTapeSubHSM.h"
#include "TapeFollowingSubHSM.h"
/**************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/


#define LIST_OF_Orienting_STATES(STATE) \
        STATE(InitPSubState) \
        STATE(ForwardInvestigate) /*Make sure state names are unique in their hierachy*/ \
        STATE(ReverseInvestigate)       \
        STATE(Turning)  \
        STATE(Bumped)  \
        STATE(BumpCheck)  \
        STATE(Escaping)\
        STATE(TapeSeen)\

#define ENUM_FORM(STATE) STATE, //Enums are reprinted verbatim and comma'd

typedef enum {
    LIST_OF_Orienting_STATES(ENUM_FORM)
} SubOrientingState_t;

#define STRING_FORM(STATE) #STATE, //Strings are stringified and comma'd
static const char *StateNames[] = {
    LIST_OF_Orienting_STATES(STRING_FORM)
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

static SubOrientingState_t CurrentState; // <- change name to match ENUM
static uint8_t MyPriority;
tape16_t myTape;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitOrientingSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunOrientingFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitOrientingSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunOrientingSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunOrientingSubHSM(ES_Event ThisEvent)
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
ES_Event RunOrientingSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SubOrientingState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitPSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                // this is where you would put any actions associated with the
                // transition from the initial pseudo-state into the actual
                // initial state
                // now put the machine into the actual initial state
                //InitFoundTapeSubHSM();
                InitTapeFollowingSubHSM();
                nextState = ForwardInvestigate;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case ForwardInvestigate: // in the first state, replace this with correct names
            //ThisEvent = RunFoundTapeSubHSM(ThisEvent);
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is still active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(TINKERBOT_TIMER, SEARCH_TIME);
                        Motor_ForwardStraight(SEARCH_SPEED);
                        //                       printf("State: Forward Investigate\n");
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
                        //                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    case BUMPED:                       
                        nextState = ReverseInvestigate;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        //                    case BUMPED:
                        //                        nextState = Turning;
                        //                        makeTransition = TRUE;
                        //                        ThisEvent.EventType = ES_NO_EVENT;
                        //                        break;
                        //                    case ESCAPE:
                        //                        makeTransition = TRUE;
                        //                        nextState = Escaping;
                        //                        ThisEvent.EventType = ES_NO_EVENT;
                        //                        break;
                        //                    case UNBUMPED:
                        //                        makeTransition = TRUE;
                        //                        nextState = ForwardInvestigate;
                        //                        ThisEvent.EventType = ES_NO_EVENT;
                        //                        break;
                    case TAPE_OFF_TO_ON:
                        myTape = GetTapeSensorState();
                        if (myTape.leftLeftTape == 1 || myTape.leftMiddleTape == 1) {
                            nextState = ReverseInvestigate;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        } else {
                            nextState = TapeSeen;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        }
                        break;

                    case ES_TIMEOUT:
                        // create the case statement for all other events that you are
                        // interested in responding to.
                        //                       printf("Timer Expired\n");
                        nextState = ReverseInvestigate;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;



                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;

        case ReverseInvestigate: // If current state is state OtherState
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(TINKERBOT_TIMER, SEARCH_TIME);
                        Motor_ReverseStraight(SEARCH_SPEED);
                        //                     printf("State: Reverse Investigate\n");
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;
                    case BUMPED:
                        makeTransition = TRUE;
                        nextState = Turning;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        //                    case UNBUMPED:
                        //                        makeTransition = TRUE;
                        //                        nextState = ReverseInvestigate;
                        //                        ThisEvent.EventType = ES_NO_EVENT;
                        //                        break;
                        //                    case ESCAPE:
                        //                        nextState = Escaping;
                        //                        makeTransition = TRUE;
                        //                        ThisEvent.EventType = ES_NO_EVENT;
                        //                        break;
                    case TAPE_OFF_TO_ON:
                        nextState = TapeSeen;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    case ES_EXIT:
                        // this is where you would put any actions associated with the
                        // exit from this state
                        break;

                    case ES_TIMEOUT:
                        // create the case statement for all other events that you are
                        // interested in responding to. This does a transition
                        nextState = Turning;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;

        case Turning: // example of a state without a sub-statemachine
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(TINKERBOT_TIMER, TURN_TIME);
                    Motor_Turn(TANK, RIGHT, TURN_SPEED);
                    //                   printf("State: Turning\n");
                    // this is where you would put any actions associated with the
                    // entry to this state
                    break;
                case BUMPED:
                    makeTransition = TRUE;
                    nextState = ReverseInvestigate;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    //                    break;
                    //                case UNBUMPED:
                    //                    makeTransition = TRUE;
                    //                    nextState = Turning;
                    //                    ThisEvent.EventType = ES_NO_EVENT;
                    //                    break;
                    //                case BUMPED:
                    //                    nextState = Escaping;
                    //                    makeTransition = TRUE;
                    //                    ThisEvent.EventType = ES_NO_EVENT;
                    //                    break;
                case TAPE_OFF_TO_ON:
                    nextState = TapeSeen;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_EXIT:
                    // this is where you would put any actions associated with the
                    // exit from this state
                    break;

                case ES_TIMEOUT:
                    // create the case statement for all other events that you are
                    // interested in responding to. This one does a transition
                    nextState = ForwardInvestigate;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;
        case TapeSeen:
            ThisEvent = RunTapeFollowingSubHSM(ThisEvent);
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
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
                    break;

                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;
            //        case Bumped: // example of a state without a sub-statemachine
            //            switch (ThisEvent.EventType) {
            //                case ES_ENTRY:
            //                    ES_Timer_InitTimer(TINKERBOT_TIMER, BUMP_TIME);
            //                    Motor_Stop(BUMP_SPEED);
            //                    printf("State: bumped\n");
            //                    // this is where you would put any actions associated with the
            //                    // entry to this state
            //                    break;
            //                case ES_EXIT:
            //                    // this is where you would put any actions associated with the
            //                    // exit from this state
            //                    break;
            //
            //                case ES_TIMEOUT:
            //                    // create the case statement for all other events that you are
            //                    // interested in responding to. This one does a transition
            //                    nextState = BumpCheck;
            //                    makeTransition = TRUE;
            //                    ThisEvent.EventType = ES_NO_EVENT;
            //                    break;
            //
            //                default: // all unhandled events pass the event back up to the next level
            //                    break;
            //            }
            //            break;
            //        case BumpCheck: // example of a state without a sub-statemachine
            //            switch (ThisEvent.EventType) {
            //                case ES_ENTRY:
            //                    ES_Timer_InitTimer(TINKERBOT_TIMER, BUMP_TIME + 100);
            //                    Motor_ForwardStraight(BUMP_SPEED);
            //                    printf("State: bump check\n");
            //                    // this is where you would put any actions associated with the
            //                    // entry to this state
            //                    break;
            //                case BUMPED:
            //                    nextState = Turning;
            //                    makeTransition = TRUE;
            //                    ThisEvent.EventType = ES_NO_EVENT;
            //                    break;
            //                case ES_EXIT:
            //                    // this is where you would put any actions associated with the
            //                    // exit from this state
            //                    break;
            //
            //                case ES_TIMEOUT:
            //                    // create the case statement for all other events that you are
            //                    // interested in responding to. This one does a transition
            //                    nextState = ForwardInvestigate;
            //                    makeTransition = TRUE;
            //                    ThisEvent.EventType = ES_NO_EVENT;
            //                    break;
            //
            //                default: // all unhandled events pass the event back up to the next level
            //                    break;
            //            }
            //            break;

        case Escaping: // example of a state without a sub-statemachine
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(TINKERBOT_TIMER, ESCAPE_TIME);
                    Motor_Turn(TANK, LEFT, ESCAPE_SPEED);
                    //                   printf("State: Escaping\n");
                    // this is where you would put any actions associated with the
                    // entry to this state
                    break;
                case ES_EXIT:
                    // this is where you would put any actions associated with the
                    // exit from this state
                    break;

                case ES_TIMEOUT:
                    // create the case statement for all other events that you are
                    // interested in responding to. This one does a transition
                    nextState = ForwardInvestigate;
                    makeTransition = TRUE;
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
        RunOrientingSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunOrientingSubHSM(ENTRY_EVENT); // <- rename to your own Run function
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

#ifdef OrientingSUBHSM_TEST // <-- change this name and define it in your MPLAB-X
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

#endif // OrientingSUBHSM_TEST

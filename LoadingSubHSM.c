/*
 * File: LoadingSubHSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Loading file to set up a Heirarchical State Machine to work with the Events and
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
 * 10/30/11 17:59 jec      fixed references to CurrentEvent in RunLoadingSM()
 * 10/23/11 18:20 jec      began conversion from SMLoading.c (02/20/07 rev)
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "NightFallHSM.h"
#include "LoadingSubHSM.h"
#include "MotorControl.h"
#include "OrientingSubHSM.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define LIST_OF_Loading_STATES(STATE) \
        STATE(InitPSubState) \
        STATE(LoadingS) /*Make sure state names are unique in their hierachy*/ \
        STATE(AligningT)       \
        STATE(GettingBall)  \
        STATE(Adjusting) \
        STATE(BackingTemp)\
        STATE(ForwardTemp)\
STATE(STOPPING)\
STATE(SHORTSTOPPING)\

#define ENUM_FORM(STATE) STATE, //Enums are reprinted verbatim and comma'd

typedef enum {
    LIST_OF_Loading_STATES(ENUM_FORM)
} SubLoadingState_t;

#define STRING_FORM(STATE) #STATE, //Strings are stringified and comma'd
static const char *StateNames[] = {
    LIST_OF_Loading_STATES(STRING_FORM)
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

static SubLoadingState_t CurrentState; // <- change name to match ENUM
static uint8_t MyPriority;
tape16_t myTape;
static int counter = 0;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitLoadingSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunLoadingFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitLoadingSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunLoadingSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunLoadingSubHSM(ES_Event ThisEvent)
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
ES_Event RunLoadingSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SubLoadingState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitPSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                // this is where you would put any actions associated with the
                // transition from the initial pseudo-state into the actual
                // initial state

                // now put the machine into the actual initial state
                nextState = LoadingS;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case LoadingS: // in the first state, replace this with correct names
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is still active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        Motor_ForwardStraight(8);
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;

                    case ES_EXIT:
                        // this is where you would put any actions associated with the
                        // exit from this state
                        break;
                    case TAPE_ON_TO_OFF:
                        myTape = GetTapeSensorState();
                        if (myTape.rightRightTape == 0 || myTape.rightMiddleTape == 0) {
                            ES_Timer_InitTimer(TINKERBOT_TIMER, 200);
                        }
                        /*********************************************************************
                         * Add else statemet to orienting
                         ***********************************************************************/
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
                        nextState = AligningT;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;
        case STOPPING: // in the first state, replace this with correct names
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is still active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(TINKERBOT_TIMER, 200);
                        Motor_Stop();
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;

                    case ES_EXIT:
                        // this is where you would put any actions associated with the
                        // exit from this state
                        break;
                        /*********************************************************************
                         * Add else statemet to orienting
                         ***********************************************************************/

                    case ES_KEYINPUT:
                        // this is an example where the state does NOT transition
                        // do things you need to do in this state
                        // event consumed
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    case ES_TIMEOUT:
                        // create the case statement for all other events that you are
                        // interested in responding to.
                        nextState = BackingTemp;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;
            case SHORTSTOPPING: // in the first state, replace this with correct names
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is still active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(TINKERBOT_TIMER, 1000);
                        Motor_Stop();
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;

                    case ES_EXIT:
                        // this is where you would put any actions associated with the
                        // exit from this state
                        break;
                        /*********************************************************************
                         * Add else statemet to orienting
                         ***********************************************************************/

                    case ES_KEYINPUT:
                        // this is an example where the state does NOT transition
                        // do things you need to do in this state
                        // event consumed
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    case ES_TIMEOUT:
                        // create the case statement for all other events that you are
                        // interested in responding to.
                        nextState = ForwardTemp;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;



        case AligningT: // If current state is state OtherState
            // run sub-state machine for this state
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(TINKERBOT_TIMER, 900);
                        Motor_Turn(TANK, LEFT, 8);
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;

                    case ES_EXIT:
                        // this is where you would put any actions associated with the
                        // exit from this state
                        break;
                        //                    case TAPE_OFF_TO_ON:
                        //                        myTape = GetTapeSensorState();
                        //                        if(myTape.leftBackTape == 1){
                        //                            //Motor_Turn(TANK, RIGHT, 8);
                        //                            nextState = STOPPING;
                        //                            makeTransition = TRUE;
                        //                            ThisEvent.EventType = ES_NO_EVENT;
                        //                        }
                        //                       break;
                    case ES_TIMEOUT:
                        // create the case statement for all other events that you are
                        // interested in responding to. This does a transition
                        nextState = GettingBall;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;

        case GettingBall: // example of a state without a sub-statemachine
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    Motor_ReverseStraight(9);
                    ES_Timer_InitTimer(TINKERBOT_TIMER, 2000);
                    // this is where you would put any actions associated with the
                    // entry to this state
                    break;

                case BUMPED:
                    Motor_Stop();
                    ES_Timer_InitTimer(TINKERBOT_TIMER, 1500);
                    break;
                    //                case TAPE_ON_TO_OFF:
                    //                    myTape = GetTapeSensorState();
                    //                    if(myTape.rightBackTape == 0){
                    //                        nextState = BackingRight;
                    //                        makeTransition = TRUE;
                    //                        ThisEvent.EventType = ES_NO_EVENT;
                    //                    }
                    //                    else if(myTape.leftBackTape == 0){
                    //                        nextState = BackingLeft;
                    //                        makeTransition = TRUE;
                    //                        ThisEvent.EventType = ES_NO_EVENT;
                    //                    }
                case ES_EXIT:
                    // this is where you would put any actions associated with the
                    // exit from this state
                    break;

                case ES_TIMEOUT:
                    // create the case statement for all other events that you are
                    // interested in responding to. This one does a transition
                    nextState = ForwardTemp;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;

        case BackingTemp: // If current state is state OtherState
            // run sub-state machine for this state
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(TINKERBOT_TIMER, 250);
                        Motor_ReverseStraight(9);
//                        if (counter >= 4) {
//                        }
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;


                    case BUMPED:
                        nextState = SHORTSTOPPING;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        //counter++;
                        break;
                        //                    case TAPE_OFF_TO_ON:
                        //                        myTape = GetTapeSensorState();
                        //                        if(myTape.leftBackTape == 1){
                        //                            nextState = GettingBall;
                        //                            makeTransition = TRUE;
                        //                            ThisEvent.EventType = ES_NO_EVENT;
                        //                        }
                    case ES_EXIT:
                        // this is where you would put any actions associated with the
                        // exit from this state
                        break;

                    case ES_TIMEOUT:
                        // create the case statement for all other events that you are
                        // interested in responding to. This does a transition
                        nextState = SHORTSTOPPING;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;

        case ForwardTemp: // If current state is state OtherState
            // run sub-state machine for this state
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(TINKERBOT_TIMER, 200);
                        Motor_Turn(SLIGHT, LEFT, 9);
                        counter++;
                        if(counter == 4){
                            ES_Event newEvent;
                            newEvent.EventType = LOADED;
                            newEvent.EventParam = 0;
                            PostNightFallHSM(newEvent);
                        }
                        // this is where you would put any actions associated with the
                        // entry to this state
                        break;
                        //                    case TAPE_OFF_TO_ON:
                        //                        myTape = GetTapeSensorState();
                        //                        if(myTape.rightBackTape ==1){
                        //                            nextState = GettingBall;
                        //                            makeTransition = TRUE;
                        //                            ThisEvent.EventType = ES_NO_EVENT;
                        //                        }

                    case ES_EXIT:
                        // this is where you would put any actions associated with the
                        // exit from this state
                        break;

                    case ES_TIMEOUT:
                        // create the case statement for all other events that you are
                        // interested in responding to. This does a transition
                        nextState = STOPPING;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;


        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunLoadingSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunLoadingSubHSM(ENTRY_EVENT); // <- rename to your own Run function
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

#ifdef LoadingSUBHSM_TEST // <-- change this name and define it in your MPLAB-X
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

#endif // LoadingSUBHSM_TEST

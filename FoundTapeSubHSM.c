/*
 * File: FoundTapeSubHSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * FoundTape file to set up a Heirarchical State Machine to work with the Events and
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
 * 10/30/11 17:59 jec      fixed references to CurrentEvent in RunFoundTapeSM()
 * 10/23/11 18:20 jec      began conversion from SMFoundTape.c (02/20/07 rev)
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "NightFallHSM.h"
#include "FoundTapeSubHSM.h"
#include "OrientingSubHSM.h"
#include "MotorControl.h"
#include "TapesService.h"
#include "TapeSensors.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define ALL_TAPE 31
#define LEFT_TAPE 24
#define RIGHT_TAPE 3
#define CENTER_TAPE 14
#define CENTER_LEFT_TAPE 12
#define CENTER_RIGHT_TAPE 6
#define OUTER_LEFT_TAPE 16
#define OUTER_RIGHT_TAPE 1

#define LIST_OF_FoundTape_STATES(STATE) \
        STATE(InitPSubState) \
        STATE(HitTape) /*Make sure state names are unique in their hierachy*/ \
        STATE(RidingTape)\
        STATE(Bumped)       \
        STATE(SawCorner)  \

#define ENUM_FORM(STATE) STATE, //Enums are reprinted verbatim and comma'd

typedef enum {
    LIST_OF_FoundTape_STATES(ENUM_FORM)
} SubFoundTapeState_t;

#define STRING_FORM(STATE) #STATE, //Strings are stringified and comma'd
static const char *StateNames[] = {
    LIST_OF_FoundTape_STATES(STRING_FORM)
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
tape16_t myTape;
static SubFoundTapeState_t CurrentState = InitPSubState; // <- change name to match ENUM
static uint8_t MyPriority;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitFoundTapeSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunFoundTapeFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitFoundTapeSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunFoundTapeSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunFoundTapeSubHSM(ES_Event ThisEvent)
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
ES_Event RunFoundTapeSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    SubFoundTapeState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitPSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                // this is where you would put any actions associated with the
                // transition from the initial pseudo-state into the actual
                // initial state

                // now put the machine into the actual initial state
                nextState = HitTape;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;


        case HitTape: // in the first state, replace this with correct names
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(2, 500);
                    myTape = GetTapeSensorState();
                    printf("\nCurrent Tape\n: %x", myTape);

                    if(myTape.tape16 == 0<<16){             //If there is no tape detected, drive straight
                        ES_Timer_InitTimer(2,250);
                        Motor_ForwardStraight(7);
                        printf("NO TAPE FOUND\n");
                        printf("FWD STRAIGHT 250\n");
                    }else if(myTape.leftLeftTape == 1){     //If the left tape is on, turn to encourage the right tape to catch
                        ES_Timer_InitTimer(2,250);
                        Motor_EvadeRight(10);
                        printf("LEFT TAPE FOUND\n");
                        printf("EVADE RIGHT 250\n");
                    }else if(myTape.rightRightTape == 1) {  //If the right tape is on, check the surrounding tape
                        if(myTape.rightMiddleTape == 1){
                            if(myTape.leftMiddleTape == 1){
                                ES_Timer_InitTimer(2, 500);
                                Motor_Turn(PIVOT, LEFT, 7);
                                printf("PIVOT LEFT 500\n");
                            }else{
                                ES_Timer_InitTimer(2, 500);
                                Motor_Turn(PIVOT, RIGHT, 7);
                                printf("PIVOT RIGHT 500\n");
                            }
                        }else{
                            ES_Timer_InitTimer(2, 500);
                            Motor_Turn(PIVOT, RIGHT, 7);
                            printf("PIVOT RIGHT 500\n");
                        }
                        printf("RIGHT TAPE FOUND\n");
                    }else{
                        if(myTape.centerFrontTape == 1 || myTape.leftMiddleTape == 1
                                || myTape.rightRightTape == 1){    //If neither outside tape is on, check for tape riding conditions
                            nextState = RidingTape;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        }
                        printf("~~~~~INNER TAPE FOUND~~~~~\n");
                    }
                    break;
                case BUMPED:
                    nextState = Bumped;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
//                case TAPE_OFF_TO_ON:
//                    nextState = HitTape;
//                    makeTransition = TRUE;
//                    ThisEvent.EventType = ES_NO_EVENT;
//                    break;
//                case TAPE_ON_TO_OFF:
//                    nextState = HitTape;
//                    makeTransition = TRUE;
//                    ThisEvent.EventType = ES_NO_EVENT;
//                    break;
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
                    printf("TapeTimer expired");
                    // create the case statement for all other events that you are
                    // interested in responding to.
                    nextState = HitTape;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;

        case Bumped: // If current state is state OtherState
            //ThisEvent = RunFoundTapeSubHSM(ThisEvent); // run sub-state machine for this state
            if (ThisEvent.EventType != ES_NO_EVENT) { // An event is active
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
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
                        //                nextState = SubAnother;
                        //                makeTransition = TRUE;
                        //                ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    default: // all unhandled events pass the event back up to the next level
                        break;
                }
            }
            break;

        case SawCorner: // example of a state without a sub-statemachine
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
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
                    //            nextState = SubFirst;
                    //            makeTransition = TRUE;
                    //            ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;
        caseRidingTape:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    // this is where you would put any actions associated with the
                    // entry to this state
                    Motor_Stop();
                    printf("I am STOP");
                    //printf("\n\nREADY TO FOLLOW TAPE\n\n");

                    ES_Timer_InitTimer(2, 500);
                    myTape = GetTapeSensorState();
                    printf("Current Tape: %x\n", myTape);

//                    if (myTape.tape16 == 0){
//                        ES_Timer_InitTimer(2, 200);
//                        Motor_Turn(TANK, RIGHT, 7);
//                    }else if (myTape.tape16 == 1){
//                        ES_Timer_InitTimer(2, 250);
//                        Motor_EvadeRight(7);
//                    }else if (myTape.tape16 == 10){
//                        ES_Timer_InitTimer(2, 250);
//                        Motor_EvadeRight(7);
//                    }else if (myTape.tape16 == 20){
//                        ES_Timer_InitTimer(2, 250);
//                        Motor_Turn(TANK, LEFT, 7);
//                    }else if
                            
                    if(myTape.leftLeftTape == 1 && myTape.centerFrontTape == 1 && myTape.centerBackTape == 1){ //hit corner
                        ES_Timer_InitTimer(2, 400);
                        Motor_Turn(PIVOT, LEFT, 7);
                        printf("PIVOT LEFT 400\n");
                    }else if(myTape.leftMiddleTape == 1 && myTape.centerFrontTape == 1 && myTape.rightMiddleTape == 1){ //all 3 center on
                        ES_Timer_InitTimer(2, 100);
                        Motor_Turn(TANK, LEFT, 7);
                        printf("TANK LEFT 100\n");
                    }else if (myTape.centerFrontTape == 1){ //just center and one other
                        if(myTape.leftMiddleTape == 1){
                            ES_Timer_InitTimer(2, 300);
                            Motor_Turn(SLIGHT, LEFT, 7);
                            printf("SLIGHT LEFT 300\n");
                        }else if(myTape.rightMiddleTape == 1){
                            ES_Timer_InitTimer(2, 300);
                            Motor_Turn(SLIGHT, RIGHT, 7);
                            printf("SLIGHT RIGHT 300\n");
                        }else{
                            ES_Timer_InitTimer(2, 300);
                            Motor_ForwardStraight(8);
                            printf("FWD Straight 500\n");
                        }
                    }else if(myTape.centerFrontTape == 0){ //center off
                        if(myTape.leftMiddleTape == 1){
                            ES_Timer_InitTimer(2, 300);
                            Motor_Turn(PIVOT, LEFT, 7);
                            printf("PIVOT LEFT 300\n");
                        }else if(myTape.rightMiddleTape == 1){
                            ES_Timer_InitTimer(2, 300);
                            Motor_Turn(PIVOT, RIGHT, 7);
                            printf("PIVOT RIGHT 300\n");
                        }
                    }else if (myTape.tape16 == 1){  //none of the middle 3 on
                        ES_Timer_InitTimer(2, 500);
                        Motor_EvadeLeft(8);
                        printf("EVADE LEFT 500\n");
                    }else if (myTape.tape16 == 10){
                        ES_Timer_InitTimer(2, 300);
                        printf("EVADE RIGHT 300\n");
                        Motor_EvadeRight(8);
                    }else{
                        ES_Timer_InitTimer(2, 100);
                        Motor_Turn(TANK, LEFT, 7);
                    }
                    break;
                case BUMPED:
                    break;
                case ES_EXIT:
                    // this is where you would put any actions associated with the
                    // exit from this state
                    break;

                case ES_TIMEOUT:
                    // create the case statement for all other events that you are
                    // interested in responding to. This one does a transition
                    nextState = RidingTape;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                default: // all unhandled events pass the event back up to the next level
                    break;
            }

        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunFoundTapeSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunFoundTapeSubHSM(ENTRY_EVENT); // <- rename to your own Run function
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

#ifdef FoundTapeSUBHSM_TEST // <-- change this name and define it in your MPLAB-X
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

#endif // FoundTapeSUBHSM_TEST

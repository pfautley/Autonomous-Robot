/*
 * File: GyroService.h
 * Author: Gabriel H Elkaim
 *
 * File provides synchronous sampling of a single tape sensor without averaging
 * that is performed every SYNCRO_SAMPLE_PERIOD msec using a simple service.
 *
 * This is a solution to problem 9 on CMPE-118 F2015 Midterm
 *
 * Created on 23/Oct/2011
 * Updated on 21/Nov/2015
 */

#ifndef SYNCHRO_SAMPLING_SERVICE_H  // <- This should be changed to your own guard on both
#define SYNCHRO_SAMPLING_SERVICE_H  //    of these lines


/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT
#include "IO_Ports.h"
#include "AD.h"

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
#define TAPELL_SENSOR_ADC_PIN AD_PORTV3
#define TAPELM_SENSOR_ADC_PIN AD_PORTV4
#define TAPEFC_SENSOR_ADC_PIN AD_PORTV5
#define TAPERM_SENSOR_ADC_PIN AD_PORTV6
#define TAPERR_SENSOR_ADC_PIN AD_PORTV7
#define TAPEBC_SENSOR_ADC_PIN AD_PORTW3
#define TAPEBL_SENSOR_ADC_PIN AD_PORTW4 /*USE AN AD PIN*/
#define TAPEBR_SENSOR_ADC_PIN AD_PORTW6 /*USE AN AD PIN*/


#define TAPELL_LED_TRIS PORTX03_TRIS
#define TAPELL_LED_PIN PORTX03_LAT

#define TAPELM_LED_TRIS PORTX04_TRIS
#define TAPELM_LED_PIN PORTX04_LAT

#define TAPEFC_LED_TRIS PORTX05_TRIS
#define TAPEFC_LED_PIN PORTX05_LAT

#define TAPERM_LED_TRIS PORTX06_TRIS
#define TAPERM_LED_PIN PORTX06_LAT

#define TAPERR_LED_TRIS PORTX07_TRIS
#define TAPERR_LED_PIN PORTX07_LAT

#define TAPEBC_LED_TRIS PORTX08_TRIS
#define TAPEBC_LED_PIN PORTX08_LAT

//#define TAPEBL_LED_TRIS PORTX08_TRIS    /*USE an X PORT PIN*/
//#define TAPEBL_LED_PIN PORTX08_LAT
//
//#define TAPEBR_LED_TRIS PORTX08_TRIS /*USE AN X PORT PIN*/
//#define TAPEBR_LED_PIN PORTX08_LAT

#define LED_ON 0
#define LED_OFF 1

#define SYNCHRO_TIMER 5

#define SYNCHRO_SAMPLE_PERIOD 5 // time in ms between gyro samples
#define TAPE_THRESHOLD 815  // value for difference when on tape 800
#define WHITE_THRESHOLD 300  // value for difference when on white backround 300

#define ON_TAPE 1
#define OFF_TAPE 0

/*******************************************************************************
 * PUBLIC TYPEDEFS                                                             *
 ******************************************************************************/

typedef union {
	struct {
		unsigned leftLeftTape : 1;
		unsigned leftMiddleTape : 1;
		unsigned centerFrontTape : 1;
		unsigned rightMiddleTape : 1;
		unsigned rightRightTape : 1;
		unsigned centerBackTape : 1;
                unsigned leftBackTape : 1;
                unsigned rightBackTape : 1;
		unsigned : 8;
	};
	unsigned short int tape16;
} tape16_t;

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/

//tape16_t myTape;
//
//myTape = (tape16_t) ThisEvent.EventParam;
 
/**
 * @Function InitSynchroSamplingService(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunSynchroSamplingService function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H. Elkaim, 2015.11.08 20:25 */
uint8_t InitSynchroSamplingService(uint8_t Priority);

/**
 * @Function PostSynchroSamplingService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H. Elkaim, 2015.11.08 20:25 */
uint8_t PostSynchroSamplingService(ES_Event ThisEvent);

/**
 * @Function RunSynchroSamplingService(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function will be called periodically (#defined) and will read
 *        the last ADC value for the tape sensor, coordinating when the LEDs are ON
 *        and when the LEDs are off to remove the background and check for an event.
 *       Returns ES_NO_EVENT if the event have been "consumed." 
 * @author Gabriel H. Elkaim, 2015.11.08 20:25 */
ES_Event RunSynchroSamplingService(ES_Event ThisEvent);

/**
 * @Function GetTapeSensorState()
 * @param none
 * @return ON_TAPE or OFF_TAPE
 * @brief This function is a wrapper to the module level variable that keeps track
 *        of the tape state for other service functions. This would be modified to
 *        return a bit for each tape sensor used
 */
tape16_t GetTapeSensorState(void);



#endif /* SYNCHRO_SAMPLING_SERVICE_H */


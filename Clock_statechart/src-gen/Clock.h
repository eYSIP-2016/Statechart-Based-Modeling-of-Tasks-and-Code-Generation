
#ifndef CLOCK_H_
#define CLOCK_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'clock'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Clock__0_Display,
	Clock__0_Display_r1_DisplayHour,
	Clock__0_Display_r1_DisplayMinutes,
	Clock__0_Set,
	Clock__0_Set_r1_SetHour,
	Clock__0_Set_r1_SetMinutes,
	Clock_last_state
} ClockStates;

/*! Type definition of the data structure for the ClockIface interface scope. */
typedef struct
{
	sc_boolean mode_raised;
	sc_boolean set_raised;
	sc_integer time;
	sc_integer hour;
	sc_integer min;
	sc_integer sec;
} ClockIface;

/*! Type definition of the data structure for the ClockTimeEvents interface scope. */
typedef struct
{
	sc_boolean clock_tev0_raised;
} ClockTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define CLOCK_MAX_ORTHOGONAL_STATES 1
	/*! Define dimension of the state configuration vector for history states. */
#define CLOCK_MAX_HISTORY_STATES 1

/*! 
 * Type definition of the data structure for the Clock state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	ClockStates stateConfVector[CLOCK_MAX_ORTHOGONAL_STATES];
	ClockStates historyVector[CLOCK_MAX_HISTORY_STATES];
	sc_ushort stateConfVectorPosition; 
	
	ClockIface iface;
	ClockTimeEvents timeEvents;
} Clock;

/*! Initializes the Clock state machine data structures. Must be called before first usage.*/
extern void clock_init(Clock* handle);

/*! Activates the state machine */
extern void clock_enter(Clock* handle);

/*! Deactivates the state machine */
extern void clock_exit(Clock* handle);

/*! Performs a 'run to completion' step. */
extern void clock_runCycle(Clock* handle);

/*! Raises a time event. */
extern void clock_raiseTimeEvent(const Clock* handle, sc_eventid evid);

/*! Raises the in event 'mode' that is defined in the default interface scope. */ 
extern void clockIface_raise_mode(Clock* handle);

/*! Raises the in event 'set' that is defined in the default interface scope. */ 
extern void clockIface_raise_set(Clock* handle);

/*! Gets the value of the variable 'time' that is defined in the default interface scope. */ 
extern sc_integer clockIface_get_time(const Clock* handle);
/*! Sets the value of the variable 'time' that is defined in the default interface scope. */ 
extern void clockIface_set_time(Clock* handle, sc_integer value);
/*! Gets the value of the variable 'hour' that is defined in the default interface scope. */ 
extern sc_integer clockIface_get_hour(const Clock* handle);
/*! Sets the value of the variable 'hour' that is defined in the default interface scope. */ 
extern void clockIface_set_hour(Clock* handle, sc_integer value);
/*! Gets the value of the variable 'min' that is defined in the default interface scope. */ 
extern sc_integer clockIface_get_min(const Clock* handle);
/*! Sets the value of the variable 'min' that is defined in the default interface scope. */ 
extern void clockIface_set_min(Clock* handle, sc_integer value);
/*! Gets the value of the variable 'sec' that is defined in the default interface scope. */ 
extern sc_integer clockIface_get_sec(const Clock* handle);
/*! Sets the value of the variable 'sec' that is defined in the default interface scope. */ 
extern void clockIface_set_sec(Clock* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean clock_isActive(const Clock* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean clock_isFinal(const Clock* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean clock_isStateActive(const Clock* handle, ClockStates state);

#ifdef __cplusplus
}
#endif 

#endif /* CLOCK_H_ */

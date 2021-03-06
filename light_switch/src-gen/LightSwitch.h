
#ifndef LIGHTSWITCH_H_
#define LIGHTSWITCH_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'LightSwitch'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	LightSwitch__region0_No_obstacle_detected,
	LightSwitch_last_state
} LightSwitchStates;

/*! Type definition of the data structure for the LightSwitchIface interface scope. */
typedef struct
{
	sc_integer speed;
} LightSwitchIface;

/*! Type definition of the data structure for the LightSwitchTimeEvents interface scope. */
typedef struct
{
	sc_boolean lightSwitch__region0_No_obstacle_detected_tev0_raised;
} LightSwitchTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define LIGHTSWITCH_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the LightSwitch state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	LightSwitchStates stateConfVector[LIGHTSWITCH_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	LightSwitchIface iface;
	LightSwitchTimeEvents timeEvents;
} LightSwitch;

/*! Initializes the LightSwitch state machine data structures. Must be called before first usage.*/
extern void lightSwitch_init(LightSwitch* handle);

/*! Activates the state machine */
extern void lightSwitch_enter(LightSwitch* handle);

/*! Deactivates the state machine */
extern void lightSwitch_exit(LightSwitch* handle);

/*! Performs a 'run to completion' step. */
extern void lightSwitch_runCycle(LightSwitch* handle);

/*! Raises a time event. */
extern void lightSwitch_raiseTimeEvent(const LightSwitch* handle, sc_eventid evid);

/*! Gets the value of the variable 'speed' that is defined in the default interface scope. */ 
extern sc_integer lightSwitchIface_get_speed(const LightSwitch* handle);
/*! Sets the value of the variable 'speed' that is defined in the default interface scope. */ 
extern void lightSwitchIface_set_speed(LightSwitch* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean lightSwitch_isActive(const LightSwitch* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean lightSwitch_isFinal(const LightSwitch* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean lightSwitch_isStateActive(const LightSwitch* handle, LightSwitchStates state);

#ifdef __cplusplus
}
#endif 

#endif /* LIGHTSWITCH_H_ */

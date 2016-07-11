
#ifndef WATER_LEVEL_CONTROLLER_H_
#define WATER_LEVEL_CONTROLLER_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'water_level_controller'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Water_level_controller_main_region_motor__off_,
	Water_level_controller_main_region_motor__on_,
	Water_level_controller_last_state
} Water_level_controllerStates;

/*! Type definition of the data structure for the Water_level_controllerIface interface scope. */
typedef struct
{
	sc_integer water_level;
	sc_integer max_water_level;
} Water_level_controllerIface;

/*! Type definition of the data structure for the Water_level_controllerTimeEvents interface scope. */
typedef struct
{
	sc_boolean water_level_controller_main_region_motor__on__tev0_raised;
} Water_level_controllerTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define WATER_LEVEL_CONTROLLER_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the Water_level_controller state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Water_level_controllerStates stateConfVector[WATER_LEVEL_CONTROLLER_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Water_level_controllerIface iface;
	Water_level_controllerTimeEvents timeEvents;
} Water_level_controller;

/*! Initializes the Water_level_controller state machine data structures. Must be called before first usage.*/
extern void water_level_controller_init(Water_level_controller* handle);

/*! Activates the state machine */
extern void water_level_controller_enter(Water_level_controller* handle);

/*! Deactivates the state machine */
extern void water_level_controller_exit(Water_level_controller* handle);

/*! Performs a 'run to completion' step. */
extern void water_level_controller_runCycle(Water_level_controller* handle);

/*! Raises a time event. */
extern void water_level_controller_raiseTimeEvent(const Water_level_controller* handle, sc_eventid evid);

/*! Gets the value of the variable 'water_level' that is defined in the default interface scope. */ 
extern sc_integer water_level_controllerIface_get_water_level(const Water_level_controller* handle);
/*! Sets the value of the variable 'water_level' that is defined in the default interface scope. */ 
extern void water_level_controllerIface_set_water_level(Water_level_controller* handle, sc_integer value);
/*! Gets the value of the variable 'max_water_level' that is defined in the default interface scope. */ 
extern sc_integer water_level_controllerIface_get_max_water_level(const Water_level_controller* handle);
/*! Sets the value of the variable 'max_water_level' that is defined in the default interface scope. */ 
extern void water_level_controllerIface_set_max_water_level(Water_level_controller* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean water_level_controller_isActive(const Water_level_controller* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean water_level_controller_isFinal(const Water_level_controller* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean water_level_controller_isStateActive(const Water_level_controller* handle, Water_level_controllerStates state);

#ifdef __cplusplus
}
#endif 

#endif /* WATER_LEVEL_CONTROLLER_H_ */

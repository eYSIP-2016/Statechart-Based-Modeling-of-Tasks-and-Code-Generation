
#ifndef ELEVATOR_H_
#define ELEVATOR_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'elevator'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Elevator_main_region_Doors_Open,
	Elevator_main_region_DoorsClosed,
	Elevator_main_region_moving,
	Elevator_main_region_moving_r1_MovingUp,
	Elevator_main_region_moving_r1_MovingDown,
	Elevator_last_state
} ElevatorStates;

/*! Type definition of the data structure for the ElevatorIface interface scope. */
typedef struct
{
	sc_integer floor;
	sc_integer current;
	sc_boolean open;
	sc_boolean floorSelected_raised;
} ElevatorIface;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define ELEVATOR_MAX_ORTHOGONAL_STATES 1

/*! 
 * Type definition of the data structure for the Elevator state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	ElevatorStates stateConfVector[ELEVATOR_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	ElevatorIface iface;
} Elevator;

/*! Initializes the Elevator state machine data structures. Must be called before first usage.*/
extern void elevator_init(Elevator* handle);

/*! Activates the state machine */
extern void elevator_enter(Elevator* handle);

/*! Deactivates the state machine */
extern void elevator_exit(Elevator* handle);

/*! Performs a 'run to completion' step. */
extern void elevator_runCycle(Elevator* handle);


/*! Gets the value of the variable 'floor' that is defined in the default interface scope. */ 
extern sc_integer elevatorIface_get_floor(const Elevator* handle);
/*! Sets the value of the variable 'floor' that is defined in the default interface scope. */ 
extern void elevatorIface_set_floor(Elevator* handle, sc_integer value);
/*! Gets the value of the variable 'current' that is defined in the default interface scope. */ 
extern sc_integer elevatorIface_get_current(const Elevator* handle);
/*! Sets the value of the variable 'current' that is defined in the default interface scope. */ 
extern void elevatorIface_set_current(Elevator* handle, sc_integer value);
/*! Gets the value of the variable 'open' that is defined in the default interface scope. */ 
extern sc_boolean elevatorIface_get_open(const Elevator* handle);
/*! Sets the value of the variable 'open' that is defined in the default interface scope. */ 
extern void elevatorIface_set_open(Elevator* handle, sc_boolean value);
/*! Raises the in event 'floorSelected' that is defined in the default interface scope. */ 
extern void elevatorIface_raise_floorSelected(Elevator* handle);


/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean elevator_isActive(const Elevator* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean elevator_isFinal(const Elevator* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean elevator_isStateActive(const Elevator* handle, ElevatorStates state);

#ifdef __cplusplus
}
#endif 

#endif /* ELEVATOR_H_ */

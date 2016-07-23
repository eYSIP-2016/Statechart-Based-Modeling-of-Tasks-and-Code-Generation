
#ifndef ELEVATORREQUIRED_H_
#define ELEVATORREQUIRED_H_

#include "..\src\sc_types.h"
#include "Elevator.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- elevatorIface_openDoors
	- elevatorIface_closeDoors
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void elevatorIface_openDoors(const Elevator* handle);
extern void elevatorIface_closeDoors(const Elevator* handle);




#ifdef __cplusplus
}
#endif 

#endif /* ELEVATORREQUIRED_H_ */

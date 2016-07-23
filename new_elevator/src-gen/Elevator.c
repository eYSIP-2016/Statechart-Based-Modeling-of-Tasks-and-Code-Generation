
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "Elevator.h"
#include "ElevatorRequired.h"
/*! \file Implementation of the state machine 'elevator'
*/

/* prototypes of all internal functions */
static sc_boolean elevator_check_main_region_Doors_Open_tr0_tr0(const Elevator* handle);
static sc_boolean elevator_check_main_region_DoorsClosed_tr0_tr0(const Elevator* handle);
static sc_boolean elevator_check_main_region_DoorsClosed_tr1_tr1(const Elevator* handle);
static sc_boolean elevator_check_main_region_moving_tr0_tr0(const Elevator* handle);
static sc_boolean elevator_check_main_region_moving_r1_MovingUp_tr0_tr0(const Elevator* handle);
static sc_boolean elevator_check_main_region_moving_r1_MovingDown_tr0_tr0(const Elevator* handle);
static void elevator_effect_main_region_Doors_Open_tr0(Elevator* handle);
static void elevator_effect_main_region_DoorsClosed_tr0(Elevator* handle);
static void elevator_effect_main_region_DoorsClosed_tr1(Elevator* handle);
static void elevator_effect_main_region_moving_tr0(Elevator* handle);
static void elevator_effect_main_region_moving_r1_MovingUp_tr0(Elevator* handle);
static void elevator_effect_main_region_moving_r1_MovingDown_tr0(Elevator* handle);
static void elevator_enact_main_region_DoorsClosed(Elevator* handle);
static void elevator_enact_main_region_moving_r1_MovingUp(Elevator* handle);
static void elevator_enact_main_region_moving_r1_MovingDown(Elevator* handle);
static void elevator_enseq_main_region_Doors_Open_default(Elevator* handle);
static void elevator_enseq_main_region_DoorsClosed_default(Elevator* handle);
static void elevator_enseq_main_region_moving_r1_MovingUp_default(Elevator* handle);
static void elevator_enseq_main_region_moving_r1_MovingDown_default(Elevator* handle);
static void elevator_enseq_main_region_default(Elevator* handle);
static void elevator_exseq_main_region_Doors_Open(Elevator* handle);
static void elevator_exseq_main_region_DoorsClosed(Elevator* handle);
static void elevator_exseq_main_region_moving(Elevator* handle);
static void elevator_exseq_main_region_moving_r1_MovingUp(Elevator* handle);
static void elevator_exseq_main_region_moving_r1_MovingDown(Elevator* handle);
static void elevator_exseq_main_region(Elevator* handle);
static void elevator_exseq_main_region_moving_r1(Elevator* handle);
static void elevator_react_main_region_Doors_Open(Elevator* handle);
static void elevator_react_main_region_DoorsClosed(Elevator* handle);
static void elevator_react_main_region_moving_r1_MovingUp(Elevator* handle);
static void elevator_react_main_region_moving_r1_MovingDown(Elevator* handle);
static void elevator_react_main_region__entry_Default(Elevator* handle);
static void elevator_clearInEvents(Elevator* handle);
static void elevator_clearOutEvents(Elevator* handle);


void elevator_init(Elevator* handle)
{
	sc_integer i;

	for (i = 0; i < ELEVATOR_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Elevator_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	elevator_clearInEvents(handle);
	elevator_clearOutEvents(handle);

	/* Default init sequence for statechart elevator */
	handle->iface.floor = 0;
	handle->iface.current = 0;
	handle->iface.open = bool_false;

}

void elevator_enter(Elevator* handle)
{
	/* Default enter sequence for statechart elevator */
	elevator_enseq_main_region_default(handle);
}

void elevator_exit(Elevator* handle)
{
	/* Default exit sequence for statechart elevator */
	elevator_exseq_main_region(handle);
}

sc_boolean elevator_isActive(const Elevator* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Elevator_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean elevator_isFinal(const Elevator* handle)
{
   return bool_false;
}

static void elevator_clearInEvents(Elevator* handle)
{
	handle->iface.floorSelected_raised = bool_false;
}

static void elevator_clearOutEvents(Elevator* handle)
{
}

void elevator_runCycle(Elevator* handle)
{
	
	elevator_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < ELEVATOR_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Elevator_main_region_Doors_Open :
		{
			elevator_react_main_region_Doors_Open(handle);
			break;
		}
		case Elevator_main_region_DoorsClosed :
		{
			elevator_react_main_region_DoorsClosed(handle);
			break;
		}
		case Elevator_main_region_moving_r1_MovingUp :
		{
			elevator_react_main_region_moving_r1_MovingUp(handle);
			break;
		}
		case Elevator_main_region_moving_r1_MovingDown :
		{
			elevator_react_main_region_moving_r1_MovingDown(handle);
			break;
		}
		default:
			break;
		}
	}
	
	elevator_clearInEvents(handle);
}


sc_boolean elevator_isStateActive(const Elevator* handle, ElevatorStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Elevator_main_region_Doors_Open :
			result = (sc_boolean) (handle->stateConfVector[0] == Elevator_main_region_Doors_Open
			);
			break;
		case Elevator_main_region_DoorsClosed :
			result = (sc_boolean) (handle->stateConfVector[0] == Elevator_main_region_DoorsClosed
			);
			break;
		case Elevator_main_region_moving :
			result = (sc_boolean) (handle->stateConfVector[0] >= Elevator_main_region_moving
				&& handle->stateConfVector[0] <= Elevator_main_region_moving_r1_MovingDown);
			break;
		case Elevator_main_region_moving_r1_MovingUp :
			result = (sc_boolean) (handle->stateConfVector[0] == Elevator_main_region_moving_r1_MovingUp
			);
			break;
		case Elevator_main_region_moving_r1_MovingDown :
			result = (sc_boolean) (handle->stateConfVector[0] == Elevator_main_region_moving_r1_MovingDown
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void elevatorIface_raise_floorSelected(Elevator* handle)
{
	handle->iface.floorSelected_raised = bool_true;
}


sc_integer elevatorIface_get_floor(const Elevator* handle)
{
	return handle->iface.floor;
}
void elevatorIface_set_floor(Elevator* handle, sc_integer value)
{
	handle->iface.floor = value;
}
sc_integer elevatorIface_get_current(const Elevator* handle)
{
	return handle->iface.current;
}
void elevatorIface_set_current(Elevator* handle, sc_integer value)
{
	handle->iface.current = value;
}
sc_boolean elevatorIface_get_open(const Elevator* handle)
{
	return handle->iface.open;
}
void elevatorIface_set_open(Elevator* handle, sc_boolean value)
{
	handle->iface.open = value;
}

/* implementations of all internal functions */

static sc_boolean elevator_check_main_region_Doors_Open_tr0_tr0(const Elevator* handle)
{
	return ((handle->iface.floorSelected_raised) && (handle->iface.floor != handle->iface.current)) ? bool_true : bool_false;
}

static sc_boolean elevator_check_main_region_DoorsClosed_tr0_tr0(const Elevator* handle)
{
	return (handle->iface.floor > handle->iface.current) ? bool_true : bool_false;
}

static sc_boolean elevator_check_main_region_DoorsClosed_tr1_tr1(const Elevator* handle)
{
	return (handle->iface.floor < handle->iface.current || handle->iface.floor > 0) ? bool_true : bool_false;
}

static sc_boolean elevator_check_main_region_moving_tr0_tr0(const Elevator* handle)
{
	return (handle->iface.floor == handle->iface.current) ? bool_true : bool_false;
}

static sc_boolean elevator_check_main_region_moving_r1_MovingUp_tr0_tr0(const Elevator* handle)
{
	return (handle->iface.floor > handle->iface.current) ? bool_true : bool_false;
}

static sc_boolean elevator_check_main_region_moving_r1_MovingDown_tr0_tr0(const Elevator* handle)
{
	return (handle->iface.floor < handle->iface.current) ? bool_true : bool_false;
}

static void elevator_effect_main_region_Doors_Open_tr0(Elevator* handle)
{
	elevator_exseq_main_region_Doors_Open(handle);
	elevatorIface_closeDoors(handle);
	elevator_enseq_main_region_DoorsClosed_default(handle);
}

static void elevator_effect_main_region_DoorsClosed_tr0(Elevator* handle)
{
	elevator_exseq_main_region_DoorsClosed(handle);
	elevator_enseq_main_region_moving_r1_MovingUp_default(handle);
}

static void elevator_effect_main_region_DoorsClosed_tr1(Elevator* handle)
{
	elevator_exseq_main_region_DoorsClosed(handle);
	elevator_enseq_main_region_moving_r1_MovingDown_default(handle);
}

static void elevator_effect_main_region_moving_tr0(Elevator* handle)
{
	elevator_exseq_main_region_moving(handle);
	elevatorIface_openDoors(handle);
	elevator_enseq_main_region_Doors_Open_default(handle);
}

static void elevator_effect_main_region_moving_r1_MovingUp_tr0(Elevator* handle)
{
	elevator_exseq_main_region_moving_r1_MovingUp(handle);
	elevator_enseq_main_region_moving_r1_MovingUp_default(handle);
}

static void elevator_effect_main_region_moving_r1_MovingDown_tr0(Elevator* handle)
{
	elevator_exseq_main_region_moving_r1_MovingDown(handle);
	elevator_enseq_main_region_moving_r1_MovingDown_default(handle);
}

/* Entry action for state 'DoorsClosed'. */
static void elevator_enact_main_region_DoorsClosed(Elevator* handle)
{
	/* Entry action for state 'DoorsClosed'. */
	handle->iface.open = bool_false;
}

/* Entry action for state 'MovingUp'. */
static void elevator_enact_main_region_moving_r1_MovingUp(Elevator* handle)
{
	/* Entry action for state 'MovingUp'. */
	handle->iface.current = handle->iface.current + 1;
}

/* Entry action for state 'MovingDown'. */
static void elevator_enact_main_region_moving_r1_MovingDown(Elevator* handle)
{
	/* Entry action for state 'MovingDown'. */
	handle->iface.current = handle->iface.current - 1;
}

/* 'default' enter sequence for state Doors Open */
static void elevator_enseq_main_region_Doors_Open_default(Elevator* handle)
{
	/* 'default' enter sequence for state Doors Open */
	handle->stateConfVector[0] = Elevator_main_region_Doors_Open;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state DoorsClosed */
static void elevator_enseq_main_region_DoorsClosed_default(Elevator* handle)
{
	/* 'default' enter sequence for state DoorsClosed */
	elevator_enact_main_region_DoorsClosed(handle);
	handle->stateConfVector[0] = Elevator_main_region_DoorsClosed;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state MovingUp */
static void elevator_enseq_main_region_moving_r1_MovingUp_default(Elevator* handle)
{
	/* 'default' enter sequence for state MovingUp */
	elevator_enact_main_region_moving_r1_MovingUp(handle);
	handle->stateConfVector[0] = Elevator_main_region_moving_r1_MovingUp;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state MovingDown */
static void elevator_enseq_main_region_moving_r1_MovingDown_default(Elevator* handle)
{
	/* 'default' enter sequence for state MovingDown */
	elevator_enact_main_region_moving_r1_MovingDown(handle);
	handle->stateConfVector[0] = Elevator_main_region_moving_r1_MovingDown;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void elevator_enseq_main_region_default(Elevator* handle)
{
	/* 'default' enter sequence for region main region */
	elevator_react_main_region__entry_Default(handle);
}

/* Default exit sequence for state Doors Open */
static void elevator_exseq_main_region_Doors_Open(Elevator* handle)
{
	/* Default exit sequence for state Doors Open */
	handle->stateConfVector[0] = Elevator_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state DoorsClosed */
static void elevator_exseq_main_region_DoorsClosed(Elevator* handle)
{
	/* Default exit sequence for state DoorsClosed */
	handle->stateConfVector[0] = Elevator_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state moving */
static void elevator_exseq_main_region_moving(Elevator* handle)
{
	/* Default exit sequence for state moving */
	elevator_exseq_main_region_moving_r1(handle);
}

/* Default exit sequence for state MovingUp */
static void elevator_exseq_main_region_moving_r1_MovingUp(Elevator* handle)
{
	/* Default exit sequence for state MovingUp */
	handle->stateConfVector[0] = Elevator_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state MovingDown */
static void elevator_exseq_main_region_moving_r1_MovingDown(Elevator* handle)
{
	/* Default exit sequence for state MovingDown */
	handle->stateConfVector[0] = Elevator_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region main region */
static void elevator_exseq_main_region(Elevator* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of elevator.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Elevator_main_region_Doors_Open :
		{
			elevator_exseq_main_region_Doors_Open(handle);
			break;
		}
		case Elevator_main_region_DoorsClosed :
		{
			elevator_exseq_main_region_DoorsClosed(handle);
			break;
		}
		case Elevator_main_region_moving_r1_MovingUp :
		{
			elevator_exseq_main_region_moving_r1_MovingUp(handle);
			break;
		}
		case Elevator_main_region_moving_r1_MovingDown :
		{
			elevator_exseq_main_region_moving_r1_MovingDown(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void elevator_exseq_main_region_moving_r1(Elevator* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of elevator.main_region.moving.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Elevator_main_region_moving_r1_MovingUp :
		{
			elevator_exseq_main_region_moving_r1_MovingUp(handle);
			break;
		}
		case Elevator_main_region_moving_r1_MovingDown :
		{
			elevator_exseq_main_region_moving_r1_MovingDown(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state Doors Open. */
static void elevator_react_main_region_Doors_Open(Elevator* handle)
{
	/* The reactions of state Doors Open. */
	if (elevator_check_main_region_Doors_Open_tr0_tr0(handle) == bool_true)
	{ 
		elevator_effect_main_region_Doors_Open_tr0(handle);
	} 
}

/* The reactions of state DoorsClosed. */
static void elevator_react_main_region_DoorsClosed(Elevator* handle)
{
	/* The reactions of state DoorsClosed. */
	if (elevator_check_main_region_DoorsClosed_tr0_tr0(handle) == bool_true)
	{ 
		elevator_effect_main_region_DoorsClosed_tr0(handle);
	}  else
	{
		if (elevator_check_main_region_DoorsClosed_tr1_tr1(handle) == bool_true)
		{ 
			elevator_effect_main_region_DoorsClosed_tr1(handle);
		} 
	}
}

/* The reactions of state MovingUp. */
static void elevator_react_main_region_moving_r1_MovingUp(Elevator* handle)
{
	/* The reactions of state MovingUp. */
	if (elevator_check_main_region_moving_tr0_tr0(handle) == bool_true)
	{ 
		elevator_effect_main_region_moving_tr0(handle);
	}  else
	{
		if (elevator_check_main_region_moving_r1_MovingUp_tr0_tr0(handle) == bool_true)
		{ 
			elevator_effect_main_region_moving_r1_MovingUp_tr0(handle);
		} 
	}
}

/* The reactions of state MovingDown. */
static void elevator_react_main_region_moving_r1_MovingDown(Elevator* handle)
{
	/* The reactions of state MovingDown. */
	if (elevator_check_main_region_moving_tr0_tr0(handle) == bool_true)
	{ 
		elevator_effect_main_region_moving_tr0(handle);
	}  else
	{
		if (elevator_check_main_region_moving_r1_MovingDown_tr0_tr0(handle) == bool_true)
		{ 
			elevator_effect_main_region_moving_r1_MovingDown_tr0(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void elevator_react_main_region__entry_Default(Elevator* handle)
{
	/* Default react sequence for initial entry  */
	handle->iface.floor = 0;
	handle->iface.current = 0;
	elevator_enseq_main_region_Doors_Open_default(handle);
}



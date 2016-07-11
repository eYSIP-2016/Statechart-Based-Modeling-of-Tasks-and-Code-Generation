
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "Water_level_controller.h"
#include "Water_level_controllerRequired.h"
/*! \file Implementation of the state machine 'water_level_controller'
*/

/* prototypes of all internal functions */
static sc_boolean water_level_controller_check_main_region_motor__off__tr0_tr0(const Water_level_controller* handle);
static sc_boolean water_level_controller_check_main_region_motor__on__tr0_tr0(const Water_level_controller* handle);
static sc_boolean water_level_controller_check_main_region_motor__on__tr1_tr1(const Water_level_controller* handle);
static void water_level_controller_effect_main_region_motor__off__tr0(Water_level_controller* handle);
static void water_level_controller_effect_main_region_motor__on__tr0(Water_level_controller* handle);
static void water_level_controller_effect_main_region_motor__on__tr1(Water_level_controller* handle);
static void water_level_controller_enact_main_region_motor__on_(Water_level_controller* handle);
static void water_level_controller_exact_main_region_motor__on_(Water_level_controller* handle);
static void water_level_controller_enseq_main_region_motor__off__default(Water_level_controller* handle);
static void water_level_controller_enseq_main_region_motor__on__default(Water_level_controller* handle);
static void water_level_controller_enseq_main_region_default(Water_level_controller* handle);
static void water_level_controller_exseq_main_region_motor__off_(Water_level_controller* handle);
static void water_level_controller_exseq_main_region_motor__on_(Water_level_controller* handle);
static void water_level_controller_exseq_main_region(Water_level_controller* handle);
static void water_level_controller_react_main_region_motor__off_(Water_level_controller* handle);
static void water_level_controller_react_main_region_motor__on_(Water_level_controller* handle);
static void water_level_controller_react_main_region__entry_Default(Water_level_controller* handle);
static void water_level_controller_clearInEvents(Water_level_controller* handle);
static void water_level_controller_clearOutEvents(Water_level_controller* handle);


void water_level_controller_init(Water_level_controller* handle)
{
	sc_integer i;

	for (i = 0; i < WATER_LEVEL_CONTROLLER_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Water_level_controller_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	water_level_controller_clearInEvents(handle);
	water_level_controller_clearOutEvents(handle);

	/* Default init sequence for statechart water_level_controller */
	handle->iface.water_level = 1;
	handle->iface.max_water_level = 0;

}

void water_level_controller_enter(Water_level_controller* handle)
{
	/* Default enter sequence for statechart water_level_controller */
	water_level_controller_enseq_main_region_default(handle);
}

void water_level_controller_exit(Water_level_controller* handle)
{
	/* Default exit sequence for statechart water_level_controller */
	water_level_controller_exseq_main_region(handle);
}

sc_boolean water_level_controller_isActive(const Water_level_controller* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Water_level_controller_last_state)
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
sc_boolean water_level_controller_isFinal(const Water_level_controller* handle)
{
   return bool_false;
}

static void water_level_controller_clearInEvents(Water_level_controller* handle)
{
	handle->timeEvents.water_level_controller_main_region_motor__on__tev0_raised = bool_false;
}

static void water_level_controller_clearOutEvents(Water_level_controller* handle)
{
}

void water_level_controller_runCycle(Water_level_controller* handle)
{
	
	water_level_controller_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < WATER_LEVEL_CONTROLLER_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Water_level_controller_main_region_motor__off_ :
		{
			water_level_controller_react_main_region_motor__off_(handle);
			break;
		}
		case Water_level_controller_main_region_motor__on_ :
		{
			water_level_controller_react_main_region_motor__on_(handle);
			break;
		}
		default:
			break;
		}
	}
	
	water_level_controller_clearInEvents(handle);
}

void water_level_controller_raiseTimeEvent(const Water_level_controller* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(Water_level_controllerTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean water_level_controller_isStateActive(const Water_level_controller* handle, Water_level_controllerStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Water_level_controller_main_region_motor__off_ :
			result = (sc_boolean) (handle->stateConfVector[0] == Water_level_controller_main_region_motor__off_
			);
			break;
		case Water_level_controller_main_region_motor__on_ :
			result = (sc_boolean) (handle->stateConfVector[0] == Water_level_controller_main_region_motor__on_
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}



sc_integer water_level_controllerIface_get_water_level(const Water_level_controller* handle)
{
	return handle->iface.water_level;
}
void water_level_controllerIface_set_water_level(Water_level_controller* handle, sc_integer value)
{
	handle->iface.water_level = value;
}
sc_integer water_level_controllerIface_get_max_water_level(const Water_level_controller* handle)
{
	return handle->iface.max_water_level;
}
void water_level_controllerIface_set_max_water_level(Water_level_controller* handle, sc_integer value)
{
	handle->iface.max_water_level = value;
}

/* implementations of all internal functions */

static sc_boolean water_level_controller_check_main_region_motor__off__tr0_tr0(const Water_level_controller* handle)
{
	return (handle->iface.max_water_level > handle->iface.water_level) ? bool_true : bool_false;
}

static sc_boolean water_level_controller_check_main_region_motor__on__tr0_tr0(const Water_level_controller* handle)
{
	return (handle->iface.max_water_level == handle->iface.water_level) ? bool_true : bool_false;
}

static sc_boolean water_level_controller_check_main_region_motor__on__tr1_tr1(const Water_level_controller* handle)
{
	return handle->timeEvents.water_level_controller_main_region_motor__on__tev0_raised;
}

static void water_level_controller_effect_main_region_motor__off__tr0(Water_level_controller* handle)
{
	water_level_controller_exseq_main_region_motor__off_(handle);
	water_level_controller_enseq_main_region_motor__on__default(handle);
}

static void water_level_controller_effect_main_region_motor__on__tr0(Water_level_controller* handle)
{
	water_level_controller_exseq_main_region_motor__on_(handle);
	water_level_controller_enseq_main_region_motor__off__default(handle);
}

static void water_level_controller_effect_main_region_motor__on__tr1(Water_level_controller* handle)
{
	water_level_controller_exseq_main_region_motor__on_(handle);
	water_level_controller_enseq_main_region_motor__on__default(handle);
}

/* Entry action for state 'motor (on)'. */
static void water_level_controller_enact_main_region_motor__on_(Water_level_controller* handle)
{
	/* Entry action for state 'motor (on)'. */
	water_level_controller_setTimer(handle, (sc_eventid) &(handle->timeEvents.water_level_controller_main_region_motor__on__tev0_raised) , 2 * 1000, bool_true);
	handle->iface.water_level = handle->iface.water_level + 1;
}

/* Exit action for state 'motor (on)'. */
static void water_level_controller_exact_main_region_motor__on_(Water_level_controller* handle)
{
	/* Exit action for state 'motor (on)'. */
	water_level_controller_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.water_level_controller_main_region_motor__on__tev0_raised) );		
}

/* 'default' enter sequence for state motor (off) */
static void water_level_controller_enseq_main_region_motor__off__default(Water_level_controller* handle)
{
	/* 'default' enter sequence for state motor (off) */
	handle->stateConfVector[0] = Water_level_controller_main_region_motor__off_;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state motor (on) */
static void water_level_controller_enseq_main_region_motor__on__default(Water_level_controller* handle)
{
	/* 'default' enter sequence for state motor (on) */
	water_level_controller_enact_main_region_motor__on_(handle);
	handle->stateConfVector[0] = Water_level_controller_main_region_motor__on_;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void water_level_controller_enseq_main_region_default(Water_level_controller* handle)
{
	/* 'default' enter sequence for region main region */
	water_level_controller_react_main_region__entry_Default(handle);
}

/* Default exit sequence for state motor (off) */
static void water_level_controller_exseq_main_region_motor__off_(Water_level_controller* handle)
{
	/* Default exit sequence for state motor (off) */
	handle->stateConfVector[0] = Water_level_controller_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state motor (on) */
static void water_level_controller_exseq_main_region_motor__on_(Water_level_controller* handle)
{
	/* Default exit sequence for state motor (on) */
	handle->stateConfVector[0] = Water_level_controller_last_state;
	handle->stateConfVectorPosition = 0;
	water_level_controller_exact_main_region_motor__on_(handle);
}

/* Default exit sequence for region main region */
static void water_level_controller_exseq_main_region(Water_level_controller* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of water_level_controller.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Water_level_controller_main_region_motor__off_ :
		{
			water_level_controller_exseq_main_region_motor__off_(handle);
			break;
		}
		case Water_level_controller_main_region_motor__on_ :
		{
			water_level_controller_exseq_main_region_motor__on_(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state motor (off). */
static void water_level_controller_react_main_region_motor__off_(Water_level_controller* handle)
{
	/* The reactions of state motor (off). */
	if (water_level_controller_check_main_region_motor__off__tr0_tr0(handle) == bool_true)
	{ 
		water_level_controller_effect_main_region_motor__off__tr0(handle);
	} 
}

/* The reactions of state motor (on). */
static void water_level_controller_react_main_region_motor__on_(Water_level_controller* handle)
{
	/* The reactions of state motor (on). */
	if (water_level_controller_check_main_region_motor__on__tr0_tr0(handle) == bool_true)
	{ 
		water_level_controller_effect_main_region_motor__on__tr0(handle);
	}  else
	{
		if (water_level_controller_check_main_region_motor__on__tr1_tr1(handle) == bool_true)
		{ 
			water_level_controller_effect_main_region_motor__on__tr1(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void water_level_controller_react_main_region__entry_Default(Water_level_controller* handle)
{
	/* Default react sequence for initial entry  */
	water_level_controller_enseq_main_region_motor__off__default(handle);
}



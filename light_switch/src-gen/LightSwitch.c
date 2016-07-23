
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "LightSwitch.h"
#include "LightSwitchRequired.h"
/*! \file Implementation of the state machine 'LightSwitch'
*/

/* prototypes of all internal functions */
static sc_boolean lightSwitch_check__region0_No_obstacle_detected_tr0_tr0(const LightSwitch* handle);
static void lightSwitch_effect__region0_No_obstacle_detected_tr0(LightSwitch* handle);
static void lightSwitch_enact__region0_No_obstacle_detected(LightSwitch* handle);
static void lightSwitch_exact__region0_No_obstacle_detected(LightSwitch* handle);
static void lightSwitch_enseq__region0_No_obstacle_detected_default(LightSwitch* handle);
static void lightSwitch_enseq__region0_default(LightSwitch* handle);
static void lightSwitch_exseq__region0_No_obstacle_detected(LightSwitch* handle);
static void lightSwitch_exseq__region0(LightSwitch* handle);
static void lightSwitch_react__region0_No_obstacle_detected(LightSwitch* handle);
static void lightSwitch_react__region0__entry_Default(LightSwitch* handle);
static void lightSwitch_clearInEvents(LightSwitch* handle);
static void lightSwitch_clearOutEvents(LightSwitch* handle);


void lightSwitch_init(LightSwitch* handle)
{
	sc_integer i;

	for (i = 0; i < LIGHTSWITCH_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = LightSwitch_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	lightSwitch_clearInEvents(handle);
	lightSwitch_clearOutEvents(handle);

	/* Default init sequence for statechart LightSwitch */
	handle->iface.speed = 0;

}

void lightSwitch_enter(LightSwitch* handle)
{
	/* Default enter sequence for statechart LightSwitch */
	lightSwitch_enseq__region0_default(handle);
}

void lightSwitch_exit(LightSwitch* handle)
{
	/* Default exit sequence for statechart LightSwitch */
	lightSwitch_exseq__region0(handle);
}

sc_boolean lightSwitch_isActive(const LightSwitch* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != LightSwitch_last_state)
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
sc_boolean lightSwitch_isFinal(const LightSwitch* handle)
{
   return bool_false;
}

static void lightSwitch_clearInEvents(LightSwitch* handle)
{
	handle->timeEvents.lightSwitch__region0_No_obstacle_detected_tev0_raised = bool_false;
}

static void lightSwitch_clearOutEvents(LightSwitch* handle)
{
}

void lightSwitch_runCycle(LightSwitch* handle)
{
	
	lightSwitch_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < LIGHTSWITCH_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case LightSwitch__region0_No_obstacle_detected :
		{
			lightSwitch_react__region0_No_obstacle_detected(handle);
			break;
		}
		default:
			break;
		}
	}
	
	lightSwitch_clearInEvents(handle);
}

void lightSwitch_raiseTimeEvent(const LightSwitch* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(LightSwitchTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean lightSwitch_isStateActive(const LightSwitch* handle, LightSwitchStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case LightSwitch__region0_No_obstacle_detected :
			result = (sc_boolean) (handle->stateConfVector[0] == LightSwitch__region0_No_obstacle_detected
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}



sc_integer lightSwitchIface_get_speed(const LightSwitch* handle)
{
	return handle->iface.speed;
}
void lightSwitchIface_set_speed(LightSwitch* handle, sc_integer value)
{
	handle->iface.speed = value;
}

/* implementations of all internal functions */

static sc_boolean lightSwitch_check__region0_No_obstacle_detected_tr0_tr0(const LightSwitch* handle)
{
	return ((handle->timeEvents.lightSwitch__region0_No_obstacle_detected_tev0_raised) && (handle->iface.speed <= 10)) ? bool_true : bool_false;
}

static void lightSwitch_effect__region0_No_obstacle_detected_tr0(LightSwitch* handle)
{
	lightSwitch_exseq__region0_No_obstacle_detected(handle);
	lightSwitch_enseq__region0_No_obstacle_detected_default(handle);
}

/* Entry action for state 'No obstacle detected'. */
static void lightSwitch_enact__region0_No_obstacle_detected(LightSwitch* handle)
{
	/* Entry action for state 'No obstacle detected'. */
	lightSwitch_setTimer(handle, (sc_eventid) &(handle->timeEvents.lightSwitch__region0_No_obstacle_detected_tev0_raised) , 1 * 1000, bool_true);
	handle->iface.speed = handle->iface.speed + 1;
}

/* Exit action for state 'No obstacle detected'. */
static void lightSwitch_exact__region0_No_obstacle_detected(LightSwitch* handle)
{
	/* Exit action for state 'No obstacle detected'. */
	lightSwitch_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.lightSwitch__region0_No_obstacle_detected_tev0_raised) );		
}

/* 'default' enter sequence for state No obstacle detected */
static void lightSwitch_enseq__region0_No_obstacle_detected_default(LightSwitch* handle)
{
	/* 'default' enter sequence for state No obstacle detected */
	lightSwitch_enact__region0_No_obstacle_detected(handle);
	handle->stateConfVector[0] = LightSwitch__region0_No_obstacle_detected;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region null */
static void lightSwitch_enseq__region0_default(LightSwitch* handle)
{
	/* 'default' enter sequence for region null */
	lightSwitch_react__region0__entry_Default(handle);
}

/* Default exit sequence for state No obstacle detected */
static void lightSwitch_exseq__region0_No_obstacle_detected(LightSwitch* handle)
{
	/* Default exit sequence for state No obstacle detected */
	handle->stateConfVector[0] = LightSwitch_last_state;
	handle->stateConfVectorPosition = 0;
	lightSwitch_exact__region0_No_obstacle_detected(handle);
}

/* Default exit sequence for region null */
static void lightSwitch_exseq__region0(LightSwitch* handle)
{
	/* Default exit sequence for region null */
	/* Handle exit of all possible states (of LightSwitch._region0) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case LightSwitch__region0_No_obstacle_detected :
		{
			lightSwitch_exseq__region0_No_obstacle_detected(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state No obstacle detected. */
static void lightSwitch_react__region0_No_obstacle_detected(LightSwitch* handle)
{
	/* The reactions of state No obstacle detected. */
	if (lightSwitch_check__region0_No_obstacle_detected_tr0_tr0(handle) == bool_true)
	{ 
		lightSwitch_effect__region0_No_obstacle_detected_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void lightSwitch_react__region0__entry_Default(LightSwitch* handle)
{
	/* Default react sequence for initial entry  */
	lightSwitch_enseq__region0_No_obstacle_detected_default(handle);
}



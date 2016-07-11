
#include <stdlib.h>
#include <string.h>
#include "..\src\sc_types.h"
#include "Clock.h"
#include "ClockRequired.h"
/*! \file Implementation of the state machine 'clock'
*/

/* prototypes of all internal functions */
static sc_boolean clock_check__lr0(const Clock* handle);
static sc_boolean clock_check__0_Display_tr0_tr0(const Clock* handle);
static sc_boolean clock_check__0_Display_r1_DisplayHour_tr0_tr0(const Clock* handle);
static sc_boolean clock_check__0_Display_r1_DisplayMinutes_tr0_tr0(const Clock* handle);
static sc_boolean clock_check__0_Set_r1_SetHour_tr0_tr0(const Clock* handle);
static sc_boolean clock_check__0_Set_r1_SetHour_tr1_tr1(const Clock* handle);
static sc_boolean clock_check__0_Set_r1_SetMinutes_tr0_tr0(const Clock* handle);
static sc_boolean clock_check__0_Set_r1_SetMinutes_tr1_tr1(const Clock* handle);
static void clock_effect__lr0(Clock* handle);
static void clock_effect__0_Display_tr0(Clock* handle);
static void clock_effect__0_Display_r1_DisplayHour_tr0(Clock* handle);
static void clock_effect__0_Display_r1_DisplayMinutes_tr0(Clock* handle);
static void clock_effect__0_Set_r1_SetHour_tr0(Clock* handle);
static void clock_effect__0_Set_r1_SetHour_tr1(Clock* handle);
static void clock_effect__0_Set_r1_SetMinutes_tr0(Clock* handle);
static void clock_effect__0_Set_r1_SetMinutes_tr1(Clock* handle);
static void clock_enact(Clock* handle);
static void clock_exact(Clock* handle);
static void clock_enseq__0_Display_default(Clock* handle);
static void clock_enseq__0_Display_r1_DisplayHour_default(Clock* handle);
static void clock_enseq__0_Display_r1_DisplayMinutes_default(Clock* handle);
static void clock_enseq__0_Set_default(Clock* handle);
static void clock_enseq__0_Set_r1_SetHour_default(Clock* handle);
static void clock_enseq__0_Set_r1_SetMinutes_default(Clock* handle);
static void clock_enseq__0_default(Clock* handle);
static void clock_enseq__0_Display_r1_default(Clock* handle);
static void clock_shenseq__0_Display_r1(Clock* handle);
static void clock_enseq__0_Set_r1_default(Clock* handle);
static void clock_exseq__0_Display(Clock* handle);
static void clock_exseq__0_Display_r1_DisplayHour(Clock* handle);
static void clock_exseq__0_Display_r1_DisplayMinutes(Clock* handle);
static void clock_exseq__0_Set(Clock* handle);
static void clock_exseq__0_Set_r1_SetHour(Clock* handle);
static void clock_exseq__0_Set_r1_SetMinutes(Clock* handle);
static void clock_exseq__0(Clock* handle);
static void clock_exseq__0_Display_r1(Clock* handle);
static void clock_exseq__0_Set_r1(Clock* handle);
static void clock_react__0_Display_r1_DisplayHour(Clock* handle);
static void clock_react__0_Display_r1_DisplayMinutes(Clock* handle);
static void clock_react__0_Set_r1_SetHour(Clock* handle);
static void clock_react__0_Set_r1_SetMinutes(Clock* handle);
static void clock_react__0__entry_Default(Clock* handle);
static void clock_react__0_Display_r1__entry_Default(Clock* handle);
static void clock_react__0_Display_r1_his(Clock* handle);
static void clock_react__0_Set_r1__entry_Default(Clock* handle);
static void clock_clearInEvents(Clock* handle);
static void clock_clearOutEvents(Clock* handle);


void clock_init(Clock* handle)
{
	sc_integer i;

	for (i = 0; i < CLOCK_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Clock_last_state;
	}
	
	for (i = 0; i < CLOCK_MAX_HISTORY_STATES; ++i)
	{
		handle->historyVector[i] = Clock_last_state;
	}
	
	handle->stateConfVectorPosition = 0;

	clock_clearInEvents(handle);
	clock_clearOutEvents(handle);

	/* Default init sequence for statechart clock */
	handle->iface.time = 23 * 60 * 60 + 59 * 60 + 60;
	handle->iface.hour = 0;
	handle->iface.min = 0;
	handle->iface.sec = 0;

}

void clock_enter(Clock* handle)
{
	/* Default enter sequence for statechart clock */
	clock_enact(handle);
	clock_enseq__0_default(handle);
}

void clock_exit(Clock* handle)
{
	/* Default exit sequence for statechart clock */
	clock_exseq__0(handle);
	clock_exact(handle);
}

sc_boolean clock_isActive(const Clock* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Clock_last_state)
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
sc_boolean clock_isFinal(const Clock* handle)
{
   return bool_false;
}

static void clock_clearInEvents(Clock* handle)
{
	handle->iface.mode_raised = bool_false;
	handle->iface.set_raised = bool_false;
	handle->timeEvents.clock_tev0_raised = bool_false;
}

static void clock_clearOutEvents(Clock* handle)
{
}

void clock_runCycle(Clock* handle)
{
	
	clock_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < CLOCK_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Clock__0_Display_r1_DisplayHour :
		{
			clock_react__0_Display_r1_DisplayHour(handle);
			break;
		}
		case Clock__0_Display_r1_DisplayMinutes :
		{
			clock_react__0_Display_r1_DisplayMinutes(handle);
			break;
		}
		case Clock__0_Set_r1_SetHour :
		{
			clock_react__0_Set_r1_SetHour(handle);
			break;
		}
		case Clock__0_Set_r1_SetMinutes :
		{
			clock_react__0_Set_r1_SetMinutes(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clock_clearInEvents(handle);
}

void clock_raiseTimeEvent(const Clock* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(ClockTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean clock_isStateActive(const Clock* handle, ClockStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Clock__0_Display :
			result = (sc_boolean) (handle->stateConfVector[0] >= Clock__0_Display
				&& handle->stateConfVector[0] <= Clock__0_Display_r1_DisplayMinutes);
			break;
		case Clock__0_Display_r1_DisplayHour :
			result = (sc_boolean) (handle->stateConfVector[0] == Clock__0_Display_r1_DisplayHour
			);
			break;
		case Clock__0_Display_r1_DisplayMinutes :
			result = (sc_boolean) (handle->stateConfVector[0] == Clock__0_Display_r1_DisplayMinutes
			);
			break;
		case Clock__0_Set :
			result = (sc_boolean) (handle->stateConfVector[0] >= Clock__0_Set
				&& handle->stateConfVector[0] <= Clock__0_Set_r1_SetMinutes);
			break;
		case Clock__0_Set_r1_SetHour :
			result = (sc_boolean) (handle->stateConfVector[0] == Clock__0_Set_r1_SetHour
			);
			break;
		case Clock__0_Set_r1_SetMinutes :
			result = (sc_boolean) (handle->stateConfVector[0] == Clock__0_Set_r1_SetMinutes
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void clockIface_raise_mode(Clock* handle)
{
	handle->iface.mode_raised = bool_true;
}
void clockIface_raise_set(Clock* handle)
{
	handle->iface.set_raised = bool_true;
}


sc_integer clockIface_get_time(const Clock* handle)
{
	return handle->iface.time;
}
void clockIface_set_time(Clock* handle, sc_integer value)
{
	handle->iface.time = value;
}
sc_integer clockIface_get_hour(const Clock* handle)
{
	return handle->iface.hour;
}
void clockIface_set_hour(Clock* handle, sc_integer value)
{
	handle->iface.hour = value;
}
sc_integer clockIface_get_min(const Clock* handle)
{
	return handle->iface.min;
}
void clockIface_set_min(Clock* handle, sc_integer value)
{
	handle->iface.min = value;
}
sc_integer clockIface_get_sec(const Clock* handle)
{
	return handle->iface.sec;
}
void clockIface_set_sec(Clock* handle, sc_integer value)
{
	handle->iface.sec = value;
}

/* implementations of all internal functions */

static sc_boolean clock_check__lr0(const Clock* handle)
{
	return handle->timeEvents.clock_tev0_raised;
}

static sc_boolean clock_check__0_Display_tr0_tr0(const Clock* handle)
{
	return handle->iface.set_raised;
}

static sc_boolean clock_check__0_Display_r1_DisplayHour_tr0_tr0(const Clock* handle)
{
	return handle->iface.mode_raised;
}

static sc_boolean clock_check__0_Display_r1_DisplayMinutes_tr0_tr0(const Clock* handle)
{
	return handle->iface.mode_raised;
}

static sc_boolean clock_check__0_Set_r1_SetHour_tr0_tr0(const Clock* handle)
{
	return handle->iface.set_raised;
}

static sc_boolean clock_check__0_Set_r1_SetHour_tr1_tr1(const Clock* handle)
{
	return handle->iface.mode_raised;
}

static sc_boolean clock_check__0_Set_r1_SetMinutes_tr0_tr0(const Clock* handle)
{
	return handle->iface.mode_raised;
}

static sc_boolean clock_check__0_Set_r1_SetMinutes_tr1_tr1(const Clock* handle)
{
	return handle->iface.set_raised;
}

static void clock_effect__lr0(Clock* handle)
{
	handle->iface.time += 1;
	handle->iface.sec = handle->iface.time % 60;
	handle->iface.min = (handle->iface.time / 60) % 60;
	handle->iface.hour = (handle->iface.time / 3600) % 24;
}

static void clock_effect__0_Display_tr0(Clock* handle)
{
	clock_exseq__0_Display(handle);
	clock_enseq__0_Set_default(handle);
}

static void clock_effect__0_Display_r1_DisplayHour_tr0(Clock* handle)
{
	clock_exseq__0_Display_r1_DisplayHour(handle);
	clock_enseq__0_Display_r1_DisplayMinutes_default(handle);
}

static void clock_effect__0_Display_r1_DisplayMinutes_tr0(Clock* handle)
{
	clock_exseq__0_Display_r1_DisplayMinutes(handle);
	clock_enseq__0_Display_r1_DisplayHour_default(handle);
}

static void clock_effect__0_Set_r1_SetHour_tr0(Clock* handle)
{
	clock_exseq__0_Set_r1_SetHour(handle);
	clock_enseq__0_Set_r1_SetMinutes_default(handle);
}

static void clock_effect__0_Set_r1_SetHour_tr1(Clock* handle)
{
	clock_exseq__0_Set_r1_SetHour(handle);
	handle->iface.time += 3600;
	clock_enseq__0_Set_r1_SetHour_default(handle);
}

static void clock_effect__0_Set_r1_SetMinutes_tr0(Clock* handle)
{
	clock_exseq__0_Set_r1_SetMinutes(handle);
	handle->iface.time += 60;
	clock_enseq__0_Set_r1_SetMinutes_default(handle);
}

static void clock_effect__0_Set_r1_SetMinutes_tr1(Clock* handle)
{
	clock_exseq__0_Set(handle);
	clock_react__0_Display_r1_his(handle);
}

/* Entry action for statechart 'clock'. */
static void clock_enact(Clock* handle)
{
	/* Entry action for statechart 'clock'. */
	clock_setTimer(handle, (sc_eventid) &(handle->timeEvents.clock_tev0_raised) , 1 * 1000, bool_true);
}

/* Exit action for state 'clock'. */
static void clock_exact(Clock* handle)
{
	/* Exit action for state 'clock'. */
	clock_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.clock_tev0_raised) );		
}

/* 'default' enter sequence for state Display */
static void clock_enseq__0_Display_default(Clock* handle)
{
	/* 'default' enter sequence for state Display */
	clock_enseq__0_Display_r1_default(handle);
}

/* 'default' enter sequence for state DisplayHour */
static void clock_enseq__0_Display_r1_DisplayHour_default(Clock* handle)
{
	/* 'default' enter sequence for state DisplayHour */
	handle->stateConfVector[0] = Clock__0_Display_r1_DisplayHour;
	handle->stateConfVectorPosition = 0;
	handle->historyVector[0] = handle->stateConfVector[0];
}

/* 'default' enter sequence for state DisplayMinutes */
static void clock_enseq__0_Display_r1_DisplayMinutes_default(Clock* handle)
{
	/* 'default' enter sequence for state DisplayMinutes */
	handle->stateConfVector[0] = Clock__0_Display_r1_DisplayMinutes;
	handle->stateConfVectorPosition = 0;
	handle->historyVector[0] = handle->stateConfVector[0];
}

/* 'default' enter sequence for state Set */
static void clock_enseq__0_Set_default(Clock* handle)
{
	/* 'default' enter sequence for state Set */
	clock_enseq__0_Set_r1_default(handle);
}

/* 'default' enter sequence for state SetHour */
static void clock_enseq__0_Set_r1_SetHour_default(Clock* handle)
{
	/* 'default' enter sequence for state SetHour */
	handle->stateConfVector[0] = Clock__0_Set_r1_SetHour;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state SetMinutes */
static void clock_enseq__0_Set_r1_SetMinutes_default(Clock* handle)
{
	/* 'default' enter sequence for state SetMinutes */
	handle->stateConfVector[0] = Clock__0_Set_r1_SetMinutes;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region 0 */
static void clock_enseq__0_default(Clock* handle)
{
	/* 'default' enter sequence for region 0 */
	clock_react__0__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void clock_enseq__0_Display_r1_default(Clock* handle)
{
	/* 'default' enter sequence for region r1 */
	clock_react__0_Display_r1__entry_Default(handle);
}

/* shallow enterSequence with history in child r1 */
static void clock_shenseq__0_Display_r1(Clock* handle)
{
	/* shallow enterSequence with history in child r1 */
	/* Handle shallow history entry of r1 */
	switch(handle->historyVector[ 0 ])
	{
		case Clock__0_Display_r1_DisplayHour :
		{
			clock_enseq__0_Display_r1_DisplayHour_default(handle);
			break;
		}
		case Clock__0_Display_r1_DisplayMinutes :
		{
			clock_enseq__0_Display_r1_DisplayMinutes_default(handle);
			break;
		}
		default: break;
	}
}

/* 'default' enter sequence for region r1 */
static void clock_enseq__0_Set_r1_default(Clock* handle)
{
	/* 'default' enter sequence for region r1 */
	clock_react__0_Set_r1__entry_Default(handle);
}

/* Default exit sequence for state Display */
static void clock_exseq__0_Display(Clock* handle)
{
	/* Default exit sequence for state Display */
	clock_exseq__0_Display_r1(handle);
}

/* Default exit sequence for state DisplayHour */
static void clock_exseq__0_Display_r1_DisplayHour(Clock* handle)
{
	/* Default exit sequence for state DisplayHour */
	handle->stateConfVector[0] = Clock_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state DisplayMinutes */
static void clock_exseq__0_Display_r1_DisplayMinutes(Clock* handle)
{
	/* Default exit sequence for state DisplayMinutes */
	handle->stateConfVector[0] = Clock_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state Set */
static void clock_exseq__0_Set(Clock* handle)
{
	/* Default exit sequence for state Set */
	clock_exseq__0_Set_r1(handle);
}

/* Default exit sequence for state SetHour */
static void clock_exseq__0_Set_r1_SetHour(Clock* handle)
{
	/* Default exit sequence for state SetHour */
	handle->stateConfVector[0] = Clock_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state SetMinutes */
static void clock_exseq__0_Set_r1_SetMinutes(Clock* handle)
{
	/* Default exit sequence for state SetMinutes */
	handle->stateConfVector[0] = Clock_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for region 0 */
static void clock_exseq__0(Clock* handle)
{
	/* Default exit sequence for region 0 */
	/* Handle exit of all possible states (of clock._0) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Clock__0_Display_r1_DisplayHour :
		{
			clock_exseq__0_Display_r1_DisplayHour(handle);
			break;
		}
		case Clock__0_Display_r1_DisplayMinutes :
		{
			clock_exseq__0_Display_r1_DisplayMinutes(handle);
			break;
		}
		case Clock__0_Set_r1_SetHour :
		{
			clock_exseq__0_Set_r1_SetHour(handle);
			break;
		}
		case Clock__0_Set_r1_SetMinutes :
		{
			clock_exseq__0_Set_r1_SetMinutes(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void clock_exseq__0_Display_r1(Clock* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of clock._0.Display.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Clock__0_Display_r1_DisplayHour :
		{
			clock_exseq__0_Display_r1_DisplayHour(handle);
			break;
		}
		case Clock__0_Display_r1_DisplayMinutes :
		{
			clock_exseq__0_Display_r1_DisplayMinutes(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void clock_exseq__0_Set_r1(Clock* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of clock._0.Set.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Clock__0_Set_r1_SetHour :
		{
			clock_exseq__0_Set_r1_SetHour(handle);
			break;
		}
		case Clock__0_Set_r1_SetMinutes :
		{
			clock_exseq__0_Set_r1_SetMinutes(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DisplayHour. */
static void clock_react__0_Display_r1_DisplayHour(Clock* handle)
{
	/* The reactions of state DisplayHour. */
	if (clock_check__lr0(handle) == bool_true)
	{ 
		clock_effect__lr0(handle);
	} 
	if (clock_check__0_Display_tr0_tr0(handle) == bool_true)
	{ 
		clock_effect__0_Display_tr0(handle);
	}  else
	{
		if (clock_check__0_Display_r1_DisplayHour_tr0_tr0(handle) == bool_true)
		{ 
			clock_effect__0_Display_r1_DisplayHour_tr0(handle);
		} 
	}
}

/* The reactions of state DisplayMinutes. */
static void clock_react__0_Display_r1_DisplayMinutes(Clock* handle)
{
	/* The reactions of state DisplayMinutes. */
	if (clock_check__lr0(handle) == bool_true)
	{ 
		clock_effect__lr0(handle);
	} 
	if (clock_check__0_Display_tr0_tr0(handle) == bool_true)
	{ 
		clock_effect__0_Display_tr0(handle);
	}  else
	{
		if (clock_check__0_Display_r1_DisplayMinutes_tr0_tr0(handle) == bool_true)
		{ 
			clock_effect__0_Display_r1_DisplayMinutes_tr0(handle);
		} 
	}
}

/* The reactions of state SetHour. */
static void clock_react__0_Set_r1_SetHour(Clock* handle)
{
	/* The reactions of state SetHour. */
	if (clock_check__lr0(handle) == bool_true)
	{ 
		clock_effect__lr0(handle);
	} 
	if (clock_check__0_Set_r1_SetHour_tr0_tr0(handle) == bool_true)
	{ 
		clock_effect__0_Set_r1_SetHour_tr0(handle);
	}  else
	{
		if (clock_check__0_Set_r1_SetHour_tr1_tr1(handle) == bool_true)
		{ 
			clock_effect__0_Set_r1_SetHour_tr1(handle);
		} 
	}
}

/* The reactions of state SetMinutes. */
static void clock_react__0_Set_r1_SetMinutes(Clock* handle)
{
	/* The reactions of state SetMinutes. */
	if (clock_check__lr0(handle) == bool_true)
	{ 
		clock_effect__lr0(handle);
	} 
	if (clock_check__0_Set_r1_SetMinutes_tr0_tr0(handle) == bool_true)
	{ 
		clock_effect__0_Set_r1_SetMinutes_tr0(handle);
	}  else
	{
		if (clock_check__0_Set_r1_SetMinutes_tr1_tr1(handle) == bool_true)
		{ 
			clock_effect__0_Set_r1_SetMinutes_tr1(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void clock_react__0__entry_Default(Clock* handle)
{
	/* Default react sequence for initial entry  */
	clock_enseq__0_Display_default(handle);
}

/* Default react sequence for initial entry  */
static void clock_react__0_Display_r1__entry_Default(Clock* handle)
{
	/* Default react sequence for initial entry  */
	clock_enseq__0_Display_r1_DisplayHour_default(handle);
}

/* Default react sequence for shallow history entry his */
static void clock_react__0_Display_r1_his(Clock* handle)
{
	/* Default react sequence for shallow history entry his */
	/* Enter the region with shallow history */
	if (handle->historyVector[0] != Clock_last_state)
	{
		clock_shenseq__0_Display_r1(handle);
	} 
}

/* Default react sequence for initial entry  */
static void clock_react__0_Set_r1__entry_Default(Clock* handle)
{
	/* Default react sequence for initial entry  */
	clock_enseq__0_Set_r1_SetHour_default(handle);
}



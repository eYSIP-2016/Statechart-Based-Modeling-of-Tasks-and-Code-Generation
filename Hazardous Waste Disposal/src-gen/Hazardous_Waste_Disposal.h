
#ifndef HAZARDOUS_WASTE_DISPOSAL_H_
#define HAZARDOUS_WASTE_DISPOSAL_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'Hazardous_Waste_Disposal'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Hazardous_Waste_Disposal_main_region_start,
	Hazardous_Waste_Disposal_main_region_start_node_selection_node_selection,
	Hazardous_Waste_Disposal_main_region_start_node_selection_node_selection_node_selection_node1,
	Hazardous_Waste_Disposal_main_region_start_node_selection_node_selection_node_selection_node2,
	Hazardous_Waste_Disposal_main_region_start_node_selection_node_selection_node_selection_call3,
	Hazardous_Waste_Disposal_main_region_start_node_selection_node_selection_node_selection_call,
	Hazardous_Waste_Disposal_main_region_start_node_selection_node_selection_node_selection_call2,
	Hazardous_Waste_Disposal_main_region_start_node_selection_node_selection_node_selection_node3,
	Hazardous_Waste_Disposal_main_region_start_node_selection_node_selection_node_selection_wait_for_node_,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_Bridge,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_yes,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_yes_Bridge_detected_turn_180_,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_yes_Bridge_detected_forward,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_yes_Bridge_detected_node1,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_turn_90_,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_forward,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_pick_weight,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_pick_weight__region0_turn_180_,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_pick_weight__region0_node1,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_pick_weight__region0_turn_left_90_,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_pick_weight__region0_drop_the_weight,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_pick_weight__region0_turn_right_90_,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_pick_weight__region0_reached_node_0,
	Hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_pick_weight__region0_node,
	Hazardous_Waste_Disposal_main_region_start_task_Collect_object,
	Hazardous_Waste_Disposal_main_region_start_task_Collect_object_collect_object_turn_180_,
	Hazardous_Waste_Disposal_main_region_start_task_Collect_object_collect_object_forward,
	Hazardous_Waste_Disposal_main_region_start_task_Collect_object_collect_object_node_2_deteced,
	Hazardous_Waste_Disposal_main_region_start_task_Collect_object_collect_object_pick_the_object,
	Hazardous_Waste_Disposal_main_region_start_task_Collect_object_collect_object_Turn_180_,
	Hazardous_Waste_Disposal_main_region_start_task_Collect_object_collect_object_move_to_junction,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_middle_node,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_middle_node__region0_move_forward_to_the_middle_node,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_middle_node__region0_check_the_flag,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_middle_node__region0_place_the_object,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_middle_node__region0_store_flag,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_middle_node__region0_trun_180__left,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_middle_node__region0_junction_node,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0_turn_90__right,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0_node1,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0_node2_and_turn_90_left,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0_flag_node___check_flag_status,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0_store_flag,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0_place_the_object,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0_turn_180__left,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0_node1____turn_90__right,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0__node_2,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_right_node__region0_junction_node,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_left_node,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_left_node__region0_turn_90__left,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_left_node__region0_node1___turn_90__right,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_left_node__region0_flag3_detected,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_left_node__region0_place_the_object,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_left_node__region0_turn_180__left,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_left_node__region0_node1_turn_90__left,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_left_node__region0_junction_node,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_left_node__region0_store_flag,
	Hazardous_Waste_Disposal_main_region_start_task_Reach_Junction_reach_junction_node_selection,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_Bridge,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_turn_90_,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_forward,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_pick_weight,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_pick_weight__region0_turn_180_,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_pick_weight__region0_node1,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_pick_weight__region0_turn_left_90_,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_pick_weight__region0_drop_the_weight,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_pick_weight__region0_turn_right_90_,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_pick_weight__region0_reached_juction_node,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_pick_weight__region0_node,
	Hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_go,
	Hazardous_Waste_Disposal_main_region_start_object_status_object1,
	Hazardous_Waste_Disposal_main_region_start_object_status_object2,
	Hazardous_Waste_Disposal_main_region_start_object_status_object3,
	Hazardous_Waste_Disposal_main_region_start_object_status_put_object,
	Hazardous_Waste_Disposal_main_region_start_motion_status_Moving,
	Hazardous_Waste_Disposal_main_region_start_motion_status_Moving_moving_Left_Motor,
	Hazardous_Waste_Disposal_main_region_start_motion_status_Moving_moving_Forward,
	Hazardous_Waste_Disposal_main_region_start_motion_status_Moving_moving_Right_motor,
	Hazardous_Waste_Disposal_main_region_start_motion_status_Stop,
	Hazardous_Waste_Disposal_last_state
} Hazardous_Waste_DisposalStates;

/*! Type definition of the data structure for the Hazardous_Waste_DisposalIface interface scope. */
typedef struct
{
	sc_boolean bridge_raised;
	sc_boolean stop_raised;
	sc_boolean bridge_detected_raised;
	sc_boolean bridge_not_detected_raised;
	sc_boolean next_object_raised;
	sc_boolean go_raised;
	sc_integer call_middle_node;
	sc_integer call_left_node;
	sc_integer call_right_node;
	sc_boolean IR_MIDDLE;
	sc_boolean IR_LEFT;
	sc_boolean IR_RIGHT;
	sc_integer count1;
	sc_integer count2;
	sc_integer count3;
	sc_integer initial_count;
	sc_integer temp0;
	sc_integer temp1;
	sc_integer temp2;
	sc_integer temp3;
	sc_integer flag1;
	sc_integer flag2;
	sc_integer flag3;
	sc_integer flag1_done;
	sc_integer flag2_done;
	sc_integer flag3_done;
	sc_integer object1;
	sc_integer object2;
	sc_integer object3;
	sc_integer next_state;
	sc_integer return_node;
} Hazardous_Waste_DisposalIface;

/*! Type definition of the data structure for the Hazardous_Waste_DisposalTimeEvents interface scope. */
typedef struct
{
	sc_boolean hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_yes_Bridge_detected_forward_tev0_raised;
	sc_boolean hazardous_Waste_Disposal_main_region_start_task_Check_bridge_status_______________________________________________________________________Bridge_Status_no_Bridge_not_detected_forward_tev0_raised;
	sc_boolean hazardous_Waste_Disposal_main_region_start_task_Back_to_initial_node_______________________________________________________________________Bridge_Status_no__region0_forward_tev0_raised;
} Hazardous_Waste_DisposalTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define HAZARDOUS_WASTE_DISPOSAL_MAX_ORTHOGONAL_STATES 4

/*! 
 * Type definition of the data structure for the Hazardous_Waste_Disposal state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Hazardous_Waste_DisposalStates stateConfVector[HAZARDOUS_WASTE_DISPOSAL_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Hazardous_Waste_DisposalIface iface;
	Hazardous_Waste_DisposalTimeEvents timeEvents;
} Hazardous_Waste_Disposal;

/*! Initializes the Hazardous_Waste_Disposal state machine data structures. Must be called before first usage.*/
extern void hazardous_Waste_Disposal_init(Hazardous_Waste_Disposal* handle);

/*! Activates the state machine */
extern void hazardous_Waste_Disposal_enter(Hazardous_Waste_Disposal* handle);

/*! Deactivates the state machine */
extern void hazardous_Waste_Disposal_exit(Hazardous_Waste_Disposal* handle);

/*! Performs a 'run to completion' step. */
extern void hazardous_Waste_Disposal_runCycle(Hazardous_Waste_Disposal* handle);

/*! Raises a time event. */
extern void hazardous_Waste_Disposal_raiseTimeEvent(const Hazardous_Waste_Disposal* handle, sc_eventid evid);

/*! Raises the in event 'bridge' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_raise_bridge(Hazardous_Waste_Disposal* handle);

/*! Raises the in event 'stop' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_raise_stop(Hazardous_Waste_Disposal* handle);

/*! Raises the in event 'bridge_detected' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_raise_bridge_detected(Hazardous_Waste_Disposal* handle);

/*! Raises the in event 'bridge_not_detected' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_raise_bridge_not_detected(Hazardous_Waste_Disposal* handle);

/*! Raises the in event 'next_object' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_raise_next_object(Hazardous_Waste_Disposal* handle);

/*! Raises the in event 'go' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_raise_go(Hazardous_Waste_Disposal* handle);

/*! Gets the value of the variable 'call_middle_node' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_call_middle_node(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'call_middle_node' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_call_middle_node(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'call_left_node' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_call_left_node(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'call_left_node' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_call_left_node(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'call_right_node' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_call_right_node(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'call_right_node' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_call_right_node(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'IR_MIDDLE' that is defined in the default interface scope. */ 
extern sc_boolean hazardous_Waste_DisposalIface_get_iR_MIDDLE(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'IR_MIDDLE' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_iR_MIDDLE(Hazardous_Waste_Disposal* handle, sc_boolean value);
/*! Gets the value of the variable 'IR_LEFT' that is defined in the default interface scope. */ 
extern sc_boolean hazardous_Waste_DisposalIface_get_iR_LEFT(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'IR_LEFT' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_iR_LEFT(Hazardous_Waste_Disposal* handle, sc_boolean value);
/*! Gets the value of the variable 'IR_RIGHT' that is defined in the default interface scope. */ 
extern sc_boolean hazardous_Waste_DisposalIface_get_iR_RIGHT(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'IR_RIGHT' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_iR_RIGHT(Hazardous_Waste_Disposal* handle, sc_boolean value);
/*! Gets the value of the variable 'count1' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_count1(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'count1' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_count1(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'count2' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_count2(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'count2' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_count2(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'count3' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_count3(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'count3' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_count3(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'initial_count' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_initial_count(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'initial_count' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_initial_count(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'temp0' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_temp0(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'temp0' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_temp0(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'temp1' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_temp1(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'temp1' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_temp1(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'temp2' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_temp2(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'temp2' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_temp2(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'temp3' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_temp3(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'temp3' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_temp3(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'flag1' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_flag1(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'flag1' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_flag1(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'flag2' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_flag2(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'flag2' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_flag2(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'flag3' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_flag3(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'flag3' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_flag3(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'flag1_done' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_flag1_done(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'flag1_done' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_flag1_done(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'flag2_done' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_flag2_done(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'flag2_done' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_flag2_done(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'flag3_done' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_flag3_done(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'flag3_done' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_flag3_done(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'object1' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_object1(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'object1' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_object1(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'object2' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_object2(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'object2' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_object2(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'object3' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_object3(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'object3' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_object3(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'next_state' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_next_state(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'next_state' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_next_state(Hazardous_Waste_Disposal* handle, sc_integer value);
/*! Gets the value of the variable 'return_node' that is defined in the default interface scope. */ 
extern sc_integer hazardous_Waste_DisposalIface_get_return_node(const Hazardous_Waste_Disposal* handle);
/*! Sets the value of the variable 'return_node' that is defined in the default interface scope. */ 
extern void hazardous_Waste_DisposalIface_set_return_node(Hazardous_Waste_Disposal* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean hazardous_Waste_Disposal_isActive(const Hazardous_Waste_Disposal* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean hazardous_Waste_Disposal_isFinal(const Hazardous_Waste_Disposal* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean hazardous_Waste_Disposal_isStateActive(const Hazardous_Waste_Disposal* handle, Hazardous_Waste_DisposalStates state);

#ifdef __cplusplus
}
#endif 

#endif /* HAZARDOUS_WASTE_DISPOSAL_H_ */

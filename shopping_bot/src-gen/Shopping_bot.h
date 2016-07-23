
#ifndef SHOPPING_BOT_H_
#define SHOPPING_BOT_H_

#include "..\src\sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'shopping_bot'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Shopping_bot_main_region_Steady_state,
	Shopping_bot_main_region_Do_Shopping,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_MOVING,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_MOVING_r1_Forward,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_MOVING_r1_Left_Motor,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_MOVING_r1_Right_motor,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_object1,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_object2,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_object3,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_Node2,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_state,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_Node1,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_node3,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r2_node1,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r2_node2,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r2_node3,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r2_initial,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r2_count_reset,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Bot_is_moving,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Bot_is_moving__region0_No_obstacle_detected,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Obstacle_detected,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Obstacle_detected__region0_speed_decrease,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Object_very_close,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Object_very_close__region0_stop,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Node_Detected,
	Shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1__final_,
	Shopping_bot_last_state
} Shopping_botStates;

/*! Type definition of the data structure for the Shopping_botIface interface scope. */
typedef struct
{
	sc_boolean done_shopping_raised;
	sc_boolean do_shopping_raised;
	sc_boolean NO_OBSTACLE_DETECTED_raised;
	sc_integer NO_OBSTACLE_DETECTED_value;
	sc_boolean OBSTACLE_DETECTED_raised;
	sc_boolean OBSTACLE_VERY_CLOSE_raised;
	sc_boolean OBSTACLE_FAR_raised;
	sc_boolean call_raised;
	sc_boolean d_call_raised;
	sc_boolean IR_MIDDLE;
	sc_boolean IR_RIGHT;
	sc_boolean IR_LEFT;
	sc_integer node1;
	sc_integer node2;
	sc_integer node3;
	sc_integer temp;
	sc_integer object1;
	sc_integer object2;
	sc_integer object3;
	sc_integer node_count;
	sc_integer speed;
	sc_integer packets_detected;
} Shopping_botIface;

/*! Type definition of the data structure for the Shopping_botTimeEvents interface scope. */
typedef struct
{
	sc_boolean shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_object1_tev0_raised;
	sc_boolean shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_object2_tev0_raised;
	sc_boolean shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r1_object3_tev0_raised;
	sc_boolean shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r2_initial_tev0_raised;
	sc_boolean shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r2_initial_tev1_raised;
	sc_boolean shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r1_White_Line_Follower_DETECTION_node_r2_initial_tev2_raised;
	sc_boolean shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Bot_is_moving__region0_No_obstacle_detected_tev0_raised;
	sc_boolean shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Obstacle_detected__region0_speed_decrease_tev0_raised;
	sc_boolean shopping_bot_main_region_Do_Shopping_r1_shopping_And_Adaptive_Cruise_Controle_r2_Adaptive_Cruise_Control_r1_Object_very_close__region0_stop_tev0_raised;
} Shopping_botTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define SHOPPING_BOT_MAX_ORTHOGONAL_STATES 3

/*! 
 * Type definition of the data structure for the Shopping_bot state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Shopping_botStates stateConfVector[SHOPPING_BOT_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Shopping_botIface iface;
	Shopping_botTimeEvents timeEvents;
} Shopping_bot;

/*! Initializes the Shopping_bot state machine data structures. Must be called before first usage.*/
extern void shopping_bot_init(Shopping_bot* handle);

/*! Activates the state machine */
extern void shopping_bot_enter(Shopping_bot* handle);

/*! Deactivates the state machine */
extern void shopping_bot_exit(Shopping_bot* handle);

/*! Performs a 'run to completion' step. */
extern void shopping_bot_runCycle(Shopping_bot* handle);

/*! Raises a time event. */
extern void shopping_bot_raiseTimeEvent(const Shopping_bot* handle, sc_eventid evid);

/*! Raises the in event 'done_shopping' that is defined in the default interface scope. */ 
extern void shopping_botIface_raise_done_shopping(Shopping_bot* handle);

/*! Raises the in event 'do_shopping' that is defined in the default interface scope. */ 
extern void shopping_botIface_raise_do_shopping(Shopping_bot* handle);

/*! Raises the in event 'NO_OBSTACLE_DETECTED' that is defined in the default interface scope. */ 
extern void shopping_botIface_raise_nO_OBSTACLE_DETECTED(Shopping_bot* handle, sc_integer value);

/*! Raises the in event 'OBSTACLE_DETECTED' that is defined in the default interface scope. */ 
extern void shopping_botIface_raise_oBSTACLE_DETECTED(Shopping_bot* handle);

/*! Raises the in event 'OBSTACLE_VERY_CLOSE' that is defined in the default interface scope. */ 
extern void shopping_botIface_raise_oBSTACLE_VERY_CLOSE(Shopping_bot* handle);

/*! Raises the in event 'OBSTACLE_FAR' that is defined in the default interface scope. */ 
extern void shopping_botIface_raise_oBSTACLE_FAR(Shopping_bot* handle);

/*! Checks if the out event 'call' that is defined in the default interface scope has been raised. */ 
extern sc_boolean shopping_botIface_israised_call(const Shopping_bot* handle);

/*! Checks if the out event 'd_call' that is defined in the default interface scope has been raised. */ 
extern sc_boolean shopping_botIface_israised_d_call(const Shopping_bot* handle);

/*! Gets the value of the variable 'IR_MIDDLE' that is defined in the default interface scope. */ 
extern sc_boolean shopping_botIface_get_iR_MIDDLE(const Shopping_bot* handle);
/*! Sets the value of the variable 'IR_MIDDLE' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_iR_MIDDLE(Shopping_bot* handle, sc_boolean value);
/*! Gets the value of the variable 'IR_RIGHT' that is defined in the default interface scope. */ 
extern sc_boolean shopping_botIface_get_iR_RIGHT(const Shopping_bot* handle);
/*! Sets the value of the variable 'IR_RIGHT' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_iR_RIGHT(Shopping_bot* handle, sc_boolean value);
/*! Gets the value of the variable 'IR_LEFT' that is defined in the default interface scope. */ 
extern sc_boolean shopping_botIface_get_iR_LEFT(const Shopping_bot* handle);
/*! Sets the value of the variable 'IR_LEFT' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_iR_LEFT(Shopping_bot* handle, sc_boolean value);
/*! Gets the value of the variable 'node1' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_node1(const Shopping_bot* handle);
/*! Sets the value of the variable 'node1' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_node1(Shopping_bot* handle, sc_integer value);
/*! Gets the value of the variable 'node2' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_node2(const Shopping_bot* handle);
/*! Sets the value of the variable 'node2' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_node2(Shopping_bot* handle, sc_integer value);
/*! Gets the value of the variable 'node3' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_node3(const Shopping_bot* handle);
/*! Sets the value of the variable 'node3' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_node3(Shopping_bot* handle, sc_integer value);
/*! Gets the value of the variable 'temp' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_temp(const Shopping_bot* handle);
/*! Sets the value of the variable 'temp' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_temp(Shopping_bot* handle, sc_integer value);
/*! Gets the value of the variable 'object1' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_object1(const Shopping_bot* handle);
/*! Sets the value of the variable 'object1' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_object1(Shopping_bot* handle, sc_integer value);
/*! Gets the value of the variable 'object2' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_object2(const Shopping_bot* handle);
/*! Sets the value of the variable 'object2' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_object2(Shopping_bot* handle, sc_integer value);
/*! Gets the value of the variable 'object3' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_object3(const Shopping_bot* handle);
/*! Sets the value of the variable 'object3' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_object3(Shopping_bot* handle, sc_integer value);
/*! Gets the value of the variable 'node_count' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_node_count(const Shopping_bot* handle);
/*! Sets the value of the variable 'node_count' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_node_count(Shopping_bot* handle, sc_integer value);
/*! Gets the value of the variable 'speed' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_speed(const Shopping_bot* handle);
/*! Sets the value of the variable 'speed' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_speed(Shopping_bot* handle, sc_integer value);
/*! Gets the value of the variable 'packets_detected' that is defined in the default interface scope. */ 
extern sc_integer shopping_botIface_get_packets_detected(const Shopping_bot* handle);
/*! Sets the value of the variable 'packets_detected' that is defined in the default interface scope. */ 
extern void shopping_botIface_set_packets_detected(Shopping_bot* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean shopping_bot_isActive(const Shopping_bot* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean shopping_bot_isFinal(const Shopping_bot* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean shopping_bot_isStateActive(const Shopping_bot* handle, Shopping_botStates state);

#ifdef __cplusplus
}
#endif 

#endif /* SHOPPING_BOT_H_ */

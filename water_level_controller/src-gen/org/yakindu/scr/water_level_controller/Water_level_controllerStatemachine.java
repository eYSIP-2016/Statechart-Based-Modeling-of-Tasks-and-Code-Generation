package org.yakindu.scr.water_level_controller;
import org.yakindu.scr.ITimer;

public class Water_level_controllerStatemachine implements IWater_level_controllerStatemachine {

	protected class SCInterfaceImpl implements SCInterface {

		private long water_level;

		public long getWater_level() {
			return water_level;
		}

		public void setWater_level(long value) {
			this.water_level = value;
		}

		private long max_water_level;

		public long getMax_water_level() {
			return max_water_level;
		}

		public void setMax_water_level(long value) {
			this.max_water_level = value;
		}

	}

	protected SCInterfaceImpl sCInterface;

	private boolean initialized = false;

	public enum State {
		main_region_motor__off_, main_region_motor__on_, $NullState$
	};

	private final State[] stateVector = new State[1];

	private int nextStateIndex;

	private ITimer timer;

	private final boolean[] timeEvents = new boolean[1];

	public Water_level_controllerStatemachine() {

		sCInterface = new SCInterfaceImpl();
	}

	public void init() {
		this.initialized = true;
		if (timer == null) {
			throw new IllegalStateException("timer not set.");
		}
		for (int i = 0; i < 1; i++) {
			stateVector[i] = State.$NullState$;
		}

		clearEvents();
		clearOutEvents();

		sCInterface.setWater_level(1);

		sCInterface.setMax_water_level(0);
	}

	public void enter() {
		if (!initialized)
			throw new IllegalStateException(
					"The state machine needs to be initialized first by calling the init() function.");

		if (timer == null) {
			throw new IllegalStateException("timer not set.");
		}
		enterSequence_main_region_default();
	}

	public void exit() {
		exitSequence_main_region();
	}

	/**
	 * @see IStatemachine#isActive()
	 */
	public boolean isActive() {

		return stateVector[0] != State.$NullState$;
	}

	/** 
	* Always returns 'false' since this state machine can never become final.
	*
	 * @see IStatemachine#isFinal()
	 */
	public boolean isFinal() {
		return false;
	}

	/**
	* This method resets the incoming events (time events included).
	*/
	protected void clearEvents() {

		for (int i = 0; i < timeEvents.length; i++) {
			timeEvents[i] = false;
		}
	}

	/**
	* This method resets the outgoing events.
	*/
	protected void clearOutEvents() {
	}

	/**
	* Returns true if the given state is currently active otherwise false.
	*/
	public boolean isStateActive(State state) {
		switch (state) {
			case main_region_motor__off_ :
				return stateVector[0] == State.main_region_motor__off_;
			case main_region_motor__on_ :
				return stateVector[0] == State.main_region_motor__on_;
			default :
				return false;
		}
	}

	/**
	* Set the {@link ITimer} for the state machine. It must be set
	* externally on a timed state machine before a run cycle can be correct
	* executed.
	* 
	* @param timer
	*/
	public void setTimer(ITimer timer) {
		this.timer = timer;
	}

	/**
	* Returns the currently used timer.
	* 
	* @return {@link ITimer}
	*/
	public ITimer getTimer() {
		return timer;
	}

	public void timeElapsed(int eventID) {
		timeEvents[eventID] = true;
	}

	public SCInterface getSCInterface() {
		return sCInterface;
	}

	public long getWater_level() {
		return sCInterface.getWater_level();
	}

	public void setWater_level(long value) {
		sCInterface.setWater_level(value);
	}
	public long getMax_water_level() {
		return sCInterface.getMax_water_level();
	}

	public void setMax_water_level(long value) {
		sCInterface.setMax_water_level(value);
	}

	private boolean check_main_region_motor__off__tr0_tr0() {
		return sCInterface.getMax_water_level() > sCInterface.getWater_level();
	}

	private boolean check_main_region_motor__on__tr0_tr0() {
		return sCInterface.getMax_water_level() == sCInterface.getWater_level();
	}

	private boolean check_main_region_motor__on__tr1_tr1() {
		return timeEvents[0];
	}

	private void effect_main_region_motor__off__tr0() {
		exitSequence_main_region_motor__off_();

		enterSequence_main_region_motor__on__default();
	}

	private void effect_main_region_motor__on__tr0() {
		exitSequence_main_region_motor__on_();

		enterSequence_main_region_motor__off__default();
	}

	private void effect_main_region_motor__on__tr1() {
		exitSequence_main_region_motor__on_();

		enterSequence_main_region_motor__on__default();
	}

	/* Entry action for state 'motor (on)'. */
	private void entryAction_main_region_motor__on_() {

		timer.setTimer(this, 0, 2 * 1000, true);

		sCInterface.setWater_level(sCInterface.water_level + 1);
	}

	/* Exit action for state 'motor (on)'. */
	private void exitAction_main_region_motor__on_() {
		timer.unsetTimer(this, 0);
	}

	/* 'default' enter sequence for state motor (off) */
	private void enterSequence_main_region_motor__off__default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_motor__off_;
	}

	/* 'default' enter sequence for state motor (on) */
	private void enterSequence_main_region_motor__on__default() {
		entryAction_main_region_motor__on_();

		nextStateIndex = 0;
		stateVector[0] = State.main_region_motor__on_;
	}

	/* 'default' enter sequence for region main region */
	private void enterSequence_main_region_default() {
		react_main_region__entry_Default();
	}

	/* Default exit sequence for state motor (off) */
	private void exitSequence_main_region_motor__off_() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}

	/* Default exit sequence for state motor (on) */
	private void exitSequence_main_region_motor__on_() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;

		exitAction_main_region_motor__on_();
	}

	/* Default exit sequence for region main region */
	private void exitSequence_main_region() {
		switch (stateVector[0]) {
			case main_region_motor__off_ :
				exitSequence_main_region_motor__off_();
				break;

			case main_region_motor__on_ :
				exitSequence_main_region_motor__on_();
				break;

			default :
				break;
		}
	}

	/* The reactions of state motor (off). */
	private void react_main_region_motor__off_() {
		if (check_main_region_motor__off__tr0_tr0()) {
			effect_main_region_motor__off__tr0();
		}
	}

	/* The reactions of state motor (on). */
	private void react_main_region_motor__on_() {
		if (check_main_region_motor__on__tr0_tr0()) {
			effect_main_region_motor__on__tr0();
		} else {
			if (check_main_region_motor__on__tr1_tr1()) {
				effect_main_region_motor__on__tr1();
			}
		}
	}

	/* Default react sequence for initial entry  */
	private void react_main_region__entry_Default() {
		enterSequence_main_region_motor__off__default();
	}

	public void runCycle() {
		if (!initialized)
			throw new IllegalStateException(
					"The state machine needs to be initialized first by calling the init() function.");

		clearOutEvents();

		for (nextStateIndex = 0; nextStateIndex < stateVector.length; nextStateIndex++) {

			switch (stateVector[nextStateIndex]) {
				case main_region_motor__off_ :
					react_main_region_motor__off_();
					break;
				case main_region_motor__on_ :
					react_main_region_motor__on_();
					break;
				default :
					// $NullState$
			}
		}

		clearEvents();
	}
}

package org.yakindu.scr.clock;
import org.yakindu.scr.ITimer;

public class ClockStatemachine implements IClockStatemachine {

	protected class SCInterfaceImpl implements SCInterface {

		private boolean mode;

		public void raiseMode() {
			mode = true;
		}

		private boolean set;

		public void raiseSet() {
			set = true;
		}

		private long time;

		public long getTime() {
			return time;
		}

		public void setTime(long value) {
			this.time = value;
		}

		private long hour;

		public long getHour() {
			return hour;
		}

		public void setHour(long value) {
			this.hour = value;
		}

		private long min;

		public long getMin() {
			return min;
		}

		public void setMin(long value) {
			this.min = value;
		}

		private long sec;

		public long getSec() {
			return sec;
		}

		public void setSec(long value) {
			this.sec = value;
		}

		protected void clearEvents() {
			mode = false;
			set = false;
		}

	}

	protected SCInterfaceImpl sCInterface;

	private boolean initialized = false;

	public enum State {
		_0_Display, _0_Display_r1_DisplayHour, _0_Display_r1_DisplayMinutes, _0_Set, _0_Set_r1_SetHour, _0_Set_r1_SetMinutes, $NullState$
	};

	private State[] historyVector = new State[1];
	private final State[] stateVector = new State[1];

	private int nextStateIndex;

	private ITimer timer;

	private final boolean[] timeEvents = new boolean[1];

	public ClockStatemachine() {

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

		for (int i = 0; i < 1; i++) {
			historyVector[i] = State.$NullState$;
		}
		clearEvents();
		clearOutEvents();

		sCInterface.setTime(23 * 60 * 60 + 59 * 60 + 60);

		sCInterface.setHour(0);

		sCInterface.setMin(0);

		sCInterface.setSec(0);
	}

	public void enter() {
		if (!initialized)
			throw new IllegalStateException(
					"The state machine needs to be initialized first by calling the init() function.");

		if (timer == null) {
			throw new IllegalStateException("timer not set.");
		}
		entryAction();

		enterSequence__0_default();
	}

	public void exit() {
		exitSequence__0();

		exitAction();
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
		sCInterface.clearEvents();

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
			case _0_Display :
				return stateVector[0].ordinal() >= State._0_Display.ordinal()
						&& stateVector[0].ordinal() <= State._0_Display_r1_DisplayMinutes.ordinal();
			case _0_Display_r1_DisplayHour :
				return stateVector[0] == State._0_Display_r1_DisplayHour;
			case _0_Display_r1_DisplayMinutes :
				return stateVector[0] == State._0_Display_r1_DisplayMinutes;
			case _0_Set :
				return stateVector[0].ordinal() >= State._0_Set.ordinal()
						&& stateVector[0].ordinal() <= State._0_Set_r1_SetMinutes.ordinal();
			case _0_Set_r1_SetHour :
				return stateVector[0] == State._0_Set_r1_SetHour;
			case _0_Set_r1_SetMinutes :
				return stateVector[0] == State._0_Set_r1_SetMinutes;
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

	public void raiseMode() {
		sCInterface.raiseMode();
	}
	public void raiseSet() {
		sCInterface.raiseSet();
	}

	public long getTime() {
		return sCInterface.getTime();
	}

	public void setTime(long value) {
		sCInterface.setTime(value);
	}
	public long getHour() {
		return sCInterface.getHour();
	}

	public void setHour(long value) {
		sCInterface.setHour(value);
	}
	public long getMin() {
		return sCInterface.getMin();
	}

	public void setMin(long value) {
		sCInterface.setMin(value);
	}
	public long getSec() {
		return sCInterface.getSec();
	}

	public void setSec(long value) {
		sCInterface.setSec(value);
	}

	private boolean check__lr0() {
		return timeEvents[0];
	}

	private boolean check__0_Display_tr0_tr0() {
		return sCInterface.set;
	}

	private boolean check__0_Display_r1_DisplayHour_tr0_tr0() {
		return sCInterface.mode;
	}

	private boolean check__0_Display_r1_DisplayMinutes_tr0_tr0() {
		return sCInterface.mode;
	}

	private boolean check__0_Set_r1_SetHour_tr0_tr0() {
		return sCInterface.set;
	}

	private boolean check__0_Set_r1_SetHour_tr1_tr1() {
		return sCInterface.mode;
	}

	private boolean check__0_Set_r1_SetMinutes_tr0_tr0() {
		return sCInterface.mode;
	}

	private boolean check__0_Set_r1_SetMinutes_tr1_tr1() {
		return sCInterface.set;
	}

	private void effect__lr0() {
		sCInterface.setTime(sCInterface.getTime() + 1);

		sCInterface.setSec(sCInterface.time % 60);

		sCInterface.setMin((sCInterface.time / 60) % 60);

		sCInterface.setHour((sCInterface.time / 3600) % 24);
	}

	private void effect__0_Display_tr0() {
		exitSequence__0_Display();

		enterSequence__0_Set_default();
	}

	private void effect__0_Display_r1_DisplayHour_tr0() {
		exitSequence__0_Display_r1_DisplayHour();

		enterSequence__0_Display_r1_DisplayMinutes_default();
	}

	private void effect__0_Display_r1_DisplayMinutes_tr0() {
		exitSequence__0_Display_r1_DisplayMinutes();

		enterSequence__0_Display_r1_DisplayHour_default();
	}

	private void effect__0_Set_r1_SetHour_tr0() {
		exitSequence__0_Set_r1_SetHour();

		enterSequence__0_Set_r1_SetMinutes_default();
	}

	private void effect__0_Set_r1_SetHour_tr1() {
		exitSequence__0_Set_r1_SetHour();

		sCInterface.setTime(sCInterface.getTime() + 3600);

		enterSequence__0_Set_r1_SetHour_default();
	}

	private void effect__0_Set_r1_SetMinutes_tr0() {
		exitSequence__0_Set_r1_SetMinutes();

		sCInterface.setTime(sCInterface.getTime() + 60);

		enterSequence__0_Set_r1_SetMinutes_default();
	}

	private void effect__0_Set_r1_SetMinutes_tr1() {
		exitSequence__0_Set();

		react__0_Display_r1_his();
	}

	/* Entry action for statechart 'clock'. */
	private void entryAction() {

		timer.setTimer(this, 0, 1 * 1000, true);
	}

	/* Exit action for state 'clock'. */
	private void exitAction() {
		timer.unsetTimer(this, 0);
	}

	/* 'default' enter sequence for state Display */
	private void enterSequence__0_Display_default() {
		enterSequence__0_Display_r1_default();
	}

	/* 'default' enter sequence for state DisplayHour */
	private void enterSequence__0_Display_r1_DisplayHour_default() {
		nextStateIndex = 0;
		stateVector[0] = State._0_Display_r1_DisplayHour;

		historyVector[0] = stateVector[0];
	}

	/* 'default' enter sequence for state DisplayMinutes */
	private void enterSequence__0_Display_r1_DisplayMinutes_default() {
		nextStateIndex = 0;
		stateVector[0] = State._0_Display_r1_DisplayMinutes;

		historyVector[0] = stateVector[0];
	}

	/* 'default' enter sequence for state Set */
	private void enterSequence__0_Set_default() {
		enterSequence__0_Set_r1_default();
	}

	/* 'default' enter sequence for state SetHour */
	private void enterSequence__0_Set_r1_SetHour_default() {
		nextStateIndex = 0;
		stateVector[0] = State._0_Set_r1_SetHour;
	}

	/* 'default' enter sequence for state SetMinutes */
	private void enterSequence__0_Set_r1_SetMinutes_default() {
		nextStateIndex = 0;
		stateVector[0] = State._0_Set_r1_SetMinutes;
	}

	/* 'default' enter sequence for region 0 */
	private void enterSequence__0_default() {
		react__0__entry_Default();
	}

	/* 'default' enter sequence for region r1 */
	private void enterSequence__0_Display_r1_default() {
		react__0_Display_r1__entry_Default();
	}

	/* shallow enterSequence with history in child r1 */
	private void shallowEnterSequence__0_Display_r1() {
		switch (historyVector[0]) {
			case _0_Display_r1_DisplayHour :
				enterSequence__0_Display_r1_DisplayHour_default();
				break;

			case _0_Display_r1_DisplayMinutes :
				enterSequence__0_Display_r1_DisplayMinutes_default();
				break;

			default :
				break;
		}
	}

	/* 'default' enter sequence for region r1 */
	private void enterSequence__0_Set_r1_default() {
		react__0_Set_r1__entry_Default();
	}

	/* Default exit sequence for state Display */
	private void exitSequence__0_Display() {
		exitSequence__0_Display_r1();
	}

	/* Default exit sequence for state DisplayHour */
	private void exitSequence__0_Display_r1_DisplayHour() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}

	/* Default exit sequence for state DisplayMinutes */
	private void exitSequence__0_Display_r1_DisplayMinutes() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}

	/* Default exit sequence for state Set */
	private void exitSequence__0_Set() {
		exitSequence__0_Set_r1();
	}

	/* Default exit sequence for state SetHour */
	private void exitSequence__0_Set_r1_SetHour() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}

	/* Default exit sequence for state SetMinutes */
	private void exitSequence__0_Set_r1_SetMinutes() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}

	/* Default exit sequence for region 0 */
	private void exitSequence__0() {
		switch (stateVector[0]) {
			case _0_Display_r1_DisplayHour :
				exitSequence__0_Display_r1_DisplayHour();
				break;

			case _0_Display_r1_DisplayMinutes :
				exitSequence__0_Display_r1_DisplayMinutes();
				break;

			case _0_Set_r1_SetHour :
				exitSequence__0_Set_r1_SetHour();
				break;

			case _0_Set_r1_SetMinutes :
				exitSequence__0_Set_r1_SetMinutes();
				break;

			default :
				break;
		}
	}

	/* Default exit sequence for region r1 */
	private void exitSequence__0_Display_r1() {
		switch (stateVector[0]) {
			case _0_Display_r1_DisplayHour :
				exitSequence__0_Display_r1_DisplayHour();
				break;

			case _0_Display_r1_DisplayMinutes :
				exitSequence__0_Display_r1_DisplayMinutes();
				break;

			default :
				break;
		}
	}

	/* Default exit sequence for region r1 */
	private void exitSequence__0_Set_r1() {
		switch (stateVector[0]) {
			case _0_Set_r1_SetHour :
				exitSequence__0_Set_r1_SetHour();
				break;

			case _0_Set_r1_SetMinutes :
				exitSequence__0_Set_r1_SetMinutes();
				break;

			default :
				break;
		}
	}

	/* The reactions of state DisplayHour. */
	private void react__0_Display_r1_DisplayHour() {
		if (check__lr0()) {
			effect__lr0();
		}

		if (check__0_Display_tr0_tr0()) {
			effect__0_Display_tr0();
		} else {
			if (check__0_Display_r1_DisplayHour_tr0_tr0()) {
				effect__0_Display_r1_DisplayHour_tr0();
			}
		}
	}

	/* The reactions of state DisplayMinutes. */
	private void react__0_Display_r1_DisplayMinutes() {
		if (check__lr0()) {
			effect__lr0();
		}

		if (check__0_Display_tr0_tr0()) {
			effect__0_Display_tr0();
		} else {
			if (check__0_Display_r1_DisplayMinutes_tr0_tr0()) {
				effect__0_Display_r1_DisplayMinutes_tr0();
			}
		}
	}

	/* The reactions of state SetHour. */
	private void react__0_Set_r1_SetHour() {
		if (check__lr0()) {
			effect__lr0();
		}

		if (check__0_Set_r1_SetHour_tr0_tr0()) {
			effect__0_Set_r1_SetHour_tr0();
		} else {
			if (check__0_Set_r1_SetHour_tr1_tr1()) {
				effect__0_Set_r1_SetHour_tr1();
			}
		}
	}

	/* The reactions of state SetMinutes. */
	private void react__0_Set_r1_SetMinutes() {
		if (check__lr0()) {
			effect__lr0();
		}

		if (check__0_Set_r1_SetMinutes_tr0_tr0()) {
			effect__0_Set_r1_SetMinutes_tr0();
		} else {
			if (check__0_Set_r1_SetMinutes_tr1_tr1()) {
				effect__0_Set_r1_SetMinutes_tr1();
			}
		}
	}

	/* Default react sequence for initial entry  */
	private void react__0__entry_Default() {
		enterSequence__0_Display_default();
	}

	/* Default react sequence for initial entry  */
	private void react__0_Display_r1__entry_Default() {
		enterSequence__0_Display_r1_DisplayHour_default();
	}

	/* Default react sequence for shallow history entry his */
	private void react__0_Display_r1_his() {
		/* Enter the region with shallow history */
		if (historyVector[0] != State.$NullState$) {
			shallowEnterSequence__0_Display_r1();
		}
	}

	/* Default react sequence for initial entry  */
	private void react__0_Set_r1__entry_Default() {
		enterSequence__0_Set_r1_SetHour_default();
	}

	public void runCycle() {
		if (!initialized)
			throw new IllegalStateException(
					"The state machine needs to be initialized first by calling the init() function.");

		clearOutEvents();

		for (nextStateIndex = 0; nextStateIndex < stateVector.length; nextStateIndex++) {

			switch (stateVector[nextStateIndex]) {
				case _0_Display_r1_DisplayHour :
					react__0_Display_r1_DisplayHour();
					break;
				case _0_Display_r1_DisplayMinutes :
					react__0_Display_r1_DisplayMinutes();
					break;
				case _0_Set_r1_SetHour :
					react__0_Set_r1_SetHour();
					break;
				case _0_Set_r1_SetMinutes :
					react__0_Set_r1_SetMinutes();
					break;
				default :
					// $NullState$
			}
		}

		clearEvents();
	}
}

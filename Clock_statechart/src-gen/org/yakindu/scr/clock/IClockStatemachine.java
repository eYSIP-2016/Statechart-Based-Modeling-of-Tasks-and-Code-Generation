package org.yakindu.scr.clock;
import org.yakindu.scr.IStatemachine;
import org.yakindu.scr.ITimerCallback;

public interface IClockStatemachine extends ITimerCallback, IStatemachine {

	public interface SCInterface {
		public void raiseMode();
		public void raiseSet();
		public long getTime();
		public void setTime(long value);
		public long getHour();
		public void setHour(long value);
		public long getMin();
		public void setMin(long value);
		public long getSec();
		public void setSec(long value);

	}

	public SCInterface getSCInterface();

}

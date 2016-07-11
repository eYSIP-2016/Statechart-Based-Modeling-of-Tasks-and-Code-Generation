package org.yakindu.scr.water_level_controller;
import org.yakindu.scr.IStatemachine;
import org.yakindu.scr.ITimerCallback;

public interface IWater_level_controllerStatemachine extends ITimerCallback, IStatemachine {
	public interface SCInterface {
		public long getWater_level();
		public void setWater_level(long value);
		public long getMax_water_level();
		public void setMax_water_level(long value);

	}

	public SCInterface getSCInterface();

}

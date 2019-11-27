/**
 * 基于霍尔传感器，检测电机转数，计算速度
 */

#ifndef _SPEEDMONITOR_h
#define _SPEEDMONITOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "GlobalDefine.h"

class SpeedMonitorClass
{
private:
	//电机一圈磁铁数量
	const unsigned int MAGNET_COUT = 2;

	//每两个信号之前的Delta最小值
	const unsigned int SIGNAL_DELTA_TIME = 30;

	bool isEnableMonitor = false;
	

protected:


public:
	//每秒信号数量
	int SignalCountPerSecond;

	//电机每秒转数
	int GetMotorRoundPerSecond();

	void Init();

	void Tick();

	void EnableHallSensorMonitor(bool isEnable);
};

extern SpeedMonitorClass SpeedMonitor;

#endif


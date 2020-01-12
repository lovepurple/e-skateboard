// MotorController.h

#ifndef _MOTORCONTROLLER_h
#define _MOTORCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "GlobalDefine.h"
#include "TimerOne.h"
#include "Utility.h"
#include "MessageDefine.h"
#include "MessageHandler.h"
#include "SpeedMonitor.h"
#include "VisibilityMonitor.h"


class MotorControllerClass
{
private:
	float m_currentMotorDuty = 0.0;
	bool m_hasChangedPower = true;

	void InitializePWM();

	static float m_GearToPWM[5];

public:
	void init();

	bool IsPowerOn();

	void PowerOn();

	void PowerOff();

	//初始化电调
	void InitializeESC();

	//电机正常启动
	void MotorStarup();

	void MotorMinPower();

	/**
	 * 设置最大油门（只有在设置电调时生效）
	 */
	void MotorMaxPower();

	//使用百分比设置速度
	bool SetMotorPower(const float percentage01);

	//获取当前百分比的速度
	float GetMotorPower();

	//使用占空比设置速度
	void SetSpeedByDuty(float pwmDuty);

	//使用档位设置速度
	void SetSpeedByGear(unsigned int gearID);

	/**
	 * 转换档位数到PWM
	 */
	float ConvertGearToPWMDuty(unsigned int gearID);

	/**
	 * 转换当PWM到档数位
	 */
	int ConvertPWMToGear(float pwmDuty);

	//刹车
	void Break();

	/**************消息处理************************/
	//todo:之后用(void*)
	//处理获取当前速度消息
	//C++常用的方式，对象内存传入，不在函数内分配新的堆内容
	char* Handle_GetCurrentSpeedMessage();

	//设置速度处理
	void Handle_SetPercentageSpeedMessage(Message& message);
};

extern MotorControllerClass MotorController;

#endif


#include <iostream>
#include<windows.h>

class GPU
{
public:
	void TurnOn()
	{
		std::cout << "GPU turned on\n";
		Sleep(250);
	}
	void CheckScreenConnection()
	{
		std::cout << "Checking screen connection\n";
		Sleep(250);
	}
	void PrintRAM()
	{
		std::cout << "Showing RAM info\n";
		Sleep(250);
	}
	void PrintWinchester()
	{
		std::cout << "Showing Winchester info\n";
		Sleep(250);
	}
	void GoodBye()
	{
		std::cout << "Print goodbye message\n";
		Sleep(250);
	}
};

class RAM
{
public:
	void TurnOn()
	{
		std::cout << "RAM turned on\n";
		Sleep(250);
	}
	void MemoryCheck()
	{
		std::cout << "Checking memory\n";
		Sleep(250);
	}
	void Clear()
	{
		std::cout << "Clearing memory\n";
		Sleep(250);
	}
};

class Winchester
{
public:
	void TurnOn()
	{
		std::cout << "Winchester turned on\n";
		Sleep(250);
	}
	void Check()
	{
		std::cout << "Checking loading sector\n";
		Sleep(250);
	}
	void TurnOff()
	{
		std::cout << "Shutting down device\n";
		Sleep(250);
	}
};

class PSU
{
public:
	void GivePower()
	{
		std::cout << "Power turned on\n";
		Sleep(250);
	}
	void GiveGPUPower()
	{
		std::cout << "Power for GPU turned on\n";
		Sleep(250);
	}
	void GiveRAMPower()
	{
		std::cout << "Power for RAM turned on\n";
		Sleep(250);
	}
	void GivePowerWinchester()
	{
		std::cout << "Power for Winchester turned on\n";
		Sleep(250);
	}
	void TurnOffPowerGPU()
	{
		std::cout << "GPU power turned off\n";
		Sleep(250);
	}
	void TurnOffPowerRAM()
	{
		std::cout << "RAM power turned off\n";
		Sleep(250);
	}
	void TurnOffPowerWinchester()
	{
		std::cout << "Winchester power turned off\n";
		Sleep(250);
	}
	void TurnOff()
	{
		std::cout << "PSU turned off\n";
		Sleep(250);
	}
};

class Sensors
{
public:
	void CheckVoltage()
	{
		std::cout << "Checking voltage\n";
		Sleep(250);
	}
	void CheckPSUTemperature()
	{
		std::cout << "Checking PSU temperature\n";
		Sleep(250);
	}
	void CheckGPUTemprerature()
	{
		std::cout << "Checking GPU temperature\n";
		Sleep(250);
	}
	void CheckRAMTemperature()
	{
		std::cout << "Checking RAM temperature\n";
		Sleep(250);
	}
	void CheckAllTemperature()
	{
		std::cout << "Checking temperature of all systems\n";
		Sleep(250);
	}
};

class PC
{
private:
	GPU gpu;
	PSU psu;
	RAM ram;
	Winchester win;
	Sensors sensors;
public:
	void TurnOn()
	{
		psu.GivePower();
		sensors.CheckVoltage();
		sensors.CheckPSUTemperature();
		sensors.CheckGPUTemprerature();
		psu.GiveGPUPower();
		gpu.TurnOn();
		gpu.CheckScreenConnection();
		sensors.CheckRAMTemperature();
		psu.GiveRAMPower();
		ram.TurnOn();
		ram.MemoryCheck();
		gpu.PrintRAM();
		psu.GivePowerWinchester();
		win.TurnOn();
		win.Check();
		gpu.PrintWinchester();
		sensors.CheckAllTemperature();
	}
	void TurnOff()
	{
		win.TurnOff();
		ram.Clear();
		ram.MemoryCheck();
		gpu.GoodBye();
		psu.TurnOffPowerGPU();
		psu.TurnOffPowerRAM();
		psu.TurnOffPowerWinchester();
		sensors.CheckVoltage();
		psu.TurnOff();
	}
};

int main()
{
	PC pc;
	pc.TurnOn();
	std::cout << '\n';
	pc.TurnOff();
}
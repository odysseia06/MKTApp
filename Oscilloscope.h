#pragma once
#include <visa.h>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <functional>
#include <math.h>
#include "Windows.h"

void replace(double& i);



class Oscilloscope
{
public:
	ViSession rmSession, scopeSession;
	ViStatus status;
	std::vector<std::string> ch1wavecommand;
	std::vector<std::string> ch2wavecommand;
	std::vector<double> ch1wave;
	std::vector<double> ch2wave;

	Oscilloscope(ViSession rmS, ViSession scS);
	void init();
	ViStatus run_commands(std::vector <std::string>& commands);
	int readHeader();
	std::vector<double> readWave(int readByte);
	double dutyCycle();
	void updateCH1Wave();
	void updateCH2Wave();
	double findCH1RMS();
	double findCH2RMS();
	double findCH1PP();
	double findCH2PP();
	double simpsonIntegration(std::vector<double> voltageWave, std::vector<double> currentWave,
		std::vector<double> x_axis);
};


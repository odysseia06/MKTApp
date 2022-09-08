#include "Oscilloscope.h"

void replace(double& i)
{
	if (i == 200.0)
		i = 0;
	if (i == -200.0)
		i = 0;
}

Oscilloscope::Oscilloscope(ViSession rmS, ViSession scS)
{
	rmSession = rmS;
	scopeSession = scS;
	ch1wavecommand = { ":WAV:SOUR CHAN1", ":WAV:MODE NORM", ":WAV:FORM ASC", ":WAV:DATA?" };
	ch2wavecommand = { ":WAV:SOUR CHAN2", ":WAV:MODE NORM", ":WAV:FORM ASC", ":WAV:DATA?" };
}

void Oscilloscope::init()
{
	ViChar buffer[1024];
	ViFindList resourceList;
	ViUInt32 numResources, ioBytes;
	char usbResource[VI_FIND_BUFLEN];
	status = viOpenDefaultRM(&rmSession); //Open Default RM
	if (status != VI_SUCCESS) {
		return;
	}
	//Find Resource
	status = viFindRsrc(rmSession, (ViConstString)"USB?*INSTR", &resourceList, &numResources, usbResource);
	if (status != VI_SUCCESS) {
		return;
	}
	status = viOpen(rmSession, usbResource, VI_NULL, VI_NULL, &scopeSession); //Open a session
	if (status != VI_SUCCESS) {
		return;
	}

	return;
}

ViStatus Oscilloscope::run_commands(std::vector <std::string>& commands)
{
	ViChar buffer[1024];
	char cmd[64];
	for (std::string n : commands) {
		strcpy_s(cmd, n.c_str());
		status = viWrite(scopeSession, (ViBuf)cmd, (ViUInt32)strlen(cmd), VI_NULL);
		if (status != VI_SUCCESS) {
			return status;
			break;
		}
	}
	return status;
}

int Oscilloscope::readHeader()
{
	//Assumes TMC Header has exactly 11 characters.
	static char readFirst[2];
	static char readHead[9];
	ViUInt32 ioBytes;
	status = viRead(scopeSession, (ViPBuf)readFirst, (ViUInt32)2, &ioBytes);
	//Handle the errors later
	status = viRead(scopeSession, (ViPBuf)readHead, (ViUInt32)9, &ioBytes);
	
	auto readByte = std::strtol(readHead, nullptr, 10);
	return readByte;

}

std::vector<double> Oscilloscope::readWave(int readByte)
{
	ViUInt32 ioBytes;
	char* readWaveAsc = new char[readByte];
	status = viRead(scopeSession, (ViPBuf)readWaveAsc, (ViUInt32)readByte, &ioBytes);
	std::vector<double> wave;
	std::stringstream ss(readWaveAsc);
	while (ss.good())
	{
		std::string substr;
		std::getline(ss, substr, ',');
		try {
			double subdb = std::stod(substr);
			wave.push_back(subdb);
		}
		catch (std::invalid_argument) {
			continue;
		}
	}
	delete[] readWaveAsc;
	return wave;
}

double Oscilloscope::dutyCycle()
{
	status = viWrite(scopeSession, (ViConstBuf)":TIM:MAIN:SCAL 0.05",
		(ViUInt32)strlen(":TIM:MAIN:SCAL 0.05"), VI_NULL);
	std::vector<double> dutycycles;
	Sleep(1000);
	for (int i = 0; i < 5; i++)
	{
		run_commands(ch1wavecommand);
		int readByte = readHeader();
		auto wave = readWave(readByte);
		std::for_each(wave.begin(), wave.end(), replace);
		double target = 0;
		double count = std::count(wave.begin(), wave.end(), target);
		double dutycycle = (wave.size() - count) / (wave.size());
		dutycycles.push_back(dutycycle);
	}
	double dutycycle_avg = std::accumulate(dutycycles.begin(), dutycycles.end(), 0.0) / dutycycles.size();
	return dutycycle_avg;
}

void Oscilloscope::updateCH1Wave()
{
	run_commands(ch1wavecommand);
	int readByte = readHeader();
	ch1wave = readWave(readByte);
}

void Oscilloscope::updateCH2Wave()
{
	run_commands(ch2wavecommand);
	int readByte = readHeader();
	ch2wave = readWave(readByte);
}

double Oscilloscope::findCH1RMS()
{
	double sum = 0;
	double rms;
	for (double i : ch1wave)
		sum += pow(i, 2.0);
	rms = sqrt((sum / ch1wave.size()));
	return rms;
}

double Oscilloscope::findCH2RMS()
{
	double sum = 0;
	double rms;
	for (double i : ch2wave)
		sum += pow(i, 2.0);
	rms = sqrt((sum / ch2wave.size()));
	return rms;
}

double Oscilloscope::findCH1PP()
{
	double max = *std::max_element(ch1wave.begin(), ch1wave.end());
	double min = *std::min_element(ch1wave.begin(), ch1wave.end());
	return (max - min);
}

double Oscilloscope::findCH2PP()
{
	double max = *std::max_element(ch2wave.begin(), ch2wave.end());
	double min = *std::min_element(ch2wave.begin(), ch2wave.end());
	return (max - min);
}

double Oscilloscope::simpsonIntegration(std::vector<double> voltageWave, std::vector<double> currentWave,
	std::vector<double> x_axis)
{
	std::vector<double> powerWave;
	double result = 0;
	std::transform(voltageWave.begin(), voltageWave.end(), currentWave.begin(), std::back_inserter(powerWave),
		std::multiplies<double>());
	for (int i = 1; i < 599; i = i + 2) //You can take 600 points from oscilloscope in the Normal mode.
	{
		result += powerWave[i - 1];
		result += powerWave[i] * (double)4;
		result += powerWave[i + 1];
	}

	result *= (x_axis[1] - x_axis[0]) / (double)3;

	result /= (x_axis.back() - x_axis.front());

	return result;
}


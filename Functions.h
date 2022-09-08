#pragma once
#include "framework.h"
#include "resource.h"
#include <vector>
#include "Oscilloscope.h"


extern std::vector<int> dummyWaveParams;
extern std::vector<int> dummyCalcParams;

extern int ch1vppC, ch1vppA, ch1vppL, ch2vppC, ch2vppA, ch2vppL,
ch1vrmsC, ch1vrmsA, ch1vrmsL, ch2vrmsC, ch2vrmsA, ch2vrmsL;

extern std::vector<int> waveParams;

extern RECT waveParamRect;
extern RECT calcParamRect;

extern RECT waveTitle;
extern RECT ch1;
extern RECT ch2;
extern RECT vpp1;
extern RECT vpp2;
extern RECT vpp3;
extern RECT vrms1;
extern RECT vrms2;
extern RECT vrms3;
extern RECT ch1vpp1;
extern RECT ch1vpp2;
extern RECT ch1vpp3;
extern RECT ch1vrms1;
extern RECT ch1vrms2;
extern RECT ch1vrms3;
extern RECT ch2vpp1;
extern RECT ch2vpp2;
extern RECT ch2vpp3;
extern RECT ch2vrms1;
extern RECT ch2vrms2;
extern RECT ch2vrms3;

extern RECT calcTitle;
extern RECT periodPower1T;
extern RECT periodPower2T;
extern RECT periodPower3T;
extern RECT plasmaPower1T;
extern RECT plasmaPower2T;
extern RECT plasmaPower3T;
extern RECT dutyCycleT;
extern RECT periodPower1V;
extern RECT periodPower2V;
extern RECT periodPower3V;
extern RECT plasmaPower1V;
extern RECT plasmaPower2V;
extern RECT plasmaPower3V;
extern RECT dutyCycleV;

extern std::vector<RECT*> oscPageRects;
extern std::vector<RECT*> oscWaveParams;
extern std::vector<RECT*> oscCalcParams;

extern int connection;
extern int present_page;


void appendMainMenu(HWND hWnd);
void startMessage(HWND hWnd);
void testMessage(HWND hWnd);
void drawRect(HDC hdc, RECT rect);
void drawSequence(HDC hdc, std::vector<RECT*> drawItems);
void drawOscParam(HWND hWnd, HDC hdc, std::vector<RECT*> drawItems, 
	std::vector<int> waveParams, Oscilloscope osc);


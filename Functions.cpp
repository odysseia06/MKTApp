#include "Functions.h"

std::vector<int> dummyWaveParams = { 1111, 2222, 3333, 4444, 5555, 6666,
7777, 8888, 9999, 1234, 2345, 3456 };
std::vector<int> dummyCalcParams = { 1111, 2222, 3333, 4444,
5555, 6666, 7777, 8888 };
int ch1vppC = 0, ch1vppA = 0, ch1vppL = 0, ch2vppC = 0, ch2vppA = 0, ch2vppL = 0,
ch1vrmsC = 0, ch1vrmsA = 0, ch1vrmsL = 0, ch2vrmsC = 0, ch2vrmsA = 0, ch2vrmsL = 0;
std::vector<int> waveParams = { ch1vppC, ch1vppA, ch1vppL, ch2vppC, ch2vppA, ch2vppL,
ch1vrmsC, ch1vrmsA, ch1vrmsL, ch2vrmsC, ch2vrmsA, ch2vrmsL };


RECT waveParamRect = { 50, 25, 650, 650 };
RECT* waveParamRectP = &waveParamRect;
RECT calcParamRect = { 650, 25, 1250, 650 };
RECT* calcParamRectP = &calcParamRect;
RECT waveTitle = { 250, 30, 450, 50 };
RECT* waveTitleP = &waveTitle;
RECT ch1 = { 250, 60, 350, 80 };
RECT* ch1P = &ch1;
RECT ch2 = { 350, 60, 450, 80 };
RECT* ch2P = &ch2;
RECT vpp1 = { 60, 90, 160, 110 };
RECT* vpp1P = &vpp1;
RECT vpp2 = { 60, 120, 160, 140 };
RECT* vpp2P = &vpp2;
RECT vpp3 = { 60, 150, 160, 170 };
RECT* vpp3P = &vpp3;
RECT vrms1 = { 60, 180, 160, 200 };
RECT* vrms1P = &vrms1;
RECT vrms2 = { 60, 210, 160, 230 };
RECT* vrms2P = &vrms2;
RECT vrms3 = { 60, 240, 160, 260 };
RECT* vrms3P = &vrms3;
RECT ch1vpp1 = { (INT)ch1.left, (INT)vpp1.top, (INT)ch1.right, (INT)vpp1.bottom };
RECT* ch1vpp1P = &ch1vpp1;
RECT ch1vpp2 = { (INT)ch1.left, (INT)vpp2.top, (INT)ch1.right, (INT)vpp2.bottom };
RECT* ch1vpp2P = &ch1vpp2;
RECT ch1vpp3 = { (INT)ch1.left, (INT)vpp3.top, (INT)ch1.right, (INT)vpp3.bottom };
RECT* ch1vpp3P = &ch1vpp3;
RECT ch1vrms1 = { (INT)ch1.left, (INT)vrms1.top, (INT)ch1.right, (INT)vrms1.bottom };
RECT* ch1vrms1P = &ch1vrms1;
RECT ch1vrms2 = { (INT)ch1.left, (INT)vrms2.top, (INT)ch1.right, (INT)vrms2.bottom };
RECT* ch1vrms2P = &ch1vrms2;
RECT ch1vrms3 = { (INT)ch1.left, (INT)vrms3.top, (INT)ch1.right, (INT)vrms3.bottom };
RECT* ch1vrms3P = &ch1vrms3;
RECT ch2vpp1 = { (INT)ch2.left, (INT)vpp1.top, (INT)ch2.right, (INT)vpp1.bottom };
RECT* ch2vpp1P = &ch2vpp1;
RECT ch2vpp2 = { (INT)ch2.left, (INT)vpp2.top, (INT)ch2.right, (INT)vpp2.bottom };
RECT* ch2vpp2P = &ch2vpp2;
RECT ch2vpp3 = { (INT)ch2.left, (INT)vpp3.top, (INT)ch2.right, (INT)vpp3.bottom };
RECT* ch2vpp3P = &ch2vpp3;
RECT ch2vrms1 = { (INT)ch2.left, (INT)vrms1.top, (INT)ch2.right, (INT)vrms1.bottom };
RECT* ch2vrms1P = &ch2vrms1;
RECT ch2vrms2 = { (INT)ch2.left, (INT)vrms2.top, (INT)ch2.right, (INT)vrms2.bottom };
RECT* ch2vrms2P = &ch2vrms2;
RECT ch2vrms3 = { (INT)ch2.left, (INT)vrms3.top, (INT)ch2.right, (INT)vrms3.bottom };
RECT* ch2vrms3P = &ch2vrms3;
RECT calcTitle = { 850, 30 , 1050, 50 };
RECT* calcTitleP = &calcTitle;
RECT periodPower1T = { 660, 60, 860, 80 };
RECT* periodPower1TP = &periodPower1T;
RECT periodPower2T = { 660, 90, 860, 110 };
RECT* periodPower2TP = &periodPower2T;
RECT periodPower3T = { 660, 120, 860, 140 };
RECT* periodPower3TP = &periodPower3T;
RECT plasmaPower1T = { 660, 150, 860, 170 };
RECT* plasmaPower1TP = &plasmaPower1T;
RECT plasmaPower2T = { 660, 180, 860, 200 };
RECT* plasmaPower2TP = &plasmaPower2T;
RECT plasmaPower3T = { 660, 210, 860, 230 };
RECT* plasmaPower3TP = &plasmaPower3T;
RECT dutyCycleT = { 660, 240, 860, 260 };
RECT* dutyCycleTP = &dutyCycleT;
RECT periodPower1V = { 900, 60, 1000, 80 };
RECT* periodPower1VP = &periodPower1V;
RECT periodPower2V = { 900, 90, 1000, 110 };
RECT* periodPower2VP = &periodPower2V;
RECT periodPower3V = { 900, 120, 1000, 140 };
RECT* periodPower3VP = &periodPower3V;
RECT plasmaPower1V = { 900, 150, 1000, 170 };
RECT* plasmaPower1VP = &plasmaPower1V;
RECT plasmaPower2V = { 900, 180, 1000, 200 };
RECT* plasmaPower2VP = &plasmaPower2V;
RECT plasmaPower3V = { 900, 210, 1000, 230 };
RECT* plasmaPower3VP = &plasmaPower3V;
RECT dutyCycleV = { 900, 240, 1000, 260 };
RECT* dutyCycleVP = &dutyCycleV;

extern std::vector<RECT*> oscPageRects = { waveParamRectP , calcParamRectP , waveTitleP,  ch1P, ch2P,
vpp1P , vpp2P ,vpp3P, vrms1P,  vrms2P , vrms3P , calcTitleP ,periodPower1TP,  periodPower2TP , 
periodPower3TP , plasmaPower1TP, plasmaPower2TP, plasmaPower3TP, dutyCycleTP
};

extern std::vector<RECT*> oscWaveParams = { ch1vpp1P , ch1vpp2P, ch1vpp3P , ch1vrms1P , ch1vrms2P ,
ch1vrms3P , ch2vpp1P , ch2vpp2P , ch2vpp3P , ch2vrms1P , ch2vrms2P , ch2vrms3P };

extern std::vector<RECT*> oscCalcParams = {periodPower1VP ,
periodPower2VP , periodPower3VP , plasmaPower1VP , plasmaPower2VP , plasmaPower3VP , dutyCycleVP };


int connection = NOT_CONNECTED;
int present_page = START_PAGE;


void appendMainMenu(HWND hWnd)
{
	HMENU hMenubar = CreateMenu();//Create empty menu
	HMENU hMenu = CreateMenu();
	//Create a top level pop-up menu
	AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMenu, TEXT("&Menu"));
	//Add menu items to pop-up window
	AppendMenu(hMenu, MF_STRING, IDM_MENUITEM1, TEXT("Connect"));
	AppendMenu(hMenu, MF_STRING, IDM_MENUITEM2, TEXT("Oscilloscope"));
	AppendMenu(hMenu, MF_STRING, IDM_MENUITEM3, TEXT("Spectrometer"));
	AppendMenu(hMenu, MF_STRING, IDM_EXIT, TEXT("Exit"));
	//Assigns a new menu to the specified window
	SetMenu(hWnd, hMenubar);
}

void startMessage(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	RECT r = { 10, 10, 500, 500 };
	SetTextColor(hdc, RGB(0, 0, 0));
	DrawText(hdc, (LPCWSTR)L"Monitor-Kontrol-Test Uygulamasýna hoþ geldiniz.", 
		-1, &r, DT_CENTER);
	EndPaint(hWnd, &ps);
	
}

void testMessage(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	RECT r = { 50, 50, 500, 500 };
	SetTextColor(hdc, RGB(0, 0, 0));
	DrawText(hdc, (LPCWSTR)L"Bu bir test yazýsýdýr.",
		-1, &r, DT_CENTER);
	EndPaint(hWnd, &ps);
}

void drawTextinRect(HDC hdc, RECT rect, LPCWSTR text)
{
	SetTextColor(hdc, RGB(0, 0, 0));
	DrawText(hdc, text,
		wcslen(text), &rect, DT_CENTER);
}

void drawRect(HDC hdc, RECT rect)
{
	
	
	Graphics graphics(hdc);
	Pen      pen(Color(255, 0, 0, 0));
	graphics.DrawRectangle(&pen, (INT)rect.left, (INT)rect.top, 
		(INT)(rect.right-rect.left), (INT)(rect.bottom-rect.top));
	
	
	
}

void drawSequence(HDC hdc, std::vector<RECT*> drawItems)
{
	for (auto i : drawItems)
	{
		if (i == &calcParamRect)
			drawRect(hdc, *i);
		if (i == &waveParamRect)
			drawRect(hdc, *i);
		if (i == &waveTitle) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Waveform Parameters");
		}
		if (i == &ch1) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Channel1");
		}
		if (i == &ch2) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Channel2");
		}
		if (i == &vpp1) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Vpp(Current)");
		}
		if (i == &vpp2) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Vpp(Average)");
		}
		if (i == &vpp3) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Vpp(Last 10)");
		}
		if (i == &vrms1) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Vrms(Current)");
		}
		if (i == &vrms2) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Vrms(Average)");
		}
		if (i == &vrms3) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Vrms(Last 10)");
		}
		if (i == &calcTitle) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Calculated Parameters");
		}
		if (i == &periodPower1T) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Period Power(Current)");
		}
		if (i == &periodPower2T) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Period Power(Average)");
		}
		if (i == &periodPower3T) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Period Power(Last 10)");
		}
		if (i == &plasmaPower1T) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Plasma Power(Current)");
		}
		if (i == &plasmaPower2T) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Plasma Power(Average)");
		}
		if (i == &plasmaPower3T) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Plasma Power(last 10)");
		}
		if (i == &dutyCycleT) {
			//drawRect(hdc, *i);
			drawTextinRect(hdc, *i, L"Dutycycle");
		}

	}
		
}

void drawOscParam(HWND hWnd, HDC hdc, std::vector<RECT*> drawItems, 
	std::vector<int> waveParams, Oscilloscope osc)
{
	osc.updateCH1Wave();
	osc.updateCH1Wave();
	ch1vppC = osc.findCH1PP();
	ch1vrmsC = osc.findCH1RMS();
	waveParams = { ch1vppC, ch1vppA, ch1vppL, ch2vppC, ch2vppA, ch2vppL,
ch1vrmsC, ch1vrmsA, ch1vrmsL, ch2vrmsC, ch2vrmsA, ch2vrmsL };
	for (int i = 0; i < drawItems.size(); i++)
	{
		wchar_t buffer[256];
		StringCbPrintfW(buffer, 256, L"%d", waveParams[i]);
		drawTextinRect(hdc, *drawItems[i], buffer);
		InvalidateRect(hWnd, drawItems[i], FALSE);
	}
}

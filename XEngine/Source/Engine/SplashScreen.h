#ifndef SPLASHSCREENDEFINED
#define SPLASHSCREENDEFINED

#include "Platform/Win32/Window.h"

namespace SplashScreen
{
	VOID XENGINE_API Open();
	VOID XENGINE_API Close();
	VOID XENGINE_API AddMessage(CONST WCHAR* message);
}

class XENGINE_API SplashWindow : public Win32::Window
{
public:
	SplashWindow();
	~SplashWindow();

	virtual LRESULT MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

private:
	WCHAR m_outputMessage[MAX_NAME_STRING];
};

#endif
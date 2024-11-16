#include "XEngine.h"
#include "Simulation.h"

#include "SplashScreen.h"

namespace XEngine
{
	Simulation::Simulation():
		Window(L"MainApplication", NULL, DEFAULTWIDTH, DEFAULTHEIGHT)
	{
		
	}

	VOID Simulation::PreInitialize()
	{
		Logger::PrintDebugSeparator();
		Logger::PrintLog(L"Application starting...\n");
		Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GetGameName());
		Logger::PrintLog(L"Boot time: %s\n", Time::GetDateTimeString().c_str());
		Logger::PrintLog(L"Engine Mode: %s\n", EngineModeToString().c_str());
		Logger::PrintDebugSeparator();

		SplashScreen::Open();

		Window::RegisterNewClass();
		Window::Initialize();
	}


	LRESULT Simulation::MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		/*switch (message)
		{
		}*/
		return Window::MessageHandler(hWnd, message, wParam, lParam);
	}

}

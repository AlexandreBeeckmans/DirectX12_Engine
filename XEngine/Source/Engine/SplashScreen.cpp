#include "XEngine.h"
#include "SplashScreen.h"

#include "Platform/Win32/Win32Utils.h"


namespace SplashScreen
{
	#define WM_OUTPUTMESSAGE (WM_USER + 0x0001)

	SplashWindow* m_pSplashWindow{};
	VOID Open()
	{
		if(m_pSplashWindow)
		{
			return;
		}
		m_pSplashWindow = new SplashWindow{};
	}

	VOID Close()
	{
		delete m_pSplashWindow;
	}

	VOID AddMessage(CONST WCHAR* message)
	{
		PostMessage(m_pSplashWindow->GetHandle(), WM_OUTPUTMESSAGE, (WPARAM)message, 0);
	}
}

SplashWindow::SplashWindow() :
	Window(L"SplashScreen", NULL, 500, 600, Win32::WindowType::POPUP)
{
	wcscpy_s(m_outputMessage, L"SplashScreen Starting...");
	Window::RegisterNewClass();
	Window::Initialize();
}

SplashWindow::~SplashWindow()
{
	
}

LRESULT SplashWindow::MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
		case WM_PAINT:
		{
			//HBITMAP hBitMap{};
			HDC hdc{};
			//HDC hmemdc{};
			PAINTSTRUCT paintStruct{};

			hdc = BeginPaint(hWnd, &paintStruct);

			Win32::Utils::AddBitmap(PerGameSettings::GetSplashURL(), hdc, 125, 50);


			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(255, 255, 255));

			if(Engine::GetMode() != Engine::EngineMode::RELEASE)
			{
				const std::wstring engineModeText{ EngineModeToString() + L" Mode" };
				SetTextAlign(hdc, TA_RIGHT);
				TextOut(hdc, GetSize().cx - 15, 15, engineModeText.c_str(), static_cast<int>(wcslen(engineModeText.c_str())));
			}

			
			SetTextAlign(hdc, TA_CENTER);
			TextOut(hdc, GetSize().cx / 2, GetSize().cy - 30, m_outputMessage, static_cast<int>(wcslen(m_outputMessage)));
			EndPaint(hWnd, &paintStruct);
		}
		break;

		case WM_OUTPUTMESSAGE:
		{
			WCHAR* msg{ (WCHAR*)wParam };
			wcscpy_s(m_outputMessage, msg);
			RedrawWindow();
			return 0;
		}
	}
	return Window::MessageHandler(hWnd, message, wParam, lParam);
}



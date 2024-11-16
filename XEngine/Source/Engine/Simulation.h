#ifndef SIMULATIONDEFINED
#define SIMULATIONDEFINED

namespace XEngine
{
	class XENGINE_API Simulation : public Win32::IApplication, public Win32::Window
	{
	public:
		Simulation();

		virtual ~Simulation(){}

		virtual VOID PreInitialize() override;
		virtual LRESULT MessageHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	};
}


#endif
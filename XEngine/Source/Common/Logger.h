#ifndef LOGGERDEFINED
#define LOGGERDEFINED
#include <string>

class XENGINE_API Logger
{
public:
	Logger();
	~Logger();

	static Logger* GetInstance()
	{
		return m_Instance;
	}

	static VOID PrintLog(const WCHAR* fmt, ...);

	static VOID StartMTail();
	static VOID PrintDebugSeparator();
	

private:
	static std::wstring LogDirectory();
	static std::wstring LogFile();

	

	static BOOL IsMTailRunning();

	



	static Logger* m_Instance;
};


#endif
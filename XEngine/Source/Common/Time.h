#ifndef TIMEDEFINED
#define TIMEDEFINED

#include<string>

namespace Time
{
	std::wstring XENGINE_API GetTime(BOOL stripped = FALSE);

	

	std::wstring XENGINE_API GetDate(BOOL stripped = FALSE);

	std::wstring XENGINE_API GetDateTimeString(BOOL stripped = FALSE);

	std::tm XENGINE_API GetLocalTime();

	
}

#endif
#include "XEngine.h"

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <sstream>


std::wstring Time::GetTime(BOOL stripped)
{
	std::tm localTime{ GetLocalTime() };
	std::wstringstream wss{};
	wss << std::put_time(&localTime, L"%H:%M:%S");

	std::wstring timeString{ wss.str() };

	if(!stripped)
	{
		return timeString;
	}

	std::erase(timeString, L':');

	return timeString;
}

std::wstring Time::GetDate(BOOL stripped)
{
	std::tm localTime{ GetLocalTime() };

	std::wstringstream wss{};
	wss << std::put_time(&localTime, L"%d/%m/%y");

	std::wstring timeString{ wss.str() };

	if(!stripped)
	{
		return timeString;
	}

	std::erase(timeString, L'/');

	return timeString;
}

std::wstring Time::GetDateTimeString(BOOL stripped)
{
	std::wstring timeString = GetDate(stripped) + L' ' + GetTime(stripped);

	if(!stripped)
	{
		return timeString;
	}

	std::erase(timeString, L' ');
	return timeString;
}

std::tm Time::GetLocalTime()
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	std::tm localTime{};
	localtime_s(&localTime, &currentTime);

	return localTime;
}

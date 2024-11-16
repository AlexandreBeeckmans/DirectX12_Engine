#include "XEngine.h"

#include <filesystem>
#include <fstream>
#include <Shlobj.h>

#include <cstdio>
#include <TlHelp32.h>


Logger* Logger::m_Instance{};

Logger::Logger()
{
	m_Instance = this;
}

Logger::~Logger()
{
}

void Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buffer[4096];
	va_list args{};

	va_start(args, fmt);
	vswprintf_s(buffer, fmt, args);
	va_end(args);

	OutputDebugString(buffer);

	std::filesystem::path logPath = LogDirectory() + L"/" + LogFile();

	if (std::wofstream outFile{ logPath, std::ios_base::app })
	{
		outFile << L"[" << Time::GetDateTimeString() << L"]" << buffer;

	}
	else
	{
		MessageBox(nullptr, L"Unable to open Log file", L"Log Error", MB_OK);
	}

}

std::wstring Logger::LogDirectory()
{
	WCHAR path[1024]{};
	WCHAR* appDataLocal{};
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &appDataLocal);

	wcscpy_s(path, appDataLocal);
	wcscat_s(path, L"\\");
	wcscat_s(path, PerGameSettings::GetGameName());
	CreateDirectory(path, NULL);
	wcscat_s(path, L"\\Log");
	CreateDirectory(path, NULL);
	return path;
}

std::wstring Logger::LogFile()
{
	WCHAR file[1024]{};
	wcscpy_s(file, PerGameSettings::GetGameName());
	wcscat_s(file, PerGameSettings::GetBootTime());
	wcscat_s(file, L".log");

	return file;
}

VOID Logger::PrintDebugSeparator()
{
#ifndef _DEBUG
	return
#endif

	std::wstring separatorString{ L"\n---------------------------------------------------------------------------------------------------------\n\n" };
	std::filesystem::path logPath = LogDirectory() + L"/" + LogFile();

	if (std::wofstream outFile{ logPath, std::ios_base::app })
	{
		outFile << separatorString;

	}
	else
	{
		MessageBox(nullptr, L"Unable to open Log file", L"Log Error", MB_OK);
	}

}

BOOL Logger::IsMTailRunning()
{
	bool exists{ false };
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot{ CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL) };

	if(Process32First(snapshot, &entry))
	{
		while(Process32Next(snapshot, &entry))
		{
			if(!_wcsicmp(entry.szExeFile, L"mTAIL.exe"))
			{
				exists = true;
			}
		}
	}

	CloseHandle(snapshot);
	return exists;
}

VOID Logger::StartMTail()
{
	if(IsMTailRunning())
	{
		PrintLog(L"--MTail failed to start - Already running\n");
		return;
	}

	PrintLog(L"--Starting MTail\n");

	WCHAR path[MAX_PATH]{ 0 };
	GetCurrentDirectory(MAX_PATH, path);
	std::wstring url{ path + std::wstring(L"/mTAIL.exe") };
	std::wstring params{ L"\"" + LogDirectory() + L"/" + LogFile() + L"\" /start" };
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);
}

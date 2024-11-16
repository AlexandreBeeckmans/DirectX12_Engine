#include "XEngine.h"

PerGameSettings* PerGameSettings::m_Instance{};

PerGameSettings::PerGameSettings()
{
	m_Instance = this;

	wcscpy_s(m_Instance->m_GameName, L"undefined");
	wcscpy_s(m_Instance->m_ShortName, L"undefined");
	wcscpy_s(m_Instance->m_BootTime, Time::GetDateTimeString(TRUE).c_str());
	wcscpy_s(m_Instance->m_splashURL, L"..\\XEngine\\Content\\Images\\logo.png");
}

PerGameSettings::~PerGameSettings()
{
}

WCHAR* PerGameSettings::GetGameName()
{
	return m_Instance->m_GameName;
}

VOID PerGameSettings::SetGameName(const UINT id)
{
	LoadString(HInstance(), id, m_Instance->m_GameName, MAX_NAME_STRING);
}

WCHAR* PerGameSettings::GetShortName()
{
	return m_Instance->m_ShortName;
}

VOID PerGameSettings::SetShortName(const UINT id)
{
	LoadString(HInstance(), id, m_Instance->m_ShortName, MAX_NAME_STRING);
}

HICON PerGameSettings::GetMainIcon()
{
	return m_Instance->m_MainIcon;
}

VOID PerGameSettings::SetMainIcon(const UINT id)
{
	LoadIcon(HInstance(), MAKEINTRESOURCE(id));
}

WCHAR* PerGameSettings::GetBootTime()
{
	return m_Instance->m_BootTime;
}

WCHAR* PerGameSettings::GetSplashURL()
{
	return m_Instance->m_splashURL;
}

void PerGameSettings::SetSplashURL(const UINT id)
{
	LoadString(HInstance(), id, m_Instance->m_splashURL, MAX_NAME_STRING);
}

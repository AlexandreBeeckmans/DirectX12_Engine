#ifndef PERGAMESETTINGSDEFINED
#define PERGAMESETTINGSDEFINED

class XENGINE_API PerGameSettings
{
public:
	PerGameSettings();
	~PerGameSettings();

	static WCHAR* GetGameName();
	static VOID SetGameName(const UINT id);

	static WCHAR* GetShortName();
	static VOID SetShortName(const UINT id);

	static HICON GetMainIcon();
	static VOID SetMainIcon(const UINT id);

	static WCHAR* GetBootTime();

	static WCHAR* GetSplashURL();
	static VOID SetSplashURL(const UINT id);

	


private:

	static PerGameSettings* GetInstance()
	{
		return m_Instance;
	}

	static PerGameSettings* m_Instance;


	WCHAR m_GameName[MAX_NAME_STRING];
	WCHAR m_ShortName[MAX_NAME_STRING];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_NAME_STRING];
	WCHAR m_splashURL[MAX_NAME_STRING];
};




#endif

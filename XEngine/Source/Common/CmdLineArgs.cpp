#include "XEngine.h"
#include "CmdLineArgs.h"

#include <algorithm>

namespace CmdLineArgs
{
	void ReadArguments()
	{
		int argc{ 0 };
		LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

		for(int i{1}; i < argc; ++i)
		{
			std::wstring key{ argv[i] };
			if(key[0] == '-')
			{
				key.erase(0, 1);
				std::ranges::transform(key, std::begin(key), ::towlower);
				ReadArgument(key.c_str());
			}
		}
	}

	VOID ReadArgument(const WCHAR* argument)
	{
		if(wcscmp(argument, L"mtail") == 0)
		{
			Logger::StartMTail();
			return;
		}

		if (wcscmp(argument, L"debug") == 0)
		{
			SetMode(DEBUG);
			return;
		}

		if (wcscmp(argument, L"editor") == 0)
		{
			SetMode(EDITOR);
			return;
		}

		if (wcscmp(argument, L"server") == 0)
		{
			SetMode(SERVER);
		}
	}
}

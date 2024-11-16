#include "XEngine.h"

namespace Engine
{
	OEngine g_XEngine;

	VOID SetMode (EngineMode newMode)
	{
		g_XEngine.SetEngineMode(newMode);
	}

	EngineMode GetMode()
	{
		return g_XEngine.GetEngineMode();
	}

	std::wstring EngineModeToString()
	{
		switch(GetMode())
		{
			case DEBUG:
			{
				return L"Debug";
			}

			case RELEASE:
			{
				return L"Release";
			}

			case SERVER:
			{
				return L"Server";
			}

			case EDITOR:
			{
				return L"Editor";
			}

			case NONE:
			default:
			{
					return L"None";
			}
		}
	}
}

OEngine::OEngine()
{
#ifdef _DEBUG
	m_EngineMode = DEBUG;
#else
	m_EngineMode = Engine::RELEASE;
#endif
}

OEngine::~OEngine()
{
}

EngineMode OEngine::GetEngineMode() const
{
	return m_EngineMode;
}

VOID OEngine::SetEngineMode(const EngineMode newMode)
{
	m_EngineMode = newMode;
}

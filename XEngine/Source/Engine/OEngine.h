#ifndef OENGINEDEFINED
#define OENGINEDEFINED

#include <string>

class XENGINE_API OEngine;


namespace Engine
{
	enum EngineMode : INT
	{
		NONE,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	extern OEngine g_XEngine;

	VOID XENGINE_API SetMode(EngineMode newMode);
	EngineMode XENGINE_API GetMode();
	std::wstring XENGINE_API EngineModeToString();
}

using namespace Engine;
class XENGINE_API OEngine
{
public:
	OEngine();
	~OEngine();

	EngineMode GetEngineMode() const;
	VOID SetEngineMode(const EngineMode newMode);

private :
	Engine::EngineMode m_EngineMode;
};




#endif

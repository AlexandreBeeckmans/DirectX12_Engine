#include "BlankProject.h"

#include "Engine/Simulation.h"

#include "Platform/Win32/WinEntry.h"

class BlankProject : public XEngine::Simulation
{

public:
	BlankProject() = default;
	~BlankProject() override = default;

	VOID SetupPerGameSettings() override;
	VOID Initialize() override{};
	VOID Update() override{};
};




ENTRYAPP(BlankProject)


VOID BlankProject::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
	PerGameSettings::SetSplashURL(IDS_SPLASHURL);
}



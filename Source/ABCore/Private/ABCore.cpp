
#include "IABCore.h"
#include "ABCorePrivate.h"

class FABCore : public IABCore
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FABCore, ABCore)
DEFINE_LOG_CATEGORY(LogAB);

void FABCore::StartupModule()
{}

void FABCore::ShutdownModule()
{}
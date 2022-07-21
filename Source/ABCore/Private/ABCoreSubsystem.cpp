#include "ABCoreSubsystem.h"

UABCoreSubsystem::UABCoreSubsystem()
{}

void UABCoreSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{}

void UABCoreSubsystem::Deinitialize()
{}

bool UABCoreSubsystem::LoadDecisionTableData()
{
	return true;
}

uint64 UABCoreSubsystem::GetStatusFlagData(int32 _flagID)
{
	return 0xFFFFFFFFFFFFFFFFllu;
}

uint64 UABCoreSubsystem::GetSkillFlagData(int32 _flagID)
{
	return 0xFFFFFFFFFFFFFFFFllu;
}

uint64 UABCoreSubsystem::GetBuffFlagData(int32 _flagID)
{
	return 0xFFFFFFFFFFFFFFFFllu;
}
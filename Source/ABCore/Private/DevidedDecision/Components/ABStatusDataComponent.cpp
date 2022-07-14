#include "DevidedDecision/Components/ABStatusDataComponent.h"

UStatusDataComponent::UStatusDataComponent()
{
	CurStatusDic.Empty();
	StatusFlagDic.Empty();
	SkillFlagDic.Empty();
	BuffFlagDic.Empty();
	StatusService.Empty();
	CurrentBitFlag = 0xFFFFFFFFFFFFFFFF;
}

void UStatusDataComponent::Initialize()
{}

void UStatusDataComponent::Shutdown()
{
	for (auto& iter: StatusService)
	{
		if (nullptr != iter.Value)
		{
			iter.Value->BeginDestroy();
		}
	}

	StatusService.Empty();
}

void UStatusDataComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{}

#pragma region Status Function
bool UStatusDataComponent::SetStatusGroupState(ABEStatusGroupType StatusGroup, int32 StatusValue, int32 OldValue)
{
	return false;
}

bool UStatusDataComponent::SetStatusGroupState(int32 StatusGroup, int32 StatusValue, int32 OldValue)
{
	return false;
}

bool UStatusDataComponent::SetState(int64 GlobalStateValue)
{
	return false;
}

int32 UStatusDataComponent::GetStatusGroupState(int32 StatusGroup)
{
	return 0;
}

int32 UStatusDataComponent::GetStatusGroupState(ABEStatusGroupType StatusGroup)
{
	return 0;
}
#pragma endregion

#pragma region Flag Function
bool UStatusDataComponent::AddSkillFlag(int32 FlagID)
{
	return false;
}

bool UStatusDataComponent::AddBuffFlag(int32 FlagID)
{
	return false;
}

bool UStatusDataComponent::RemoveSkillFlag(int32 FlagID)
{
	return false;
}

bool UStatusDataComponent::RemoveBuffFlag(int32 FlagID)
{
	return false;
}

uint64 UStatusDataComponent::GetCurrentBigFlag()
{
	return 0llu;
}
#pragma endregion

void UStatusDataComponent::BeginPlay()
{}
void UStatusDataComponent::BeginDestroy()
{}

uint64 UStatusDataComponent::CalculateCurrentBitFlag()
{
	return 0llu;
}

void UStatusDataComponent::OnStatusChange()
{}

void UStatusDataComponent::OnChangeStatusActiveService(ABEStatusGroupType StatusGroup, int32 StatusValue, int32 OldValue)
{}
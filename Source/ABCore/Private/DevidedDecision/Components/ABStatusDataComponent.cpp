#include "DevidedDecision/Components/ABStatusDataComponent.h"
#include "ABCoreSubsystem.h"
#include "Kismet/GameplayStatics.h"


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
bool UStatusDataComponent::SetStatusGroupState(ABEStatusGroupType StatusGroup, int32 StatusValue, int32 OldValue, bool CalculateFlag)
{
	int32 GroupValue = (int32)StatusGroup;
	return SetStatusGroupState(StatusValue, StatusValue, OldValue, CalculateFlag);
}

bool UStatusDataComponent::SetStatusGroupState(int32 StatusGroup, int32 StatusValue, int32 OldValue, bool CalculateFlag)
{
	int32 GlobalValue = 0;
	if (CurStatusDic.Contains(StatusGroup))
	{
		CurStatusDic[StatusGroup] = StatusValue;
		GlobalValue = TransStatusValue2GlobalValue(StatusGroup, StatusValue);
		AddStatusFlag(GlobalValue);
	}

	GlobalValue = TransStatusValue2GlobalValue(StatusGroup, OldValue);
	RemoveStatusFlag(GlobalValue);

	if (CalculateFlag)
	{
		OnStatusChange();
	}

	return true;
}

bool UStatusDataComponent::SetState(int32 GlobalStateValue, bool CalculateFlag)
{
	int32 StatusValue = 0xFFFFFFFF;
	int32 StatusGroup = 0xFFFFFFFF;
	TransGlobalStatusValue2Prototype(GlobalStateValue, StatusGroup, StatusValue);
	int32 OldValue = GetStatusGroupState(StatusGroup);
	
	return SetStatusGroupState(StatusGroup, StatusValue, OldValue, CalculateFlag);
}

int32 UStatusDataComponent::GetStatusGroupState(int32 StatusGroup)
{
	if (CurStatusDic.Contains(StatusGroup))
	{
		return CurStatusDic[StatusGroup];
	}

	return 0;
}

int32 UStatusDataComponent::GetStatusGroupState(ABEStatusGroupType StatusGroup)
{
	return GetStatusGroupState((int32)StatusGroup);
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

bool UStatusDataComponent::AddStatusFlag(int32 FlagID)
{
	if (StatusFlagDic.Contains(FlagID))
	{
		return false;
	}
	
	return true;
}

bool UStatusDataComponent::RemoveStatusFlag(int32 FlagID)
{
	if (StatusFlagDic.Contains(FlagID))
	{
		StatusFlagDic.Remove(FlagID);
		return true;
	}

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
	auto gameInstance = UGameplayStatics::GetGameInstance(this);
	UABCoreSubsystem* abCoreSubsys = gameInstance->GetSubsystem<UABCoreSubsystem>();
	if (nullptr == gameInstance)
	{
		return 0xFFFFFFFFFFFFFFFFllu;
	}

	uint64 tempFlag = 0xFFFFFFFFFFFFFFFFllu;
	TMap<int32, int32>::TIterator iterStatus = StatusFlagDic.CreateIterator();
	for (; iterStatus; ++iterStatus)
	{
		uint64 flagValue = abCoreSubsys->GetStatusFlagData(iterStatus->Value);
		if (0xFFFFFFFFFFFFFFFFllu != flagValue)
		{
			tempFlag &= flagValue;
		}
	}

	TMap<int32, int32>::TIterator iterSkill = SkillFlagDic.CreateIterator();
	for (; iterSkill; ++ iterSkill)
	{
		uint64 flagValue = abCoreSubsys->GetSkillFlagData(iterSkill->Value);
		if (0xFFFFFFFFFFFFFFFFllu != flagValue)
		{
			tempFlag &= flagValue;
		}
	}

	TMap<int32, int32>::TIterator iterBuff = BuffFlagDic.CreateIterator();
	for (; iterBuff; ++iterBuff)
	{
		uint64 flagValue = abCoreSubsys->GetBuffFlagData(iterBuff->Value);
		if (0xFFFFFFFFFFFFFFFFllu != flagValue)
		{
			tempFlag &= flagValue;
		}
	}
	return tempFlag;
}

void UStatusDataComponent::OnStatusChange()
{
	CurrentBitFlag = CalculateCurrentBitFlag();
}

void UStatusDataComponent::OnChangeStatusActiveService(ABEStatusGroupType StatusGroup, int32 StatusValue, int32 OldValue)
{}
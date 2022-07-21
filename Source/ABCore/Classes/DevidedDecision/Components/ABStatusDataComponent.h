/*

	Shawn Lee

*/
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "Components/ActorComponent.h"
#include "../ABStatusData.h"
#include "../ComponentDatas/Service/StatusService/ABBaseStatusService.h"

#include "ABStatusDataComponent.generated.h"

#pragma region Service Data

UCLASS(Abstract, Blueprintable)
class UStatusServiceDataElement : public UObject
{
	GENERATED_BODY()
public:
	UStatusServiceDataElement() : StatusService(nullptr)
	{}

	void BeginDestroy() override
	{
		Super::BeginDestroy();
	}

	virtual bool CheckFitStatus(int32 _statusId) { return false; }

	UPROPERTY(EditAnywhere, Instanced, Category = "Status Service")
		UABBaseStatusService* StatusService;
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusSystemServiceDataElement : public UStatusServiceDataElement
{
	GENERATED_BODY()
public:
	UStatusSystemServiceDataElement() : UStatusServiceDataElement() {}

	UPROPERTY(EditAnywhere, Category = "Status Service")
		ABESystemStatusGroupType SystemStatus;

	virtual bool CheckFitStatus(int32 _statusId) override { return (ABESystemStatusGroupType)_statusId == SystemStatus; }
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusLiveServiceDataElement : public UStatusServiceDataElement
{
	GENERATED_BODY()
public:
	UStatusLiveServiceDataElement() : UStatusServiceDataElement() {}

	UPROPERTY(EditAnywhere, Category = "Status Service")
		ABEAliveStatusGroupType DeathStatus;

	virtual bool CheckFitStatus(int32 _statusId) override { return (ABEAliveStatusGroupType)_statusId == DeathStatus; }
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusRiddingServiceDataElement : public UStatusServiceDataElement
{
	GENERATED_BODY()
public:
	UStatusRiddingServiceDataElement() : UStatusServiceDataElement() {}

	UPROPERTY(EditAnywhere, Category = "Status Service")
		ABERidingStatusGroupType RiddingStatus;

	virtual bool CheckFitStatus(int32 _statusId) override { return (ABERidingStatusGroupType)_statusId == RiddingStatus; }
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusEvironmentServiceDataElement : public UStatusServiceDataElement
{
	GENERATED_BODY()
public:
	UStatusEvironmentServiceDataElement() : UStatusServiceDataElement() {}

	UPROPERTY(EditAnywhere, Category = "Status Service")
		ABEEvironmentStatusGroupType EvironmentStatus;

	virtual bool CheckFitStatus(int32 _statusId) override { return (ABEEvironmentStatusGroupType)_statusId == EvironmentStatus; }
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusCombatServiceDataElement : public UStatusServiceDataElement
{
	GENERATED_BODY()
public:
	UStatusCombatServiceDataElement() : UStatusServiceDataElement() {}

	UPROPERTY(EditAnywhere, Category = "Status Service")
		ABECombatStatusGroupType CombatStatus;

	virtual bool CheckFitStatus(int32 _statusId) override { return (ABECombatStatusGroupType)_statusId == CombatStatus; }
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusStanceServiceDataElement : public UStatusServiceDataElement
{
	GENERATED_BODY()
public:
	UStatusStanceServiceDataElement() : UStatusServiceDataElement() {}

	UPROPERTY(EditAnywhere, Category = "Status Service")
		ABEStanceStatusGroupType StanceStatus;

	virtual bool CheckFitStatus(int32 _statusId) override { return (ABEStanceStatusGroupType)_statusId == StanceStatus; }
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusControlServiceDataElement : public UStatusServiceDataElement
{
	GENERATED_BODY()
public:
	UStatusControlServiceDataElement() : UStatusServiceDataElement() {}

	UPROPERTY(EditAnywhere, Category = "Status Service")
		ABEControlStatusGroupType ControlStatus;

	virtual bool CheckFitStatus(int32 _statusId) override { return (ABEControlStatusGroupType)_statusId == ControlStatus; }
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusPostureServiceDataElement : public UStatusServiceDataElement
{
	GENERATED_BODY()
public:
	UStatusPostureServiceDataElement() : UStatusServiceDataElement() {}

	UPROPERTY(EditAnywhere, Category = "Status Service")
		ABEPostureStatusGroupType PostureStatus;

	virtual bool CheckFitStatus(int32 _statusId) override { return (ABEPostureStatusGroupType)_statusId == PostureStatus; }
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusBehitServiceDataElement : public UStatusServiceDataElement
{
	GENERATED_BODY()
public:
	UStatusBehitServiceDataElement() : UStatusServiceDataElement() {}

	UPROPERTY(EditAnywhere, Category = "Status Service")
		ABEBehitStatusGroupType BehitStatus;

	virtual bool CheckFitStatus(int32 _statusId) override { return (ABEBehitStatusGroupType)_statusId == BehitStatus; }
};

UCLASS(EditInlineNew, Blueprintable)
class UStatusServiceData : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Instanced, Category = "Status Service Element")
		TArray<UStatusServiceDataElement*> DataElements;

	UStatusServiceData()
	{
		DataElements.Reset();
	}

	void BeginDestroy() override
	{
		int nCount = DataElements.Num();
		for (auto& ele : DataElements)
		{
			if (nullptr != ele && !ele->IsPendingKill())
			{
				ele->BeginDestroy();
			}
		}

		DataElements.Reset();
		Super::BeginDestroy();
	}
};
#pragma endregion

UCLASS(ClassGroup = (Custom), Blueprintable, meta = (BlueprintSpawnableComponent))
class UStatusDataComponent: public UActorComponent
{
	GENERATED_BODY()
public:
	UStatusDataComponent();
	void Initialize();
	void Shutdown();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

#pragma region Status Function
	virtual bool SetStatusGroupState(ABEStatusGroupType StatusGroup, int32 StatusValue, int32 OldValue, bool CalculateFlag = true);
	virtual bool SetStatusGroupState(int32 StatusGroup, int32 StatusValue, int32 OldValue, bool CalculateFlag = true);
	virtual bool SetState(int32 GlobalStateValue, bool CalculateFlag = true);
	virtual int32 GetStatusGroupState(int32 StatusGroup);
	virtual int32 GetStatusGroupState(ABEStatusGroupType StatusGroup);
#pragma endregion

#pragma region Flag Function
	virtual bool AddSkillFlag(int32 FlagID);
	virtual bool AddBuffFlag(int32 FlagID);
	virtual bool AddStatusFlag(int32 FlagID);
	virtual bool RemoveStatusFlag(int32 FlagID);
	virtual bool RemoveSkillFlag(int32 FlagID);
	virtual bool RemoveBuffFlag(int32 FlagID);

	virtual uint64 GetCurrentBigFlag();
#pragma endregion

protected:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

	virtual uint64 CalculateCurrentBitFlag();
	virtual void OnStatusChange();
	virtual void OnChangeStatusActiveService(ABEStatusGroupType StatusGroup, int32 StatusValue, int32 OldValue);
#pragma region Variable
	//	Current Status for every status group value
	TMap<int32, int32> CurStatusDic;

	//	Status Flag
	TMap<int32, int32> StatusFlagDic;
	//	Skill Flag
	TMap<int32, int32> SkillFlagDic;
	//	Buff Flag
	TMap<int32, int32> BuffFlagDic;

	//	Current count Status, Skill, Buff Flag calculate result
	uint64 CurrentBitFlag;

	UPROPERTY(EditAnywhere, Instanced, Category = "Status Service")
	TMap<ABEStatusGroupType, UStatusServiceData*> StatusService;
#pragma endregion

};


/*
*	Shawn lee
*/

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ABCoreSubsystem.generated.h"

UCLASS()
class UABCoreSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UABCoreSubsystem();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	virtual bool LoadDecisionTableData();

	virtual uint64 GetStatusFlagData(int32 _flagID);
	virtual uint64 GetSkillFlagData(int32 _flagID);
	virtual uint64 GetBuffFlagData(int32 _flagID);
};


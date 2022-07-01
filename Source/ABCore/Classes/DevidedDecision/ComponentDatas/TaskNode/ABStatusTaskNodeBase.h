/*
	Shawn Lee
*/

#pragma once

#include "CoreMinimal.h"
#include "ABDDTaskNodeBase.h"
#include "../../ABStatusData.h"
#include "ABStatusTaskNodeBase.generated.h"

class UABInputProcessComponent;
class UABDDTaskNodeScratchPad;

UCLASS(Abstract, Blueprintable)
class UABStatusTaskNodeBase : public UABDDTaskNodeBase
{
	GENERATED_BODY()
public:

	UABStatusTaskNodeBase();
#pragma region Status Set

	ABEStatusGroupType StatusGroup = ABEStatusGroupType::ABESGT_Invalid;
	ABESystemStatusGroupType SystemStatus;
	ABEAliveStatusGroupType AliveStatus;
	ABERidingStatusGroupType RidingStatus;
	ABEEvironmentStatusGroupType EvironmentStatus;
	ABECombatStatusGroupType CombatStatus;
	ABEStanceStatusGroupType StanceStatus;
	ABEControlStatusGroupType ControlStatus;
	ABEPostureStatusGroupType PostureStatus;
	ABEBehitStatusGroupType BehitStatus;

#pragma endregion

protected:
#pragma region Devided class should override function below
	virtual EBTNodeResult::Type OnExecuteTask(UBehaviorTreeComponent& _ownerComp, uint8* _nodeMemory) override;
	virtual void OnFinished(UBehaviorTreeComponent& _ownerComp, uint8* _nodeMemory, EBTNodeResult::Type _taskResult) override;
#pragma endregion

};
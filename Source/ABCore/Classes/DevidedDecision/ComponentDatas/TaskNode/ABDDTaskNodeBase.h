/*
*	Shawn Lee
*/

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ABDDTaskNodeBase.generated.h"

class UABDDTaskNodeScratchPad;
class UABInputProcessComponent;

UCLASS(Abstract, Blueprintable)
class UABDDTaskNodeBase : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UABDDTaskNodeBase();
	void FinishExecute(UBehaviorTreeComponent& _ownerCom, bool _bSuccess) const;
	bool CheckIsMainPlayer(UBehaviorTreeComponent& _ownerCom) const;
#pragma region Devided class do not override functions below
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override final;
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override final;
	virtual void OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult) override final;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual UABInputProcessComponent* GetRoleInputProcessComponent(UBehaviorTreeComponent& _ownerComp) const;
#pragma endregion

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputName")
		FName InputEventName;

protected:
#pragma region Devided class should override function below
	virtual EBTNodeResult::Type OnExecuteTask(UBehaviorTreeComponent& _ownerComp, uint8* _nodeMemory);
	virtual void OnFinished(UBehaviorTreeComponent& _ownerComp, uint8* _nodeMemory, EBTNodeResult::Type _taskResult);
	virtual void OnTickTask(UBehaviorTreeComponent& _ownerComp, uint8* NodeMemory, float DeltaSeconds);
#pragma endregion

};


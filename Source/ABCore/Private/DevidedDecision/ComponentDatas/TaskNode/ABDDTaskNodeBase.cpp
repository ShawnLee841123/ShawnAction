#include "DevidedDecision/ComponentDatas/TaskNode/ABDDTaskNodeBase.h"
#include "DevidedDecision/ComponentDatas/TaskNode/ABDDTaskNodeScratchPad.h"
#include "GameFramework/Pawn.h"
#include "DevidedDecision/Components/ABInputProcessComponent.h"

UABDDTaskNodeBase::UABDDTaskNodeBase()
{
	bNotifyTaskFinished = true;
}

void UABDDTaskNodeBase::FinishExecute(UBehaviorTreeComponent& _ownerCom, bool _bSuccess) const
{
	EBTNodeResult::Type nodeResult(EBTNodeResult::Succeeded);

	UABInputProcessComponent* inputCom = GetRoleInputProcessComponent(_ownerCom);
	if (nullptr != inputCom)
	{
		UABDDTaskNodeScratchPad* taskParam = inputCom->GetInputEventScratchPad(InputEventName);
		if (nullptr != taskParam)
		{
			taskParam->SetRunningTask(false);
			taskParam->ReleaseActive();
		}
	}

	FinishLatentTask(_ownerCom, nodeResult);
}

bool UABDDTaskNodeBase::CheckIsMainPlayer(UBehaviorTreeComponent& _ownerCom) const
{
	return false;
}
#pragma region Devided class do not override functions below
EBTNodeResult::Type UABDDTaskNodeBase::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	bNotifyTick = true;
	UABInputProcessComponent* inputCom = GetRoleInputProcessComponent(OwnerComp);
	if (nullptr == inputCom)
		return EBTNodeResult::InProgress;

	UABDDTaskNodeScratchPad* taskParam = inputCom->GetInputEventScratchPad(InputEventName);
	if (nullptr == taskParam)
		return EBTNodeResult::InProgress;

	if (taskParam->CheckRunning())
		return EBTNodeResult::InProgress;

	taskParam->SetRunningTask(true);

	return OnExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UABDDTaskNodeBase::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type result = EBTNodeResult::Aborted;
	return result;
}

void UABDDTaskNodeBase::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult)
{
	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);
	if (EBTNodeResult::Aborted == TaskResult)
	{
		return;
	}

	UABInputProcessComponent* inputCom = GetRoleInputProcessComponent(OwnerComp);
	if (nullptr != inputCom)
	{
		UABDDTaskNodeScratchPad* taskParam = inputCom->GetInputEventScratchPad(InputEventName);
		if (nullptr != taskParam)
		{
			taskParam->SetRunningTask(false);
			taskParam->ReleaseActive();
		}
	}

	OnFinished(OwnerComp, NodeMemory, TaskResult);
}

void UABDDTaskNodeBase::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	OnTickTask(OwnerComp, NodeMemory, DeltaSeconds);
}

UABInputProcessComponent* UABDDTaskNodeBase::GetRoleInputProcessComponent(UBehaviorTreeComponent& _ownerComp) const
{
	APawn* role = Cast<APawn>(_ownerComp.GetOwner());
	if (nullptr == role)
		return nullptr;

	UActorComponent* tempCom = role->GetComponentByClass(UABInputProcessComponent::StaticClass());
	if (nullptr == tempCom)
	{
		return nullptr;
	}
	
	UABInputProcessComponent* InputComp = Cast<UABInputProcessComponent>(tempCom);
	return InputComp;
}
#pragma endregion

#pragma region Devided class should override function below
EBTNodeResult::Type UABDDTaskNodeBase::OnExecuteTask(UBehaviorTreeComponent& _ownerComp, uint8* _nodeMemory)
{
	EBTNodeResult::Type result = EBTNodeResult::InProgress;
	//	todo
	return result;
}

void UABDDTaskNodeBase::OnFinished(UBehaviorTreeComponent& _ownerComp, uint8* _nodeMemory, EBTNodeResult::Type _taskResult)
{}

void UABDDTaskNodeBase::OnTickTask(UBehaviorTreeComponent& _ownerComp, uint8* NodeMemory, float DeltaSeconds)
{}
#pragma endregion

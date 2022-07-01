#include "DevidedDecision/ComponentDatas/TaskNode/ABStatusTaskNodeBase.h"
#include "DevidedDecision/ComponentDatas/TaskNode/ABDDTaskNodeScratchPad.h"
#include "GameFramework/Pawn.h"
#include "DevidedDecision/Components/ABInputProcessComponent.h"

UABStatusTaskNodeBase::UABStatusTaskNodeBase()
{
	bNotifyTaskFinished = true;
}

#pragma region Devided class should override function below
EBTNodeResult::Type UABStatusTaskNodeBase::OnExecuteTask(UBehaviorTreeComponent& _ownerComp, uint8* _nodeMemory)
{
	EBTNodeResult::Type result = Super::OnExecuteTask(_ownerComp, _nodeMemory);
	APawn* pawn = Cast<APawn>(_ownerComp.GetOwner());
	if (nullptr == pawn)
	{
		return result;
	}

	return result;
}

void UABStatusTaskNodeBase::OnFinished(UBehaviorTreeComponent& _ownerComp, uint8* _nodeMemory, EBTNodeResult::Type _taskResult)
{}
#pragma endregion
#include "DevidedDecision/ComponentDatas/Decorators/Status/ABDecorator_CheckInputAction.h"
#include "GameFramework/Pawn.h"
#include "DevidedDecision/ComponentDatas/TaskNode/ABDDTaskNodeScratchPad.h"
#include "DevidedDecision/Components/ABInputProcessComponent.h"

UABDecorator_CheckInputAction::UABDecorator_CheckInputAction()
{
	bNotifyTick = true;
}

void UABDecorator_CheckInputAction::BeginDestroy()
{
	Super::BeginDestroy();
}

bool UABDecorator_CheckInputAction::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	APawn* pawn = Cast<APawn>(OwnerComp.GetOwner());
	if (nullptr == pawn)
	{
		return false;
	}

	UABInputProcessComponent* inputCom = Cast<UABInputProcessComponent>(pawn->GetComponentByClass(UABInputProcessComponent::StaticClass()));
	if (nullptr == inputCom)
	{
		return false;
	}

	UABDDTaskNodeScratchPad* taskPad = inputCom->GetInputEventScratchPad(ActionName);
	if (nullptr != taskPad)
	{
		if (!taskPad->IsPendingKill())
		{
			return taskPad->CheckActive();
		}
	}

	return false;
}
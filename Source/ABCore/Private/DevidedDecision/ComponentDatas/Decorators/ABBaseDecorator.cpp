#include "DevidedDecision/ComponentDatas/Decorators/ABBaseDecorator.h"

UABBaseDecorator::UABBaseDecorator()
{}

#pragma region Devided class need to override function below
bool UABBaseDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	return true;
}

void UABBaseDecorator::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	if (!CalculateRawConditionValue(OwnerComp, NodeMemory) && bNotifyTick)
	{
		OwnerComp.RequestExecution(this);
	}
}
#pragma endregion
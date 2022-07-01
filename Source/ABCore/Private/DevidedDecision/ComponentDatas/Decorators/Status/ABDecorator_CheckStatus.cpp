#include "DevidedDecision/ComponentDatas/Decorators/Status/ABDecorator_CheckStatus.h"
#include "DevidedDecision/Components/ABStatusDataComponent.h"

UABDecorator_CheckStatus::UABDecorator_CheckStatus()
{
	bNotifyTick = false;
}

bool UABDecorator_CheckStatus::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	return false;
}

#if WITH_EDITOR
void UABDecorator_CheckStatus::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{}
#endif
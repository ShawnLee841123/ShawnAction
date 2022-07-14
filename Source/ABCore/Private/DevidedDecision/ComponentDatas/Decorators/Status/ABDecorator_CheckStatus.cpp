#include "DevidedDecision/ComponentDatas/Decorators/Status/ABDecorator_CheckStatus.h"
#include "DevidedDecision/Components/ABStatusDataComponent.h"

UABDecorator_CheckStatus::UABDecorator_CheckStatus()
{
	bNotifyTick = false;

	bEditSystem = false;
	bEditLive = false;
	bEditRiding = false;
	bEditEnvirorment = false;
	bEditCombat = false;
	bEditStance = false;
	bEditControl = false;
	bEditPosture = false;
	bEditBehit = false;
}

bool UABDecorator_CheckStatus::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	return false;
}

#if WITH_EDITOR
void UABDecorator_CheckStatus::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	bEditSystem = ABEStatusGroupType::ABESGT_System == CheckGroup;
	bEditLive = ABEStatusGroupType::ABESGT_Alive == CheckGroup;
	bEditRiding = ABEStatusGroupType::ABESGT_Riding == CheckGroup;
	bEditEnvirorment = ABEStatusGroupType::ABESGT_Evironment == CheckGroup;
	bEditCombat = ABEStatusGroupType::ABESGT_Combat == CheckGroup;
	bEditStance = ABEStatusGroupType::ABESGT_Stance == CheckGroup;
	bEditControl = ABEStatusGroupType::ABESGT_Control == CheckGroup;
	bEditPosture = ABEStatusGroupType::ABESGT_Posture == CheckGroup;
	bEditBehit = ABEStatusGroupType::ABESGT_Behit == CheckGroup;
}
#endif
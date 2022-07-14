/*
	Shawn Lee
*/

#pragma once

#include "CoreMinimal.h"
#include "../ABBaseDecorator.h"
#include "../../../ABStatusData.h"
#include "UObject/NoExportTypes.h"

#include "ABDecorator_CheckStatus.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UABDecorator_CheckStatus : public UABBaseDecorator
{
	GENERATED_BODY()
public:

	UABDecorator_CheckStatus();
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
#pragma region Edit Flag
	UPROPERTY()
	bool bEditSystem;
	UPROPERTY()
	bool bEditLive;
	UPROPERTY()
	bool bEditRiding;
	UPROPERTY()
	bool bEditEnvirorment;
	UPROPERTY()
	bool bEditCombat;
	UPROPERTY()
	bool bEditStance;
	UPROPERTY()
	bool bEditControl;
	UPROPERTY()
	bool bEditPosture;
	UPROPERTY()
	bool bEditBehit;
#pragma endregion

	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusGroup"))
	ABEStatusGroupType CheckGroup;

	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType", EditCondition = bEditSystem))
	ABESystemStatusGroupType StatusValue;
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType", EditCondition = bEditLive))
	ABEAliveStatusGroupType AliveValue;
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType", EditCondition = bEditRiding))
	ABERidingStatusGroupType RidingValue;
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType", EditCondition = bEditEnvirorment))
	ABEEvironmentStatusGroupType EnvValue;
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType", EditCondition = bEditCombat))
	ABECombatStatusGroupType CombatValue;
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType", EditCondition = bEditStance))
	ABEStanceStatusGroupType StanceValue;
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType", EditCondition = bEditControl))
	ABEControlStatusGroupType ControlValue;
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType", EditCondition = bEditPosture))
	ABEPostureStatusGroupType PostureValue;
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType", EditCondition = bEditBehit))
	ABEBehitStatusGroupType BehitValue;
};
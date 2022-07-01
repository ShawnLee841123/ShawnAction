/*
	Shawn Lee
*/

#pragma once

#include "CoreMinimal.h"
#include "../ABBaseDecorator.h"
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
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusGroup"))
	uint8 CheckGroup;
	UPROPERTY(EditAnywhere, Category = "RoleStatusGroup", meta = (DisplayName = "StatusType"))
	uint8 CheckValue;
};
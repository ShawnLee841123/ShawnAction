/*
	Shawn Lee
*/

#pragma once
#include "CoreMinimal.h"
#include "../ABBaseDecorator.h"

#include "ABDecorator_CheckInputAction.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UABDecorator_CheckInputAction : public UABBaseDecorator
{
	GENERATED_BODY()
public:

	UABDecorator_CheckInputAction();

	virtual void BeginDestroy() override;
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

#pragma region Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InputActionName")
	FName ActionName;
#pragma endregion

};
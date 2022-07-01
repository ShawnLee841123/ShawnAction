/*
	Shawn Lee
*/

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "ABBaseDecorator.generated.h"

UCLASS(BlueprintType)
class UABBaseDecorator : public UBTDecorator
{
	GENERATED_BODY()
public:
	UABBaseDecorator();

#pragma region Devided class need to override function below
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
#pragma endregion

};
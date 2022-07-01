/*
*	Shawn Lee
*/

#pragma once

#include "CoreMinimal.h"
#include "AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ABDevidedBaseComponent.generated.h"

class UBlackboardComponent;
class UBlackboardData;

UCLASS(ClassGroup = (Custom), Blueprintable, meta = (BlueprintSpawnableComponent))
class UABDevidedBaseComponent : public UBehaviorTreeComponent
{
	GENERATED_BODY()
public:
	UABDevidedBaseComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

#pragma region function
	virtual bool UseBlackboard(UBlackboardData* _blackboardAsset, UBlackboardComponent*& _blackboardComponent);
	virtual bool InitializeBlackboard(UBlackboardComponent& _blackboardCompTemp, UBlackboardData& _blackboardAsset);
#pragma endregion

#pragma region Variable
	UBlackboardComponent* Blackboard;

	UPROPERTY(EditAnywhere, Category = "Decision Asset | Tree")
	UBehaviorTree* RuningTree;
#pragma endregion

};
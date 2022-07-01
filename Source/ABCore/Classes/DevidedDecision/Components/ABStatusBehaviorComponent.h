/*
	Shawn Lee
*/

#pragma once

#include "CoreMinimal.h"
#include "ABDevidedBaseComponent.h"
#include "DevidedDecision/ComponentDatas/TaskNode/ABDDTaskNodeBase.h"
#include "ABStatusBehaviorComponent.generated.h"

class UABDDTaskNodeBase;

UCLASS(ClassGroup = (Custom), blueprintable, meta = (BlueprintSpawnableComponent))
class UABStatusBehaviorComponent : public UABDevidedBaseComponent
{
	GENERATED_BODY()
public:
	UABStatusBehaviorComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	bool RestartRunRoot(const FName& _inputName);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		void OnReciveRestartTreeEvent();

	UFUNCTION(BlueprintCallable, Category = "Run Status Behavior Tree")
		void RunBehaviorTree();

protected:

	virtual void BeginPlay() override;

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:

	void RunPlayerBehavior();
	void RunNpcBehavior();

	const UABDDTaskNodeBase* CurActiveNode;
	FName CurInputName;
};

/*
*	Shawn Lee
* Every role need to have this on it`s components list
* 
*/

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "ABInputProcessComponent.generated.h"

class UABDDTaskNodeScratchPad;

UCLASS(BlueprintType)
class UABInputProcessComponent : public UActorComponent
{
	GENERATED_BODY()
public:

	UABInputProcessComponent(const FObjectInitializer& ObjectIntializer = FObjectInitializer::Get());

	void Initialize();

	void Shutdown();

#pragma region Event Input
	UFUNCTION(BlueprintCallable, Category = "Event Management")
		void RemoveInputEvent(FName _inputName);

	UFUNCTION(BlueprintCallable, Category = "Event Management")
		bool CheckInputEvent(FName _inputName);

	UFUNCTION(BlueprintCallable, Category = "Event Management")
		void SetInputEventActivityStatus(FName _inputName, bool _bIsActive);

	UFUNCTION(BlueprintCallable, Category = "Event Management")
		UABDDTaskNodeScratchPad* GetInputEventScratchPad(FName _inputName);

	//	清除向前移动信息
	UFUNCTION(BlueprintCallable, Category = "Event Management / Main Player Input")
		void RemoveMoveForwardEventParam();

	//	清除向右移动信息
	UFUNCTION(BlueprintCallable, Category = "Event Management / Main Player Input")
		void RemoveMoveRightEventParam();

#pragma endregion

protected:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	virtual void CheckRestartTree(FName _inputName);

	UPROPERTY()
		TMap<FName, UABDDTaskNodeScratchPad*> InputParamsMap;

};
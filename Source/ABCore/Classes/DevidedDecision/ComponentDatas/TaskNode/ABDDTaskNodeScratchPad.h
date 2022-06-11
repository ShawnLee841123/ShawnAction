/*
*	Shawn Lee
* 
*/


#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "ABDDTaskNodeScratchPad.generated.h"

class UABDDTaskNodeBase;

UCLASS(BlueprintType)
class ABCORE_API UABDDTaskNodeScratchPad: public UObject
{
	GENERATED_BODY()
public:

	UABDDTaskNodeScratchPad(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void SetActive(bool _isActive);
	virtual bool CheckActive();
	virtual void SetRunningTask(bool _isRunning);
	virtual bool CheckRunning();
	virtual void ReleaseActive();
	virtual bool CheckRestartTree();

protected:
#pragma region Variable
	bool bIsActive;
	bool bIsAutoReleaseActive;
	bool bIsRunningTask;
#pragma endregion
};
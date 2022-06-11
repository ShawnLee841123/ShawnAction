/*
*	Shawn Lee
* 
*/


#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include "DDTaskNodeScratchPad.generated.h"

class UABDDTaskNodeBase;

UCLASS(BlueprintType)
class UABDDTaskNodeScratchPad : public UObject
{
	GENERATED_BODY()
public:

	UABDDTaskNodeScratchPad(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
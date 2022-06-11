/*
*	Shawn Lee
*/

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "DDTaskNodeBase.generated.h"



UCLASS(Abstract, Blueprintable)
class UABDDTaskNodeBase : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UABDDTaskNodeBase();

};


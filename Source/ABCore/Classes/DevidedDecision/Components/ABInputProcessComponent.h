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



UCLASS(BlueprintType)
class UABInputProcessComponent : public UActorComponent
{
	GENERATED_BODY()
public:

	UABInputProcessComponent(const FObjectInitializer& ObjectIntializer = FObjectInitializer::Get());

	void Initialize();

	void Shutdown();

};
#include "DevidedDecision/Components/ABDevidedBaseComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

UABDevidedBaseComponent::UABDevidedBaseComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{}


#pragma region function
bool UABDevidedBaseComponent::UseBlackboard(UBlackboardData* _blackboardAsset, UBlackboardComponent*& _blackboardComponent)
{
	APawn* pawn = Cast<APawn>(GetOwner());
	if (nullptr == pawn)
		return false;

	if (nullptr == _blackboardAsset)
		return false;

	Blackboard = pawn->FindComponentByClass<UBlackboardComponent>();
	if (nullptr == Blackboard)
	{
		Blackboard = NewObject<UBlackboardComponent>(this, TEXT("BlackboardComponent"));
		if (nullptr != Blackboard)
		{
			InitializeBlackboard(*Blackboard, *_blackboardAsset);
			Blackboard->RegisterComponent();
		}
	}
	else if (nullptr == Blackboard->GetBlackboardAsset())
	{
		InitializeBlackboard(*Blackboard, *_blackboardAsset);
	}
	else if (_blackboardAsset != Blackboard->GetBlackboardAsset())
	{
		InitializeBlackboard(*Blackboard, *_blackboardAsset);
	}

	_blackboardComponent = Blackboard;
	return nullptr != _blackboardAsset;
}

bool UABDevidedBaseComponent::InitializeBlackboard(UBlackboardComponent& _blackboardCompTemp, UBlackboardData& _blackboardAsset)
{
	APawn* pawn = Cast<APawn>(GetOwner());
	if (nullptr == pawn)
		return false;

	if (_blackboardCompTemp.InitializeBlackboard(_blackboardAsset))
	{
		const FBlackboard::FKey SelfKey = _blackboardAsset.GetKeyID(FBlackboard::KeySelf);
		if (FBlackboard::InvalidKey != SelfKey)
		{
			_blackboardCompTemp.SetValue<UBlackboardKeyType_Object>(SelfKey, this);
		}

		return true;
	}

	return false;
}
#pragma endregion
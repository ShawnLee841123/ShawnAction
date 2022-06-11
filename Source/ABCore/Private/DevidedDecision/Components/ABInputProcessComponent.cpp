#include "DevidedDecision/Components/ABInputProcessComponent.h"
#include "DevidedDecision/Components/ABDevidedBaseComponent.h"
#include "GameFramework/Pawn.h"
#include "DevidedDecision/ComponentDatas/TaskNode/ABDDTaskNodeScratchPad.h"

UABInputProcessComponent::UABInputProcessComponent(const FObjectInitializer& ObjectIntializer)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UABInputProcessComponent::Initialize()
{}

void UABInputProcessComponent::Shutdown()
{
	InputParamsMap.Empty();
}

#pragma region Event Input

void UABInputProcessComponent::RemoveInputEvent(FName _inputName)
{
	if (InputParamsMap.Contains(_inputName))
	{
		UABDDTaskNodeScratchPad* tempScratchPad = InputParamsMap[_inputName];
		InputParamsMap.Remove(_inputName);
	}
}

bool UABInputProcessComponent::CheckInputEvent(FName _inputName)
{
	if (InputParamsMap.Contains(_inputName))
	{
		return true;
	}

	return false;
}

void UABInputProcessComponent::SetInputEventActivityStatus(FName _inputName, bool _bIsActive)
{
	if (InputParamsMap.Contains(_inputName))
	{
		UABDDTaskNodeScratchPad* taskParam = InputParamsMap[_inputName];
		taskParam->SetActive(_bIsActive);
	}
}

UABDDTaskNodeScratchPad* UABInputProcessComponent::GetInputEventScratchPad(FName _inputName)
{
	if (!CheckInputEvent(_inputName))
	{
		return nullptr;
	}

	UABDDTaskNodeScratchPad* ptrRet = InputParamsMap[_inputName];
	if (nullptr == ptrRet)
	{
		RemoveInputEvent(_inputName);
		return nullptr;
	}

	if (ptrRet->IsPendingKill())
	{
		RemoveInputEvent(_inputName);
		return nullptr;
	}

	return ptrRet;
}

//	清除向前移动信息
void UABInputProcessComponent::RemoveMoveForwardEventParam()
{}

//	清除向右移动信息
void UABInputProcessComponent::RemoveMoveRightEventParam()
{}

#pragma endregion


void UABInputProcessComponent::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
}

void UABInputProcessComponent::BeginDestroy()
{
	Shutdown();
	Super::BeginDestroy();
}

void UABInputProcessComponent::CheckRestartTree(FName _inputName)
{
	UABDDTaskNodeScratchPad* taskParam = InputParamsMap[_inputName];
	if (nullptr == taskParam)
	{
		return;
	}

	if (nullptr == GetOwner())
	{
		taskParam->ReleaseActive();
		return;
	}

	UABDevidedBaseComponent* behavicData = Cast<UABDevidedBaseComponent>(GetOwner()->GetComponentByClass(UABDevidedBaseComponent::StaticClass()));

	bool bRestartSuccess = false;
	if (nullptr != behavicData)
	{
		bRestartSuccess = behavicData->RestartRunRoot(_inputName);
	}

	if (!bRestartSuccess)
	{
		taskParam->ReleaseActive();
	}
}
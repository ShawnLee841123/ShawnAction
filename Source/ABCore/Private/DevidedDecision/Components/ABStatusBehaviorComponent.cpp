#include "DevidedDecision/Components/ABStatusBehaviorComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "DevidedDecision/ComponentDatas/TaskNode/ABDDTaskNodeBase.h"

UABStatusBehaviorComponent::UABStatusBehaviorComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
	, CurActiveNode(nullptr)
	, CurInputName(TEXT(""))
{
	PrimaryComponentTick.bCanEverTick = true;
}

bool UABStatusBehaviorComponent::RestartRunRoot(const FName& _inputName)
{
	APawn* pawn = Cast<APawn>(GetOwner());
	if (nullptr == pawn)
	{
		if (_inputName.IsEqual("MoveState") && _inputName.IsEqual(CurInputName) && nullptr != CurActiveNode)
		{
			CurActiveNode->FinishExecute(*this, true);
			CurActiveNode = nullptr;
			CurInputName = "";
		}
	}

	APlayerController* pc = Cast<APlayerController>(pawn->GetController());
	if (nullptr == pc)
	{
		if (_inputName.IsEqual("MoveState") && _inputName.IsEqual(CurInputName) && nullptr != CurActiveNode)
		{
			CurActiveNode->FinishExecute(*this, true);
			CurActiveNode = nullptr;
			CurInputName = "";
		}
	}

	const UABDDTaskNodeBase* curActiveTask = Cast<UABDDTaskNodeBase>(GetActiveNode());
	if (nullptr != curActiveTask && curActiveTask != CurActiveNode)
	{
		if (nullptr != CurActiveNode)
		{
			CurActiveNode->FinishExecute(*this, true);
		}

		CurActiveNode = curActiveTask;
		CurInputName = CurActiveNode->InputEventName;
	}
	else if (nullptr != CurActiveNode && _inputName.IsEqual(CurActiveNode->InputEventName))
	{
		//	After CurActiveNode finish, clear InputEventName in the node working process 
		return true;
	}

	RestartTree();
	TickComponent(0.0f, ELevelTick::LEVELTICK_All, nullptr);
	const UBTNode* btNode = GetActiveNode();
	if (nullptr == btNode)
	{
		TickComponent(0.0f, ELevelTick::LEVELTICK_All, nullptr);
	}

	const UABDDTaskNodeBase* findTaskNode = Cast<UABDDTaskNodeBase>(GetActiveNode());
	if (nullptr != findTaskNode)
	{
		if (nullptr != CurActiveNode && findTaskNode != CurActiveNode)
		{
			CurActiveNode->FinishExecute(*this, true);
			CurActiveNode = nullptr;
			CurInputName = "";
		}

		if (_inputName.IsEqual(findTaskNode->InputEventName))
		{
			CurActiveNode = findTaskNode;
			CurInputName = _inputName;
			return true;
		}
	}
	else if (nullptr != CurActiveNode && findTaskNode != CurActiveNode)
	{
		CurActiveNode->FinishExecute(*this, true);
		CurActiveNode = nullptr;
		CurInputName = "";
	}
	return false;
}

void UABStatusBehaviorComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (this->IsPendingKill())
		return;

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	const UABDDTaskNodeBase* curActTask = Cast<UABDDTaskNodeBase>(GetActiveNode());
	if (nullptr != curActTask && curActTask != CurActiveNode)
	{
		if (nullptr != CurActiveNode)
		{
			CurActiveNode->FinishExecute(*this, true);
		}

		CurActiveNode = curActTask;
	}
}
void UABStatusBehaviorComponent::OnReciveRestartTreeEvent()
{
	RestartTree();
	TickComponent(0.0f, ELevelTick::LEVELTICK_All, nullptr);
}
void UABStatusBehaviorComponent::RunBehaviorTree()
{
	if (nullptr == RuningTree)
	{
		return;
	}

	bool bSuccess = false;
	UBlackboardComponent* blackboardCom = nullptr;
	if (RuningTree->BlackboardAsset)
	{
		if (nullptr == blackboardCom)
		{
			bSuccess = UseBlackboard(RuningTree->BlackboardAsset, blackboardCom);
		}

		bSuccess = true;
	}

	if (bSuccess)
	{
		StartTree(*RuningTree, EBTExecutionMode::Looped);
	}
}
void UABStatusBehaviorComponent::BeginPlay()
{
	Super::BeginPlay();
	//todo: delegate function initial

	RunBehaviorTree();
}
void UABStatusBehaviorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	//todo: delegate function remove
}
void UABStatusBehaviorComponent::RunPlayerBehavior(){}
void UABStatusBehaviorComponent::RunNpcBehavior(){}
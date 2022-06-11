#include "DevidedDecision/ComponentDatas/TaskNode/ABDDTaskNodeScratchPad.h"
#include "DevidedDecision/ComponentDatas/TaskNode/ABDDTaskNodeBase.h"

UABDDTaskNodeScratchPad::UABDDTaskNodeScratchPad(const FObjectInitializer& ObjectInitializer): bIsActive(false), bIsAutoReleaseActive(true), bIsRunningTask(false)
{}

void UABDDTaskNodeScratchPad::SetActive(bool _isActive)
{
	bIsActive = _isActive;
}

bool UABDDTaskNodeScratchPad::CheckActive()
{
	return bIsActive;
}

void UABDDTaskNodeScratchPad::SetRunningTask(bool _isRunning)
{
	bIsRunningTask = _isRunning;
}

bool UABDDTaskNodeScratchPad::CheckRunning()
{
	return bIsRunningTask;
}

void UABDDTaskNodeScratchPad::ReleaseActive()
{
	if (bIsAutoReleaseActive)
		bIsActive = false;
}

bool UABDDTaskNodeScratchPad::CheckRestartTree()
{
	bool bRet = CheckActive();
	if (!bRet)
	{
		bIsActive = false;
	}

	return bRet;
}
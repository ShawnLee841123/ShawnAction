#include "DevidedDecision/ComponentDatas/Service/StatusService/ABBaseStatusService.h"
#include "DevidedDecision/ABStatusData.h"

UABBaseStatusService::UABBaseStatusService()
{}

UABBaseStatusService::~UABBaseStatusService()
{}

void UABBaseStatusService::OnEnterStatus(APawn* _owner, ABEStatusGroupType _groupId, int32 _statusId)
{
	BP_OnEnterStatus(_owner, _groupId, _statusId);
}

void UABBaseStatusService::OnLeaveStatus(APawn* _owner, ABEStatusGroupType _groupId, int32 _statusId)
{
	BP_OnLeaveStatus(_owner, _groupId, _statusId);
}

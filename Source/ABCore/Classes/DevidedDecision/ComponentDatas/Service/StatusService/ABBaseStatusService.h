/*
*	Shawn Lee
*/


#pragma once

#include "GameFramework/Pawn.h"
#include "ABBaseStatusService.generated.h"

UCLASS(EditInlineNew, meta = (DisplayName = "Status Service", ShortToolTip = "StatusService"))
class UABBaseStatusService : public UObject
{
	GENERATED_BODY()
public:
	UABBaseStatusService();
	virtual ~UABBaseStatusService();

	virtual void OnEnterStatus(APawn* _owner, ABEStatusGroupType _groupId, int32 _statusId);
	virtual void OnLeaveStatus(APawn* _owner, ABEStatusGroupType _groupId, int32 _statusId);

	UFUNCTION(BlueprintImplementableEvent, Category = "BP_OnEnterState")
	void BP_OnEnterStatus(APawn* _owner, ABEStatusGroupType _groupId, int32 _statusId);
	UFUNCTION(BlueprintImplementableEvent, Category = "BP_OnLeaveState")
	void BP_OnLeaveStatus(APawn* _owner, ABEStatusGroupType _groupId, int32 _statusId);
};
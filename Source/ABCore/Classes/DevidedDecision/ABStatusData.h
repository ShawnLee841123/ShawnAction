/*
	Shawn Lee
*/
#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABStatusData.generated.h"

UENUM(BlueprintType)
enum class ABEStatusGroupType : uint8
{
	ABESGT_Invalid = 0 UMETA(Hidden),
	ABESGT_System UMETA(DisplayName = "GroupSystem"),		//	System Group
	ABESGT_Alive UMETA(DisplayName = "GroupAlive"),
	ABESGT_Riding UMETA(DisplayName = "GroupRiding"),
	ABESGT_Evironment UMETA(DisplayName = "GroupEvironment"),
	ABESGT_Combat UMETA(DisplayName = "GroupCombat"),
	ABESGT_Stance UMETA(DisplayName = "GroupStance"),
	ABESGT_Control UMETA(DisplayName = "GroupControl"),
	ABESGT_Posture UMETA(DisplayName = "GroupPosture"),
	ABESGT_Behit UMETA(DisplayName = "GroupBehit"),

	ABESGT_MAX,
};

UENUM(BlueprintType)
enum class ABESystemStatusGroupType : uint8
{
	ABESGST_Idle = 0,				//	system operation status(default
	ABESGST_Unbreakable,			//	only system can operate status
};

UENUM(BlueprintType)
enum class ABEDeathStatusGroupType : uint8
{
	ABEDGST_Live = 0,				//	live status
	ABEDGST_Dead,					//	death status
	ABEDGST_Born,					//	born status
};

UENUM(BlueprintType)
enum class ABERidingStatusGroupType : uint8
{
	ABERGST_UnRiding = 0,			//	unriding status
	ABERGST_Driving,				//	riding driver status
};

UENUM(BlueprintType)
enum class ABEEvironmentStatusGroupType : uint8
{
	ABEEGST_Invalid = 0 UMETA(Hidden),
	ABEEGST_Land = 1,				//	land status
	ABEEGST_Water,					//	water status
	ABEEGST_Air,					//	air status
};

UENUM(BlueprintType)
enum class ABECombatStatusGroupType : uint8
{
	ABECGST_Unfight = 0,			//	unfight status
	ABECGST_Fight,					//	fight status
};

UENUM(BlueprintType)
enum class ABEControlStatusGroupType : uint8
{
	ABECGST_Invalid = 0 UMETA(Hidden),	//	error status
	ABECGST_Idle,						//	idle status
	ABECGST_Run,						//	run status
	ABECGST_Sprint,						//	sprint status
	ABECGST_ExtraMovement,				//	extra movement status
	ABECGST_Turnto,						//	turn to status
	ABECGST_Dodge,						//	dodge status
	ABECGST_Jump,						//	jump status
};

UENUM(BlueprintType)
enum class ABEPostureStatusGroupType : uint8
{
	ABEPGST_Invalid = 0 UMETA(Hidden),
	ABEPGST_Armed = 1,					//	armed status
	ABEPGST_UnArmed,					//	unarmed status
};

UENUM(BlueprintType)
enum class ABEBehitStatusGroupType : uint8
{
	ABEBGST_None = 0,					//	no status
	ABEBGST_Default,					//	default status
	ABEBGST_Stiff,						//	stiff status
	ABEBGST_Floating,					//	floating status
	ABEBGST_KnockFlew,					//	knock flew status
};

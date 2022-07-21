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
	ABESGT_System UMETA(DisplayName = "GroupSystem"),			//	System Group
	ABESGT_Alive UMETA(DisplayName = "GroupAlive"),				//	Live or dead
	ABESGT_Riding UMETA(DisplayName = "GroupRiding"),			//	none, driver or passager
	ABESGT_Evironment UMETA(DisplayName = "GroupEvironment"),	//	air, ground or water
	ABESGT_Combat UMETA(DisplayName = "GroupCombat"),			//	fight or unfight
	ABESGT_Stance UMETA(DisplayName = "GroupStance"),			//	standing crouching or crawling
	ABESGT_Control UMETA(DisplayName = "GroupControl"),			//	idle run spring jump turnto doge.....
	ABESGT_Posture UMETA(DisplayName = "GroupPosture"),			//	armed or unarmed
	ABESGT_Behit UMETA(DisplayName = "GroupBehit"),				//	none, normal, Stiff, kickback, kickflew or kickdown

	ABESGT_MAX,
};

UENUM(BlueprintType)
enum class ABESystemStatusGroupType : uint8
{
	ABESGST_Idle = 0,				//	system operation status(default
	ABESGST_Unbreakable,			//	only system can operate status
};

UENUM(BlueprintType)
enum class ABEAliveStatusGroupType : uint8
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
	ABERGST_Passager,				//	passager status
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
enum class ABEStanceStatusGroupType : uint8
{
	ABESSGT_Standing = 0,
	ABESSGT_Crouch,
	ABESSGT_Crawling,
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
	ABEBGST_KnockBack,					//	floating status
	ABEBGST_KnockFlew,					//	knock flew status
	ABEBGST_KnockDown,
};

enum EStatusFlagCheckBit
{
	//	0~5
	ESFCB_None = 0,
	ESFCB_Idle,					//1
	ESFCB_Move,					//2
	ESFCB_Spring,				//4
	ESFCB_Doge,					//8
	ESFCB_Jump,					//16
	//	6~10
	ESFCB_ChangePosture,		//32
	ESFCB_Stiff,				//64
	ESFCB_Knockback,			//128
	ESFCB_Knockflew,			//256
	ESFCB_Knockdown,			//512
	//	11~15
	ESFCB_UseSkill,				//1024
};

#pragma region Status Bit Value

#pragma endregion



static int32 TransStatusValue2GlobalValue(int32 StatusGroup, int32 StatusValue)
{
	int globalStatusId = (StatusGroup << 16) + StatusValue;
	return globalStatusId;
}

static void TransGlobalStatusValue2Prototype(int32 GlobalValue, int32& StatusGroup, int32& StatusValue)
{
	int tempValue = GlobalValue;
	StatusValue = tempValue & 0x0000FFFF;
	StatusGroup = ((tempValue & 0xFFFF0000) >> 16);
}

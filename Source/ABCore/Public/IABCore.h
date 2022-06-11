// Copyright (c) Shawn Lee Personal. All rights reserved

#pragma once

#include "Modules/ModuleManager.h"

class IABCore : public IModuleInterface
{
public:
	static inline IABCore& Get()
	{
		return FModuleManager::LoadModuleChecked<IABCore>("ABCore");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("ABCore");
	}
};
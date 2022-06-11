// Copyright (c) ShawnLee. All rights reserved.

namespace UnrealBuildTool.Rules
{
	public class ABCore : ModuleRules
	{
		public ABCore(ReadOnlyTargetRules Target) : base (Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
					System.IO.Path.Combine(ModuleDirectory, "Public"),
					System.IO.Path.Combine(ModuleDirectory, "Classes"),
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					System.IO.Path.Combine(ModuleDirectory, "Private"),
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"AIModule",
					"Core",
					"CoreUObject",
					"Engine",
					"GameplayTags",
					"GameplayTasks", // AIModule requires this...
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					//"AbleCore",
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
		}
	}
}

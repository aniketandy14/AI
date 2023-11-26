// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CXXAI : ModuleRules
{
	public CXXAI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject", 
			"Engine",
			"InputCore", 
			"HeadMountedDisplay",
		    "AIModule",
		    "GameplayTasks",
		    "NavigationSystem"});
	}
}

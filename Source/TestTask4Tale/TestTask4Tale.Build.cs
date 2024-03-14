// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestTask4Tale : ModuleRules
{
	public TestTask4Tale(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

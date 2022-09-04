// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LiDAR_V2 : ModuleRules
{
	public LiDAR_V2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}

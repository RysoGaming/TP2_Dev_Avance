// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TP2_Dev_Avance : ModuleRules
{
	public TP2_Dev_Avance(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"GameplayTags" 
		});
	}
}
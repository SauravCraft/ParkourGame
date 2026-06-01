// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ParkourGame : ModuleRules
{
	public ParkourGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ParkourGame",
			"ParkourGame/Variant_Platforming",
			"ParkourGame/Variant_Platforming/Animation",
			"ParkourGame/Variant_Combat",
			"ParkourGame/Variant_Combat/AI",
			"ParkourGame/Variant_Combat/Animation",
			"ParkourGame/Variant_Combat/Gameplay",
			"ParkourGame/Variant_Combat/Interfaces",
			"ParkourGame/Variant_Combat/UI",
			"ParkourGame/Variant_SideScrolling",
			"ParkourGame/Variant_SideScrolling/AI",
			"ParkourGame/Variant_SideScrolling/Gameplay",
			"ParkourGame/Variant_SideScrolling/Interfaces",
			"ParkourGame/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

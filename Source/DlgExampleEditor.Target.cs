// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DlgExampleEditorTarget : TargetRules
{
	public DlgExampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("DlgExample");

		bLegacyPublicIncludePaths = false;

		bUndefinedIdentifierErrors = true;
        bShadowVariableErrors = true;
		WindowsPlatform.bStrictConformanceMode = true;
	}
}

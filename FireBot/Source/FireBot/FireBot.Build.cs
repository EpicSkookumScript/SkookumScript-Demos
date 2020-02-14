// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System.Collections.Generic;
using Tools.DotNETCommon;

public class FireBot : ModuleRules
{
  public FireBot(ReadOnlyTargetRules Target) : base(Target)
  {
    PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

    // Load SkookumScript.ini and add any ScriptSupportedModules specified to the list of PrivateDependencyModuleNames
    PrivateDependencyModuleNames.AddRange(GetSkookumScriptModuleNames(Path.Combine(ModuleDirectory, "../..")));
  }

  // Load SkookumScript.ini and return any ScriptSupportedModules specified
  public static List<string> GetSkookumScriptModuleNames(string PluginOrProjectRootDirectory, bool AddSkookumScriptRuntime = true)
  {
    List<string> moduleList = null;

    // Load SkookumScript.ini and get ScriptSupportedModules
    string iniFilePath = Path.Combine(PluginOrProjectRootDirectory, "Config/SkookumScript.ini");
    if (File.Exists(iniFilePath))
    {
      ConfigFile iniFile = new ConfigFile(new FileReference(iniFilePath), ConfigLineAction.Add);
      var skookumConfig = new ConfigHierarchy(new ConfigFile[] { iniFile });
      skookumConfig.GetArray("CommonSettings", "ScriptSupportedModules", out moduleList);
    }

    if (moduleList == null)
    {
      moduleList = new List<string>();
    }

    // Add additional modules needed for SkookumScript to function
    moduleList.Add("AgogCore");
    moduleList.Add("SkookumScript");
    if (AddSkookumScriptRuntime)
    {
      moduleList.Add("SkookumScriptRuntime");
    }

    return moduleList;
  }

}

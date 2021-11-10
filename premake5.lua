include "Dependencies.lua"

workspace "Modular-Educational-Engine"
	architecture "x64"
	startproject "MEE"

	configurations
	{
		"Debug",
		"Release",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Basic_Modules"
	include "Basic_Input"
	include "Basic_Physics"
	include "Basic_Renderer"
group ""

include "MEE"
--include "EngineTest"
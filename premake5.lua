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

group "Dependencies"
--include "Dependencies/SDL"
	--include "Dependencies/easyloggingpp"
	--include "Dependencies/stb"
	include "Dependencies/yaml-cpp"
group ""

include "MEE"
include "Basic_Input"
include "Basic_Physics"
include "Basic_Renderer"
--include "EngineTest"
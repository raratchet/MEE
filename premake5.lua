
if _ACTION == "clion" or _ACTION == "Clion" then
	require "cmake"
	require "clion"
elseif _ACTION == "cmake" then
	require "cmake"
end

include "Dependencies.lua"

workspace "Modular-Educational-Engine"
	architecture "x64"
	startproject "EngineTest"

	configurations
	{
		"Debug"--,
		--"Release",
	}

outputdir = "%{cfg.buildcfg}"

group "Basic_Modules"
	include "Basic_Input"
	include "Basic_Physics"
	include "Basic_Renderer"

group "Tests"
	include "EngineTest"
	
group ""
	include "MEE"

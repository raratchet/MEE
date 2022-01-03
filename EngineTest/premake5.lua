project "EngineTest"
   kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	
	targetdir ("%{wks.location}/bin/" .. outputdir)
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"include/**.h",
		"src/**.cpp"
	}
	
	includedirs
    {
		("%{wks.location}".."/".."%{prj.name}".."/include"),
		"%{IncludeDir.MEE}"
    }
	
	libdirs
    {
		"%{LibDir.MEE}"
    }
	
	filter "system:windows"
		systemversion "latest"
		links
		{
			"MEE.lib"
		}

	filter "system:macosx"
		links
		{
			"libMEE.dylib"
		}


		
	filter "configurations:Debug"
		defines "_DEBUG"
		runtime "Debug"
		symbols "on"
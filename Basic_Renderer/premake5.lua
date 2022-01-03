project "Basic_Renderer"
   kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/Plugins/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/Plugins/%{prj.name}")
	
	files
	{
		"include/**.h",
		"src/**.cpp"
	}
	
	includedirs
    {
		("%{wks.location}".."/".."%{prj.name}".."/include"),
		"%{IncludeDir.SDL2}",
		"%{IncludeDir.SDL_image}",
		"%{IncludeDir.MEE}"
    }
	
	libdirs
    {
		"%{LibDir.SDL2}",
		"%{LibDir.SDL_image}",
		"%{LibDir.MEE}"
    }
	
	filter "system:windows"
		systemversion "latest"
		links
		{
			"SDL2.lib",
			"SDL2main.lib",
			"SDL2_image.lib",
			"MEE.lib"
		}

	filter "system:macosx"
		links
		{
			"libSDL2.dylib",
			"libSDL2_image.dylib",
			"libMEE.dylib"
		}
		
	filter "configurations:Debug"
		defines "_DEBUG"
		runtime "Debug"
		symbols "on"
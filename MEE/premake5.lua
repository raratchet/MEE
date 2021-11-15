project "MEE"
   kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	
	
	targetdir ("%{wks.location}/bin/" .. outputdir)
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"include/**.h",
		"src/**.cpp"
	}
	
	defines
	{
		"MEE_ENGINE"
	}
	
	includedirs
    {
		("%{wks.location}".."/".."%{prj.name}".."/include"),
		"%{IncludeDir.SDL2}",
		"%{IncludeDir.GLEW}",
		"%{IncludeDir.easyloggingpp}",
		"%{IncludeDir.yaml_cpp}"
    }
	
	libdirs
	{
		"%{LibDir.SDL2}",
		"%{LibDir.GLEW}",
		"%{LibDir.easyloggingpp}",
		"%{LibDir.yaml_cpp}"
	}
	
	links
	{
		"SDL2.lib",
		"SDL2main.lib",
		"yaml-cppd.lib",
		"glew32.lib",
		"glew32s.lib",
		"easyloggingpp.lib"
	}
	
	filter "configurations:Debug"
		defines "MEE_DEBUG"
		defines "_DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "system:windows"
		systemversion "latest"
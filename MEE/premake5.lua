project "MEE"
   kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
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
		"%{IncludeDir.easyloggingpp}",
		"%{IncludeDir.yaml_cpp}"
    }
	
	links
	{
		"SDL2.lib",
		"SDL2main.lib",
		"yaml-cppd.lib",
		"easyloggingpp.lib"
	}
	
	filter "configurations:Debug"
		defines "MEE_DEBUG"
		runtime "Debug"
		symbols "on"
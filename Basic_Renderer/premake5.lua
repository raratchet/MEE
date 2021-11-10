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
	
	links
	{
		"SDL2.lib",
		"SDL2main.lib"
	}
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
	
	links
	{
		"SDL2.lib",
		"SDL2main.lib",
		"SDL2_image.lib",
		"MEE.lib"
	}
	
	postbuildcommands 
	{ 
		"{COPYFILE} ./resources/info.yaml %{targetdir}",
		"{COPYFILE} %{LibDir.SDL_image}/SDL2_image.dll %{targetdir}",	
		"{COPYFILE} %{LibDir.SDL_image}/libjpeg-9.dll %{targetdir}",	
		"{COPYFILE} %{LibDir.SDL_image}/libpng16-16.dll %{targetdir}",	
		"{COPYFILE} %{LibDir.SDL_image}/libtiff-5.dll %{targetdir}",	
		"{COPYFILE} %{LibDir.SDL_image}/libwebp-7.dll %{targetdir}",	
		"{COPYFILE} %{LibDir.SDL_image}/zlib.1.dll %{targetdir}"	
	}
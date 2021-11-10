project "Basic_Physics"
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
	
	Box2D_path = "Dependencies/Box2D"
	
	includedirs
    {
		("%{wks.location}".."/".."%{prj.name}".."/include"),
		("%{Box2D_path}".."/include"),
		"%{IncludeDir.MEE}"
    }
	
	libdirs
	{
		("%{Box2D_path}".."/libs"),
		"%{LibDir.MEE}"
	}
	
	links
	{
		"box2d.lib",
		"MEE.lib"
	}
	
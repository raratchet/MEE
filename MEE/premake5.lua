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
	
	--Deberia cambiar segun el realease
	filter { "system:windows" }
		ok,err = os.copyfile("C:/Work/A_Cruel_Angel_Engine/MEE/Dependencies/SDL2/lib/SDL2.dll" , "C:/Work/A_Cruel_Angel_Engine/MEE/bin/Debug")
		--print("La direccion es: " , wks.location)
		print("Copy file resulted in: " , ok , err)
		ok,err = os.copyfile("%{wks.location}Dependencies\\glew\\glew32.dll" , "%{wks.location}bin\\Debug\\")
		print("Copy file resulted in: " , ok , err)

	
	filter "configurations:Debug"
		defines "MEE_DEBUG"
		runtime "Debug"
		symbols "on"
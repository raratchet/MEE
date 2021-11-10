

IncludeDir = {}

IncludeDir["SDL2"] = "%{wks.location}/Dependencies/SDL2/include"
IncludeDir["SDL_image"] = "%{wks.location}/Dependencies/SDL2_image/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Dependencies/yaml-cpp/include"
IncludeDir["GLEW"] = "%{wks.location}/Dependencies/glew/include"
IncludeDir["stb_image"] = "%{wks.location}/Dependencies/stb"
IncludeDir["easyloggingpp"] = "%{wks.location}/Dependencies/easyloggingpp/src"
IncludeDir["MEE"] = "%{wks.location}/MEE/include"

LibDir = {}
LibDir["SDL2"] = "%{wks.location}/Dependencies/SDL2/lib"
LibDir["SDL_image"] = "%{wks.location}/Dependencies/SDL2_image/lib"
LibDir["yaml_cpp"] = "%{wks.location}/Dependencies/yaml-cpp/lib"
LibDir["GLEW"] = "%{wks.location}/Dependencies/glew/lib"
LibDir["easyloggingpp"] = "%{wks.location}/Dependencies/easyloggingpp/lib"
LibDir["MEE"] = "%{wks.location}/bin/%{cfg.buildcfg}"


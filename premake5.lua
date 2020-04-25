workspace "SFML"
    architecture "x64"
    configurations
    {
        "Debug",
		"release"
    }

project "sfml_space_invaders"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/")
    objdir ("bin-int/")

    links{
		"sfml-audio",
        "sfml-system",
        "sfml-window",
        "sfml-graphics",
    }

    files
    {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs
    {
        "include/",
    }

    filter "system:linux"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "DEBUG"
		symbols "Off"

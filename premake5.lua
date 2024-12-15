workspace "Bee"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--包含一个解决方案的相对路径
IncludeDir = {}
IncludeDir["GLFW"] = "Bee/vendor/GLFW/include"

include "Bee/vendor/GLFW"

project "Bee"
    location "Bee"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    --预编译头文件
    pchheader "beepch.h"
    pchsource "Bee/src/beepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BEE_PLATFORM_WINDOWS",
            "BEE_BUILD_DLL",
            "BEE_ENABLE_ASSERTS"
        }
        
        postbuildcommands
        {
            --这里先创建这个文件夹否则无法直接启动
            "{RMDIR} ../bin/" .. outputdir .. "/Sandbox",
            "{MKDIR} ../bin/" .. outputdir .. "/Sandbox",
            --注意这里的dll文件生成时，sanbox文件夹还不存在
            "{COPYFILE} ../bin/" .. outputdir .. "/Bee/Bee.dll ../bin/" .. outputdir .. "/Sandbox"
        }
    
    filter "configurations:Debug"
        defines "BEE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BEE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BEE_DIST"
        optimize "On"
    
    filter {"system:windows","configurations:Release"}
        buildoptions "/MD"

project "Sandbox" 
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Bee/vendor/spdlog/include",
        "Bee/src"
    }

    links
    {
        "Bee"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "BEE_PLATFORM_WINDOWS"
        }
        
        
    filter "configurations:Debug"
    defines "BEE_DEBUG"
    symbols "On"

    filter "configurations:Release"
        defines "BEE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BEE_DIST"
        optimize "On"
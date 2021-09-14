workspace "Pyrite"
    architecture "x64"

    startproject "PyriteSandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/"

    IncludeDir = {}
    IncludeDir["glfw"] = "PyriteEngine/vendor/glfw/include"
    IncludeDir["spdlog"] = "PyriteEngine/vendor/spdlog/include"

    include "PyriteEngine/vendor/glfw" -- Adds the glfw premake file

    project "PyriteEngine"
        location "PyriteEngine"
        kind "SharedLib"
        language "C++"

        targetdir ("bin/" .. outputdir .. "%{prj.name}")
        objdir ("tmp-build/" .. outputdir .. "%{prj.name}")

        pchheader "pyrpch.h"
        pchsource "%{prj.name}/src/pyrpch.cpp"

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
        }

        includedirs
        {
            "%{prj.name}/src",
            "%{IncludeDir.glfw}",
            "%{IncludeDir.spdlog}"
        }

        links
        {
            "glfw",
            "opengl32.lib"
        }

        filter "system:windows"

            cppdialect "C++20"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "PYR_PLATFORM_WINDOWS",
                "PYR_BUILD_DLL"
            }

            postbuildcommands
            {
                ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "PyriteSandbox") -- This is crap
            }

        filter "configurations:Debug"
            defines
            {
                "PYR_DEBUG",
                "PYR_ENABLE_ASSERTIONS"
            }
            symbols "On"
        
        filter "configurations:Release"
            defines
            {
                "PYR_RELEASE",
                "PYR_ENABLE_ASSERTIONS"
            }
            optimize "On"

        filter "configurations:Dist"
            defines "PYR_DIST"
            optimize "On"




    project "PyriteSandbox"
        location "PyriteSandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "%{prj.name}")
        objdir ("tmp-build/" .. outputdir .. "%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
        }

        includedirs
        {
            "%{IncludeDir.spdlog}",
            "PyriteEngine/src"
        }

        links
        {
            "PyriteEngine"
        }

        filter "system:windows"

            cppdialect "C++20"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "PYR_PLATFORM_WINDOWS"
            }

        filter "configurations:Debug"
            defines "PYR_DEBUG"
            symbols "On"
        
        filter "configurations:Release"
            defines "PYR_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "PYR_DIST"
            optimize "On"
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

    project "PyriteEngine"
        location "PyriteEngine"
        kind "SharedLib"
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
            "%{prj.name}/vendor/spdlog/include"
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
            defines "PYR_DEBUG"
            symbols "On"
        
        filter "configurations:Release"
            defines "PYR_RELEASE"
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
            "PyriteEngine/vendor/spdlog/include",
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
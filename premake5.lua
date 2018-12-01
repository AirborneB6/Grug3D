workspace "Grug3D"
    architecture "x64"
    configurations {"Debug" , "Release" , "Dist"}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Grug3D"
    location "Grug3D"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On" 
        systemversion "latest"

    defines
    {
        "GRUG_BUILD_DLL",
        "GRUG_PLATFORM_WINDOWS",
        "_WINDLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

filter "configurations:Debug"
    defines "GRUG_DEBUG"
    symbols "On"

filter "configurations:Release"
    defines "GRUG_RELEASE"
    optimize "On"

filter "configurations:Dist"
    defines "GRUG_DIST"
    optimize "On"

    


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
        "Grug3D/vendor/spdlog/include",
        "Grug3D/src"
    }

    links
    {
        "Grug3D"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On" 
        systemversion "latest"

    defines
    {
        "GRUG_PLATFORM_WINDOWS"
    }

filter "configurations:Debug"
    defines "GRUG_DEBUG"
    symbols "On"

filter "configurations:Release"
    defines "GRUG_RELEASE"
    optimize "On"

filter "configurations:Dist"
    defines "GRUG_DIST"
    optimize "On"
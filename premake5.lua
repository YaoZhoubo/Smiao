workspace "Smiao" -- sln文件名
architecture "x64"
configurations {"Debug", "Release", "Dist"}
-- 组成输出目录:Debug-windows-x86_64
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Smiao--------------------------------------------------------------------------------------------------------------------------------
project "Smiao" -- 项目
location "Smiao" -- 在sln所属文件夹下的文件夹
kind "SharedLib" -- dll动态库
language "C++"
targetdir("bin/" .. outputdir .. "/%{prj.name}") -- 输出目录
objdir("bin-int/" .. outputdir .. "/%{prj.name}") -- 中间目录

-- 包含的所有h和cpp文件
files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
-- 包含目录
includedirs {"vendor/spdlog/include", "%{prj.name}/src"}
-- 如果是window系统
filter "system:windows"
cppdialect "C++17"
-- On:代码生成的运行库选项是MTD,静态链接MSVCRT.lib库;
-- Off:代码生成的运行库选项是MDD,动态链接MSVCRT.dll库;打包后的exe放到另一台电脑上若无这个dll会报错
staticruntime "On"
systemversion "latest" -- windowSDK版本
-- 预处理器定义
defines {"SM_ENGINE"}
-- 编译好后移动Smiao.dll文件到Sandbox文件夹下
postbuildcommands {("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")}
-- 不同配置下的预定义不同
filter "configurations:Debug"
defines "_DEBUG"
symbols "On"

filter "configurations:Release"
defines "_RELEASE"
optimize "On"

-- Sandbox--------------------------------------------------------------------------------------------------------------------------------
project "Sandbox"
location "Sandbox"
kind "ConsoleApp"
language "C++"

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
-- 同样包含spdlog头文件
includedirs {"vendor/spdlog/include", "Smiao/src"}
-- 引用hazel
links {"Smiao"}

filter "system:windows"
cppdialect "C++17"
staticruntime "On"
systemversion "latest"

defines {""}

filter "configurations:Debug"
defines "_DEBUG"
symbols "On"

filter "configurations:Release"
defines "_RELEASE"
optimize "On"

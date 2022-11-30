:: TODO: Refactor this file to make it part of the cmake compilation

C:\VulkanSDK\1.3.231.1\Bin\glslc.exe shaders\simple_shader.vert -o shaders\simple_shader.vert.spv
C:\VulkanSDK\1.3.231.1\Bin\glslc.exe shaders\simple_shader.frag -o shaders\simple_shader.frag.spv

ROBOCOPY  shaders\ build\mingw_clang\debug\shaders\ /mir
ROBOCOPY  shaders\ build\mingw_clang\release\shaders\ /mir
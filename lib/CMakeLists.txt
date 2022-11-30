cmake_minimum_required(VERSION 3.23)

add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(vulkan)

find_package(Vulkan)

target_include_directories(Oxymore_Engine PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(Oxymore_Engine PUBLIC glfw glm ${Vulkan_LIBRARIES})
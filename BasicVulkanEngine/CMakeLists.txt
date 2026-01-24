cmake_minimum_required(VERSION 3.20)

project(vrender LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(VRENDER_ROOT_DIR ${CMAKE_SOURCE_DIR}/src)

add_library(vrender
	src/PlatformLayer/WindowBackends/GLFWWindowSurfaceProvider.cpp
	src/PlatformLayer/WindowBackends/SDLWindowSurfaceProvider.cpp
	src/PlatformLayer/WindowBackends/SFMLWindowSurfaceProvider.cpp

	src/RenderLayer/Instance.cpp
)

find_package(Vulkan REQUIRED MODULE)
target_link_libraries(vrender PUBLIC Vulkan::Vulkan)

add_subdirectory(external/glfw-3.4)
target_include_directories(vrender PUBLIC external/glfw/include)
target_link_libraries(vrender PUBLIC glfw)
target_compile_definitions(vrender PUBLIC VRENDER_HAS_GLFW)

find_package(SDL2 QUIET)
if (SDL2_FOUND)
	message(STATUS "SDL Found - Enabling SDL Window Backend")

	target_link_libraries(vrender PRIVATE SDL2::SDL2)
	target_compile_definitions(vrender PRIVATE VRENDER_HAS_SDL)
endif()

find_package(SFML QUIET)
if (SFML_FOUND)
	message(STATUS "SFML Found - Enabling SFML Window Backend")


endif()

target_include_directories(vrender PUBLIC
	src/
	src/PlatformLayer/WindowBackends/
)

add_executable(vrender_test main.cpp)
target_link_libraries(vrender_test PRIVATE vrender)
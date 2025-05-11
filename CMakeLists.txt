cmake_minimum_required(VERSION 3.22.1)
project(clock)

if(MSVC)
    add_definitions(-DSFML_STATIC)
    find_package(OpenGL REQUIRED)
endif()

find_package(SFML 2.6 REQUIRED COMPONENTS system window graphics)

add_executable(clock src/main.cpp)

if(MSVC)
    target_link_libraries(clock sfml-system-s sfml-window-s sfml-graphics-s openal32 opengl32 freetype winmm gdi32)
else()
    target_link_libraries(clock sfml-system sfml-window sfml-graphics)
endif()
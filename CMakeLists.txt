cmake_minimum_required(VERSION 3.25)
project(Taskr VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Statically link the C++ runtime so users don't need the VC++ Redistributable
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_executable(taskr WIN32
    src/main.cpp
)

target_compile_definitions(taskr PRIVATE
    UNICODE _UNICODE
    WIN32_LEAN_AND_MEAN
    NOMINMAX
)

if(MSVC)
    target_compile_options(taskr PRIVATE /W4 /WX /permissive- /utf-8)
endif()
cmake_minimum_required(VERSION 3.15)
project(ggdi VERSION 0.0.0 LANGUAGES CXX)

include(CMakeDependentOption)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_definitions(-DPLATFORM_WIN32=1 -DGGDI_DLL=1)
endif()

cmake_dependent_option(USE_MSVC_RUNTIME_LIBRARY_DLL
    "Use MSVC runtime library DLL" ON "MSVC" OFF)
if(MSVC AND NOT USE_MSVC_RUNTIME_LIBRARY_DLL)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif(MSVC AND NOT USE_MSVC_RUNTIME_LIBRARY_DLL)

file(
    GLOB_RECURSE hdrs
    ./include/*.h
    ./src/*.h
    ./src/*.hxx
)

file(
    GLOB_RECURSE srcs
    ./src/*.cpp
    ./src/*.cxx
)

add_library(${PROJECT_NAME} SHARED ${srcs} ${headers})

install(DIRECTORY ./include DESTINATION ".")
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
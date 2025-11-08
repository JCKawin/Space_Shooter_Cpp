cmake_minimum_required(VERSION 3.16)
project(Space_Shooter_Cpp LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

if(NOT PROJECT_SOURCES)
    message(FATAL_ERROR "No source files found in src/*.cpp")
endif()

# Executable target (CMake will add .exe on Windows automatically)
add_executable(Space_Shooter_Cpp ${PROJECT_SOURCES})

# Public headers (your own and/or third-party headers copied to include/)
target_include_directories(Space_Shooter_Cpp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link external prebuilt libraries from lib/
# This will link all libraries found in the lib folder with appropriate extensions per-platform.
if(WIN32)
    file(GLOB EXT_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.lib")
elseif(APPLE)
    file(GLOB EXT_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.a" "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.dylib")
else()
    file(GLOB EXT_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.a" "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.so")
endif()

if(EXT_LIBS)
    target_link_directories(Space_Shooter_Cpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
    target_link_libraries(Space_Shooter_Cpp PRIVATE ${EXT_LIBS})
endif()

# CMakeList.txt : CMake project for Space_Shooter_Cpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.30)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Space_Shooter_Cpp")

if (WIN32)
# vcpkg
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")
endif()

set(SOURCEFILES
    src/Space_Shooter_Cpp.cpp
    src/Space_Shooter_Cpp.h
    src/Ship.cpp
    src/Ship.h)

# Add source to this project's executable.
add_executable (Space_Shooter_Cpp ${SOURCEFILES})

find_package(raylib CONFIG REQUIRED)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Space_Shooter_Cpp PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(Space_Shooter_Cpp PRIVATE raylib)

# TODO: Add tests and install targets if needed.

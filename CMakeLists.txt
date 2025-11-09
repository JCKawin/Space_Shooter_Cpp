cmake_minimum_required(VERSION 3.16)
project(Space_Shooter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE MY_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(Space_Shooter "${MY_FILES}")

target_compile_definitions(Space_Shooter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(Space_Shooter ${CMAKE_CURRENT_SOURCE_DIR}/lib/libraylib.a)

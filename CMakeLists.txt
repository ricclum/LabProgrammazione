cmake_minimum_required(VERSION 3.13)
project(Lab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)
set(SOURCE_FILES Item.h Item.cpp List.h List.cpp AbstractSubject.h Observer.h User.h User.cpp)
add_executable(LabProj ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(LabProj core)
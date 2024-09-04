cmake_minimum_required(VERSION 3.13)
project(Lab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)
set(SOURCE_FILES Item.cpp Item.h List.cpp List.h User.cpp User.h AbstractSubject.h Observer.h main.cpp)
add_executable(LabProj ${SOURCE_FILES})
add_library(core ${SOURCE_FILES}
        main.cpp)
target_link_libraries(LabProj core)



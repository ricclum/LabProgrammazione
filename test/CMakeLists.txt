add_subdirectory(./lib)
set (lib_SOURCE_DIR, ./lib/)
include_directories(${lib_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ItemTest.cpp ListTest.cpp UserTest.cpp ObTestUser.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)
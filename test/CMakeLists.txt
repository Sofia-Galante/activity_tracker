cmake_minimum_required(VERSION 3.12)


add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ActivityTest.cpp ActivityFixture.cpp)
add_executable(runActivityTests ${TEST_SOURCE_FILES})
target_link_libraries(runActivityTests gtest gtest_main core)
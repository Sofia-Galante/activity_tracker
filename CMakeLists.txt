cmake_minimum_required(VERSION 3.12)
project(activitytracker)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net gl core base adv)
include(${wxWidgets_USE_FILE})

add_subdirectory(test)

set(SOURCE_FILES Activity.cpp Activity.h Register.cpp Register.h FrameDay.cpp FrameDay.h Subject.h Observer.h FrameActivity.cpp FrameActivity.h)
add_executable(activitytracker main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(activitytracker ${wxWidgets_LIBRARIES} core)
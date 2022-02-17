cmake_minimum_required(VERSION 3.8)
#set(OpenCV_DIR "../opencv_build")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(dyakov_v_d)

find_package(OpenCV 4 REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(prj.labs)

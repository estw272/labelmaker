cmake_minimum_required(VERSION 3.16)

project(labelmaker_main
    VERSION 0.1.0
    DESCRIPTION "" 
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

#project settings
include(ProjectSettings)
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

#project warnings
include(CompilerWarnings)
add_library(project_warnings INTERFACE)
set_project_warnings(project_warnings)

#Qt and Boost settings
include(QtSettings)
include(BoostSettings)

#project libs
if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/cmake/LibsPath.cmake)
    include(LibsPath)
endif()

add_subdirectory(libs)
add_subdirectory(apps)

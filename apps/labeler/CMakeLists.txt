cmake_minimum_required(VERSION 3.16)

project(labelmaker
    VERSION 0.1.0 
    DESCRIPTION "" 
    LANGUAGES CXX
)

#version
configure_file(src/labelmaker_version.cpp.in src/labelmaker_version.cpp @ONLY)
add_library(labelmaker_version STATIC src/labelmaker_version.h src/labelmaker_version.cpp)
set_target_properties(labelmaker_version PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(labelmaker_version PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADER_FILES
)
set(SOURCE_FILES
)
set(UI_FILES
)
set(RESOURCE_FILES
)
set(PROTO_FILES
)
add_executable(labelmaker ${HEADER_FILES} ${SOURCE_FILES} ${PROTO_FILES} ${UI_FILES} ${RESOURCE_FILES})
set_target_properties(labelmaker PROPERTIES OUTPUT_NAME labelmaker)
set_target_properties(labelmaker PROPERTIES LINKER_LANGUAGE CXX)
target_precompile_headers(labelmaker PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h)

# set MT / MTd static linking flags
set_property(TARGET labelmaker PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

find_package(spdlog REQUIRED)
find_package(Boost REQUIRED COMPONENTS date_time regex)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

target_link_libraries(labelmaker
    PRIVATE 
        project_options
        project_warnings
        labelmaker_version

        spdlog::spdlog

        Boost::boost 
        Boost::date_time 
        Boost::regex 

        Qt5::Core 
        Qt5::Gui 
        Qt5::Widgets 
)
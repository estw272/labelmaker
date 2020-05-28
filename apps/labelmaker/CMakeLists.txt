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
    src/mainwindow.h
    src/mainwidget.h
    src/mainpanelwidget.h
    src/imagelisttablemodel.h
    src/programstate.h
    src/tagswidget.h
    src/qflowlayout.h
    src/tag.h
)
set(SOURCE_FILES
    src/main.cpp
)
set(UI_FILES
    src/mainwindow.ui
    src/mainwidget.ui
)
set(RESOURCE_FILES
    src/mainwindow.cpp
    src/mainwidget.cpp
    src/mainpanelwidget.cpp
    src/imagelisttablemodel.cpp
    src/programstate.cpp
    src/tagswidget.cpp
    src/qflowlayout.cpp
    src/tag.cpp
)
add_executable(labelmaker ${HEADER_FILES} ${SOURCE_FILES} ${UI_FILES} ${RESOURCE_FILES})
set_target_properties(labelmaker PROPERTIES OUTPUT_NAME labelmaker)
set_target_properties(labelmaker PROPERTIES LINKER_LANGUAGE CXX)
target_precompile_headers(labelmaker PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.h)

# set MT / MTd static linking flags
set_property(TARGET labelmaker PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

find_package(spdlog REQUIRED)
#find_package(Boost REQUIRED COMPONENTS)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

target_link_libraries(labelmaker
    PRIVATE 
        project_options
        project_warnings
        labelmaker_version

        spdlog::spdlog

#        Boost::boost

        Qt5::Core 
        Qt5::Gui 
        Qt5::Widgets 
)
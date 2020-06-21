cmake_minimum_required(VERSION 3.16)

project(proto_messages
        VERSION 0.1.0
        DESCRIPTION ""
        LANGUAGES CXX
)

add_library(proto_messages STATIC
        proto/protoimageinfo.pb.cc
        proto/protoimageinfo.pb.h
        proto/prototagscache.pb.cc
        proto/prototagscache.pb.h
        proto/prototag.pb.cc
        proto/prototag.pb.h
)
target_include_directories(proto_messages PUBLIC ${CMAKE_CURRENT_LIST_DIR}/proto)

# set MT / MTd static linking flags
if (MSVC)
    set_property(TARGET proto_messages PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

find_package(protobuf CONFIG REQUIRED)

target_link_libraries(proto_messages
        PUBLIC
            protobuf::libprotobuf
            protobuf::libprotobuf-lite
            protobuf::libprotoc
)

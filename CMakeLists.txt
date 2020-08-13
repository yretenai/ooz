cmake_minimum_required(VERSION 3.17)

project(libooz)

add_library(libooz SHARED kraken.cpp bitknit.cpp lzna.cpp)

set_target_properties(libooz PROPERTIES CMAKE_CXX_STANDARD 20)
set_target_properties(libooz PROPERTIES CMAKE_CXX_STANDARD_REQUIRED ON)
set_target_properties(libooz PROPERTIES CMAKE_CXX_EXTENSIONS OFF)
set_target_properties(libooz PROPERTIES CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O0")

if(MSVC)
    generate_export_header(libooz BASE_NAME OOZ DEFINE_NO_DEPRECATED EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/autogen/export_win32.h)
else()
    # :(
    generate_export_header(libooz BASE_NAME OOZ DEFINE_NO_DEPRECATED EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/autogen/export_clang.h)
endif()

cmake_minimum_required(VERSION 3.9)

set(project "ADLX_Wrapper")

set(all_file
  "adlxWrapper.cpp"
  ${CMAKE_SOURCE_DIR}/../SDK/ADLXHelper/Windows/Cpp/ADLXHelper.h
  ${CMAKE_SOURCE_DIR}/../SDK/ADLXHelper/Windows/Cpp/ADLXHelper.cpp
  ${CMAKE_SOURCE_DIR}/../SDK/platform/Windows/WinAPIs.cpp
 )

 set(BUILD_SHARED_LIBS true)
 set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

add_library(${project} ${all_file})


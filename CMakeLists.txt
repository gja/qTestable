cmake_minimum_required(VERSION 2.8)
project(helloworld)

option(USE_TEST "Generate Test Libraries" OFF)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(Qt4 REQUIRED)
set(QT_USE_QTDBUS TRUE)

if(USE_TEST)
  set(QT_USE_QTTEST TRUE)
endif(USE_TEST)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
include_directories(include)

set(LIBRARIES ${QT_LIBRARIES})

add_subdirectory(lib bin)

if(USE_TEST)
  add_subdirectory(test)
  add_subdirectory(ft)
endif(USE_TEST)

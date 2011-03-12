cmake_minimum_required(VERSION 2.8)
project(qTestable)

if(NOT VERSION)
  set (VERSION LATEST)
endif(NOT VERSION)

option(USE_TEST "Generate Test Libraries" OFF)

find_package(Qt4 REQUIRED)
set(QT_USE_QTDBUS TRUE)
find_package(QJSON REQUIRED)

if(USE_TEST)
  set(QT_USE_QTTEST TRUE)
  enable_testing()
endif(USE_TEST)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
include_directories(include ${QJSON_INCLUDE_DIR})

set(LIBRARIES ${QT_LIBRARIES} ${QJSON_LIBRARIES})

add_subdirectory(lib)
add_subdirectory(include)

if(USE_TEST)
  add_subdirectory(test)
  add_subdirectory(ft)
endif(USE_TEST)

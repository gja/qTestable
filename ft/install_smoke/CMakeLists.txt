cmake_minimum_required(VERSION 2.8)
project(qTestable-smoke)

find_package(Qt4 REQUIRED)
find_package(qTestable REQUIRED)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

SET(SOURCES main.cpp Form.cpp)
SET(HEADERS Form.h) 
QT4_WRAP_UI(UI_FILES Form.ui)
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

enable_testing()

add_executable(install_smoke ${SOURCES} ${HEADERS_MOC} ${UI_FILES})
target_link_libraries(install_smoke ${QT_LIBRARIES} ${QTESTABLE_LIBRARIES})

add_test(install_smoke "${CMAKE_CURRENT_SOURCE_DIR}/runTest.sh")

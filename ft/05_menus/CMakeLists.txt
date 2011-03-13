SET(CURRENT_TEST 05_menus)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

SET(SOURCES main.cpp Form.cpp)
SET(HEADERS Form.h) 
QT4_WRAP_UI(UI Form.ui)
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

configure_file(runTest.rb.in runTest.rb)
add_executable(${CURRENT_TEST} ${SOURCES} ${HEADERS_MOC} ${UI})
target_link_libraries(${CURRENT_TEST} ${LIBRARIES})
#add_test(${CURRENT_TEST} "${CMAKE_CURRENT_BINARY_DIR}/runTest.rb")

SET(CURRENT_TEST 02_button_with_slot_based_commands) 

SET(SOURCES main.cpp LabelToButtonConnector.cpp)
SET(HEADERS LabelToButtonConnector.h Handler.h) 
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

configure_file(runTest.sh.in runTest.sh)
add_executable(${CURRENT_TEST} ${SOURCES} ${HEADERS_MOC})
target_link_libraries(${CURRENT_TEST} ${LIBRARIES})
add_test(${CURRENT_TEST} "${CMAKE_CURRENT_BINARY_DIR}/runTest.sh")

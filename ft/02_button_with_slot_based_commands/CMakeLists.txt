SET(SOURCES main.cpp LabelToButtonConnector.cpp)
SET(HEADERS LabelToButtonConnector.h Handler.h) 
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

add_executable(02_button_with_slot_based_commands ${SOURCES} ${HEADERS_MOC})
target_link_libraries(02_button_with_slot_based_commands ${LIBRARIES})

add_test(02_button_with_slot_based_commands "${CMAKE_CURRENT_SOURCE_DIR}/runTest.sh")

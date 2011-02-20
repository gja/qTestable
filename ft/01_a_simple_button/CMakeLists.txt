SET(SOURCES main.cpp LabelToButtonConnector.cpp)
SET(HEADERS LabelToButtonConnector.h)
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

add_executable(01_a_simple_button ${SOURCES} ${HEADERS_MOC})
target_link_libraries(01_a_simple_button ${LIBRARIES})

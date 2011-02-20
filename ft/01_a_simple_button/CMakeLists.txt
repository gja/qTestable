SET(SOURCES main.cpp)
SET(HEADERS )
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

add_executable(01_a_simple_button ${SOURCES} ${HEADERS_MOC})
target_link_libraries(01_a_simple_button ${LIBRARIES})

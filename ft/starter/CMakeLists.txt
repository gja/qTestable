SET(SOURCES main.cpp QTestableProxy.cpp)
SET(HEADERS QTestableProxy.h)
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

add_executable(starter ${SOURCES} ${HEADERS_MOC})
target_link_libraries(starter ${LIBRARIES})

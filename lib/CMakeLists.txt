SET(helloworld_SOURCES helloworld.cpp)
SET(helloworld_HEADERS )
QT4_WRAP_CPP(helloworld_HEADERS_MOC ${helloworld_HEADERS})

ADD_LIBRARY(helloworld SHARED ${helloworld_SOURCES} ${helloworld_HEADERS_MOC})
TARGET_LINK_LIBRARIES(helloworld ${QT_LIBRARIES})

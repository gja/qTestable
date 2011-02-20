SET(BLANK)
SET(qTestable_SOURCES QTestableApplication.cpp ConfigParser.cpp ParseRestRequest.cpp QTestableDBusAdaptor.cpp QTestableDBusServer.cpp ${BLANK})
SET(qTestable_HEADERS QTestableDBusAdaptor.h QTestableDBusServer.h)
QT4_WRAP_CPP(qTestable_HEADERS_MOC ${qTestable_HEADERS})

add_library(qTestable SHARED ${qTestable_SOURCES} ${qTestable_HEADERS_MOC})
target_link_libraries(qTestable ${LIBRARIES})

SET(BLANK)
SET(qTestable_SOURCES QTestableApplication.cpp ConfigParser.cpp ${BLANK})
SET(qTestable_HEADERS )
QT4_WRAP_CPP(qTestable_HEADERS_MOC ${qTestable_HEADERS})

ADD_LIBRARY(qTestable SHARED ${qTestable_SOURCES} ${qTestable_HEADERS_MOC})
TARGET_LINK_LIBRARIES(qTestable ${QT_LIBRARIES})

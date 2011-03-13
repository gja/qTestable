SET(BLANK)
SET(HBLANK)
SET(qTestable_SOURCES QTestableService.cpp ConfigParser.cpp QTestableAutomationRequest.cpp
      QTestableDBusAdaptor.cpp QTestableDBusServer.cpp Dispatcher.cpp QTestableClassHandler.cpp
      StandardHandlers.cpp ObjectFinder.cpp Helper.cpp ${BLANK})
SET(qTestable_HEADERS QTestableDBusAdaptor.h QTestableDBusServer.h handlers/handler_for_button.h 
      handlers/handler_for_application.h handlers/handler_for_label.h handlers/handler_for_menuBar.h ${HBLANK})
QT4_WRAP_CPP(qTestable_HEADERS_MOC ${qTestable_HEADERS})

add_library(qTestable SHARED ${qTestable_SOURCES} ${qTestable_HEADERS_MOC})
target_link_libraries(qTestable ${LIBRARIES})

SET_TARGET_PROPERTIES(qTestable
                      PROPERTIES
                      VERSION ${VERSION}
                      SOVERSION 1)

INSTALL(TARGETS qTestable
        DESTINATION lib
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

CONFIGURE_FILE(qTestable.pc.in qTestable.pc @ONLY)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/qTestable.pc
        DESTINATION lib/pkgconfig
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

INSTALL(FILES IQTestableClassHandler.h QTestableAutomationRequest.h QTestableClassHandler.h QTestable.h QTestableService.h
        DESTINATION include/qTestable
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

INSTALL(FILES FindqTestable.cmake
        DESTINATION share/cmake/Modules
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)


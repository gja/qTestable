ENABLE_TESTING()

include_directories(${CMAKE_CURRENT_BINARY_DIR})

macro (do_test arg)
  qt4_generate_moc(${arg}.cpp ${arg}.moc)
  add_executable (${arg} ${arg}.cpp)
  add_custom_target(${arg}.moc SOURCES ${arg}.moc)
  add_dependencies (${arg} ${arg}.moc)
  target_link_libraries(${arg} ${QT_LIBRARIES} qTestable)
  add_test (${arg} ${arg})
endmacro (do_test)


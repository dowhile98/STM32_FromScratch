add_library(nanoModbus INTERFACE)
target_sources(nanoModbus INTERFACE ${CMAKE_CURRENT_LIST_DIR}/nanoModbus/nanomodbus.c)
target_include_directories(nanoModbus INTERFACE ${CMAKE_CURRENT_LIST_DIR}/nanoModbus)
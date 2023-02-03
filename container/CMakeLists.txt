set(MODULE_CONTAINER container)

aux_source_directory(. CONTAINER_SOURCE)

add_library(${MODULE_CONTAINER} SHARED ${CONTAINER_SOURCE})

target_include_directories(${MODULE_CONTAINER} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${MODULE_CONTAINER} common)
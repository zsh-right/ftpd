set(MODULE_NETWORK network)

aux_source_directory(. NETWORK_SOURCE)

add_library(${MODULE_NETWORK} SHARED ${NETWORK_SOURCE})

target_include_directories(${MODULE_NETWORK} PUBLIC ${PROJECT_SOURCE_DIR})

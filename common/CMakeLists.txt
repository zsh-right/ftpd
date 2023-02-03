set(MODULE_COMMON common)

aux_source_directory(. COMMON_SOURCE)

add_library(${MODULE_COMMON} SHARED ${COMMON_SOURCE})
set(MODULE_FTP_COMMAND ftp_command)

aux_source_directory(. FTP_COMMAND_SOURCE)

add_library(${MODULE_FTP_COMMAND} SHARED ${FTP_COMMAND_SOURCE})

target_include_directories(${MODULE_FTP_COMMAND} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${MODULE_FTP_COMMAND} container)

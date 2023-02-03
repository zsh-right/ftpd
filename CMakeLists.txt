CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(FTP_SERVER)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


set(CMAKE_BUILD_TYPE "Debug")

add_subdirectory(common)
add_subdirectory(network)
add_subdirectory(container)
add_subdirectory(ftp_command)
add_subdirectory(ftp_server)
add_subdirectory(ftp_client)

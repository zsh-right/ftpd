set(MUDULE_MAIN server)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(${MUDULE_MAIN} main.cpp)


target_include_directories(${MUDULE_MAIN} PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(${MUDULE_MAIN}
    common
    container
    network
    ftp_command
    -lACE)

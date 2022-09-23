cmake_minimum_required(VERSION 3.10)

project(img_server LANGUAGES CXX C  VERSION 0.1)

set(AUTHOR "David D" )
set(DESCRIPTION "server for imgs")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

set(CMAKE_CXX_STANDARD 20)

include_directories( 
    ./include 
    ./include/handlers 
    ./poco/include 
    ./CImg 
    ${X11_INCLUDE_DIR} 
    )

add_executable(img_server "")

add_subdirectory(./src)
add_subdirectory(./src/handlers)


find_package(X11 REQUIRED)
target_link_libraries( img_server PRIVATE X11 )

find_package(JPEG REQUIRED)
target_link_libraries( img_server PRIVATE jpeg )

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
target_link_libraries(img_server PRIVATE Threads::Threads)

find_package(Poco REQUIRED Foundation)
target_link_libraries(img_server PRIVATE Poco::Foundation)

find_package(Poco REQUIRED Net)
target_link_libraries(img_server PRIVATE Poco::Net)

find_package(Poco REQUIRED Util)
target_link_libraries(img_server PRIVATE Poco::Util)


set_target_properties(
    PROPERTIES
    CXX_STANDARD 20
)






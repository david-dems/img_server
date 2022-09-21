cmake_minimum_required( VERSION 3.10 )

project(img_server LANGUAGES CXX C  VERSION 0.1)

set( AUTHOR "David D" )
set( DESCRIPTION "server for imgs" )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin )

set( CMAKE_CXX_STANDARD 20 )

#include_directories( ./src )
include_directories( ./include )
include_directories( ./include/handlers )
include_directories( ./poco/include )

add_executable( img_server "")
add_subdirectory( ./src )
add_subdirectory( ./src/handlers )



target_link_libraries( img_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/poco/lib/libPocoFoundation.so)
target_link_libraries( img_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/poco/lib/libPocoUtil.so)
target_link_libraries( img_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/poco/lib/libPocoNet.so)

set_target_properties(
    PROPERTIES
    CXX_STANDARD 20
)






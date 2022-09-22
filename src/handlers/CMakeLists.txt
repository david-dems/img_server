set( SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/recieve_image.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/not_found_handler.cpp
)
target_sources( img_server PRIVATE ${SOURCES} )
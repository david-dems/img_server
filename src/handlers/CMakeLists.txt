set( SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/set_text.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/recieve_image.cpp
)
target_sources( img_server PRIVATE ${SOURCES} )
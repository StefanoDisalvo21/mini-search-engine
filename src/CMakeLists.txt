add_library(searchengine
    document.cpp
    search_engine.cpp
    helpers_function.cpp
    command_line_interface.cpp
)


target_include_directories(searchengine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${ICU_INCLUDE_DIR} 
    PRIVATE ${EXTERNAL_DIR}   
)

target_link_libraries(searchengine
    PUBLIC ${ICU_LIBS}           
)


add_executable(mini_search_engine main.cpp)
target_link_libraries(mini_search_engine PRIVATE searchengine)

add_library(searchengine
    document.cpp
    search_engine.cpp
)

target_include_directories(searchengine
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${ICU_INCLUDE_DIRS}  
)

target_link_libraries(searchengine
    PUBLIC ${ICU_LIBRARIES}     
)

add_executable(mini_search_engine main.cpp)
target_link_libraries(mini_search_engine PRIVATE searchengine)

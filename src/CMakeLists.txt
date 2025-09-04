add_library(searchengine
    document.cpp
    search_engine.cpp
)
add_executable(mini_search_engine main.cpp)
target_link_libraries(mini_search_engine PRIVATE searchengine)
target_include_directories(searchengine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

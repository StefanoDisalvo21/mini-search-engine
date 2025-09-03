add_library(searchengine
    document.cpp
    search_engine.cpp
)
target_include_directories(searchengine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

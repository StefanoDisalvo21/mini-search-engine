add_executable(doc_test doc_test.cpp)
target_link_libraries(doc_test PRIVATE searchengine gtest_main)
add_executable(engine_test engine_test.cpp)
target_link_libraries(engine_test PRIVATE searchengine gtest_main)
add_executable(performance_test performance_test.cpp)
target_link_libraries(performance_test PRIVATE searchengine gtest_main)

target_compile_definitions(performance_test PRIVATE 
    IMDB_DATASET_PATH="${CMAKE_SOURCE_DIR}/data/imdb_dataset"
)

include(GoogleTest)
gtest_discover_tests(doc_test)
gtest_discover_tests(engine_test)
gtest_discover_tests(performance_test)
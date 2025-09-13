add_executable(doc_test doc_test.cpp)
target_link_libraries(doc_test PRIVATE searchengine gtest_main)
add_executable(engine_test engine_test.cpp)
target_link_libraries(engine_test PRIVATE searchengine gtest_main)


include(GoogleTest)
gtest_discover_tests(doc_test)
gtest_discover_tests(engine_test)

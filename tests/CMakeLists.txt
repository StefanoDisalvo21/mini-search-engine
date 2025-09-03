enable_testing()

add_executable(doc_test doc_test.cpp)
target_link_libraries(doc_test PRIVATE document GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(doc_test)

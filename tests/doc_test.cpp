#include <gtest/gtest.h>
#include "document.hpp"
using namespace std;

TEST(Load_Test,first_test){
    DomLoad dom_obj;
    string ds="../../random_name";
    EXPECT_THROW(dom_obj.read_docs(ds),invalid_argument);

}
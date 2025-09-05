#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "document.hpp"
using namespace std;

TEST(Load_Test,first_test){
    DomLoad dom_obj;
    string ds="../../random_name";
    EXPECT_THROW(dom_obj.load_data(ds),invalid_argument);

}
TEST(Load_Test,second_test){
    DomLoad dom_obj;
    string ds="../../README.md";
    EXPECT_THROW(dom_obj.load_data(ds),invalid_argument);

}

TEST(Load_Test,third_test){
    DomLoad dom_obj;
    string ds="../../data";
    vector<Document> docs = dom_obj.load_data(ds);
    sort(docs.begin(),docs.end());
    vector<string> names;
    vector<string> expected_names={"art1.txt","art2.txt","art3.txt","art4.txt"};
    for(int i=0;i<docs.size();i++){
        names.push_back(docs[i].get_file_name());
    }
    EXPECT_EQ(names,expected_names);
}
TEST(Load_Test,fourth_test){
    DomLoad dom_obj;
    Document doc("art1.txt","hi");
    Document doc1("art2.txt","hi");
    Document doc2("art3.txt","hi");
    Document doc3("art4.txt","hi");
    string ds="../../data";
    vector<Document> vt = dom_obj.load_data(ds);
    vector<Document> expected_vector={doc,doc1,doc2,doc3};
    sort(vt.begin(),vt.end());
    EXPECT_EQ(vt,expected_vector);
}
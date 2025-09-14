#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "document.hpp"
#include "search_engine.hpp"
using namespace std;

TEST(Index_Test, first_test){
    Document docs("art1.txt","Hello, Mark this is Mark");
    vector<Document> vector_docs;
    docs.normalization();
    docs.tokenization();
    vector_docs.push_back(docs);
    SearchEngine index_try;
    index_try.build_index(vector_docs);
    unordered_map<string, unordered_map<string,int>> expected_index;
    unordered_map<string, unordered_map<string,int>> index=index_try.get_index();

    expected_index["hello"]={{"art1.txt",1}};
    expected_index["mark"]={{"art1.txt",2}};
    expected_index["this"]={{"art1.txt",1}};
    expected_index["is"]={{"art1.txt",1}};
    EXPECT_EQ(index,expected_index);
}

TEST(Index_Test, second_test){
    Document docs("art1.txt","Hello, Mark this is Mark");
    Document docs2("art2.txt","Hello, Mark this is Jeff");
    vector<Document> vector_docs;
    docs.normalization();
    docs.tokenization();
    docs2.normalization();
    docs2.tokenization();
    vector_docs.push_back(docs);
    vector_docs.push_back(docs2);
    SearchEngine index_try;
    index_try.build_index(vector_docs);
    unordered_map<string, unordered_map<string,int>> expected_index;
    unordered_map<string, unordered_map<string,int>> index=index_try.get_index();

    expected_index["hello"]={{"art1.txt",1}, {"art2.txt",1}};
    expected_index["mark"]={{"art1.txt",2}, {"art2.txt",1}};
    expected_index["this"]={{"art1.txt",1},{"art2.txt",1}};
    expected_index["is"]={{"art1.txt",1},{"art2.txt",1}};
    expected_index["jeff"]={{"art2.txt",1}};
    EXPECT_EQ(index,expected_index);
}
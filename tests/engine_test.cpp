#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "document.hpp"
#include "search_engine.hpp"
using namespace std;

TEST(Index_Test, first_test){
    Document docs("art1.txt","Hello, Mark this is Mark");
    vector<Document> vector_docs;
    string cont= docs.get_file_content();
    icu::UnicodeString norm_string = helpers::normalization(cont);
    docs.set_normalized_string(norm_string);
    vector<string> tokens= helpers::tokenization(norm_string);
    docs.set_tokens(tokens);
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
    string cont= docs.get_file_content();
    icu::UnicodeString norm_string = helpers::normalization(cont);
    docs.set_normalized_string(norm_string);
    vector<string> tokens= helpers::tokenization(norm_string);
    docs.set_tokens(tokens);
    string cont2= docs2.get_file_content();
    icu::UnicodeString norm_string2 = helpers::normalization(cont2);
    docs2.set_normalized_string(norm_string2);
    vector<string> tokens2= helpers::tokenization(norm_string2);
    docs2.set_tokens(tokens2);
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
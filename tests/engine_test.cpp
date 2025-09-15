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


TEST(Score_Test, first_test){
    Document docs("doc1.txt", "cat dog cat mouse");
    Document docs2("doc2.txt", "dog dog elephant cat");
    Document docs3("doc3.txt", "mouse cat elephant elephant");
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
    string cont3= docs3.get_file_content();
    icu::UnicodeString norm_string3 = helpers::normalization(cont3);
    docs3.set_normalized_string(norm_string3);
    vector<string> tokens3= helpers::tokenization(norm_string3);
    docs3.set_tokens(tokens3);
    vector_docs.push_back(docs);
    vector_docs.push_back(docs2);
    vector_docs.push_back(docs3);
    SearchEngine index_try;
    index_try.build_index(vector_docs);
    unordered_map<string, unordered_map<string,int>> index=index_try.get_index();
    for (auto& [word, doc_map] : index) {
        cout << word << ": ";
        for (auto& [file, occ] : doc_map) std::cout << file << "(" << occ << ") ";
            cout << "\n";
    }
    string test_search="Cat Elephant";
    vector<pair<string,double>> results=index_try.search(test_search,vector_docs);
    double expected_score=0.274;
    EXPECT_EQ(results[0].first, "doc3.txt"); 
    EXPECT_NEAR(results[0].second, expected_score, 1e-3);

}
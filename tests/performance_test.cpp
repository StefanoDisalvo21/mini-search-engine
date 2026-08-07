#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include <chrono>
#include "search_engine.hpp"
#include "document.hpp"
using namespace std;

//loading test performance 12k doc
TEST(Performance_Test, load_test){
    DomLoad loader;
    vector<Document> data_vector;
    auto start = chrono::high_resolution_clock::now();
    data_vector = loader.load_data(IMDB_DATASET_PATH);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> delta = end - start;
    double seconds = delta.count();
    RecordProperty("total_docs", std::to_string(data_vector.size()));
    RecordProperty("total time", std::to_string(seconds));
    EXPECT_FALSE(data_vector.size()==0);
}


//building index performance 12k doc
TEST(Performance_Test, index_test){
    DomLoad loader;
    SearchEngine indexing;
    vector<Document> data_vector;
    data_vector = loader.load_data(IMDB_DATASET_PATH);
    auto start = chrono::high_resolution_clock::now();
    indexing.build_index(data_vector);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> delta = end - start;
    double seconds = delta.count();
    RecordProperty("total_docs", std::to_string(data_vector.size()));
    RecordProperty("total_time", std::to_string(seconds));
    EXPECT_FALSE(data_vector.size()==0);
}


//search 3 word performance 12k doc
TEST(Performance_Test, search_test){
    DomLoad loader;
    SearchEngine working_engine;
    string query = "best film ever";
    vector<Document> data_vector;
    data_vector = loader.load_data(IMDB_DATASET_PATH);
    working_engine.build_index(data_vector);
    vector<pair<int,double>> query_results;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0;i<100;++i){
        query_results=working_engine.search(query,data_vector);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> delta = end - start;
    double seconds = delta.count();
    double average_search_latency = delta.count()/100;

    
    RecordProperty("total_docs", std::to_string(data_vector.size()));
    RecordProperty("total_time", std::to_string(seconds));
    RecordProperty("avg_search_latency", std::to_string(seconds));
    EXPECT_FALSE(query_results.empty());
}
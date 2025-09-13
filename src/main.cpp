#include<iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem>
#include "document.hpp"
#include "search_engine.hpp"
using namespace std;


int main(){
    DomLoad loader;
    const string data_information = "../../data";
    vector<Document> data_vector=loader.load_data(data_information);
    SearchEngine working_engine;
    working_engine.build_index(data_vector);
    return 0;
}
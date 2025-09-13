#include<iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem>
#include "document.hpp"
#include "search_engine.hpp"
using namespace std;


int main(){
    int choice;
    DomLoad loader;
    const string data_information = "../../data";
    vector<Document> data_vector=loader.load_data(data_information);
    vector<vector<string>> tokens;
    for(const auto& docs :data_vector){
        tokens.push_back(docs.get_tokens());
    }
    return 0;
}
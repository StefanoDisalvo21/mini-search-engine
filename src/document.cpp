#include<iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem>
#include <fstream>
#include "document.hpp"
#include "helpers_function.hpp"
using namespace std;

namespace fs = std::filesystem;

vector<Document> DomLoad::read_docs(const string& data_path){
    vector<Document> ds;
    if(!fs::exists(data_path)){
        throw invalid_argument("The path does not exist");
    }
    if(!fs::is_directory(data_path)){
        throw invalid_argument("Not a directory");
    }
    for(auto& entry:fs::directory_iterator(data_path)){
        if(fs::path(entry).extension().string()==".txt"){
            Document doc(entry.path().filename().string(),"hi");
            ds.push_back(doc);
        }
    }
    return ds;
}


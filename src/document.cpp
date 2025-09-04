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

vector<Document> DomLoad::read_docs(const string& path){
    if(!fs::exists(path)){
        throw invalid_argument("The path does not exist");
    }

}


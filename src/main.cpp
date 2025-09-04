#include<iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem>
#include "document.hpp"
#include "search_engine.hpp"
#include "helpers_function.hpp"
using namespace std;


int main(){
    int choice;
    DomLoad loader;
    const string data_information = "../../data";
    vector<Document> docs=loader.read_docs(data_information);
    return 0;
}
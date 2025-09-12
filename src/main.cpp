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
    vector<Document> docs=loader.load_data(data_information);
    return 0;
}
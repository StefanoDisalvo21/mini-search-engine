#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <filesystem>
#include "document.hpp"
#include "helpers_function.hpp"
using namespace std;

class SearchEngine{
    private:
        unordered_map<string, unordered_map<string,int>> index;
    public:
        void build_index(vector<Document>& data);
        vector<pair<string,double>> search(string& query);
};
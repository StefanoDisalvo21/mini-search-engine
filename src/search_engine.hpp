#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <filesystem>
#include <cmath>
#include "document.hpp"
#include "helpers_function.hpp"
using namespace std;

class SearchEngine{
    private:
        unordered_map<string, unordered_map<string,int>> index;
    public:
        const unordered_map<string,unordered_map<string,int>>& get_index() const {return index;};
        void build_index(vector<Document>& data_vector);
        vector<pair<string,double>> search(string& query,vector<Document>& data_vector);
        vector<pair<string,double>>calc_score(string& quert,vector<Document>&data_vector);
};
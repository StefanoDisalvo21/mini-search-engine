#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <filesystem>
#include <cmath>
#include <unordered_set>
#include "document.hpp"
#include "helpers_function.hpp"
using namespace std;

class SearchEngine{
    private:
        unordered_map<string, unordered_map<int,int>> index;
    public:
        const unordered_map<string,unordered_map<int,int>>& get_index() const {return index;};
        void build_index(vector<Document>& data_vector);
        vector<pair<int,double>> search(string& query,vector<Document>& data_vector);
        void evaluate_score(vector<pair<int,double>>&results_vector,vector<Document>&data_vector,vector<string>&query_tokens);
        void display_results(vector<pair<int,double>>& query_results);
};
#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <filesystem>
#include <cmath>
#include <unordered_set>
#include <sstream>
#include <iostream>
#include "document.hpp"
#include "helpers_function.hpp"
using namespace std;

class SearchEngine{
    private:
        unordered_map<string, vector<pair<int,int>>> index;
    public:
        const unordered_map<string,vector<pair<int,int>>>& get_index() const {return index;};
        void build_index(vector<Document>& data_vector);
        vector<pair<int,double>> search(string& query,vector<Document>& data_vector);
        void evaluate_score(vector<pair<int,double>>&results_vector,vector<Document>&data_vector,vector<string>&query_tokens,unordered_set<int>& boolean_filtered_docs);
        void translate_results(vector<pair<string,double>>& query_results);
        void display_results(vector<pair<int,double>>& query_results, vector<Document>&data_vector);
        unordered_set<int> process_boolean_queries(string& query, vector<Document>& data_vector);
        unordered_set<int> index_look_up_function(const string& token);
};
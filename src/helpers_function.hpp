#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include<string>
#include <sstream>
#include <algorithm>
#include "document.hpp"
using namespace std;

namespace helpers{
    void space_trim(icu::UnicodeString& token);
    vector<string> doc_tokenization(icu::UnicodeString& norm_string);
    icu::UnicodeString normalization(string& cont);
    bool is_boolean(vector<string>& tok);
    vector<string> boolean_tokenization(string& query);
    unordered_set<int> set_intersect_function(const unordered_set<int>& res,const unordered_set<int>& operand);
    unordered_set<int> set_union_function(const unordered_set<int>& res, const unordered_set<int>& operand);
};
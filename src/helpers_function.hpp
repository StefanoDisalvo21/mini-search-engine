#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "document.hpp"
using namespace std;

namespace helpers{
    void space_trim(icu::UnicodeString& token);
    vector<string> tokenization(icu::UnicodeString& norm_string);
    icu::UnicodeString normalization(string& cont);
    bool is_boolean_query(vector<string>& query_token);
};
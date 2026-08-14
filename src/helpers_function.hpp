#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
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
};
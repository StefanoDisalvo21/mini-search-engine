#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "document.hpp"
using namespace std;

namespace helpers{
    void space_trim(icu::UnicodeString& token);
    vector<string> doc_tokenization(icu::UnicodeString& norm_string);
    icu::UnicodeString normalization(string& cont);
};
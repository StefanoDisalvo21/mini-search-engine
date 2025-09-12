#include "helpers_function.hpp"
using namespace std;

namespace helpers{
    void space_trim(icu::UnicodeString& token){
        int first=0;
        int last_position = token.length()-1;
        while(u_isWhitespace_77(token.char32At(first))&&first<last_position){
            first++;
        }
        while(u_isWhitespace_77(token.char32At(last_position))&&last_position>first){
            last_position--;
        }
        token = token.tempSubString(first,last_position-first+1);
    }
};
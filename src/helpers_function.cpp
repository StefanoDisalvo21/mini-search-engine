#include "helpers_function.hpp"
using namespace std;

namespace helpers{
    void space_trim(icu::UnicodeString& token){
        int first=0;
        int last_position = token.length()-1;
        //checking if the first char of the string is a space, if so moving the first pos of the string
        while(u_isWhitespace(token.char32At(first))&&first<last_position){
            first++;
        }
        //checking if the last char of the string is a space, if so moving the last pos of the string
        while(u_isWhitespace(token.char32At(last_position))&&last_position>first){
            last_position--;
        }
        //trimming
        token = token.tempSubString(first,last_position-first+1);
    }
    //function to normalize
    icu::UnicodeString normalization(string& doc_content){
        UErrorCode error= U_ZERO_ERROR;
        icu::UnicodeString normalized_string;
        icu::UnicodeString txt_unicode = icu::UnicodeString::fromUTF8(doc_content);
        const icu::Normalizer2* norm = icu::Normalizer2::getNFCInstance(error);
        norm->normalize(txt_unicode,normalized_string,error);
        normalized_string.toLower();
        return normalized_string;
    }

    vector<string> doc_tokenization(icu::UnicodeString& normalized_string){
        vector<string> tokens;
        UErrorCode error= U_ZERO_ERROR;
        icu::Locale loc("en");
        icu::BreakIterator* brk =icu::BreakIterator::createWordInstance(loc,error);
        brk->setText(normalized_string);
        int start=brk->first();
        //looping each token of the document
        while(brk->next()!=icu::BreakIterator::DONE){
            int end_phrase = brk->current();
            int lenght_phrase = end_phrase-start;
            icu::UnicodeString temp_token = normalized_string.tempSubString(start,lenght_phrase);
            //check if the token is a word/number or not
            if(brk->getRuleStatus()==UBRK_WORD_LETTER||brk->getRuleStatus()==UBRK_WORD_NUMBER){
                helpers::space_trim(temp_token);
                string tok;
                temp_token.toUTF8String(tok);
                tokens.push_back(tok);
            }
            start = end_phrase;
        }
        sort(tokens.begin(),tokens.end());
        return tokens;
    }

    vector<string> boolean_tokenization(string& query){
        // Vector of string to save tokens
        vector <string> tokens;
        // stringstream class check1
        stringstream check1(query);
        string word;
        while(getline(check1, word, ' '))
        {
            if(word!=""){
                tokens.push_back(word);
            }
        }
        return tokens;
    }
    
    bool is_boolean(vector<string>& tok){
        for(auto& tokens:tok){
            if(tokens=="AND"||tokens=="NOT"||tokens=="OR"){
                return true;
            }
        }
        return false;
    }

    unordered_set<int> set_intersect_function(const unordered_set<int>& res, const unordered_set<int>& operand){
        //result structure
        unordered_set<int> result_structure;
        if(res.size()<operand.size()){
            for(auto& doc_id:res){
                if(operand.count(doc_id)){
                    result_structure.insert(doc_id);
                }
            }
        }
        else{
            for(auto& doc_id:operand){
                if(res.count(doc_id)){
                    result_structure.insert(doc_id);
                }
            }
        }
        return result_structure;
    }
};
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

    vector<string> tokenization(icu::UnicodeString& normalized_string){
        vector<string> tokens;
        UErrorCode error= U_ZERO_ERROR;
        icu::Locale loc("en");
        icu::BreakIterator* brk =icu::BreakIterator::createWordInstance(loc,error);
        brk->setText(normalized_string);
        int start=brk->first();
        while(brk->next()!=icu::BreakIterator::DONE){
            int end_phrase = brk->current();
            int lenght_phrase = end_phrase-start;
            icu::UnicodeString temp_token = normalized_string.tempSubString(start,lenght_phrase);
            if(brk->getRuleStatus()==UBRK_WORD_LETTER||brk->getRuleStatus()==UBRK_WORD_NUMBER){
                helpers::space_trim(temp_token);
                string tok;
                temp_token.toUTF8String(tok);
                tokens.push_back(tok);
            }
            start = end_phrase;
        }
        return tokens;
    }
};
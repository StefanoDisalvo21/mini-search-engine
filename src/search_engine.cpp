#include "search_engine.hpp"
using namespace std;


void SearchEngine::build_index(vector<Document>& data_vector){
    for(auto& data_docs:data_vector){
        vector<string> tokens = data_docs.get_tokens();
        for(auto& words:tokens){
            index[words][data_docs.get_file_name()]++;
        }
    }
}

vector<pair<string,double>> SearchEngine::search(string& query, vector<Document>&data_vector){
    icu::UnicodeString normalized_string=helpers::normalization(query);
    vector<string> query_tokens = helpers::tokenization(normalized_string);
    unordered_map<string,double> query_index;
    int number_of_documents = data_vector.size();
    double term_frequency=0;
    double inverse_document_frequency=0;
    double tf_idf=0;
    for(auto& tok: query_tokens){
        for(auto& data_tok:data_vector){
            term_frequency=index[tok][data_tok.get_file_name()]/data_tok.get_tokens().size();
            inverse_document_frequency= log10(number_of_documents/index[tok].size());
            tf_idf=term_frequency*inverse_document_frequency;
            query_index[data_tok.get_file_name()]+=tf_idf;
        }
    }
}
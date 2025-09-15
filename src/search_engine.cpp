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
    unordered_map<string,double> query_index_score;
    vector<pair<string,double>> results;
    int number_of_documents = data_vector.size();
    double term_frequency=0;
    double inverse_document_frequency=0;
    double tf_idf=0;
    for(auto& tok: query_tokens){
        for(auto& data_tok:data_vector){
            if(index.find(tok)!=index.end()){
                auto& doc_map = index[tok];
                if(doc_map.find(data_tok.get_file_name())!=doc_map.end()){
                    term_frequency=static_cast<double>(index[tok][data_tok.get_file_name()])/static_cast<double>(data_tok.get_tokens().size());
                    inverse_document_frequency= log10(1+(static_cast<double>(number_of_documents)/static_cast<double>(index[tok].size())));
                    tf_idf=term_frequency*inverse_document_frequency;
                    query_index_score[data_tok.get_file_name()]+=tf_idf;
                }
            }
        }
    }
    for(auto& elements:query_index_score){
        results.push_back({elements.first,elements.second});
    }
    sort(results.begin(),results.end(), [](auto& a, auto& b){return a.second>b.second;});
    return results;
}
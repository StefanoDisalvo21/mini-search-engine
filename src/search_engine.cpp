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
    vector<pair<string,double>> results;
    //check if the query is boolean
    if(helpers::is_boolean_query(query_tokens)==true){
        vector<Document>filtered_document;
        //check tokens and skip boolean words
        for(auto& tok:query_tokens){
            if(tok=="and"||tok=="not"||tok=="or"){
                continue;
            }
            else{

            }
        }
    }
    else{
        evaluate_score(results, data_vector,query_tokens);
    }
    return results;
}

void SearchEngine::evaluate_score(vector<pair<string,double>>&results_vector,vector<Document>&data_vector,vector<string>&query_tokens){
    unordered_map<string,double> query_index_score;
    int number_of_documents = data_vector.size();
    double term_frequency=0;
    double inverse_document_frequency=0;
    double tf_idf=0;
    //searching for each token in each doc
    for(auto& tok: query_tokens){
        for(auto& data_tok:data_vector){
            //checking if the token is in the index
            if(index.find(tok)!=index.end()){
                auto& doc_map = index[tok];
                //check if the token is in the docs
                if(doc_map.find(data_tok.get_file_name())!=doc_map.end()){
                    //score evaluation
                    term_frequency=static_cast<double>(index[tok][data_tok.get_file_name()])/static_cast<double>(data_tok.get_tokens().size());
                    inverse_document_frequency= log10(1+(static_cast<double>(number_of_documents)/static_cast<double>(index[tok].size())));
                    tf_idf=term_frequency*inverse_document_frequency;
                    query_index_score[data_tok.get_file_name()]+=tf_idf;
                }
            }
        }
    }
    for(auto& elements:query_index_score){
        results_vector.push_back({elements.first,elements.second});
    }
    sort(results_vector.begin(),results_vector.end(), [](auto& a, auto& b){return a.second>b.second;});
}
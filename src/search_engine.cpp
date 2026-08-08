#include "search_engine.hpp"
using namespace std;

//index building
void SearchEngine::build_index(vector<Document>& data_vector){
    for(auto& data_docs:data_vector){
        vector<string> tokens = data_docs.get_tokens();
        for(auto& words:tokens){
            index[words][data_docs.get_doc_id()]++;
        }
    }
}

//processing query
vector<pair<int,double>> SearchEngine::search(string& query, vector<Document>&data_vector){
    icu::UnicodeString normalized_string=helpers::normalization(query);
    vector<string> query_tokens = helpers::doc_tokenization(normalized_string);
    vector<pair<int,double>> results;
    evaluate_score(results, data_vector,query_tokens);
    return results;
}

//evaluating score
void SearchEngine::evaluate_score(vector<pair<int,double>>&results_vector,vector<Document>&data_vector,vector<string>&query_tokens){
    unordered_map<int,double> query_index_score;
    int number_of_documents = data_vector.size();
    double term_frequency=0;
    double inverse_document_frequency=0;
    double tf_idf=0;
    //searching for each token 
    for(auto& tok: query_tokens){ 
        //find tiken 
        auto doc_map_iterator = index.find(tok); 
        //going to the next loop if not found 
        if(doc_map_iterator == index.end()) continue; 
        //getting the value of the first unordered_map (another unorthered map)
        auto& doc_map = doc_map_iterator->second;
        inverse_document_frequency = log10(1+(static_cast<double>(number_of_documents)/static_cast<double>(doc_map.size())));
        //checking each document 
        for(auto& x : doc_map){
            int doc_id = x.first; 
            int term_count = x.second;
            term_frequency = static_cast<double>(term_count)/static_cast<double>(data_vector[doc_id].get_tokens().size());
            tf_idf = term_frequency*inverse_document_frequency;
            query_index_score[doc_id]+=tf_idf;
        }
    }
    for(auto& elements:query_index_score){
        results_vector.push_back({elements.first,elements.second});
    }
    sort(results_vector.begin(),results_vector.end(), [](auto& a, auto& b){return a.second>b.second;});
}

//function to translate from ids to filename 

//displaying results
void SearchEngine::display_results(vector<pair<int,double>>& query_results, vector<Document>&data_vector){
    if(query_results.size()==0){
        cout<<"\nNo corrispondece in the documents\n";
    }
    else{
        int i=1;
        for(auto& x:query_results){
            cout<<i<<". - "<<data_vector[x.first].get_file_name()<<" - Score: "<<x.second<<endl;
            ++i;
        }
    }
}
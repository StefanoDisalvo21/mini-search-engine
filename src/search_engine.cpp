#include "search_engine.hpp"
using namespace std;

//index building
void SearchEngine::build_index(vector<Document>& data_vector){
    for(auto& data_docs:data_vector){
        vector<string> tokens = data_docs.get_tokens();
        //local structure in order to count the terms to pushback
        unordered_map<string,int> term_count;
        for(auto& words:tokens){
            term_count[words]++;
        }
        //updating index
        for(auto& elements:term_count){
            index[elements.first].push_back({data_docs.get_doc_id(),elements.second});
        }

    }//end outer for
}

//processing query
vector<pair<int,double>> SearchEngine::search(string& query, vector<Document>&data_vector){
    //boolean filter
    unordered_set<int> boolean_processed_data=process_boolean_queries(query,data_vector);
    icu::UnicodeString normalized_string=helpers::normalization(query);
    vector<string> query_tokens = helpers::doc_tokenization(normalized_string);
    vector<pair<int,double>> results;
    evaluate_score(results, data_vector,query_tokens,boolean_processed_data);
    return results;
}

//evaluating score
void SearchEngine::evaluate_score(vector<pair<int,double>>&results_vector,vector<Document>&data_vector,vector<string>&query_tokens,unordered_set<int>& boolean_filtered_docs){
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
            if(boolean_filtered_docs.count(x.first)){
                //doc evaluation
                int doc_id = x.first; 
                int term_count = x.second;
                term_frequency = static_cast<double>(term_count)/static_cast<double>(data_vector[doc_id].get_tokens().size());
                tf_idf = term_frequency*inverse_document_frequency;
                query_index_score[doc_id]+=tf_idf;
            }
        }
    }
    for(auto& elements:query_index_score){
        results_vector.push_back({elements.first,elements.second});
    }
    //lamba function that orders the results in increasing order regarding points scored
    sort(results_vector.begin(),results_vector.end(), [](auto& a, auto& b){return a.second>b.second;});
}


//index lookup function
unordered_set<int> SearchEngine::index_look_up_function(const string& token){
    unordered_set<int> document_finds;
    //find token and check if not in the document
    auto doc_map_iterator = index.find(token);
    if(doc_map_iterator==index.end()){

    }
    else{
        auto&  doc_map = doc_map_iterator->second;
        for(auto& x:doc_map){
            document_finds.insert(x.first);
        }   
    }
    return document_finds;
}

//end index look up function

//boolean query processor
unordered_set<int> SearchEngine::process_boolean_queries(string& query, vector<Document>& data_vector){
    vector<string> tokens = helpers::boolean_tokenization(query);
    unordered_set<int> candidate_docs_id;
    icu::UnicodeString normalization_helper;
    if(helpers::is_boolean(tokens)){
        //while to perform the algorithm
        int iterator = 0;
        //string for the boolean operator
        string boolean_operator = "none";
        while(iterator<tokens.size()){
            unordered_set<int> operand;
            //set for the operand
            if(tokens[iterator]=="NOT"){
                ++iterator;
                //getting normalized tokens
                normalization_helper=helpers::normalization(tokens[iterator]);
                string token;
                normalization_helper.toUTF8String(token);
                unordered_set<int> excluded_docs = index_look_up_function(token);
                //getting the complement posting list
                for(int i=0;i<data_vector.size();++i){
                    if(excluded_docs.count(i)){
                        continue;
                    }
                    else{
                        operand.insert(i);
                    }
                }
                ++iterator;
            }
            else {
                //getting normalized tokens
                normalization_helper=helpers::normalization(tokens[iterator]);
                string token;
                normalization_helper.toUTF8String(token);
                //getting the posting list
                operand = index_look_up_function(token);
                ++iterator;
            }
            if(candidate_docs_id.empty()){
                candidate_docs_id = operand;
            }
            else{
                if(boolean_operator=="AND"){
                    candidate_docs_id = helpers::set_intersect_function(candidate_docs_id,operand);
                }     
                else if(boolean_operator=="OR"){
                    candidate_docs_id = helpers::set_union_function(candidate_docs_id,operand);
                }      
            }
            //getting operator
            if(iterator<tokens.size()){
                boolean_operator = tokens[iterator];
                ++iterator;
            }
        }
    }
    else{
        for(int i=0;i<data_vector.size();++i){
            candidate_docs_id.insert(i);
        }
    }
    return candidate_docs_id;
}// end boolean processor

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
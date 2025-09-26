#include "document.hpp"
using namespace std;

namespace fs = std::filesystem;

//load data
vector<Document> DomLoad::load_data(const string& data_path){
    vector<Document> document_data;

    //path existence check
    if(!fs::exists(data_path)){
        throw invalid_argument("The path does not exist");
    }
    if(!fs::is_directory(data_path)){
        throw invalid_argument("Not a directory");
    }

    //reading each document
    for(auto& entry:fs::directory_iterator(data_path)){
        string cont,word;
        if(fs::path(entry).extension().string()==".txt"){
            ifstream ist{entry.path()};
            if(!ist){
                throw invalid_argument("Cannot open the file");
            }
            while(getline(ist,word)){
                cont += word;
            }
            Document doc(entry.path().filename().string(),cont);
            icu::UnicodeString norm_string = helpers::normalization(cont);
            doc.set_normalized_string(norm_string);
            vector<string> tokens= helpers::tokenization(norm_string);
            doc.set_tokens(tokens);
            document_data.push_back(doc);
        }
    }
    return document_data;
}
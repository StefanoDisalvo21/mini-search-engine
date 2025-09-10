#include "document.hpp"
#include "helpers_function.hpp"
using namespace std;

namespace fs = std::filesystem;

//loading data from the folder
vector<Document> DomLoad::load_data(const string& data_path){
    vector<Document> ds;
    if(!fs::exists(data_path)){
        throw invalid_argument("The path does not exist");
    }
    if(!fs::is_directory(data_path)){
        throw invalid_argument("Not a directory");
    }
    for(auto& entry:fs::directory_iterator(data_path)){
        string cont,word;
        if(fs::path(entry).extension().string()==".txt"){
            ifstream ist{entry.path()};
            if(!ist){
                throw invalid_argument("Cannot open the file");
            }
            while(getline(ist,word)){
                cont+=word;
            }
            Document doc(entry.path().filename().string(),cont);
            doc.normalization();
            ds.push_back(doc);
         
        }
    }
    return ds;
}//end loading vectors

//function to normalize
void Document::normalization(){
    UErrorCode error= U_ZERO_ERROR;
    icu::UnicodeString txt_unicode = icu::UnicodeString::fromUTF8(content);
    const icu::Normalizer2* norm = icu::Normalizer2::getNFCInstance(error);
    norm->normalize(txt_unicode,normalized_string,error);
    normalized_string.toLower();
}

void Document::tokenization(){
    
}
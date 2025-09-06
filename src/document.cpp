#include "document.hpp"
#include "helpers_function.hpp"
using namespace std;

namespace fs = std::filesystem;

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
            ds.push_back(doc);
        }
    }
    return ds;
}


#include<iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem>
#include "document.hpp"
#include "search_engine.hpp"
using namespace std;

namespace fs= filesystem;
int main(){
    DomLoad loader;
    SearchEngine working_engine;
    int choice;
    const string data_information = "insert-path"; //the path need to be inserted manually with an absolute path
    vector<Document> data_vector=loader.load_data(data_information);
    working_engine.build_index(data_vector);
    do{
        cout<<"\n\t--Mini Search Engine--\t\n";
        cout<<"1)Search\n2)Quit\nChoose: ";
        cin>>choice;
        if(cin.fail()) {
            cin.clear();               
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(choice==1){
            string query;
            cout<<"\nSearch: ";
            getline(cin,query);
            vector<pair<string,double>> query_results=working_engine.search(query,data_vector);
            int i=1;
            for(auto& x:query_results){
                cout<<i<<". - "<<x.first<<" - Score: "<<x.second<<endl;
                ++i;
            }
        }
        else if(choice==2){
            cout<<"\nThanks, see you next time"<<endl;
        }
        else{
            cout<<"\nNot a valid choice";
        }
    }while(choice!=2);
    return 0;
}
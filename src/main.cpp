#include<iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem>
#include "document.hpp"
#include "search_engine.hpp"
#include "command_line_interface.hpp"
using namespace std;

namespace fs= filesystem;
int main(int argc, char **argv){
    //object declaration
    DomLoad loader;
    SearchEngine working_engine;
    CommandLineInterface cli;

    //variables declaration
    vector<Document> data_vector;
    string query;
    string data_information;

    //header of the program "UI"
    cout<<"\n\t--Mini Search Engine--\t\n";

    //calling the cli interface
    int cli_call_result = cli.cli_call(argc,argv);
    if(cli_call_result!=0){
        return cli_call_result;
    }//end check cli control;

    //getting the data path
    data_information=cli.get_path();

    //loading data
    try{
        data_vector=loader.load_data(data_information);
        working_engine.build_index(data_vector);
    }
    catch(const exception& e){
        cerr<<e.what()<<endl;
        return 1;
    }
    //end loading data

    cout<<"\nType ':quit' in order to exit\n";
    do{
        cout<<"\nSearch: ";
        getline(cin,query);
        if(query==":quit"){
            cout<<"\nThanks, see you next time"<<endl;
        }
        else{
            vector<pair<int,double>> query_results=working_engine.search(query,data_vector);
            working_engine.display_results(query_results,data_vector);
        }

    }while(query!=":quit");
    return 0;
}
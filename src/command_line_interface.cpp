#include "command_line_interface.hpp"
#include <CLI11.hpp>

//call in order to return to main
int CommandLineInterface::cli_call(int argc, char **argv){
    CLI::App app;
    string path_option;

    //adding option (can be expanded)
    app.add_option("--path",path_option,"The command is mandatory for starting the program,\n it requires the folder path in which your\n .txt docs are")->mandatory();


    //try catch block to handle errors and --help call
    try{
        //parsing and assigning the path
       app.parse(argc,argv);
        path = path_option;
    }
    catch(CLI::ParseError& e){
        app.exit(e);
        return -1;
    }
    return 0;
}
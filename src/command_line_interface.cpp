#include "command_line_interface.hpp"
#include <CLI11.hpp>

//call in order to return to main
int CommandLineInterface::cli_call(int argc, char **argv){
    CLI::App app;
    string path_option;

    //adding option (can be expanded)
    app.add_option("--path",path_option,"The command is mandatory for starting the program,\n it requires the folder path in which your\n .txt docs are")->mandatory();

    //parsing and assigning the path
    CLI11_PARSE(app,argc,argv);
    path = path_option;

    return 0;
}
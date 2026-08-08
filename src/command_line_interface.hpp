#include <iostream>

using namespace std;


class CommandLineInterface{
    private:
        string path;
    public:
        const string get_path(){return path;}
        int cli_call(int argc, char **argv);

};
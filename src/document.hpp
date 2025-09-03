#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <filesystem>
using namespace std;

class Document{
  private:
    string file_name;
    string content;
    vector<string> tokens;
  public:
    Document(const string& fname, const string& text)
    :file_name(fname),content(text){};
    void tokenize();
         
};



class DomLoad{
  public:
    static vector<Document> read_docs(const string& path);
    void end();
};


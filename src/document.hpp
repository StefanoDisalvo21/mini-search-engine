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
    const string get_file_name() {return file_name;}
    const string get_file_content() {return content;};
    bool operator==(const Document &doc2) const{
      return file_name==doc2.file_name&&
      content==doc2.content;
    }
    bool operator<(const Document& doc2) const {
      return file_name < doc2.file_name;
    }
         
};



class DomLoad{
  public:
    vector<Document> read_docs(const string& data_path);
};


#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <filesystem>
#include <unicode/unistr.h>
#include <unicode/normalizer2.h>
#include <unicode/brkiter.h>
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
    void normalization();
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
    vector<Document> load_data(const string& data_path);
};


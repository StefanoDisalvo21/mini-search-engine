#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <filesystem>
#include <unicode/unistr.h>
#include <unicode/normalizer2.h>
#include <unicode/brkiter.h>
#include "helpers_function.hpp"
using namespace std;

class Document{
  private:
    string file_name;
    string content;
    int document_id=0;
    icu::UnicodeString normalized_string;
    vector<string> tokens;
  public:
    Document(const string& fname, const string& text)
    :file_name(fname),content(text){}
    const string get_file_name() {return file_name;}
    const string get_file_content() {return content;}
    const vector<string>& get_tokens() const {return tokens;}
    const int get_doc_id() const {return document_id;}
    void set_tokens(vector<string>& tok) {tokens=tok;}
    void set_document_id(int& doc_id){document_id=doc_id;}
    void set_normalized_string(icu::UnicodeString & norm_string){normalized_string=norm_string;}
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


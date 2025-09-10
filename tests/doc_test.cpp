#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "document.hpp"
using namespace std;

namespace test_strings{
    string content4="\"Artificial Intelligence - arXiv\" and \"Journal of Artificial Intelligence Research\" "
    "are excellent resources for academic research papers. ArXiv is a repository for pre-print "
    "papers in various scientific fields, including AI. The Journal of Artificial Intelligence "
    "Research (JAIR) publishes peer-reviewed articles on all areas of AI.\"AI researchers lured "
    "with high salaries are leaving Meta, quoting Mark Zuckerberg’s own advice on their way out\" "
    "from The Economic Times. This article provides insight into the competitive landscape of AI "
    "research, discussing the \"talent war\" between major tech companies and what motivates top researchers.";;
    string content3="\"AI Apocalypse? Why language surrounding tech is sounding increasingly religious\" from the Associated Press. "
"This article discusses the growing debate around the potential of AI to bring about a technological \"apocalypse\" or a new age of human evolution. "
"It highlights different perspectives from researchers and tech CEOs.\""
"Are AI bots now ‘digital beings’ with rights? New group fuels global debate on consciousness and human morality\" from The Economic Times. "
"This article delves into the complex and emerging debate over whether AI systems could one day be considered \"conscious\" and deserve rights. "
"It mentions a group advocating for \"AI rights\" and counter-arguments from tech leaders.";
    string content2="\"AI boosts career, does not replace it: Real work lessons from engineer who uses AI as second brain\" from The Economic Times. "
"This piece focuses on how AI is being used as a tool to enhance human productivity rather than replace jobs. "
"It includes an example of a software engineer who uses AI to accelerate projects and improve his workflow.\""
"AI bringing dinosaurs to life: How scientists are turning Jurassic Park into reality\" from The Times of India. "
"This article explores how AI is being used in paleontology to reconstruct fossils, generate realistic visuals of dinosaurs, "
"and even hypothesize genetic sequences.";
    string content1="\"The birth of Artificial Intelligence (AI) research\" by Lawrence Livermore National Laboratory. "
"This article provides a timeline of key events, starting with Alan Turing's 1950 paper \"Computing Machinery and Intelligence\" "
"and the 1956 Dartmouth workshop where the term \"artificial intelligence\" was coined. "
"It also discusses the early boom and subsequent \"AI winters\" in funding and interest.\""
"The History of AI: A Timeline of Artificial Intelligence\" from Coursera. "
"This article offers a detailed timeline, including historical and fictional precedents for AI, "
"such as Jonathan Swift's \"Gulliver's Travels,\" and key early developments like the creation of the first chatbot, ELIZA, in 1966.";
}
TEST(Load_Test,first_test){
    DomLoad dom_obj;
    string ds="../../random_name";
    EXPECT_THROW(dom_obj.load_data(ds),invalid_argument);

}
TEST(Load_Test,second_test){
    DomLoad dom_obj;
    string ds="../../README.md";
    EXPECT_THROW(dom_obj.load_data(ds),invalid_argument);

}

TEST(Load_Test,third_test){
    DomLoad dom_obj;
    string ds="../../data";
    vector<Document> docs = dom_obj.load_data(ds);
    sort(docs.begin(),docs.end());
    vector<string> names;
    vector<string> expected_names={"art1.txt","art2.txt","art3.txt","art4.txt"};
    for(int i=0;i<docs.size();i++){
        names.push_back(docs[i].get_file_name());
    }
    EXPECT_EQ(names,expected_names);
}
TEST(Load_Test,fourth_test){
    DomLoad dom_obj;
    Document doc("art1.txt",test_strings::content1);
    Document doc1("art2.txt",test_strings::content2);
    Document doc2("art3.txt",test_strings::content3);
    Document doc3("art4.txt",test_strings::content4);
    string ds="../../data";
    vector<Document> vt = dom_obj.load_data(ds);
    vector<Document> expected_vector={doc,doc1,doc2,doc3};
    sort(vt.begin(),vt.end());
    sort(expected_vector.begin(),expected_vector.end());
    for(size_t i=0;i<vt.size();++i){
      EXPECT_EQ(vt[i].get_file_content(), expected_vector[i].get_file_content());
      EXPECT_EQ(vt[i].get_file_name(), expected_vector[i].get_file_name());
    }


}
TEST(Load_Test,fifth_test){
    DomLoad dom_obj;
    string ds="../../data";
    vector<Document> vt = dom_obj.load_data(ds);
    EXPECT_EQ(vt[0].get_file_content(),test_strings::content4);
    EXPECT_EQ(vt[1].get_file_content(),test_strings::content3);
    EXPECT_EQ(vt[2].get_file_content(),test_strings::content2);
    EXPECT_EQ(vt[3].get_file_content(),test_strings::content1);
}
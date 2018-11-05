#include "Include/Loader.hpp"
#include "Include/Word.hpp" // 用于提供friend 信息
#include "Include/User.hpp"
#include <fstream>

using json = nlohmann::json;
using namespace std;


void to_json(json& j, const Word& p){
    j =  json{
        {"index", p.index},
        {"id", p.id},
        {"word", p.word},
        {"query_time_point", p.query_time_point}, {"killed", p.killed},
    };
}

void from_json(const json& j, Word& p){
    j.at("index").get_to(p.index);
    j.at("id").get_to(p.id);
    j.at("word").get_to(p.word);
    j.at("query_time_point").get_to(p.query_time_point);
    j.at("killed").get_to(p.killed);
}

void to_json(json& j, const User& u){
    j =  json{
        {"show_limitation", u.show_limitation},
    };
}

void from_json(const json& j, User& p){
    j.at("show_limitation").get_to(p.show_limitation);
}

// 注意：这里的~不可以使用
const std::string Loader::config_dir = "/home/shen/Core/sl/Test/";

void Loader::store(){
    std::ofstream outfile(config_dir + "words.json");
    for(Word & w : words){
        json j = w;
        outfile << j.dump() << endl;
    }
    outfile.close();

    outfile = std::ofstream(config_dir + "user.json");
    json j = user;
    outfile << j.dump() << endl;
    outfile.close();
}


void Loader::load(){
    std::ifstream infile(config_dir + "words.json");
    string line;
    while (std::getline(infile, line)){
        json j = json::parse(line);
        Word w = j;
        words.push_back(w);
    }

    // Parse a file
}






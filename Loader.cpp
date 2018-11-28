#include <Loader.hpp>
#include <Word.hpp> // 用于提供friend 信息
#include <User.hpp>
#include <Strategy.hpp>

#include <iomanip>
#include <fstream>
#include <set>
#include <string>


using json = nlohmann::json;
using namespace std;

// 注意：这里的~不可以使用
const std::string Loader::config_dir = "/home/shen/Core/sl/src/";


void to_json(json& j, const Word& p){
    j =  json{
        {"word", p.word},
        {"index", p.index},
        {"id", p.id},
        {"killed", p.killed},
        {"query_time_point", p.query_time_point},
    };
}

void from_json(const json& j, Word& p){
    j.at("word").get_to(p.word);
    j.at("index").get_to(p.index);
    j.at("id").get_to(p.id);
    j.at("killed").get_to(p.killed);
    j.at("query_time_point").get_to(p.query_time_point);
}

void to_json(json& j, const User& u){
    j =  json{
        {"show_limitation", u.show_limitation},
        {"show_word_id", u.show_word_id},
        {"random_show_limitation", u.random_show_limitation},
    };
}

void from_json(const json& j, User& p){
    j.at("show_limitation").get_to(p.show_limitation);
    j.at("show_word_id").get_to(p.show_word_id);
    j.at("random_show_limitation").get_to(p.random_show_limitation);
}


void Loader::store(){
    std::ofstream outfile(config_dir + "words.json");
    for(Word & w : words){
        json j = w;
        outfile << j.dump() << endl;
    }
    outfile.close();

    outfile = std::ofstream(config_dir + "user.json");
    json j = user;
    outfile << std::setw(4) << j << std::endl;
    outfile.close();
}

void Loader::set_default_config(){
    User user;
    ofstream outfile = std::ofstream(config_dir + "user.json");
    json j = user;
    outfile << std::setw(4) << j << std::endl;
    outfile.close();
}



void Loader::load(){
    std::ifstream infile(config_dir + "words.json");
    string line;
    // TODO: should not restricted to a line
    while (std::getline(infile, line)){
        json j = json::parse(line);
        Word w = j;
        words.push_back(w);
    }
    infile.close();
}

void Loader::load_config(){
    std::ifstream infile = std::ifstream(config_dir + "user.json");
    json j;
    infile >> j;
    user = j;
    infile.close();
}

void Loader::add_one_word(const std::string & w){
    // get unused id
    int word_num = words.size();
    vector<bool> id(word_num, false);
    for (int i = 0; i < word_num ; i++) {
        id[words[i].get_id()] = true;
        // check if alread exits
        if(w == words[i].get_word()){
            cerr << "This word has already been in the database" << endl;
            Strategy::check_word(words[i], true);
            return;
        }
    }

    int i;
    for (i = 0; i < word_num; i++) {
        if(!id[i]){
            break;
        }
    }

    // add word
    words.emplace_back(w, i);
}

void Loader::add_file(const std::string & path){
    ifstream f(path);
    if(!f.good()){
        fprintf(stderr, "%s can't be opened !\n", path.c_str());
        exit(0);
    }
    fprintf(stderr, "Open %s\n", path.c_str());

    // get a bunch of id just by appending
    int max_id = 0;
    for(auto & w : words){
        if(max_id < w.get_id()){
            max_id = w.get_id();
        }
    }

    // word and location
    map<string,int> sorted_words;
    int loc = 0;
    for(auto w : words){
        sorted_words.insert(make_pair(w.get_word(), loc ++));
    }


    std::ifstream infile(path);
    string line;
    while (std::getline(infile, line)){
        auto f = sorted_words.find(line);
        if(f == sorted_words.end()){
            words.emplace_back(line, ++max_id);
            sorted_words.insert(make_pair(line, loc++));
        }else{
            Strategy::check_word(words[f->second], true);
        }
    }
}


void Loader::check_word(int id, check_t type){
    // find the word
    int word_num = words.size();
    int i;
    for (i = 0; i < word_num ; i++) {
        if(words[i].get_id() == id){
            cout << "id check : " << words[i].get_word() << endl;
            break;
        }
    }
    
    if(i == word_num){
        fprintf(stderr, "Error: can not find word with id");
        exit(0);
    }
    handle_word(words[i], type);
}

void Loader::check_word(std::string & word, check_t type){
    int word_num = words.size();
    int i;
    for (i = 0; i < word_num ; i++) {
        if(words[i].get_word() == word){
            cout << "word check : " << word << endl;
            break;
        }
    }
    
    if(i == word_num){
        fprintf(stderr, "Check you spell");
        exit(0);
    }
    handle_word(words[i], type);
}

void Loader::handle_word(Word & word, check_t type){
    switch(type){
        case REM:
            Strategy::check_word(word, false);
            break;
        case FORGET:
            Strategy::check_word(word, true);
            break;
        case SHUTDOWN:
           word.kill();
            break;
        case REMOVE:
            int i;
            for (i = 0; i < words.size(); i++) {
                if(words[i].get_id() == word.get_id()) break;
            }
            words.erase(words.begin() + i, words.begin() + i + 1);
            break;
    }
}


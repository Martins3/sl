#ifndef WORD_HPP
#define WORD_HPP

#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "json.hpp"
#include <ctime>


class Word{
    int id;
    // how many times forget it !
    int index;
    std::string word;
    // time point to query the words
    std::vector<std::pair<time_t, bool> > query_time_point;
    // whether the word is mask as impressive
    bool killed;
public:
    friend class Strategy;
    friend void to_json(nlohmann::json& j, const Word& p);
    friend void from_json(const nlohmann::json& j, Word& p);
    friend struct SortById;
    friend struct SortByIndex;

    void print_header(){
        std::cout << "id:    " << "word:    " << std::endl;
    }

    void print_word(){
        std::cout << id << "\t" << word << std::endl;
    }



    Word(std::string w, int id);
    Word() = default; // for json
    void kill();
    // remove from database
    void remove();
    // user check this word
    void check(bool forget = true);
};

struct SortById{
    inline bool operator()(Word a, Word b){
        return a.id > b.id;
    }
};

struct SortByIndex{
    inline bool operator()(Word a, Word b){
        return a.index > b.index;
    }
};
#endif

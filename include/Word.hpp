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
    // config
    static const int INDEX_BASE;

    int id;
    int index;
    std::string word;
    int flag;
    std::vector<std::pair<time_t, bool> > query_time_point;
public:
    friend class Strategy;
    friend void to_json(nlohmann::json& j, const Word& p);
    friend void from_json(const nlohmann::json& j, Word& p);
    friend struct SortById;
    friend struct SortByIndex;
    friend struct SortByDic;

    int get_id(){
        return id;
    }

    std::string get_word(){
        return word;
    }

    Word(std::string w, int id);
    Word() = default;
};

struct SortById{
    inline bool operator()(const Word & a, const Word & b){
        return a.id > b.id;
    }
};

struct SortByDic{
    inline bool operator()(const Word & a, const Word & b){
        return a.word > b.word;
    }
};

struct SortByIndex{
    inline bool operator()(const Word & a, const Word & b){
        return a.index > b.index;
    }
};

#endif

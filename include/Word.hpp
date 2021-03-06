#ifndef WORD_HPP
#define WORD_HPP

#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "json.hpp"
#include <ctime>
#include <algorithm>


class Word{
    std::string word;
    int id;
    int index;
    // bool killed;
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

    void set_index(int index){
        this->index = index;
    }
    
    std::vector<std::pair<time_t, bool> > & get_record(){
        return query_time_point;
    }

    bool get_flag(int i){
        return flag &(1 << i);
    }

    void set_flag(int i){
        flag |= (1 << i);
    }

    void clear_flag(int i){
      flag &= ~(1 <<i);
    }

    std::string get_word(){
        return word;
    }

    void check(bool forget){
        query_time_point.push_back(std::make_pair(time(nullptr), forget));
    }

    Word(std::string w, int id): word(w){
        query_time_point.push_back(std::make_pair(time(nullptr), true));
    };
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

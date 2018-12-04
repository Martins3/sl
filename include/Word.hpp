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
    // config
    static const int INDEX_BASE;

    int id;
    int index;
    std::string word;
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
        flag = flag | (1 << i);
    }

    void clear_flag(int i){
        // TODO: we need more effiency algorithm
    }

    std::string get_word(){
        return word;
    }

    void check(bool forget){
        query_time_point.push_back(std::make_pair(time(nullptr), false));
    }

    Word(std::string w, int id):id(id), word(w){};
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

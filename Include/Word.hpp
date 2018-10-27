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
    // how many times forget it !
    int id;
    int index;
    std::string word;
    // time point to query the words
    std::vector<std::pair<time_t, bool> > query_time_point;
    // whether the word is mask as impressive
    bool killed;
public:
    friend void to_json(nlohmann::json& j, const Word& p);
    friend void from_json(const nlohmann::json& j, Word& p);

    Word(std::string w, int id);
    Word() = default; // for json
    void kill();
    // remove from database
    void remove();
    // user check this word
    void check(bool forget = true);
};


#endif

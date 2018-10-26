#ifndef WORD_HPP
#define WORD_HPP

#include <chrono>
#include <string>
#include <vector>


class Word{
    // how many times forget it !
    int forget_counter;
    std::string word;
    // time point to query the words
    std::vector<std::chrono::time_point<std::chrono::system_clock> > query_time_point;
    // whether the word is mask as impressive
    bool killed;
private:



public:
    Word(std::string w);
    void kill();
    // remove from database
    //
    void remove();
    // user check this word
    void check(bool forget = false);
};


#endif

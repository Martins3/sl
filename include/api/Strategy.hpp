#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <Word.hpp>
#include <User.hpp>
#include <ctime>

class Strategy{
public:
    static void sort(std::vector<Word> & w, int count);
    static void interactive();
};

#endif

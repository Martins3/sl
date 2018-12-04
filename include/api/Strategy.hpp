#ifndef STRATEGY_HPP
#define STRATEGY_HPP



/**
 * Strategy constains to function:
 * 1. how to sort words
 * 2. what to do when check one word
 *
 * All the methods are just static methods
 */

#include <Word.hpp>
#include <User.hpp>
#include <ctime>

class Strategy{
public:
    static void sort(std::vector<Word> & w, int count);
};


#endif

#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "Word.hpp"
#include "User.hpp"


/**
 * Strategy constains to function:
 * 1. how to sort words
 * 2. what to do when check one word
 *
 * All the methods are just static methods
 */
class Strategy{
public:
    static void Ebbinghaus(std::vector<Word> & words);
    static void check_word(Word & w, bool forget);
};
#endif

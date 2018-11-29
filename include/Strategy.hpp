#ifndef STRATEGY_HPP
#define STRATEGY_HPP



/**
 * Strategy constains to function:
 * 1. how to sort words
 * 2. what to do when check one word
 *
 * All the methods are just static methods
 */

#include "Word.hpp"
#include "User.hpp"
#include <ctime>

// should make it singleton
// totally virtual
class Strategy{
public:
    static void Ebbinghaus(std::vector<Word> & words);
    static void check_word(Word & w, bool forget);
};

struct SortByIndex{
    inline bool operator()(const Word & a, const Word & b){
        if(a.killed && !b.killed){
            return false;
        }

        if(!a.killed && b.killed){
            return true;
        }

        return a.index  > b.index;
    }
};
#endif

#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "Word.hpp"
#include "User.hpp"


/**
 * Strategy constains to function:
 * 1. how to sort words
 * 2. what to do when check one word
 */
class Strategy{
    User config;
public:
    void Ebbinghaus(std::vector<Word> & words);
    void check(Word & w, bool forget = false);

    static Strategy& getInstance(){
        static Strategy    instance;
        return instance;
    }
    Strategy(Strategy const&)       = delete;
    void operator=(Strategy const&)  = delete;

private:
    Strategy() = default;
};
#endif

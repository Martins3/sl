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
    static int get_index(std::vector<std::pair<time_t, bool> > query_time_point){
        return 0;
    }
};


#endif

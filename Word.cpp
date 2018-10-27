#include "Include/Word.hpp"
using namespace std;

Word::Word(std::string w, int id):
    id(id), index(1000), word(w), killed(false){}

void Word::check(bool forget){
    // Add now
    query_time_point.push_back(make_pair(time(nullptr), forget));
}


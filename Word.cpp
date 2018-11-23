#include <Word.hpp>
using namespace std;

const int Word::INDEX_BASE = 1000;

Word::Word(std::string w, int id):
    id(id), index(Word::INDEX_BASE), word(w), killed(false){}

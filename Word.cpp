#include <Word.hpp>
using namespace std;

Word::Word(std::string w, int id):
    id(id), index(1000), word(w), killed(false){}

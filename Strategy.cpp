#include <Strategy.hpp>

using namespace std;


void Strategy::check_word(Word & w, bool forget){
    // TODO: we will do it later
    // w.query_time_point.push_back(make_pair(time(nullptr), forget));
    if(forget){
        w.add_index(100);
    }else{
        w.add_index(-100);
    }
}
  
void Strategy::Ebbinghaus(std::vector<Word> & words){
    sort(words.begin(), words.end(), SortByIndex());
}


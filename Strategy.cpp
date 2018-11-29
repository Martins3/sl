#include <Strategy.hpp>

using namespace std;


void Strategy::check_word(Word & w, bool forget){
    w.query_time_point.push_back(make_pair(time(nullptr), forget));
}
  
void Strategy::Ebbinghaus(std::vector<Word> & words){
    sort(words.begin(), words.end(), SortByIndex());
}


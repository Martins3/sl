#include <Strategy.hpp>

using namespace std;


void Strategy::check_word(Word & w, bool forget){
    // TODO: we will do it later
    // w.query_time_point.push_back(make_pair(time(nullptr), forget));
    
    if(forget){
        w.query_time_point.clear();
        w.add_index(100);
    }else{
        // TODO: more complex startegy will implement later
        // w.query_time_point.clear();
        // w.query_time_point.push_back(make_pair(time(nullptr), true));
        auto & ts = w.query_time_point;
        if(w.query_time_point.empty()){
            w.add_index(-100);
            ts.push_back(make_pair(time(nullptr), true));
        }else{
            time_t hours = (time(nullptr) - ts.back().first) / 3600;
            // TODO: Numbers maybe overflow, shouldn't be a problem not
            int s = hours << ts.size();
            w.add_index(-s);
            ts.push_back(make_pair(time(nullptr), true));
        }
    }
}
  
void Strategy::Ebbinghaus(std::vector<Word> & words){
    sort(words.begin(), words.end(), SortByIndex());
}


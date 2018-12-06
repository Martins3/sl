#include<api/Strategy.hpp>
#include<Word.hpp>
#include<algorithm>
#include<climits>

using namespace std;

inline int get_minute(long now, long time){
    return (now - time) / (60);
}

inline int get_hour(long now, long time){
    return (now - time) / (3600);
}

inline int get_day(long now, long time){
    return (now - time) / (86400);
}

void Strategy::sort(std::vector<Word> & words, int count){
    long now = time(nullptr);
    count = min((int)words.size(), count);

    
    for(auto & w : words){
        auto q = w.get_record();
        if(q.size() == 1){
            // recently added
            w.set_index(INT_MAX - get_minute(now, q[0].first));
        }else if(get_day(now, q.back().first) < 3 && q.back().second == false){
            // recently remember 
            w.set_index(INT_MIN + get_hour(now, q.back().first));
        }else{
            // implement a easy strategy
            int index = 0;
            for(auto & t : q){
                if(t.second)
                    index ++;
                else
                    index --;
            }
            w.set_index(index);
        }
    }

    std::sort(words.begin(), words.end(), SortByIndex());
}

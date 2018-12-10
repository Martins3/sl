#include<api/Strategy.hpp>
#include<Word.hpp>
#include<Loader.hpp>
#include<algorithm>
#include<climits>
#include<Interface.hpp>
#include<Util.hpp>

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


bool never_remembered(std::vector<std::pair<time_t, bool> > & query_time_point){
    for(auto & p : query_time_point){
        if(p.second == false){
            return false;
        }
    }
    return true;
}



void Strategy::sort(std::vector<Word> & words, int count){
    long now = time(nullptr);
    count = min((int)words.size(), count);

    
    for(auto & w : words){
        auto q = w.get_record();
        if(never_remembered(q)){
            // recently added
            w.set_index(INT_MAX - get_minute(now, q.back().first));
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

void Strategy::interactive(){
        Loader & L = Loader::getInstance();
        Interface & I = Interface::getInstance();
        vector<Word> & words = L.getWords();
        srand (time(NULL));

        // get all the alread reviewed words
        vector<Word*> v;
        for (int i = 0; i < words.size(); i++) {
            if(!never_remembered(words[i].query_time_point)){
                v.push_back(&(words[i]));
            }
        }
        if(v.empty()){
            cout << "You don't remember anything, it's too early to step into interactive mode" << endl;
            return;
        }
        

        int len = v.size();
        while(true){
            int inx = rand() % len;
            Word & w = *(v[inx]);

            I.print_word_info(w, false); // id is useless here
            string input;
            getline(std::cin, input);
            if(input == "y"){
                w.check(false);
            }else if(input == "n"){
                w.check(true);
                cout << Util::exec("trans -sp " + w.get_word()) << endl;
            }else if(input == "gg"){
                break;
            }else if(input == "x"){
                string sw = w.get_word();
                L.check_word(sw, REMOVE);
            }else{
                cerr << "Specification:\nY : yes\nN : No\nGG : over" << endl;
                break;
            }
        }
        return;
}

#include <Strategy.hpp>

using namespace std;

void Strategy::check(Word & w, bool forget){
    w.query_time_point.push_back(make_pair(time(nullptr), forget));
}

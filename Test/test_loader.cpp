#ifndef TEST_LODER_HPP
#define TEST_LODER_HPP
#include "../Include/Loader.hpp"
#include<iostream>
#include<thread>
#include <unistd.h>
#include <iomanip>

using namespace std;
using json = nlohmann::json;

void fuck_to_json(){
    Loader & L = Loader::getInstance();
    vector<Word> & words = L.load();
    for(auto & w : words){
        json j = w;
        cout << j << endl;
    }
    // Word w("test", 1);
    // w.check();
    // sleep(1);
    // words.push_back(w);
    // w.check();
    // words.push_back(w);
    // L.store();
}

#endif

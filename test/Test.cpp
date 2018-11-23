#ifndef TEST_LODER_HPP
#define TEST_LODER_HPP

#include <Loader.hpp>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <iomanip>
#include <vector>

#include <Interface.hpp>
#include <string>

using namespace std;
using json = nlohmann::json;

void store_data();


int test_main(int argc, const char *argv[]){
    thread loader([](){ Loader::getInstance().load(); });
    Interface & I = Interface::getInstance();

    if(I.parse_options(argc,  argv) == 0){
        loader.join();
        I.handle();
    }else{
        // maybe just stop it !
        loader.join();
        // store is not needed !
    }
    return 0;
}

// read the data
void test_load(){
    Loader & L = Loader::getInstance();
    L.load();

    vector<Word> & w = L.getWords();

    for(auto & word : w){
        word.print_word();
    }
}

void add_word_using_file(){
    Loader & L = Loader::getInstance();
    L.add_one_word("hhhhhh");

    vector<Word> & w = L.getWords();
    for(auto & word : w){
        word.print_word();
    }

    store_data();
}




void store_data(){
    Loader::getInstance().store();
}

#endif
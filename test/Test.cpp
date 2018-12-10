#ifndef TEST_LODER_HPP
#define TEST_LODER_HPP

#include <Printer.hpp>
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
    thread loader([](){ Loader::getInstance().load_words(); });
    Loader & L = Loader::getInstance();
    L.load_config();
    Interface & I = Interface::getInstance();
    if(I.parse_options(argc,  argv) == 0){
        loader.join();
        I.handle();
        L.store();
    }else{
        // maybe just stop it !
        loader.join();
        // store is not needed !
    }
    return 0;
}

void clear_data(){
    Loader::getInstance().store();
}

void clear_user_data(){
    Loader::getInstance().set_default_config();
}

void export_words_data(){
    auto & L = Loader::getInstance();
    L.load_words();
    for(auto & w : L.getWords()){
        cout << w.get_word() << endl;
    }
}

void histogram(){
  // string str= "Added Words";
  // int left_indent = str.size();
  // int num = 202;
}


#endif

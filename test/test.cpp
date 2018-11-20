#ifndef TEST_LODER_HPP
#define TEST_LODER_HPP

#include <Loader.hpp>
#include <iostream>
#include<thread>
#include <unistd.h>
#include <iomanip>

#include <Interface.hpp>

using namespace std;
using json = nlohmann::json;


int test_main(int argc, const char *argv[]){
    thread loader([](){ Loader::getInstance().load(); });
    Interface & I = Interface::getInstance();
#ifdef DEBUG
    printf("%s\n", "ffffffffff");
#endif
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

void fuck_to_json(){
    Loader::getInstance().store();
}

#endif

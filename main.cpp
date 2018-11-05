#include "Include/Word.hpp"
#include "Include/Interface.hpp"
#include "Include/Loader.hpp"
#include "Include/Test.hpp"

// Test files

#include<iostream>
#include<stdio.h>
#include<thread>

using namespace std;

int main(int argc, const char *argv[]){
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


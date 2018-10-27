#include "Include/Word.hpp"
#include "Include/Interface.hpp"
#include "Include/Loader.hpp"

#include<iostream>
#include<stdio.h>
#include<thread>

using namespace std;





auto f = [](Loader &){
    cout << "fuck" << endl;
};


using namespace std;

int main(int argc, const char *argv[]){
    Loader & L = Loader::getInstance();
    thread loader(f, ref(L));

    Interface & I = Interface::getInstance();
    if(I.parse_options(argc,  argv) == 0){
        I.handle();
    }
    return 0;
}


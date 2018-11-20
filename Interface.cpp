#include <Interface.hpp>
#include <Strategy.hpp>
#include <Query.hpp>
#include <Loader.hpp>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int Interface::parse_options(int argc, const char *argv[]){
    int opt;
#ifdef Debug
                cout << "forget" << endl;
#endif
    while ((opt = getopt(argc,(char **)argv,"r:f:c:d:w:?")) != EOF){
        switch(opt){
            case 'r':
                word_id = strtol(optarg, NULL, 10);
                if(word_id == errno){
                    cout << "word is should be a integer" << endl;
                    abort();
                }
                forget = true;
                break;
            case 'f':
                word_id = strtol(optarg, NULL, 10);
                if(word_id == errno){
                    cout << "word id should be a integer" << endl;
                    abort();
                }
                break;
            case 'c':
                path_to_config = optarg;
                cout << "Path to configuration is : "<< path_to_config << endl;
                break;
            case 'd':
                path_to_new_words = optarg;
                cout << "Path to new Words is : "<< path_to_new_words << endl;
                break;
            case 'w':
                word = optarg;
                cout << "Added words is : "<< word << endl;
                break;
            case '?':
                fprintf(stderr,
                        "usuage is: \n\
                        ");
                break;
            default:
                cout << endl;
                abort();
        }
    }
    return 0;
}

void Interface::handle(){
    Strategy & S = Strategy::getInstance();
    Loader & L = Loader::getInstance();

    if(path_to_config.size()){
        cout << "reading config" << endl;
        return;
    }

    if(path_to_new_words.size()){
        cout << "reading data" << endl;
        return;
    }

    // add a word
    if(word.size()){

        return;
    }

    if(forget){
        cout << "forget some wrods" << endl;
    }


    else{
        cout << "remember some words" << endl;
    }

    // just show words
    S.Ebbinghaus(L.getWords());
    int count = L.getUserConfig().get_show_limitation();
}



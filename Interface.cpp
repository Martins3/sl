#include "Include/Interface.hpp"
#include "Include/Strategy.hpp"
#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

using namespace std;

int Interface::parse_options(int argc, const char *argv[]){
    int opt;
    while ((opt = getopt(argc,(char **)argv,"fw:c:")) != EOF){
        switch(opt){
            case 'f':
#ifdef Debug
                cout << "forget" << endl;
#endif
                cout << "forget" << endl;
                forget = true;
                break;
            case 'w':
                word = strtol(optarg, NULL, 10);
                if(show_number == errno){
                    cout << "Count of lines show be a integer" << endl;
                    abort();
                }
                break;
            case 'c':
                show_number = strtol(optarg, NULL, 10);
                if(show_number == errno){
                    cout << "Count of lines show be a integer" << endl;
                    abort();
                }
                cout << "show number "<< show_number << endl;
                break;
            case '?':
                fprintf(stderr,
                        "usuage is \n\
                        -c : for enabling cowsay(todo) \n\
                        -w : show statistic for one word \n\
                        -s: show user learning process\n\
                        -n: set how many words to show\n\
                        ");
            default:
                cout << endl;
                abort();
        }
    }
    return 0;
}

void Interface::handle(){

    // if(word.size()){
//
//
        // if(forget){
            // Word w;
           // Strategy::check(, true)
        // }else{
//
        // }
    // }else{
    // }

    cout << "handle over" << endl;
}



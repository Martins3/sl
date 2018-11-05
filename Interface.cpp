#include "Include/Interface.hpp"
#include "Include/Strategy.hpp"
#include "Include/Query.hpp"
#include "Include/Loader.hpp"
#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

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
    Query & query = Query::getInstance();
    Loader & loader = Loader::getInstance();
    if(path_to_config.size()){
        cout << "reading config" << endl;
        return;
    }

    if(path_to_new_words.size()){
        cout << "reading data" << endl;
        return;
    }

    if(word.size()){
        if(!query.check_in_range(word)){
            cout << "Added words is not in the database !" << endl;
            return;
        }

        else{
            /**
             * Find the unused id, this algorithm seems fairly stupid.
             * TODO: fix this by using a special word.
             */
            vector<Word> & words = loader.getWords();
            sort(words.begin(), words.end(), SortById());
            for (int i = 0; i < words.size(); i++) {
                if(i != words[i].id){

                }
            }
        }
        return;
    }

    if(forget){
        cout << "forget some wrods" << endl;
    }


    else{
        cout << "remember some words" << endl;

    }
}



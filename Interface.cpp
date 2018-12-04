#include <Interface.hpp>
#include <Strategy.hpp>
#include <Query.hpp>
#include <Loader.hpp>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>

using namespace std;
const std::string Interface::ANSI_COLOR_RED     = "\x1b[31m";
const std::string Interface::ANSI_COLOR_GREEN   = "\x1b[32m";
const std::string Interface::ANSI_COLOR_YELLOW  = "\x1b[33m";
const std::string Interface::ANSI_COLOR_BLUE    = "\x1b[34m";
const std::string Interface::ANSI_COLOR_MAGENTA = "\x1b[35m";
const std::string Interface::ANSI_COLOR_CYAN    = "\x1b[36m";
const std::string Interface::ANSI_COLOR_RESET   = "\x1b[0m";

void Interface::parse_word_id(){
    User & u = Loader::getInstance().getUserConfig();

    if(u.is_show_word_id()){
        word_id = strtol(optarg, NULL, 10);
        if(word_id == errno){
            std::cerr << "word id should be a integer" << std::endl;
            exit(1);
        }
    }else{
        word = optarg;
    }
}

int Interface::parse_options(int argc, const char *argv[]){
    int opt;

    while ((opt = getopt(argc,(char **)argv,"r:f:c:d:w:hs:x:")) != EOF){
        switch(opt){
            case 'r':
                parse_word_id();
                forget = false;
                review = false;
                break;
            case 'f':
                parse_word_id();
                forget = true;
                review = false;
                break;
            case 'c':
                path_to_config = optarg;
                cout << "Path to configuration is : "<< path_to_config << endl;
                break;
            case 'd':
                path_to_new_words = optarg;
                break;
            case 'x':
                parse_word_id();
                remove = true;
                break;
            case 's':
                parse_word_id();
                shutdown = true;
                break;
            case 'w':
                add = true;
                word = optarg;
                cout << "Added words is : "<< word << endl;
                break;
            case 'h':
                fprintf(stderr, "\
                    usuage is:\n\
                        -h show this help information\n\
                        -r remember\n\
                        -f forget\n\
                        -c load new configuration file\n\
                        -d add a file of words\n\
                        -x remove one word from database permanentely\n\
                        -s forbid this word to appear recently\n\
                        -w add one word\n");

                exit(0);
            default:
                cout << endl;
                abort();
        }
    }
    return 0;
}


void Interface::handle(){
    Loader & L = Loader::getInstance();
    User & U = L.getUserConfig();
    bool id = U.is_show_word_id();

    if(path_to_config.size()){
        // TODO there is no need to doing things so complex
        return;
    }


    if(path_to_new_words.size()){
        L.add_file(path_to_new_words);
        return;
    }


    if(shutdown){
        if(U.is_show_word_id()){
            L.check_word(word_id, SHUTDOWN);
        }else{
            L.check_word(word, SHUTDOWN);
        }
        return;
    }

    if(remove){
        if(U.is_show_word_id()){
            L.check_word(word_id,REMOVE);
        }else{
            L.check_word(word, REMOVE);
        }
        return;
    }

    // add a word
    if(add){
        L.add_one_word(word);
        return;
    }

    if(review){
        // just show words
        vector<Word> & words = L.getWords();
        // sort it

        sort(words.begin(), words.end(), SortByIndex());
        int count = L.getUserConfig().get_show_limitation();

        print_header(id);
        for (int i = 0; i < count; i++) {
            // words[i].add_index(-1);
            print_word_info(words[i], id);
        }

        // show random
        int len = words.size();
        int r_limit  = U.get_random_show_limitation();

        if(r_limit > 0){
            cout << ANSI_COLOR_BLUE
                 << "----------------\n" << endl; 
        }

        srand (time(NULL));
        for (int i = 0; i < r_limit ; i++) {
            int inx = rand() % len;
            // words[inx].add_index(-1);
            print_word_info(words[inx], id);
        }

        // exit(0);
        return;
    }

    // show words
    if(forget){
        if(U.is_show_word_id()){
            L.check_word(word_id,FORGET);
        }else{
            L.check_word(word, FORGET);
        }
    }
    else{
        if(U.is_show_word_id()){
            L.check_word(word_id, REM);
        }else{
            L.check_word(word, REM);
        }
    }
}


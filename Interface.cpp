#include <Interface.hpp>
#include <Strategy.hpp>
#include <Query.hpp>
#include <Loader.hpp>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>

using namespace std;

int Interface::parse_options(int argc, const char *argv[]){
    int opt;

    while ((opt = getopt(argc,(char **)argv,"r:f:c:d:w:h")) != EOF){
        switch(opt){
            case 'r':
                word_id = strtol(optarg, NULL, 10);
                if(word_id == errno){
                    cout << "word is should be a integer" << endl;
                    exit(0);
                }
                review = false;
                break;
            case 'f':
                word_id = strtol(optarg, NULL, 10);
                if(word_id == errno){
                    cout << "word id should be a integer" << endl;
                    exit(0);
                }
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
            case 'w':
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

    if(path_to_config.size()){
        // TODO L.read_config
        L.store();
        return;
    }


    if(path_to_new_words.size()){
        L.add_file(path_to_new_words);
        L.store();
        return;
    }

    // add a word
    if(word.size()){
        L.add_one_word(word);
        L.store();
        return;
    }

    if(review){
        // just show words
        vector<Word> & words = L.getWords();
        Strategy::Ebbinghaus(words);
        int count = L.getUserConfig().get_show_limitation();

        print_header();
        for (int i = 0; i < count; i++) {
            words[i].print_word();
        }
        return;
    }

    // show words
    if(forget){
        L.check_word(word_id, false);
    }

    else{
        L.check_word(word_id, true);
    }
    L.store();
}



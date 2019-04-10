#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <Loader.hpp>
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <Word.hpp>
#include <string>


/**
 * handle user IO
 */

class Interface{
    // colors
    // command line args
    int word_id;
    bool forget;
    bool review;
    bool shutdown;
    bool remove;
    bool add;
    bool interactive;

    std::string path_to_config;
    std::string path_to_new_words;
    std::string show_record;
    std::string word;

    void parse_word_id();
public:
    Interface(Interface const&)       = delete;
    void operator=(Interface const&)  = delete;
    static Interface& getInstance(){
        static Interface instance;
        return instance;
    }

    int parse_options(int argc, const char *argv[]);
    void handle();
private:
    Interface():review(true), shutdown(false), remove(false), add(false), interactive(false){}
};

#endif


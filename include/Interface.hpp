#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <Loader.hpp>
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <Word.hpp>
#include <string>


/**
 * handle user IO and show 
 */

enum COLOR{
    RED, GREEN, YELLO, BLUE, MAGENTA, CYAN
};

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
    std::string word;

    // beatify the print TODO
    void println(const std::string & line, enum COLOR c = RED);
    template<typename T> void printElement(T t, const int& width) {
        std::cout << std::left << std::setw(width) << std::setfill(' ') << t;
    }


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

    static const std::string ANSI_COLOR_RED     ;
    static const std::string ANSI_COLOR_GREEN   ;
    static const std::string ANSI_COLOR_YELLOW  ;
    static const std::string ANSI_COLOR_BLUE    ;
    static const std::string ANSI_COLOR_MAGENTA ;
    static const std::string ANSI_COLOR_CYAN    ;
    static const std::string ANSI_COLOR_RESET   ;

    void print_header(bool id){
        Loader::getInstance().getUserConfig().is_show_word_id();
        if(id){
            std::cout << ANSI_COLOR_RED<< "id\t";
        }
        std::cout << ANSI_COLOR_CYAN << "word" << std::endl;
    }

    void print_word_info(Word & w, bool id){
        if(id){
            std::cout << ANSI_COLOR_YELLOW << w.get_id() << "\t";
        }
        std::cout << ANSI_COLOR_GREEN << w.get_word() << std::endl;
    }
private:
    Interface():review(true), shutdown(false), remove(false), add(false), interactive(false){}
};

#endif


#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <string>
#include <iostream>
#include <unistd.h>
#include <iomanip>


/**
 * handle user IO and show 
 */

enum COLOR{
    RED, GREEN, YELLO, BLUE, MAGENTA, CYAN
};

class Interface{
    // colors
    const std::string ANSI_COLOR_RED     = "\x1b[31m";
    const std::string ANSI_COLOR_GREEN   = "\x1b[32m";
    const std::string ANSI_COLOR_YELLOW  = "\x1b[33m";
    const std::string ANSI_COLOR_BLUE    = "\x1b[34m";
    const std::string ANSI_COLOR_MAGENTA = "\x1b[35m";
    const std::string ANSI_COLOR_CYAN    = "\x1b[36m";
    const std::string ANSI_COLOR_RESET   = "\x1b[0m";
    // command line args
    int show_number;

    std::string word;
    bool forget = false;

    // print
    void println(const std::string & line, enum COLOR c = RED);
    template<typename T> void printElement(T t, const int& width) {
        std::cout << std::left << std::setw(width) << std::setfill(' ') << t;
    }

    // show words startery
    
    // modify data base
public:
    Interface(Interface const&)       = delete;
    void operator=(Interface const&)  = delete;
    static Interface& getInstance(){
        static Interface    instance;
        return instance;
    }

    int parse_options(int argc, const char *argv[]);
    void handle();
private:
    Interface() = default;
};
#endif


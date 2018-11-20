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
    int word_id;
    bool forget = false;

    std::string path_to_config = nullptr;
    std::string path_to_new_words = nullptr;
    std::string word = nullptr;

    // beatify the print TODO
    void println(const std::string & line, enum COLOR c = RED);
    template<typename T> void printElement(T t, const int& width) {
        std::cout << std::left << std::setw(width) << std::setfill(' ') << t;
    }

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


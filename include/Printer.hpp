#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <Word.hpp>

enum COLOR{
    RED, GREEN, YELLO, BLUE, MAGENTA, CYAN
};

class Printer{
    static const std::string ANSI_COLOR_RED     ;
    static const std::string ANSI_COLOR_GREEN   ;
    static const std::string ANSI_COLOR_YELLOW  ;
    static const std::string ANSI_COLOR_BLUE    ;
    static const std::string ANSI_COLOR_MAGENTA ;
    static const std::string ANSI_COLOR_CYAN    ;
    static const std::string ANSI_COLOR_RESET   ;


    static void histogram_line(std::string str, int left_indent, int num);
public:

    static void histogram(std::vector<std::string> & name, std::vector<int> & quantity);
    static void header(bool id){ if(id){
            std::cout << ANSI_COLOR_RED<< "id\t";
        }
        std::cout << ANSI_COLOR_CYAN << "word" << std::endl;
    }

    static void word_info(Word & w, bool id){
        if(id){
            std::cout << ANSI_COLOR_YELLOW << w.get_id() << "\t";
        }
        std::cout << ANSI_COLOR_GREEN << w.get_word() << std::endl;
    }

    static void delimiter(){
      std::cout << Printer::ANSI_COLOR_BLUE
           << "----------------\n" << std::endl; 
    }
};

#endif /* end of include guard: PRINTER_H */

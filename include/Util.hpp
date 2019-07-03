#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <array>



class Util{
public:
    static std::string exec(const std::string cmd);
    static void edit_file(const char *file) ;
};

// learn temporarily put here
void learn();

#endif /* end of include guard: UTIL_H */

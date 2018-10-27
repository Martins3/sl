#ifndef LOADER_HPP
#define LOADER_HPP

#include <string>
#include "json.hpp"
#include "Word.hpp"
#include "User.hpp"



class Loader{
    static const std::string words_path;
    static const std::string user_path;

public:
    static Loader& getInstance(){
        static Loader    instance;
        return instance;
    }
    Loader(Loader const&)       = delete;
    void operator=(Loader const&)  = delete;

private:
    Loader() = default;
};
#endif

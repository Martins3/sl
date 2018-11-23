#ifndef LOADER_HPP
#define LOADER_HPP

#include <string>
#include "json.hpp"
#include "Word.hpp"
#include "User.hpp"

/**
 * 1. Loader is a singleton
 * 2. if anyone wants to change database, it show use store and load
 */

class Loader{
    static const std::string config_dir;
    std::vector<Word> words;
    User user;
public:
    // load should be done at begining 
    void load();
    void store();

    void add_one_word(const std::string & w);
    void add_file(const std::string & path);

    std::vector<Word> & getWords(){
        return words;
    }

    User & getUserConfig(){
        return user;
    }

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

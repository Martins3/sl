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

typedef enum CHECK_TYPE{
    REM, FORGET, SHUTDOWN, REMOVE
} check_t;

class Loader{
    static const std::string config_dir;
    std::vector<Word> words;
    User user;
public:
    // load should be done at begining 
    void load_words();
    void load_config();
    void store();

    void add_one_word(const std::string & w);
    void add_file(const std::string & path);
    void review(bool id);

    void check_word(int id, check_t type);
    void check_word(std::string & word, check_t type);
    void handle_word(Word & word, check_t type);

    void set_default_config();
    std::vector<Word> & getWords(){
        return words;
    }

    User & getUserConfig(){
        return user;
    }

    static Loader& getInstance(){
        static Loader instance;
        return instance;
    }
    Loader(Loader const&)       = delete;
    void operator=(Loader const&)  = delete;
private:
    Loader()=default;
};
#endif

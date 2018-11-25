#ifndef USER_HPP
#define USER_HPP

#include <json.hpp>
#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

/**
 * Used one class for record user access information is wasted
 */

using json = nlohmann::json;
class User{
    int show_limitation;
    bool show_word_id;
    int random_show_limitation;
    // std::string strategy;
    friend void to_json(json& j, const User& u);
    friend void from_json(const json& j, User& p);
public:
    int get_show_limitation(){
        return show_limitation;
    }

    bool is_show_word_id(){
        return show_word_id;
    }

    int get_random_show_limitation(){
        return random_show_limitation;
    }

    User():show_limitation(10), show_word_id(false),
        random_show_limitation(5){};
};


#endif

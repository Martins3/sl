#ifndef USER_HPP
#define USER_HPP

#include "json.hpp"
#include <chrono>
#include <string>
#include <vector>
#include <ctime>

/**
 * Used one class for record user access information is wasted
 */

using json = nlohmann::json;
class User{
    int show_limitation = 10;
    // std::string strategy;
    friend void to_json(json& j, const User& u);
    friend void from_json(const json& j, User& p);
};


#endif

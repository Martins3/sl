#ifndef USER_HPP
#define USER_HPP

#include "json.hpp"
#include <chrono>
#include <string>
#include <vector>
#include <ctime>

using json = nlohmann::json;
class User{
    int show_limitation = 10;
    std::vector<time_t> check_point;

    friend void to_json(json& j, const User& u);
    friend void from_json(const json& j, User& p);
};


#endif

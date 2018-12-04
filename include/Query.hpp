#ifndef QUERY_HPP
#define QUERY_HPP
#include<string>

class Query{
public:
    // use shell-translate
    static void trans(std::string word);
    // use database TODO
    static void ecdict(std::string word);
    // check the words is in our specific database TODO
    static bool check_in_range(std::string word);
};
#endif

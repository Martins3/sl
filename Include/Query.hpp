#ifndef QUERY_HPP
#define QUERY_HPP
#include<string>

class Query{
private:
    static std::string exec(const std::string cmd);


public:
    // use shell-translate
    void trans(std::string word);
    // use database
    void ecdict(std::string word);
};
#endif

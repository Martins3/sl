#ifndef QUERY_HPP
#define QUERY_HPP
#include<string>

class Query{
private:
    static std::string exec(const std::string cmd);
public:
    // use shell-translate
    void trans(std::string word);
    // use database TODO
    void ecdict(std::string word);
    // check the words is in our specific database TODO
    bool check_in_range(std::string word);



    Query(Query const&)       = delete;
    void operator=(Query const&)  = delete;
    static Query& getInstance(){
        static Query    instance;
        return instance;
    }
private:
    Query() = default;
};
#endif

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
    // check the words is in our specific database
    bool check_in_range(std::string word);



    Query(Query const&)       = delete;
    void operator=(Query const&)  = delete;
    static Query& getInstance(){
        static Query    instance;
        return instance;
    }
    int parse_options(int argc, const char *argv[]);
    void handle();
private:
    Query() = default;
};
#endif

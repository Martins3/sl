#ifndef STATISTIC_HPP_N0RHLI4W
#define STATISTIC_HPP_N0RHLI4W
#include <ctime>
#include <string>
#include <vector>
#include <ctime>

// record user's information

typedef enum CHECK_TYPE{
  REVIEW = 0,
  INTERACTIVE = 1, 
  ADD = 2,
  REM = 3,
  FORGET = 4,
  SHUTDOWN = 5,
  REMOVE = 6
} check_t;

class OP_Record{
public:
  time_t time_point;
  check_t type;
  OP_Record(check_t t):time_point(time(nullptr)), type(t){}
  OP_Record()=default;
};




#endif /* end of include guard: STATISTIC_HPP_N0RHLI4W */

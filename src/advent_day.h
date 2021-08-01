#ifndef ADVENTDAY_H
#define ADVENTDAY_H
#include <string>

class AdventDay {
  public:
    virtual ~AdventDay() {};
    virtual std::string part1() = 0;
    virtual std::string part2() = 0;
};
#endif

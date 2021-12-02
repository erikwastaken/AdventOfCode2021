#ifndef DAY02_HPP
#define DAY02_HPP
#include <string>
#include <vector>

namespace aoc21 {

  struct Instruction {
    std::string direction;
    int distance;
  };
  
  struct Point {
    int x;
    int y;
  };

  class Day02 {
    public:
      Day02(const std::vector<std::string>&);
      std::string part1();

    private:
      std::vector<Instruction> _instructions {};
      Point _position;

      Instruction parseInputLine(const std::string&);
  };

}

#endif


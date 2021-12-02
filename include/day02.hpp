#ifndef DAY02_HPP
#define DAY02_HPP
#include <string>
#include <vector>

namespace aoc21 {

  
  class Day02 {
    public:
      Day02(const std::vector<std::string>&);
      std::string part1() const;
      std::string part2() const;

    private:
      struct Instruction {
        std::string direction;
        int distance;
      };
      std::vector<Instruction> _instructions {};
      Instruction parseInputLine(const std::string&) const;
  };

}

#endif


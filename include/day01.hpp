#ifndef DAY01_HPP
#define DAY01_HPP
#include <string>
#include <vector>

namespace aoc21 {

  class Day01 {
    public:
      explicit Day01(const std::vector<std::string>& input);
      std::string part1() const;
      std::string part2() const;
    private:
      std::vector<int> _depths;
  };

}

#endif


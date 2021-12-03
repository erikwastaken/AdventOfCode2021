#ifndef DAY03_HPP
#define DAY03_HPP
#include <string>
#include <vector>

namespace aoc21 {

  class Day03 {
    public:
      Day03(const std::vector<std::string>&);
      std::string part1() const;
      std::string part2() const;
    private:
      std::vector<int> _diagnostics {};
      int _bit_length {0};

      int getMostCommon(const int, const std::vector<int>&) const;
      int getOxygenRating() const;
      int getCo2Rating() const;
  };

}

#endif


#ifndef DAY03_HPP
#define DAY03_HPP
#include <string>
#include <vector>
#include <functional>

namespace aoc21 {

  int getMostCommon(const int, const std::vector<int>&);
  int getLeastCommon(const int, const std::vector<int>&);

  class Day03 {
    public:
      Day03(const std::vector<std::string>&);
      std::string part1() const;
      std::string part2() const;
    private:
      std::vector<int> _diagnostics {};
      int _bit_length {0};

      int getRating(std::function<int(int, const std::vector<int>&)>) const;
  };

}

#endif


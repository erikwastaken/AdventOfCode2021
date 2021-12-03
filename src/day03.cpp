#include "day03.hpp"
#include <vector>
#include <string>
#include "exceptions.hpp"

namespace aoc21 {

  int getMostCommon(const int position, const std::vector<int>& values) {
    int countOn = 0;
    for (const auto& n : values) {
      if ( ((n >> position) & 1) == 1 ) {
        ++countOn;
      }
    }
    return (2 * countOn < values.size()) ? 0 : 1;
  };

  int getLeastCommon(const int position, const std::vector<int>& values) {
    return 1 ^ getMostCommon(position, values);
  };

  Day03::Day03(const std::vector<std::string>& input) {
    for (const auto& line : input) {
      auto number = std::stoi(line, nullptr, 2);
      this->_diagnostics.push_back(number);
    }
    this->_bit_length = input[0].size();
  };

  std::string Day03::part1() const {
    int gamma = 0;
    int epsilon = 0;
    for (auto i=0; i!=_bit_length; ++i) {
      if (getMostCommon(i, _diagnostics) == 1) {
        gamma |= 1 << i;
        epsilon &= ~(1 << i);
      } else {
        gamma &= ~(1 << i);
        epsilon |= 1 << i;
      }
    }
    return std::to_string( epsilon * gamma );
  };

  std::string Day03::part2() const {
    auto oxygen = getRating(&getMostCommon);
    auto co2Scrubber = getRating(&getLeastCommon);
    return std::to_string(oxygen * co2Scrubber);
  };

  int Day03::getRating(std::function<int(int, const std::vector<int>&)> getCommon) const {
    auto keep = _diagnostics;
    for (int i = _bit_length - 1; keep.size() != 1; --i) {
      if (i == -1) throw AoCException("Could not narrow down to single value");
      auto tmp = std::vector<int>();
      auto favouredBit = getCommon(i,keep);
      for (const auto& n : keep) {
        if ( ((n >> i) & 1) == favouredBit) {
          tmp.push_back(n);
        }
      }
      keep = tmp;
    }
    return keep[0];
  };

}

#include "day01.hpp"

aoc21::Day01::Day01(const std::vector<std::string>& input) {
  for (const auto& line : input) {
    _depths.push_back(std::stoi(line));
  }
}

std::string aoc21::Day01::part1() {
  auto depthIncreases = 0;
  auto previous = _depths[0];
  for (auto i = 1; i != _depths.size(); ++i) {
    auto current = _depths[i];
    if (previous < current) {
      ++depthIncreases;
    }
    previous = current;
  }
  return std::to_string(depthIncreases);
}

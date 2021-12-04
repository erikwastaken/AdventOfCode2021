#ifndef DAY_HANDLER_HPP
#define DAY_HANDLER_HPP
#include <concepts>
#include <iostream>

namespace aoc21 {

  template<typename T>
  concept Day = requires(T d) {
    { d.part1() } -> std::same_as<std::string>;
    { d.part2() } -> std::same_as<std::string>;
  };

  template<Day T>
  inline void execute(const T& day) {
    std::cout << "Part1: " << day.part1() << '\n';
    std::cout << "Part2: " << day.part2() << '\n';
  }

  void runDay(int day, const std::string& path);

}

#endif


#ifndef DAY_HANDLER_HPP
#define DAY_HANDLER_HPP
#include <concepts>
#include <iostream>
#include <chrono>

namespace aoc21 {

  template<typename T>
  concept Day = requires(T d) {
    { d.part1() } -> std::same_as<std::string>;
    { d.part2() } -> std::same_as<std::string>;
  };

  template<Day T>
  void execute(const T& day);
  void runDay(int day, const std::string& path);
  void printExecutionTime(const std::chrono::time_point<std::chrono::high_resolution_clock> &start,const std::chrono::time_point<std::chrono::high_resolution_clock> &end);

}

#endif


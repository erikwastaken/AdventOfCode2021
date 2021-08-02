#include <iostream>
#include "advent_day.h"
#include "advent_factory.h"
#include "exceptions.h"

int main(int argc, char* argv[]) {
  try {
    auto day = AdventFactory().createDayFromCommandLine(argc, argv);
    std::cout << "Part1: " << day->part1() << std::endl;
    std::cout << "Part2: " << day->part2() << std::endl;
  } catch (AoCException& e) {
    std::cout << e.what() << std::endl;
  }
}

#include <iostream>
#include <memory>
#include "advent_day.h"
#include "default_day.h"

std::unique_ptr<AdventDay> createDay(int day);

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Provide a day as a command line argument" << std::endl;
    return 1;
  }
  std::cout << "Day" << argv[1] << std::endl;
  std::string argv1 = argv[1];
  int num = std::stoi(argv1);
  auto day = createDay(num);
  std::cout << "Part1: " << day->part1() << std::endl;
  std::cout << "Part2: " << day->part2() << std::endl;
}

std::unique_ptr<AdventDay> createDay(int day) {
  switch (day) {
    default: return std::unique_ptr<AdventDay>{ new DefaultDay() };
  }
}

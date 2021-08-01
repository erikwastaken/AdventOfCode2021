#include <iostream>
#include <memory>
#include <cstdlib>
#include "advent_day.h"
#include "default_day.h"

std::unique_ptr<AdventDay> createDay(int day);
int parseCommandLineArguments(int argc, char* argv[]);

int main(int argc, char* argv[]) {
  int num = parseCommandLineArguments(argc, argv);
  auto day = createDay(num);
  std::cout << "Day" << num << std::endl;
  std::cout << "Part1: " << day->part1() << std::endl;
  std::cout << "Part2: " << day->part2() << std::endl;
}

std::unique_ptr<AdventDay> createDay(int day) {
  switch (day) {
    default: return std::unique_ptr<AdventDay>{ new DefaultDay() };
  }
}

int getDayNumber() {
  while (true) {
    int d {0};
    std::cout << "Please provide the day: ";
    std::cin >> d;
    if (0 < d && d < 26) return d;
  }
}

int parseCommandLineArguments(int argc, char* argv[]) {
  if (argc < 2) return getDayNumber();
  else return std::atoi(argv[1]);
}

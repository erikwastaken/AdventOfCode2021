#include <iostream>
#include <concepts>
#include "default_day.hpp"
#include "file_reader.hpp"
#include "exceptions.hpp"

template<typename T>
concept Day = requires(T d) {
  { d.part1() } -> std::same_as<std::string>;
  { d.part2() } -> std::same_as<std::string>;
};

template<Day T>
void execute(T day) {
  std::cout << "Part1: " << day.part1() << "\n";
  std::cout << "Part2: " << day.part2() << "\n";
}

auto getFileContents(std::string path) {
  auto fr = aoc21::FileReader(path);
  return fr.getLines();
}

void runDay(int day) {
  switch (day) {
    default: execute(aoc21::DefaultDay());
  }
}

int main(int argc, char* argv[]) {
  try {
    if (argc != 2)
      return 1;
    auto d = std::atoi(argv[1]);
    if (d == 0 || d > 25)
      return 2;
    runDay(d);
  } catch (aoc21::AoCException& e) {
    std::cerr << e.what() << '\n';
  }
}

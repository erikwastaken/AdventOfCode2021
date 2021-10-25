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

auto getFileContents(const std::string& path) {
  auto fr = aoc21::FileReader(path);
  return fr.getLines();
}

void runDay(int day,std::string& path) {
  switch (day) {
    default: execute(aoc21::DefaultDay());
  }
}

std::string getDefaultPath(int d) {
  if (d < 10)
    return "input/inputDay0" + std::to_string(d) + ".txt";
  return "input/inputDay" + std::to_string(d) + ".txt";
}

int main(int argc, char* argv[]) {
  try {
    if (argc != 2 && argc != 3)
      return 1;
    auto d = std::atoi(argv[1]);
    if (d == 0 || d > 25)
      return 2;
    auto path = argc == 2 ? getDefaultPath(d) : std::string(argv[2]);
    runDay(d,path);
  } catch (aoc21::AoCException& e) {
    std::cerr << e.what() << '\n';
  }
}

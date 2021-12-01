#include <iostream>
#include "exceptions.hpp"
#include "utils.hpp"
#include "day_handler.hpp"

constexpr auto getDayFromCommandLine(const int argc, char* argv[]) {
    if (argc != 2 && argc != 3)
      throw aoc21::ParameterException("Wrong number of parameters");
    auto d = std::atoi(argv[1]);
    if (d < 1 || d > 25)
      throw aoc21::ParameterException("Day out of range");
    return d;
}

int main(int argc, char* argv[]) {
  try {
    auto d = getDayFromCommandLine(argc, argv);
    auto path = argc == 2 ? aoc21::getDefaultPath(d) : std::string(argv[2]);
    aoc21::runDay(d,path);
  } catch (aoc21::AoCException& e) {
    std::cerr << e.what() << '\n';
  }
}

#include "day_handler.hpp"

void aoc21::runDay(const int day, const std::string& path) {
  switch (day) {
    case 1: 
      execute(aoc21::Day01(aoc21::getFileContents(path)));
      break;
    default:
      execute(aoc21::DefaultDay());
  }
}

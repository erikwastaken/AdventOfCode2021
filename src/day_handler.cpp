#include "day_handler.hpp"
#include "utils.hpp"
#include "default_day.hpp"
#include "day01.hpp"
#include "day02.hpp"

void aoc21::runDay(const int day, const std::string& path) {
  switch (day) {
    case 1: 
      execute(aoc21::Day01(aoc21::getFileContents(path)));
      break;
    case 2:
      execute(aoc21::Day02(aoc21::getFileContents(path)));
      break;
    default:
      execute(aoc21::DefaultDay());
  }
}

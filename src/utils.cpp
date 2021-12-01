#include "utils.hpp"

std::vector<std::string> aoc21::getFileContents(const std::string& path) {
  auto fr = aoc21::FileReader(path);
  return fr.getLines();
}

std::string aoc21::getDefaultPath(const int d) {
  if (d < 10)
    return "input/inputDay0" + std::to_string(d) + ".txt";
  return "input/inputDay" + std::to_string(d) + ".txt";
}

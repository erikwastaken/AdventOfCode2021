#ifndef UTILS_HPP
#define UTILS_HPP
#include <vector>
#include <string>
#include "file_reader.hpp"

namespace aoc21 {

  std::vector<std::string> getFileContents(const std::string& path);
  std::string getDefaultPath(int d);

}
#endif


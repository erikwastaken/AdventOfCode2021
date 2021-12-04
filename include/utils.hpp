#ifndef UTILS_HPP
#define UTILS_HPP
#include <vector>
#include <string>
#include <functional>
#include "file_reader.hpp"

namespace aoc21 {

  std::vector<std::string> getFileContents(const std::string& path);
  std::string getDefaultPath(int d);
  std::vector<std::string> splitString (const std::string &input, char splitChar);
  std::vector<int> splitString(const std::string &input, char splitChar, const std::function<int (const std::string&)>&);

}
#endif


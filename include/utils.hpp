#ifndef UTILS_HPP
#define UTILS_HPP
#include <vector>
#include <string>
#include <functional>
#include "file_reader.hpp"

namespace std {
    template <> struct hash<std::pair<int,int>> {
        inline size_t operator()(const std::pair<int,int> &p) const {
            std::hash<int> int_hasher;
            return int_hasher(p.first) ^ int_hasher(p.second);
        }
    };
}

namespace aoc21 {

  std::vector<std::string> getFileContents(const std::string& path);
  std::string getDefaultPath(int d);
  std::vector<std::string> splitString (const std::string &input, char splitChar);
  std::vector<int> splitString(const std::string &input, char splitChar, const std::function<int (const std::string&)>&);

}
#endif


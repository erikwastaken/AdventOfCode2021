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

std::vector<std::string> aoc21::splitString(const std::string & input, char splitChar) {
    auto result = std::vector<std::string>();
    auto buffer = std::string();
    for (auto c: input) {
        if (c == splitChar) {
            if (buffer.length() == 0) {
                continue;
            } else {
                result.emplace_back(buffer);
                buffer = std::string();
            }
        } else {
            buffer += c;
        }
    }
    if (buffer.length() != 0) {
        result.emplace_back(buffer);
    }
    return result;
}

std::vector<int> aoc21::splitString(const std::string & input, char splitChar, const std::function<int(const std::string&)>& func) {
    auto result = std::vector<int>();
    auto buffer = std::string();
    for (auto c: input) {
        if (c == splitChar) {
            if (buffer.length() == 0) {
                continue;
            } else {
                result.emplace_back(func(buffer));
                buffer = std::string();
            }
        } else {
            buffer += c;
        }
    }
    if (buffer.length() != 0) {
        result.emplace_back(func(buffer));
    }
    return result;
}
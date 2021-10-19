#include "file_reader.hpp"

aoc21::FileReader::FileReader(const std::string& path) {
  _file.open(path);
  if (!_file.is_open()) throw FileReaderException(path + " could not be opened");
}

aoc21::FileReader::~FileReader() {
  _file.close();
}

std::vector<std::string> aoc21::FileReader::getLines() {
  std::vector<std::string> lines {};
  for (std::string line; std::getline(_file, line); ) {
    lines.push_back(line);
  }
  return lines;
}

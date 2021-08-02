#include "file_reader.h"

FileReader::FileReader(std::string path) {
  _file.open(path);
  if (!_file.is_open()) throw FileReaderException(path + " could not be opened");
}

FileReader::~FileReader() {
  _file.close();
}

std::vector<std::string> FileReader::getLines() {
  std::vector<std::string> lines {};
  for (std::string line; std::getline(_file, line); ) {
    lines.push_back(line);
  }
  return lines;
}

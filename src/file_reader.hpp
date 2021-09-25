#ifndef FILE_READER_H
#define FILE_READER_H
#include <fstream>
#include <vector>
#include <string>
#include "exceptions.hpp"

class FileReader {
  public:
    FileReader(const std::string);
    ~FileReader();
    std::vector<std::string> getLines();
  private:
    std::fstream _file;
};

#endif
